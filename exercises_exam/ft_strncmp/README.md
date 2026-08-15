# ft_strncmp

Fichiers à rendre : `ft_strncmp.c`
Autorisé : aucune fonction externe (pas de string.h)

Réimplémentez la fonction `strncmp` : elle compare les `n` premiers
caractères de deux chaînes de caractères.

La fonction doit retourner :
- `0` si les `n` premiers caractères sont identiques,
- une valeur négative si `s1` est "plus petite" que `s2` sur ces `n`
  caractères,
- une valeur positive si `s1` est "plus grande" que `s2` sur ces `n`
  caractères.

Prototype : `int ft_strncmp(char *s1, char *s2, unsigned int n);`

Exemple :

    ft_strncmp("abc", "abd", 2)   // -> 0 (les 2 premiers caracteres sont identiques)
    ft_strncmp("abc", "abd", 3)   // -> negatif