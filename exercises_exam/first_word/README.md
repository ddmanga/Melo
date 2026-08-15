# first_word

Fichiers à rendre : `first_word.c`
Autorisé : `write`

Écrivez un programme qui prend une chaîne de caractères en paramètre et
affiche son premier mot, suivi d'un retour à la ligne.

Un mot est une portion de chaîne délimitée par des espaces/tabulations,
ou par le début/la fin de la chaîne.

Si le nombre de paramètres n'est pas égal à 1, ou s'il n'y a aucun mot,
affichez simplement un retour à la ligne.

Exemples :

    $> ./first_word "FOR PONY" | cat -e
    FOR$
    $> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
    this$
    $> ./first_word "   " | cat -e
    $
    $> ./first_word "a" "b" | cat -e
    $
    $> ./first_word "  lorem,ipsum  " | cat -e
    lorem,ipsum$