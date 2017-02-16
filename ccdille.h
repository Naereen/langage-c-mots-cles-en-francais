#ifndef CCDILLE_H
#define CCDILLE_H

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

#endif
