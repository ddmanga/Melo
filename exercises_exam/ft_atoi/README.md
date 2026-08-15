# ft_atoi

Fichiers à rendre : `ft_atoi.c`
Autorisé : aucune fonction externe (pas de stdlib.h/atoi)

Réimplémentez la fonction `atoi` : elle convertit une chaîne de
caractères représentant un nombre en un entier (`int`).

La fonction doit :
- ignorer les espaces et tabulations en début de chaîne (`' '`, `'\t'`,
  `'\n'`, `'\v'`, `'\f'`, `'\r'`),
- gérer un signe optionnel (`+` ou `-`) juste avant les chiffres,
- s'arrêter dès qu'elle rencontre un caractère qui n'est pas un chiffre,
- retourner `0` si la chaîne ne contient aucun chiffre valide.

Prototype : `int ft_atoi(const char *str);`

Exemple :

    ft_atoi("   -42abc")   // -> -42
    ft_atoi("+123")        // -> 123
    ft_atoi("hello")       // -> 0