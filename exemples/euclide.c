/* Ce fichier a été généré par ç, ne pas l'éditer */

#include <stdio.h>

int unsigned algorithme_d_euclide(int unsigned a, int unsigned b) {
  if (a < b) {
    return algorithme_d_euclide(b, a);
  }
  return b == 0 ? a : algorithme_d_euclide(b, a%b);
}

int main(int argc, char const **argv) {
  int unsigned a = 8;
  int unsigned b = 12;
  int unsigned resultat = algorithme_d_euclide(a, b);
  printf("%u\n", resultat);

  return 0;
}
