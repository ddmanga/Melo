"""Outils ('function calling') que le LLM peut appeler pour aider l'élève.

Le point sensible ici est run_gdb_session : on exécute réellement gdb sur le
binaire de l'élève, donc on whiteliste strictement les commandes autorisées
et on impose un timeout, pour éviter qu'un binaire foireux (boucle infinie...)
ne bloque l'outil.
"""
import subprocess
from pathlib import Path
from typing import List

# whitelist stricte de commandes gdb (préfixes) autorisées.
# volontairement pas de 'shell', 'call', 'python' etc. qui permettraient
# d'exécuter du code arbitraire côté machine hôte.
ALLOWED_GDB_PREFIXES = (
    "break", "b ", "run", "r", "backtrace", "bt", "print", "p ",
    "next", "n", "step", "s", "continue", "c", "list", "l",
    "info", "watch", "frame", "f ",
)


def _is_allowed(cmd: str) -> bool:
    cmd = cmd.strip()
    return any(cmd == p.strip() or cmd.startswith(p) for p in ALLOWED_GDB_PREFIXES)


def run_gdb_session(binary_path: str, commands: List[str], timeout: int = 10) -> str:
    """Lance gdb en mode batch sur le binaire avec une liste de commandes."""
    if not Path(binary_path).exists():
        return f"Erreur : binaire introuvable ({binary_path})"

    safe_commands = [c for c in commands if _is_allowed(c)]
    rejected = [c for c in commands if c not in safe_commands]

    gdb_args = ["gdb", "--batch", "-q"]
    for c in safe_commands:
        gdb_args += ["-ex", c]
    gdb_args.append(binary_path)

    try:
        proc = subprocess.run(gdb_args, capture_output=True, text=True, timeout=timeout)
        output = proc.stdout + proc.stderr
    except FileNotFoundError:
        return "Erreur : gdb n'est pas installé sur cette machine."
    except subprocess.TimeoutExpired:
        output = "gdb : timeout (le binaire boucle probablement à l'infini)"

    if rejected:
        output += f"\n\n(commandes refusées, non autorisées : {rejected})"
    return output


def get_exercise_context(exercise_dir: Path) -> str:
    """Contenu du sujet/README d'un exercice, utilisé comme contexte pour le LLM."""
    readme = exercise_dir / "README.md"
    if readme.exists():
        return readme.read_text(encoding="utf-8")
    manifest = exercise_dir / "manifest.yaml"
    return manifest.read_text(encoding="utf-8") if manifest.exists() else ""


# schéma "tools" au format attendu par l'API OpenAI (function calling)
TOOLS_SCHEMA = [
    {
        "type": "function",
        "function": {
            "name": "run_gdb_session",
            "description": (
                "Lance gdb en mode batch sur le binaire compilé de l'élève avec une "
                "liste de commandes gdb (break, run, print, backtrace, next, step...). "
                "Utile pour localiser un segfault ou inspecter des variables."
            ),
            "parameters": {
                "type": "object",
                "properties": {
                    "binary_path": {"type": "string"},
                    "commands": {
                        "type": "array",
                        "items": {"type": "string"},
                        "description": "ex: ['break main', 'run', 'next', 'print *ptr']",
                    },
                },
                "required": ["binary_path", "commands"],
            },
        },
    }
]
