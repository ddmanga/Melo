# intersection

Fichiers à rendre : `inter.c`
Autorisé : `write`

Écrivez un programme qui prend deux chaînes de caractères en paramètre et
affiche, sans doublon et dans leur ordre d'apparition dans la première
chaîne, tous les caractères présents dans les deux chaînes à la fois.
Chaque caractère sera immédiatement suivi d'un `\n`.

Si le nombre de paramètres n'est pas égal à 2, le programme affiche
simplement `\n`.

Exemple :

    $> ./inter abcde aeiouy | cat -e
    a$
    e$