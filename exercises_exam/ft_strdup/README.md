# ft_strdup

Fichiers à rendre : `ft_strdup.c`
Autorisé : `malloc`

Réimplémentez `strdup` : la fonction doit allouer (avec `malloc`) et
retourner une copie de la chaîne passée en paramètre.

Prototype : `char *ft_strdup(const char *src);`

Points d'attention :
- Ne pas oublier le `\0` final dans l'allocation.
- Gérer le cas d'une chaîne vide.
- Le buffer retourné doit être `free`-able normalement par l'appelant.