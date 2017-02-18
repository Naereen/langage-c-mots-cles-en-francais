#include "ç.h"

int main(int argc, char* argv[]) {
	size_t i = 0;

	FILE *fichier, *temporaire;
	char* chemin_du_fichier = NULL;
	char const* suffixe = ".c.fr";

	int succes_de_la_traduction;
	char* chemin_de_la_traduction;

	int succes_de_la_compilation;

	if (argc == 1) {
		return 0;
	}

	for (i = 1; i < (size_t)argc; ++i) {
		chemin_du_fichier = argv[i];

		if (strcmp(&chemin_du_fichier[strlen(chemin_du_fichier)-strlen(suffixe)], suffixe) != 0) {
			fprintf(stderr, "Type de fichier non supporté %s\n", chemin_du_fichier);
			return 1;
		}

		/* J4OUVRE */
		fichier = fopen(chemin_du_fichier, "r");
		if (fichier == NULL) {
			fprintf(stderr, "Le fichier %s n'a pas pu etre ouvert\n", chemin_du_fichier);
			return 1;
		}

		/* set the name of the fichier to create */
		chemin_de_la_traduction = malloc(strlen(chemin_du_fichier) * sizeof(char));
		memcpy(chemin_de_la_traduction, chemin_du_fichier, strlen(chemin_du_fichier));
		chemin_de_la_traduction[strlen(chemin_du_fichier)-3] = '\0';

		/* create the fichier to write in */
		temporaire = fopen(chemin_de_la_traduction, "w");
		if (temporaire == NULL) {
			fprintf(stderr, "Failed to create a new fichier.\n");
			return 8;
		}

		/* read words from the fichier */
		succes_de_la_traduction = ccdille_traduire_fichier(fichier, temporaire);
		if (succes_de_la_traduction != 0) {
			return succes_de_la_traduction;
		}

		/* JE FERME */
		fclose(fichier);
		fclose(temporaire);
	}

	succes_de_la_compilation = execl("/usr/bin/cc", "cc", "-o", "a.sortie", chemin_de_la_traduction, NULL);

	free(chemin_de_la_traduction);

	return succes_de_la_compilation;
}

int ccdille_traduire_fichier(FILE* entree, FILE* sortie) {
	char tampon[TAILLE_DU_TAMPON];
	int c;
	int succes_de_la_traduction;
	size_t longueur;
	size_t ecrit;

	longueur = 0;
	for (;;) {
		c = fgetc(entree);

		if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '(' || c == ')' || c == '/' || c == '*' || c == ';' || c == EOF) {
			succes_de_la_traduction = ccdille_traduire_mot((char*)tampon, &longueur);
			if (succes_de_la_traduction || c == EOF) {
				ecrit = fwrite((void*)tampon, sizeof(char), longueur, sortie);
				if (ecrit < longueur) {
					return 6;
				}

				if (c == EOF) {
					break;
				}

				tampon[0] = (char) c;
				ecrit = fwrite((void*)tampon, sizeof(char), 1, sortie);

				if (ecrit < 1) {
					return 7;
				}

				longueur = 0;
				continue;
			}
		}

		tampon[longueur] = (char) c;
		++longueur;
	}

	return 0;
}

int ccdille_traduire_mot(char* mot, size_t* longueur) {
	size_t i;
	enum ccdille_comparaison_de_chaine_de_caractere_resultat resultat;
	struct mot_cle_francais_t mot_cle_francais;
	for (i = 0; i < sizeof(mot_cles_francais)/sizeof(*mot_cles_francais); i++) {
		mot_cle_francais = mot_cles_francais[i];
		resultat = ccdille_comparaison_de_chaine_de_caractere(mot, *longueur, mot_cle_francais.mot, strlen(mot_cle_francais.mot));
		switch (resultat) {
		case CCDILLE_CORRESPONDANCE:
			*longueur = strlen(mot_cle_francais.traduction);
			memcpy(mot, mot_cle_francais.traduction, *longueur);
			return 1;
		case CCDILLE_PREFIXE:
			return 0;
		case CCDILLE_PAS_DE_CORRESPONDANCE:
			break;
		/* mdr ya pas de default */
		}
	}

	return 1;
}

size_t ccdille_min(size_t a, size_t b) {
	return a <= b ? a : b;
}

enum ccdille_comparaison_de_chaine_de_caractere_resultat ccdille_comparaison_de_chaine_de_caractere(char const* a, size_t taille_de_a, char const* b, size_t taille_de_b) {
	size_t i;
	for (i = 0; i < ccdille_min(taille_de_a, taille_de_b); i++) {
		if (a[i] != b[i]) {
			return CCDILLE_PAS_DE_CORRESPONDANCE;
		}
	}
	if (taille_de_a == taille_de_b) {
		return CCDILLE_CORRESPONDANCE;
	}
	if (taille_de_a > taille_de_b || b[i] != ' ') {
		return CCDILLE_PAS_DE_CORRESPONDANCE;
	}
	return CCDILLE_PREFIXE;
}
