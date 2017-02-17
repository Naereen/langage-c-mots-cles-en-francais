#ifndef CCDILLE_H
#define CCDILLE_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024

enum ccdille_strcmp_result {
  CCDILLE_NO_MATCH,
  CCDILLE_MATCH,
  CCDILLE_PREFIX
};

struct french_keyword {
  char* word;
  char* translation;
};

int ccdille_parse_word(char* word, size_t* len);
size_t ccdille_min(size_t a, size_t b);
enum ccdille_strcmp_result ccdille_strcmp(char const* a, size_t len_a, char const* b, size_t len_b);

struct french_keyword keywords[] = {
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
