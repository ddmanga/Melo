# ft_print_comb2

Répertoire (piscine) : ex2/
Fichiers à rendre : ft_print_comb2.c
Fonctions autorisées : write

Écrire une fonction qui affiche toutes les combinaisons possibles de deux
nombres à deux chiffres (XX XX) entre 00 et 99, listées par ordre croissant.

Prototype :
void ft_print_comb2(void);

Exemple (avec cat -e pour voir la fin de ligne) :
./a.out | cat -e
00 01, 00 02, 00 03, ..., 00 99, 01 02, ..., 97 99, 98 99$

## Points clés du format

- Chaque nombre est toujours affiché sur 2 chiffres (zero-padding) :
  "00", "01", ..., "09", "10", etc.
- Le premier nombre est toujours strictement inférieur au second
  (jamais "05 03", jamais "42 42").
- Les paires sont séparées par ", " (virgule + espace).
- Après la toute dernière paire ("98 99"), il n'y a ni virgule ni espace,
  seulement un retour à la ligne final.
- Tout est affiché sur une seule ligne (pas de saut de ligne entre les paires,
  uniquement à la toute fin).

## Piège principal

C'est une double boucle : le premier nombre va de 00 à 98, et pour chaque
premier nombre, le second va de (premier + 1) à 99. Une erreur classique est
de mal gérer la virgule finale (en ajouter une après la toute dernière paire,
ou en oublier une entre deux paires).