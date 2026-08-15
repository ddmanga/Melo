# union

Fichiers à rendre : `union.c`
Autorisé : `write`

Écrivez un programme qui prend deux chaînes de caractères en paramètre et
affiche, sans doublon et dans leur ordre d'apparition, tous les
caractères différents présents dans au moins une des deux chaînes. Chaque
caractère sera immédiatement suivi d'un `\n`.

Si le nombre de paramètres n'est pas égal à 2, le programme affiche
simplement `\n`.

Exemple :

    $> ./union abcde 6azert | cat -e
    a$
    b$
    c$
    d$
    e$
    6$
    z$
    r$
    t$