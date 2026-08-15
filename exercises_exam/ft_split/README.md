# ft_split

Répertoire : `ex_final/`
Fichiers à rendre : `ft_split.c`
Autorisé : `malloc`, `free`

Écrivez une fonction qui découpe une chaîne de caractères en un tableau de
mots, séparés par un caractère séparateur donné. Les séparateurs
consécutifs, en début ou en fin de chaîne, ne doivent pas produire de mots
vides.

Le tableau retourné doit être terminé par un pointeur `NULL` (comme
`argv`), et chaque mot ainsi que le tableau lui-même doivent être alloués
avec `malloc` (donc libérables avec `free`).

Prototype : `char **ft_split(char *str, char sep);`

Exemple :

    ft_split("bonjour   le monde", ' ')
    // -> {"bonjour", "le", "monde", NULL}

    ft_split("  a,,b  ", ',')
    // avec sep=',' -> {"  a", "b  ", NULL}