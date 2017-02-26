# ccdille

Une version sava de frenchsyntaxe.h.

C'est un précompilateur qui traduit le code en français vers du code en C.

Coréalisé par DiestVanMaitre_culain et Emersion.

# Exemples d'utilisation

## Compilation

Pour compiler vos programmes, utiliser la commande suivante :
```shell
ç construire mon_programme.c.fr
```

## L'Algorithme D'Euclide

```c
#inclure <entrées et sorties standard.en-tête>

entier non signé algorithme_d_euclide(entier non signé a, entier non signé b) {
  si (a < b) {
    retourner algorithme_d_euclide(b, a);
  }
  retourner b == 0 ? a : algorithme_d_euclide(b, a%b);
}

entier principale(entier argc, caractère constant **argv) {
  entier non signé a = 8;
  entier non signé b = 12;
  entier non signé resultat = algorithme_d_euclide(a, b);
  printf("%u\n", resultat);

  retourner 0;
}
```
