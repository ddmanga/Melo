# ft_putnbr

**Répertoire (piscine) :** `ex0/`
**Fichiers à rendre :** `ft_putnbr.c`
**Fonctions autorisées :** `write`

Écrire une fonction qui affiche un nombre passé en paramètre. La fonction
doit pouvoir afficher **toutes** les valeurs possibles d'un `int`, y compris
les bornes (`INT_MIN`, `INT_MAX`).

Prototype :
```c
void ft_putnbr(int nb);
```

Exemple :
```
ft_putnbr(42) affiche :
42
```

## Piège principal

`INT_MIN` (-2147483648) ne peut pas être simplement transformé en positif
avec `-nb` : `2147483648` dépasse la capacité d'un `int` (qui va jusqu'à
`2147483647`), ce qui provoque un **overflow**, un comportement indéfini en C.

Une façon sûre de gérer ça : passer en `long` (ou `long long`) avant de
prendre l'opposé, puisque `long` peut représenter `2147483648` sans problème.

## Autres cas à ne pas oublier

- `0` (aucun signe, un seul chiffre)
- Les nombres négatifs à un seul chiffre (`-7`)
- Les nombres à plusieurs chiffres, positifs et négatifs
- `INT_MAX` (2147483647)
