# ft_strcpy

Fichiers à rendre : `ft_strcpy.c`
Autorisé : aucune fonction externe (pas de string.h)

Réimplémentez la fonction `strcpy` : elle copie la chaîne de caractères
`src` (avec son `\0` final) dans `dest`.

La fonction doit retourner l'adresse de `dest`.

Attention : contrairement à `ft_strdup`, `ft_strcpy` n'alloue **aucune**
mémoire — `dest` doit déjà être un espace mémoire suffisamment grand,
fourni par l'appelant.

Prototype : `char *ft_strcpy(char *dest, char *src);`

Exemple :

    char buf[20];
    ft_strcpy(buf, "hello");
    // buf vaut maintenant "hello"