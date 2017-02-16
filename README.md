# ccdille

Une version sava de frenchsyntaxe.h.

C'est un précompilateur qui traduit le code en français vers du code en C.

Coréalisé par DiestVanMaitre_culain et Emersion.

# Exemples d'utilisation
## Compilation
Pour compiler vos programmes, utiliser la commande suivante
```shell
ç mon_programme.c.fr 
```
## L'Algorithme D'Euclide

```c
#inclure <entrées et sorties standard.en-tête>

non signé entier algorithme_d_euclide(non signé entier a, non signé entier b) {
  si (a < b) {
    retourner algorithme_d_euclide(b, a);
  }
  retourner b == 0 ? a : algorithme_d_euclide(b, a%b);
}

entier principale(entier argc, caractère constant **argv) {
  non signé entier a = 8;
  non signé entier b = 12;
  non signé entier resultat = algorithme_d_euclide(a, b);
  printf("%u\n", resultat);

  retourner 0;
}

```




