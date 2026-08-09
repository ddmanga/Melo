"""Wrapper simple autour du client OpenAI, avec boucle de function calling.

Un seul point d'entrée (Assistant.ask) : facile à relire, à modifier,
ou à brancher sur un autre modèle plus tard.
"""
import json
import os
from pathlib import Path

import yaml
from openai import OpenAI

from ai.tools import TOOLS_SCHEMA, run_gdb_session

CONFIG_PATH = Path(__file__).parent.parent / "config.yaml"


def _load_config() -> dict:
    return yaml.safe_load(CONFIG_PATH.read_text(encoding="utf-8"))


class Assistant:
    def __init__(self):
        config = _load_config()
        api_key_env = config["openai"]["api_key_env"]
        api_key = os.environ.get(api_key_env)
        if not api_key:
            raise RuntimeError(
                f"variable d'environnement {api_key_env} non définie "
                f"(export {api_key_env}=sk-...)"
            )
        self.client = OpenAI(api_key=api_key)
        self.model = config["openai"]["model"]

    def ask(self, system_prompt: str, user_message: str, use_tools: bool = False) -> str:
        messages = [
            {"role": "system", "content": system_prompt},
            {"role": "user", "content": user_message},
        ]

        # boucle simple : tant que le modèle demande un outil, on l'exécute
        # et on lui renvoie le résultat, jusqu'à ce qu'il réponde en texte.
        for _ in range(5):  # garde-fou pour éviter une boucle infinie
            response = self.client.chat.completions.create(
                model=self.model,
                messages=messages,
                tools=TOOLS_SCHEMA if use_tools else None,
            )
            message = response.choices[0].message

            if not message.tool_calls:
                return message.content

            messages.append(message)
            for tool_call in message.tool_calls:
                if tool_call.function.name == "run_gdb_session":
                    args = json.loads(tool_call.function.arguments)
                    result = run_gdb_session(args["binary_path"], args["commands"])
                else:
                    result = f"Outil inconnu : {tool_call.function.name}"

                messages.append({
                    "role": "tool",
                    "tool_call_id": tool_call.id,
                    "content": result,
                })

        return "L'assistant a dépassé le nombre d'appels d'outils autorisés."
