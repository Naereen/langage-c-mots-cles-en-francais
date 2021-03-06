/* Ce fichier a été généré par ç, ne pas l'éditer */

#include "ç.h"

int main(int argc, char* argv[]) {
	size_t i = 0;

	FILE *fichier_d_entree, *fichier_de_la_traduction;
	char *action, *argument;
	char *chemin_d_entree, *chemin_de_la_sortie;
	int position_de_l_extension;
	char *extension, *langage, *langage_d_entree;

	int succes_de_la_traduction, ecrit;
	char *chemin_de_la_traduction;
	struct mot_cle_francais *mot_cles;
	size_t mot_cles_taille;
	enum ccdille_sens sens;
	char *debut_commentaire, *fin_commentaire;

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
	langage = NULL;
	sens = CCDILLE_A_L_ENDROIT;

	for (i = 2; i < (size_t)argc; ++i) {
		argument = argv[i];

		if (argument[0] == '-' && strlen(argument) > 1) {
			if (strcmp(argument, "-o") == 0) {
				i++;
				chemin_de_la_sortie = argv[i];
			} else if (strcmp(argument, "-l") == 0) {
				i++;
				langage = argv[i];
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
		langage_d_entree = langage;

		/* J4OUVRE */
		if (strcmp(chemin_d_entree, "-") == 0) {
			fichier_d_entree = stdin;
			if (langage_d_entree == NULL) {
				fprintf(stderr, "Langage d'entrée non spécifié, C est utilisé par défaut\n");
				langage_d_entree = "c";
			}
		} else {
			if (sens == CCDILLE_A_L_ENDROIT && strcmp(&chemin_d_entree[strlen(chemin_d_entree)-strlen(EXTENSION_DE_FICHIER)], EXTENSION_DE_FICHIER) != 0) {
				fprintf(stderr, "Type de fichier non supporté %s (un fichier de type %s était attendu)\n", chemin_d_entree, EXTENSION_DE_FICHIER);
				return 1;
			}

			/* définir le nom du fichier traduit qui sera produit */
			free(chemin_de_la_traduction);
			chemin_de_la_traduction = malloc((strlen(chemin_d_entree) + strlen(EXTENSION_DE_FICHIER) + 1) * sizeof(char));
			memcpy(chemin_de_la_traduction, chemin_d_entree, strlen(chemin_d_entree) + 1);
			if (sens == CCDILLE_A_L_ENDROIT) {
				chemin_de_la_traduction[strlen(chemin_de_la_traduction)-strlen(EXTENSION_DE_FICHIER)] = '\0';
			} else {
				strcat(chemin_de_la_traduction, EXTENSION_DE_FICHIER);
			}

			/* déterminer l'extension du fichier source */
			extension = "";
			if (sens == CCDILLE_A_L_ENDROIT) {
				position_de_l_extension = ccdille_dernier_index_de(chemin_de_la_traduction, '.');
				if (position_de_l_extension >= 0) {
					extension = &chemin_de_la_traduction[position_de_l_extension+1];
				}
			} else {
				position_de_l_extension = ccdille_dernier_index_de(chemin_d_entree, '.');
				if (position_de_l_extension >= 0) {
					extension = &chemin_d_entree[position_de_l_extension+1];
				}
			}
			/* auto-détection du langage d'entrée en fonction de l'extension du fichier */
			if (langage_d_entree == NULL) {
				if (strcmp(extension, "c") == 0 || strcmp(extension, "h") == 0) {
					langage_d_entree = "c";
				} else if (strcmp(extension, "ml") == 0 || strcmp(extension, "mli") == 0) {
					langage_d_entree = "ml";
				} else if (strcmp(extension, "rs") == 0) {
					langage_d_entree = "rs";
				} else {
					fprintf(stderr, "Extension %s non supportée\n", extension);
					return 1;
				}
			}

			fichier_d_entree = fopen(chemin_d_entree, "r");
			if (fichier_d_entree == NULL) {
				fprintf(stderr, "Le fichier %s n'a pas pu être ouvert\n", chemin_d_entree);
				return 1;
			}
		}

		/* seuls C et OCaml sont supportés for le moment */
		if (strcmp(langage_d_entree, "c") == 0) {
			mot_cles = mot_cles_c;
			mot_cles_taille = sizeof(mot_cles_c)/sizeof(*mot_cles_c);
			debut_commentaire = (char*) DEBUT_COMMENTAIRE_C;
			fin_commentaire = (char*) FIN_COMMENTAIRE_C;
		} else if (strcmp(langage_d_entree, "ml") == 0) {
			mot_cles = mot_cles_ml;
			mot_cles_taille = sizeof(mot_cles_ml)/sizeof(*mot_cles_ml);
			debut_commentaire = (char*) DEBUT_COMMENTAIRE_ML;
			fin_commentaire = (char*) FIN_COMMENTAIRE_ML;
		} else if (strcmp(langage_d_entree, "rs") == 0) {
			mot_cles = mot_cles_rs;
			mot_cles_taille = sizeof(mot_cles_rs)/sizeof(*mot_cles_rs);
			debut_commentaire = (char*) DEBUT_COMMENTAIRE_RS;
			fin_commentaire = (char*) FIN_COMMENTAIRE_RS;
		} else {
			fprintf(stderr, "Langage %s non supporté\n", langage_d_entree);
			return 1;
		}

		/* if on traduit sans compiler, écrire la traduction dans le fichier de sortie, if spécifié */
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

		/* écrire l'en-tête de traduction if nécessaire */
		if (sens == CCDILLE_A_L_ENDROIT) {
			ecrit = fprintf(fichier_de_la_traduction, "%s%s%s\n\n", debut_commentaire, EN_TETE_DE_TRADUCTION, fin_commentaire);
			if (ecrit < 0) {
				return 9;
			}
		}

		/* read words from the fichier */
		succes_de_la_traduction = ccdille_traduire_fichier(fichier_d_entree, fichier_de_la_traduction, mot_cles, mot_cles_taille, sens);
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
		if (strcmp(langage_d_entree, "c") == 0) {
			succes_de_la_compilation = execl("/usr/bin/cc", "cc", "-o", chemin_de_la_sortie, chemin_de_la_traduction, NULL);
		} else if (strcmp(langage_d_entree, "ml") == 0) {
			succes_de_la_compilation = execl("/usr/bin/ocamlc", "ocamlc", "-o", chemin_de_la_sortie, chemin_de_la_traduction, NULL);
		} else {
			fprintf(stderr, "Langage %s non supporté à la compilation\n", langage_d_entree);
			succes_de_la_compilation = 1;
		}
	}
	free(chemin_de_la_traduction);

	return succes_de_la_compilation;
}

int ccdille_utilisation() {
	fprintf(stderr, "Utilisation : ç traduire|construire [-1] [-l langage] [-o a.sortie] [entrée...]\n");
	return 1;
}

int ccdille_traduire_fichier(FILE* entree, FILE* sortie, struct mot_cle_francais *mot_cles, size_t mot_cles_taille, enum ccdille_sens sens) {
	char tampon[TAILLE_DU_TAMPON];
	int c;
	int succes_de_la_traduction;
	size_t longueur;
	size_t ecrit;

	longueur = 0;
	for (;;) {
		c = fgetc(entree);

		if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '(' || c == ')' || c == '/' || c == '*' || c == ';' || c == '|' || c == '&' || c == '*' || c == '!' || c == '=' || c == ':' || c == EOF) {
			succes_de_la_traduction = ccdille_traduire_mot(mot_cles, mot_cles_taille, (char*)tampon, &longueur, sens);
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

int ccdille_traduire_mot(struct mot_cle_francais *mot_cles, size_t mot_cles_taille, char* mot_a_traduire, size_t* longueur, enum ccdille_sens sens) {
	size_t i;
	enum ccdille_comparaison_de_chaine_de_caractere_resultat resultat;
	struct mot_cle_francais mot_cle;
	char *mot, *traduction;

	for (i = 0; i < mot_cles_taille; i++) {
		mot_cle = mot_cles[i];
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

int ccdille_dernier_index_de(char* mot, char c) {
	int i = strlen(mot) - 1;
	while (i >= 0) {
		if (mot[i] == c) {
			return i;
		}
		i--;
	}
	return -1;
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
