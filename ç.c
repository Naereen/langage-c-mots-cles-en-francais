#include "ç.h"

int main(int argc, char* argv[]) {
	size_t i = 0;

	FILE *fichier_d_entree, *fichier_de_la_traduction;
	char *action, *argument;
	char *chemin_d_entree, *chemin_de_la_sortie;

	int succes_de_la_traduction;
	char *chemin_de_la_traduction;
	enum ccdille_sens sens = CCDILLE_A_L_ENDROIT;

	int succes_de_la_compilation;

	if (argc == 1) {
		return ccdille_utilisation();
	}

	action = argv[1];
	if (strcmp(action, "traduire") != 0 && strcmp(action, "construire") != 0) {
		return ccdille_utilisation();
	}

	chemin_de_la_traduction = NULL;
	chemin_de_la_sortie = NULL;

	for (i = 2; i < (size_t)argc; ++i) {
		argument = argv[i];

		if (argument[0] == '-' && strlen(argument) > 1) {
			if (strcmp(argument, "-o") == 0) {
				i++;
				chemin_de_la_sortie = argv[i];
			} else if (strcmp(argument, "-1") == 0) {
				if (strcmp(action, "traduire") != 0) {
					fprintf(stderr, "Impossible d'utiliser l'option -1 sans l'action traduire\n");
					return 1;
				}
				sens = CCDILLE_A_L_ENVERS;
			} else {
				fprintf(stderr, "Option non reconnue: %s\n", argument);
				return 1;
			}
			continue;
		}
		chemin_d_entree = argument;

		/* J4OUVRE */
		if (strcmp(chemin_d_entree, "-") == 0) {
			fichier_d_entree = stdin;
		} else {
			if (sens == CCDILLE_A_L_ENDROIT && strcmp(&chemin_d_entree[strlen(chemin_d_entree)-strlen(EXTENSION_DE_FICHIER)], EXTENSION_DE_FICHIER) != 0) {
				fprintf(stderr, "Type de fichier non supporté %s\n", chemin_d_entree);
				return 1;
			}

			/* définir le nom du fichier traduit qui sera produit */
			free(chemin_de_la_traduction);
			chemin_de_la_traduction = malloc((strlen(chemin_d_entree) + strlen(EXTENSION_DE_FICHIER) + 1) * sizeof(char));
			memcpy(chemin_de_la_traduction, chemin_d_entree, strlen(chemin_d_entree) + 1);
			if (sens == CCDILLE_A_L_ENDROIT) {
				chemin_de_la_traduction[strlen(chemin_d_entree)-3] = '\0';
			} else {
				strcat(chemin_de_la_traduction, EXTENSION_DE_FICHIER);
			}

			fichier_d_entree = fopen(chemin_d_entree, "r");
			if (fichier_d_entree == NULL) {
				fprintf(stderr, "Le fichier %s n'a pas pu être ouvert\n", chemin_d_entree);
				return 1;
			}
		}

		if (strcmp(action, "traduire") == 0 && chemin_de_la_sortie != NULL) {
			free(chemin_de_la_traduction);
			chemin_de_la_traduction = malloc((strlen(chemin_de_la_sortie) + 1) * sizeof(char));
			memcpy(chemin_de_la_traduction, chemin_de_la_sortie, strlen(chemin_de_la_sortie) + 1);
		}

		/* ouvrir le fichier où la traduction sera écrite */
		if (chemin_de_la_traduction == NULL || strcmp(chemin_de_la_traduction, "-") == 0) {
			fichier_de_la_traduction = stdout;
		} else {
			fichier_de_la_traduction = fopen(chemin_de_la_traduction, "w");
			if (fichier_de_la_traduction == NULL) {
				fprintf(stderr, "Failed to create a new fichier.\n");
				return 8;
			}
		}

		/* read words from the fichier */
		succes_de_la_traduction = ccdille_traduire_fichier(fichier_d_entree, fichier_de_la_traduction, sens);
		if (succes_de_la_traduction != 0) {
			return succes_de_la_traduction;
		}

		/* JE FERME */
		fclose(fichier_d_entree);
		fclose(fichier_de_la_traduction);
	}

	succes_de_la_compilation = 0;
	if (strcmp(action, "construire") == 0) {
		if (chemin_de_la_sortie == NULL) {
			chemin_de_la_sortie = "a.sortie";
		}
		succes_de_la_compilation = execl("/usr/bin/cc", "cc", "-o", chemin_de_la_sortie, chemin_de_la_traduction, NULL);
	}
	free(chemin_de_la_traduction);

	return succes_de_la_compilation;
}

int ccdille_utilisation() {
	printf("Utilisation : ç traduire|construire [-1] [-o sortie.out] [entrée...]\n");
	return 1;
}

int ccdille_traduire_fichier(FILE* entree, FILE* sortie, enum ccdille_sens sens) {
	char tampon[TAILLE_DU_TAMPON];
	int c;
	int succes_de_la_traduction;
	size_t longueur;
	size_t ecrit;

	longueur = 0;
	for (;;) {
		c = fgetc(entree);

		if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '(' || c == ')' || c == '/' || c == '*' || c == ';' || c == '|' || c == '&' || c == '*' || c == '!' || c == '=' || c == ':' || c == EOF) {
			succes_de_la_traduction = ccdille_traduire_mot((char*)tampon, &longueur, sens);
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

int ccdille_traduire_mot(char* mot_a_traduire, size_t* longueur, enum ccdille_sens sens) {
	size_t i;
	enum ccdille_comparaison_de_chaine_de_caractere_resultat resultat;
	struct mot_cle_francais mot_cle;
	char *mot, *traduction;

	for (i = 0; i < sizeof(mot_cles_c)/sizeof(*mot_cles_c); i++) {
		mot_cle = mot_cles_c[i];
		if (sens == CCDILLE_A_L_ENDROIT) {
			mot = mot_cle.mot;
			traduction = mot_cle.traduction;
		} else {
			mot = mot_cle.traduction;
			traduction = mot_cle.mot;
		}

		resultat = ccdille_comparaison_de_chaine_de_caractere(mot_a_traduire, *longueur, mot, strlen(mot));
		switch (resultat) {
		case CCDILLE_CORRESPONDANCE:
			*longueur = strlen(traduction);
			memcpy(mot_a_traduire, traduction, *longueur);
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
