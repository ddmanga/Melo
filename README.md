# piscine-tester

Testeur maison pour la piscine 42 : teste tes exos avant la moulinette,
simule un examen, et propose une aide IA (explication + debug via gdb).

## Installation

```bash
pip install -r requirements.txt
```

Pour l'aide IA :
```bash
export OPENAI_API_KEY=sk-...
```

## Utilisation

```bash
# lister les exercices disponibles
./cli.py list

# tester un exercice
./cli.py test ft_strdup /chemin/vers/mon/rendu/

# simuler un examen (tire des exos par tag, chronomètre)
./cli.py exam /chemin/vers/mon/rendu/ --tag exam_C_00 --nb 3 --duration 180

# demander à l'IA d'expliquer un exercice (sans donner la solution)
./cli.py ai-explain ft_strdup

# demander de l'aide au debug (l'IA peut utiliser gdb sur ton binaire)
./cli.py ai-debug ft_strdup /chemin/vers/mon/rendu/ "j'ai un segfault sur une chaine vide"
```

## Ajouter un exercice

Créer un dossier `exercises/mon_exo/` avec :
- `manifest.yaml` (sources attendues, options de compil, liste de tests)
- `README.md` (optionnel, sert de contexte pour `ai-explain`)
- `includes/` (optionnel, headers fournis par le sujet)

Voir `exercises/ft_strdup/` comme exemple. Chaque test peut fournir soit
un `main:` inline dans le YAML, soit un fichier externe via `program:`.
Aucune ligne de code Python à modifier pour ajouter un exercice.

## Architecture

```
cli.py            -> point d'entrée, sous-commandes
core/
  sandbox.py      -> exécution isolée d'un binaire (timeout, stdout/stderr)
  valgrind.py     -> détection des leaks mémoire
  runner.py       -> compile + exécute + compare (coeur du testeur)
  report.py       -> affichage terminal des résultats
exercises/        -> un dossier par exercice, données pures (yaml)
exam/
  simulator.py    -> pioche des exos par tag, chronomètre, sauvegarde une session
ai/
  client.py       -> wrapper OpenAI + boucle de function calling
  tools.py        -> l'outil gdb exposé au LLM (sandboxé, whitelist de commandes)
  prompts.py      -> les deux system prompts (explication / debug)
```

Le moteur (`core/`) ne connaît rien aux exercices : ils sont des données
(YAML), pas du code. L'IA consomme les mêmes briques (manifest, résultats
du runner) sans rien dupliquer.
