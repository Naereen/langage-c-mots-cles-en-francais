/* Ce fichier a été généré par ç, ne pas l'éditer */

#ifndef CCDILLE_H
#define CCDILLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TAILLE_DU_TAMPON 1024
#define EXTENSION_DE_FICHIER ".fr"
#define EN_TETE_DE_TRADUCTION "Ce fichier a été généré par ç, ne pas l'éditer"

enum ccdille_comparaison_de_chaine_de_caractere_resultat {
  CCDILLE_PAS_DE_CORRESPONDANCE,
  CCDILLE_CORRESPONDANCE,
  CCDILLE_PREFIXE
};

enum ccdille_sens {
  CCDILLE_A_L_ENDROIT,
  CCDILLE_A_L_ENVERS
};

struct mot_cle_francais {
  char *mot;
  char *traduction;
};

int ccdille_utilisation();
int ccdille_traduire_fichier(FILE* entree, FILE* sortie, struct mot_cle_francais *mot_cles, size_t mot_cles_taille, enum ccdille_sens sens);
int ccdille_traduire_mot(struct mot_cle_francais *mot_cles, size_t mot_cles_taille, char* mot_a_traduire, size_t* longueur, enum ccdille_sens sens);
size_t ccdille_minimum(size_t a, size_t b);
int ccdille_dernier_index_de(char* mot, char c);
enum ccdille_comparaison_de_chaine_de_caractere_resultat ccdille_comparaison_de_chaine_de_caractere(char const *a, size_t longueur_de_a, char const *b, size_t longueur_de_b);

/* Langage C */
#define DEBUT_COMMENTAIRE_C "/* "
#define FIN_COMMENTAIRE_C " */"
struct mot_cle_francais mot_cles_c[] = {
  /* Directives préprocesseur */
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

  /* Mot-clefs du langage */
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
  {"ent8_t", "int8_t"},
  {"ent16_t", "int16_t"},
  {"ent32_t", "int32_t"},
  {"ent64_t", "int64_t"},
  {"pent8_t", "uint8_t"},
  {"pent16_t", "uint16_t"},
  {"pent32_t", "uint32_t"},
  {"pent64_t", "uint64_t"},
  {"ent_aumoins8_t", "int_least8_t"},
  {"ent_aumoins16_t", "int_least16_t"},
  {"ent_aumoins32_t", "int_least32_t"},
  {"ent_aumoins64_t", "int_least64_t"},
  {"pent_aumoins8_t", "uint_least8_t"},
  {"pent_aumoins16_t", "uint_least16_t"},
  {"pent_aumoins32_t", "uint_least32_t"},
  {"pent_aumoins64_t", "uint_least64_t"},
  {"ent_rapide8_t", "int_fast8_t"},
  {"ent_rapide16_t", "int_fast16_t"},
  {"ent_rapide32_t", "int_fast32_t"},
  {"ent_rapide64_t", "int_fast64_t"},
  {"pent_rapide8_t", "uint_fast8_t"},
  {"pent_rapide16_t", "uint_fast16_t"},
  {"pent_rapide32_t", "uint_fast32_t"},
  {"pent_rapide64_t", "uint_fast64_t"},
  {"entptr_t", "intptr_t"},
  {"pentptr_t", "uintptr_t"},
  {"entmax_t", "intmax_t"},
  {"pentmax_t", "uintmax_t"},
  {"ENT8_MIN", "INT8_MIN"},
  {"ENT16_MIN", "INT16_MIN"},
  {"ENT32_MIN", "INT32_MIN"},
  {"ENT64_MIN", "INT64_MIN"},
  {"ENT8_MAX", "INT8_MAX"},
  {"ENT16_MAX", "INT16_MAX"},
  {"ENT32_MAX", "INT32_MAX"},
  {"ENT64_MAX", "INT64_MAX"},
  {"PENT8_MAX", "UINT8_MAX"},
  {"PENT16_MAX", "UINT16_MAX"},
  {"PENT32_MAX", "UINT32_MAX"},
  {"PENT64_MAX", "UINT64_MAX"},
  {"ENT_AUMOINS8_MIN", "INT_LEAST8_MIN"},
  {"ENT_AUMOINS16_MIN", "INT_LEAST16_MIN"},
  {"ENT_AUMOINS32_MIN", "INT_LEAST32_MIN"},
  {"ENT_AUMOINS64_MIN", "INT_LEAST64_MIN"},
  {"ENT_AUMOINS8_MAX", "INT_LEAST8_MAX"},
  {"ENT_AUMOINS16_MAX", "INT_LEAST16_MAX"},
  {"ENT_AUMOINS32_MAX", "INT_LEAST32_MAX"},
  {"ENT_AUMOINS64_MAX", "INT_LEAST64_MAX"},
  {"PENT_AUMOINS8_MAX", "UINT_LEAST8_MAX"},
  {"PENT_AUMOINS16_MAX", "UINT_LEAST16_MAX"},
  {"PENT_AUMOINS32_MAX", "UINT_LEAST32_MAX"},
  {"PENT_AUMOINS64_MAX", "UINT_LEAST64_MAX"},
  {"ENT_RAPIDE8_MIN", "INT_FAST8_MIN"},
  {"ENT_RAPIDE16_MIN", "INT_FAST16_MIN"},
  {"ENT_RAPIDE32_MIN", "INT_FAST32_MIN"},
  {"ENT_RAPIDE64_MIN", "INT_FAST64_MIN"},
  {"ENT_RAPIDE8_MAX", "INT_FAST8_MAX"},
  {"ENT_RAPIDE16_MAX", "INT_FAST16_MAX"},
  {"ENT_RAPIDE32_MAX", "INT_FAST32_MAX"},
  {"ENT_RAPIDE64_MAX", "INT_FAST64_MAX"},
  {"PENT_RAPIDE8_MAX", "UINT_FAST8_MAX"},
  {"PENT_RAPIDE16_MAX", "UINT_FAST16_MAX"},
  {"PENT_RAPIDE32_MAX", "UINT_FAST32_MAX"},
  {"PENT_RAPIDE64_MAX", "UINT_FAST64_MAX"},
  {"ENTPTR_MIN", "INTPTR_MIN"},
  {"ENTPTR_MAX", "INTPTR_MAX"},
  {"PENTPTR_MAX", "UINTPTR_MAX"},
  {"ENTMAX_MIN", "INTMAX_MIN"},
  {"ENTMAX_MAX", "INTMAX_MAX"},
  {"PENTMAX_MAX", "UINTMAX_MAX"},
  {"FICHIER", "FILE"},
  {"NUL", "NULL"},

  /* Librairie standard - https://en.wikipedia.org/wiki/C_standard_library */
  {"<assertion.en-tête>", "<assert.h>"},
  {"<complexe.en-tête>", "<complex.h>"},
  {"<types des caractères.en-tête>", "<ctype.h>"},
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
  {"<types des caractères larges.en-tête>", "<wctype.h>"},

  {"principale", "main"},
  {"pricipal", "main"},

  /* Librairie POSIX - https://en.wikipedia.org/wiki/C_POSIX_library */
  {"<entrées et sorties asynchrones.en-tête>", "<aio.h>"},
  {"<arpa/internet.en-tête>", "<arpa/inet.h>"},
  {"<cpio.en-tête>", "<cpio.h>"}, /* TODO */
  {"<entité de répertoire.en-tête>", "<dirent.h>"},
  {"<liaison dynamique.en-tête>", "<dlfcn.h>"},
  {"<manipulation de descripteurs de fichier.en-tête>", "<fcntl.h>"},
  {"<formattage de messages.en-tête>", "<fmtmsg.h>"},
  {"<correspondance de noms de fichiers.en-tête>", "<fnmatch.h>"},
  {"<parcours d'arbres de fichiers.en-tête>", "<ftw.h>"},
  {"<correspondance de motifs.en-tête>", "<glob.h>"},
  {"<groupe d'utilisateur.en-tête>", "<grp.h>"},
  {"<conversion d'encodage de caractères.en-tête>", "<iconv.h>"},
  {"<informations de langues.en-tête>", "<langinfo.h>"},
  {"<manipulation de chemins de fichiers.en-tête>", "<libgen.h>"},
  {"<monétaire.en-tête>", "<monetary.h>"},
  {"<file de messages.en-tête>", "<mqueue.h>"},
  {"<ndbm.en-tête>", "<ndbm.h>"}, /* TODO */
  {"<réseau/interfaces.en-tête>", "<net/if.h>"},
  {"<base de données réseau.en-tête>", "<netdb.h>"},
  {"<réseau internet/in.en-tête>", "<netinet/in.h>"}, /* TODO */
  {"<réseau internet/tcp.en-tête>", "<netinet/tcp.h>"},
  {"<types d'internationalisation.en-tête>", "<nl_types.h>"},
  {"<sondage.en-tête>", "<poll.h>"},
  {"<fil posix.en-tête>", "<pthread.h>"},
  {"<mot de passe.en-tête>", "<pwd.h>"},
  {"<expression régulière.en-tête>", "<regex.h>"},
  {"<plannification.en-tête>", "<sched.h>"},
  {"<recherche.en-tête>", "<search.h>"},
  {"<sémaphore.en-tête>", "<semaphore.h>"},
  {"<pondre.en-tête>", "<spawn.h>"},
  {"<chaîne de caractères sensible à la casse.en-tête>", "<strings.h>"},
  {"<options de flux.en-tête>", "<stropts.h>"},
  {"<système/communication inter-processus.en-tête>", "<sys/ipc.h>"},
  {"<système/gestion de la mémoire.en-tête>", "<sys/mman.h>"},
  {"<système/message.en-tête>", "<sys/msg.h>"},
  {"<système/ressource.en-tête>", "<sys/resource.h>"},
  {"<système/sélection.en-tête>", "<sys/select.h>"},
  {"<système/sémaphore.en-tête>", "<sys/sem.h>"},
  {"<système/mémoire partagée.en-tête>", "<sys/shm.h>"},
  {"<système/chaussette.en-tête>", "<sys/socket.h>"},
  {"<système/statistique.en-tête>", "<sys/stat.h>"},
  {"<système/statistique for système de fichiers virtuel.en-tête>", "<sys/statvfs.h>"},
  {"<système/temps.en-tête>", "<sys/time.h>"},
  {"<système/temps des fichiers.en-tête>", "<sys/times.h>"},
  {"<système/types.en-tête>", "<sys/types.h>"},
  {"<système/entrées et sorties vectorielles.en-tête>", "<sys/uio.h>"},
  {"<système/chaussette unix.en-tête>", "<sys/un.h>"},
  {"<système/informations.en-tête>", "<sys/utsname.h>"}, /* TODO */
  {"<système/attente.en-tête>", "<sys/wait.h>"},
  {"<journal système.en-tête>", "<syslog.h>"},
  {"<tar.en-tête>", "<tar.h>"}, /* TODO */
  {"<entrées et sorties du terminal.en-tête>", "<termios.h>"},
  {"<traçage.en-tête>", "<trace.h>"}, /* déprécié */
  {"<limitation de ressource.en-tête>", "<ulimit.h>"}, /* déprécié */
  {"<bibliothèque posix.en-tête>", "<unistd.h>"},
  {"<temps des nœuds d'index.en-tête>", "<utime.h>"},
  {"<utmpx.en-tête>", "<utmpx.h>"}, /* TODO */
  {"<expansion de mots.en-tête>", "<wordexp.h>"}
};

/* Langage OCaml */
#define DEBUT_COMMENTAIRE_ML "(* "
#define FIN_COMMENTAIRE_ML " *)"
struct mot_cle_francais mot_cles_ml[] = {
  /* Mot-clefs */
  {"et", "and"},
  {"en tant que", "as"},
  {"s'assurer que", "assert"},
  {"décalage arithmétique vers la droite", "asr"},
  {"début", "begin"},
  {"classe", "class"},
  {"une contrainte", "constraint"},
  {"fini", "done"},
  {"descendant jusqu'à", "downto"},
  {"sinon", "else"},
  {"fin", "end"},
  {"exception", "exception"},
  {"externe", "external"},
  {"faux", "false"},
  {"pour", "for"},
  {"fon", "fun"},
  {"fonction", "function"},
  {"foncteur", "functor"},
  {"si", "if"},
  {"dans", "in"},
  {"inclure", "include"},
  {"hérite de", "inherit"},
  {"initialisateur", "initializer"},
  {"et logique", "land"},
  {"paresseux", "lazy"},
  {"soit", "let"},
  {"ou logique", "lor"},
  {"décalage logique vers la gauche", "lsl"},
  {"décalage logique vers la droite", "lsr"},
  {"ou logique exclusif bit-à-bit", "lxor"},
  {"faire correspondre", "match"},
  {"méthode", "method"},
  {"modulo", "mod"},
  {"module", "module"},
  {"muable", "mutable"},
  {"nouveau", "new"},
  {"non récursive", "nonrec"},
  {"objet", "object"},
  {"de", "of"},
  {"ouvrir", "open"},
  {"ou", "or"},
  {"privée", "private"},
  {"récursive", "rec"},
  {"signature", "sig"},
  {"structure", "struct"},
  {"alors", "then"},
  {"jusqu'à", "to"},
  {"vrai", "true"},
  {"essayer", "try"},
  {"type", "type"},
  {"valeur", "val"},
  {"virtuel", "virtual"},
  {"lorsque", "when"},
  {"tant que", "while"},
  {"à", "with"},
  {"faire", "do"},
};

/* Langage RuSt */
#define DEBUT_COMMENTAIRE_RS "/* "
#define FIN_COMMENTAIRE_RS " */"
struct mot_cle_francais mot_cles_rs[] = {
  /* Mots clef */
  {"soit", "let"},
  {"déconstruire", "match"},
  {"caisson étranger", "extern crate"},
  {"fn", "fn"},
  {"var", "mut"},
  {"utiliser", "use"},
  {"ref", "ref"},
  {"pub", "pub"},
  {"mod", "mod"},
  {"énum", "enum"},
  {"struct", "struct"},
  {"soit", "self"},
  {"faux", "false"},
  {"vrai", "true"},
  {"où", "where"},
  {"pas sûr", "unsafe"},
  {"si", "if"},
  {"sinon", "else"},
  {"statique", "static"},
  {"const", "const"},
  {"pour", "for"},
  {"tant que", "while"},
  {"boucler", "loop"},

  /* Types primitifs */
  {"e8", "i8"},
  {"e16", "i16"},
  {"e32", "i32"},
  {"e64", "i64"},
  {"e128", "i128"},
  {"etaille", "isize"},
  {"n8", "u8"},
  {"n16", "u16"},
  {"n32", "u32"},
  {"n64", "u64"},
  {"n128", "u128"},
  {"ntaille", "usize"},
  {"car", "char"},
  {"bool", "bool"},
  {"chaine", "str"},

  /* Directives processeur */
  {"#[dériver de", "#[derive"},

  /* Types autoimportés la stdlib */
  {"Option", "Option"},
  {"Quelque", "Some"},
  {"Aucun", "None"},
  {"Résultat", "Result"},
  {"Passable", "Ok"},
  {"Mauvais", "Err"},
  {"Boîte", "Box"},
  {"Vec", "Vec"},
  {"Comme référence", "AsRef"},
  {"Chaîne", "String"},

  {"principale", "main"}
};

#endif
