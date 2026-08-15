# ft_itoa

Fichiers à rendre : `ft_itoa.c`
Autorisé : `malloc`

Écrivez une fonction qui alloue (avec `malloc`) et retourne une chaîne de
caractères représentant l'entier passé en paramètre. Les nombres négatifs
doivent être gérés.

Prototype : `char *ft_itoa(int n);`

Exemple :

    ft_itoa(123)          // -> "123"
    ft_itoa(-123)         // -> "-123"
    ft_itoa(0)             // -> "0"