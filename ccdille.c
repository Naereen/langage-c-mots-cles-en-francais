#include "ccdille.h"



int main(int argc, char* argv[]) {
  size_t i = 0;

  FILE *file, *temp;
  char* file_path = NULL;

  char buffer[BUF_SIZE];
  int c;
  int parse_success;
  size_t len;
  char* temp_file_name;
  size_t written;

  int compilation_success;

  if (argc == 1) {
    return 0;
  }

  temp_file_name = calloc(10 * sizeof(char));

  for (i = 1; i < (size_t)argc; ++i) {
    file_path = argv[i];

    /* open the file to parse */
    file = fopen(file_path, "r");
    if (file == NULL) {
      fprintf(stderr, "File %s could not be opened\n", file_path);
      return 1;
    }

    /* set the name of the file to create */
    asprintf(&temp_file_name, "%lu%s", i, ".c");

    /* create the file to write in */
    temp = fopen(temp_file_name, "w");
    if (temp == NULL) {
      fprintf(stderr, "Failed to create a new file.\n");
      return 8;
    }

    /* read words from the file */
    len = 0;
    for (;;) {
      c = fgetc(file);

      if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '(' || c == '*' || c == EOF) {
        parse_success = ccdille_parse_word((char*)buffer, &len);
        if (parse_success || c == EOF) {
          written = fwrite((void*)buffer, sizeof(char), len, temp);
          if (written < len) {
            return 6;
          }

          if (c == EOF) {
            break;
          }

          buffer[0] = (char) c;
          written = fwrite((void*)buffer, sizeof(char), 1, temp);

          if (written < 1) {
            return 7;
          }

          len = 0;
          continue;
        }
      }

      buffer[len] = (char) c;
      ++len;
    }

    /* close the file */
    fclose(file);
  }

  fclose(temp);

  compilation_success = execl("/usr/bin/cc", "cc", "-o", "fr.out", temp_file_name, NULL);

  free(temp_file_name);

  return compilation_success;
}

int ccdille_parse_word(char* word, size_t* len) {
  size_t i;
  enum ccdille_strcmp_result result;
  struct french_keyword keyword;
  for (i = 0; i < sizeof(keywords)/sizeof(*keywords); i++) {
    keyword = keywords[i];
    result = ccdille_strcmp(word, *len, keyword.word, strlen(keyword.word));
    switch (result) {
    case CCDILLE_MATCH:
      *len = strlen(keyword.translation);
      memcpy(word, keyword.translation, *len);
      return 1;
    case CCDILLE_PREFIX:
      return 0;
    case CCDILLE_NO_MATCH:
      break;
    /* mdr ya pas de default */
    }
  }

  return 1;
}

size_t ccdille_min(size_t a, size_t b) {
  return a <= b ? a : b;
}

enum ccdille_strcmp_result ccdille_strcmp(char const* a, size_t len_a, char const* b, size_t len_b) {
  size_t i;
  for (i = 0; i < ccdille_min(len_a, len_b); i++) {
    if (a[i] != b[i]) {
      return CCDILLE_NO_MATCH;
    }
  }
  if (len_a == len_b) {
    return CCDILLE_MATCH;
  }
  if (len_a > len_b || b[i] != ' ') {
    return CCDILLE_NO_MATCH;
  }
  return CCDILLE_PREFIX;
}
