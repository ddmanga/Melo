# ft_strcmp

Fichiers à rendre : `ft_strcmp.c`
Autorisé : aucune fonction externe (pas de string.h)

Réimplémentez la fonction `strcmp` : elle compare deux chaînes de
caractères.

La fonction doit retourner :
- `0` si les deux chaînes sont identiques,
- une valeur négative si `s1` est "plus petite" que `s2` (le premier
  caractère différent a un code ASCII inférieur dans `s1`),
- une valeur positive si `s1` est "plus grande" que `s2`.

Prototype : `int ft_strcmp(char *s1, char *s2);`

Exemple :

    ft_strcmp("abc", "abc")   // -> 0
    ft_strcmp("abc", "abd")   // -> negatif
    ft_strcmp("abd", "abc")   // -> positif