#ifndef CCDILLE_H
#define CCDILLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TAILLE_DU_TAMPON 1024
#define EXTENSION_DE_FICHIER ".fr"

enum ccdille_comparaison_de_chaine_de_caractere_resultat {
  CCDILLE_PAS_DE_CORRESPONDANCE,
  CCDILLE_CORRESPONDANCE,
  CCDILLE_PREFIXE
};

enum ccdille_sens {
  CCDILLE_A_L_ENDROIT,
  CCDILLE_A_L_ENVERS
};

struct mot_cle_francais_t {
  char *mot;
  char *traduction;
};

int ccdille_utilisation();
int ccdille_traduire_fichier(FILE* entree, FILE* sortie, enum ccdille_sens sens);
int ccdille_traduire_mot(char* mot_a_traduire, size_t* longueur, enum ccdille_sens sens);
size_t ccdille_minimum(size_t a, size_t b);
enum ccdille_comparaison_de_chaine_de_caractere_resultat ccdille_comparaison_de_chaine_de_caractere(char const *a, size_t longueur_de_a, char const *b, size_t longueur_de_b);

struct mot_cle_francais_t mot_cles_francais[] = {
  {"#définir", "#define"},
  {"#retirer la définition", "#undef"},
  {"#inclure", "#include"},
  {"#si défini", "#ifdef"},
  {"#si non défini", "#ifndef"},
  {"#si", "#if"},
  {"#sinon", "#else"},
  {"#sinon si", "#elif"},
  {"#fin si", "#endif"},
  {"#pragmatique", "#pragma"},
  {"#erreur", "#error"},

  {"automatique", "auto"},
  {"casser", "break"},
  {"cas", "case"},
  {"caractère", "char"},
  {"constant", "const"},
  {"constante", "const"},
  {"continuer", "continue"},
  {"par défaut", "default"},
  {"faire", "do"},
  {"double", "double"},
  {"sinon", "else"},
  {"énumération", "enum"},
  {"externe", "extern"},
  {"flottant", "float"},
  {"pour", "for"},
  {"aller à", "goto"},
  {"si", "if"},
  {"entier", "int"},
  {"long", "long"},
  {"mettre en registre", "register"},
  {"retourner", "return"},
  {"court", "short"},
  {"signé", "signed"},
  {"taille de", "sizeof"},
  {"statique", "static"},
  {"structure", "struct"},
  {"commuter", "switch"},
  {"définir un type", "typedef"},
  {"union", "union"},
  {"non signé", "unsigned"},
  {"vide", "void"},
  {"volatile", "volatile"},
  {"tant que", "while"},

  {"taille_t", "size_t"},
  {"FICHIER", "FILE"},
  {"NUL", "NULL"},

  {"<assertion.en-tête>", "<assert.h>"},
  {"<complexe.en-tête>", "<complex.h>"},
  {"<types du langage c.en-tête>", "<ctype.h>"},
  {"<numéro d'erreur.en-tête>", "<errno.h>"},
  {"<environnement en virgule flottante.en-tête>", "<fenv.h>"},
  {"<flottant.en-tête>", "<float.h>"},
  {"<types entiers.en-tête>", "<inttypes.h>"},
  {"<organisation internationnale de normalisation 646.en-tête>", "<iso646.h>"},
  {"<limites.en-tête>", "<limits.h>"},
  {"<lieu.en-tête>", "<locale.h>"},
  {"<mathématiques.en-tête>", "<math.h>"},
  {"<initialiser les sauts.en-tête>", "<setjmp.h>"},
  {"<signal.en-tête>", "<signal.h>"},
  {"<arguments standard.en-tête>", "<stdarg.h>"},
  {"<booléens standard.en-tête>", "<stdbool.h>"},
  {"<définitions standard.en-tête>", "<stddef.h>"},
  {"<entiers standard.en-tête>", "<stdint.h>"},
  {"<entrées et sorties standard.en-tête>", "<stdio.h>"},
  {"<bibliothèque standard.en-tête>", "<stdlib.h>"},
  {"<chaîne de caractères.en-tête>", "<string.h>"},
  {"<opérations mathématiques sur des types génériques.en-tête>", "<tgmath.h>"},
  {"<processus.en-tête>", "<threads.h>"},
  {"<temps.en-tête>", "<time.h>"},
  {"<caractères larges.en-tête>", "<wchar.h>"},
  {"<types des caractères larges.en-tête>", "<wctypes.h>"},

  {"principale", "main"},
  {"pricipal", "main"}
};

#endif
