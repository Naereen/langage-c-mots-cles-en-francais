# ç

Une version sava de frenchsyntaxe.h.

C'est un précompilateur qui traduit le code en français vers du code en C.

Coréalisé par DiestVanMaitre_culain et Emersion.

## Installation

Comme `ç` utilise lui-même `ç` pour se compiler, il faut construire `ç` à partir
des sources C, et non des sources C.fr :

```shell
make bootstrap
```

Une fois `ç` compilé, on pourra le modifier et le recompiler à partir des
sources C.fr :
```shell
make
```

Pour produire une version de déboggage `ç.debug` :
```shell
make debug
```

## Exemples d'utilisation

### Compilation

Pour compiler vos programmes, utiliser la commande suivante :
```shell
ç construire mon_programme.c.fr
```

### L'Algorithme D'Euclide

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
