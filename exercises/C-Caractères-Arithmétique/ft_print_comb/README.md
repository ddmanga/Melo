# ft_print_comb

Répertoire (piscine) : ex1/
Fichiers à rendre : ft_print_comb.c
Fonctions autorisées : write

Écrire une fonction qui affiche toutes les combinaisons possibles de trois
chiffres différents, dans l'ordre croissant à l'intérieur de chaque
combinaison, elles-mêmes listées par ordre croissant.

Prototype :
void ft_print_comb(void);

Exemple (avec cat -e pour voir la fin de ligne) :
./a.out | cat -e
012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789$

- 987 n'apparaît pas car les chiffres doivent être croissants dans la
  combinaison (789 a déjà été affiché, sous cette forme uniquement).
- 999 n'apparaît pas car un chiffre ne peut pas être utilisé plus d'une fois
  dans la même combinaison.

## Points clés du format

- Chaque combinaison est 3 chiffres collés, sans séparateur interne
  ("012", pas "0-1-2" ni "0 1 2").
- Les chiffres d'une combinaison sont toujours strictement croissants
  (a < b < c) : jamais de chiffre répété, jamais dans le désordre.
- Les combinaisons sont séparées par ", " (virgule + espace).
- Après la toute dernière combinaison ("789"), pas de virgule ni d'espace,
  seulement un retour à la ligne final.
- Il y a exactement 120 combinaisons possibles (choisir 3 chiffres distincts
  parmi 0 à 9, sans tenir compte de l'ordre puisqu'il est imposé croissant).

## Piège principal

C'est une triple boucle imbriquée : le premier chiffre va de 0 à 7, le
second de (premier + 1) à 8, le troisième de (second + 1) à 9 — ces bornes
garantissent qu'il reste toujours assez de chiffres plus grands pour
compléter la combinaison. Comme pour ft_print_comb2, l'erreur classique est
une virgule mal placée en tout début ou toute fin de la sortie.