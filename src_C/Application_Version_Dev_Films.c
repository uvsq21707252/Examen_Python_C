#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "media.h"

void ajouter_media(Categorie *categorie) {
    if (categorie->nbMedia < MAX_TITRE) {
        printf("Titre : ");
        fgets(categorie->medias[categorie->nbMedia].titre, sizeof(categorie->medias[categorie->nbMedia].titre), stdin);
        categorie->medias[categorie->nbMedia].titre[strcspn(categorie->medias[categorie->nbMedia].titre, "\n")] = '\0';

        printf("Description : ");
        fgets(categorie->medias[categorie->nbMedia].description, sizeof(categorie->medias[categorie->nbMedia].description), stdin);
        categorie->medias[categorie->nbMedia].description[strcspn(categorie->medias[categorie->nbMedia].description, "\n")] = '\0';

        printf("Notation (sur 5 étoiles) : ");
        scanf("%f", &categorie->medias[categorie->nbMedia].notation);

        getchar();  // Capture du caractère newline

        (categorie->nbMedia)++;

        printf("Le média a été ajouté avec succès.\n\n");
    } else {
        printf("La liste des médias est pleine. Impossible d'ajouter un nouveau média.\n\n");
    }
}

void afficher_media(const Categorie *categorie) {
    printf("----- Liste des médias dans la catégorie %s -----\n", categorie->nom);

    if (categorie->nbMedia == 0) {
        printf("Aucun média n'a été ajouté dans cette catégorie.\n\n");
        return;
    }

    for (int i = 0; i < categorie->nbMedia; i++) {
        printf("Média %d :\n", i + 1);
        printf("Titre : %s\n", categorie->medias[i].titre);
        printf("Description : %s\n", categorie->medias[i].description);
        printf("Notation : %.1f étoiles\n", categorie->medias[i].notation);
        printf("\n");
    }
}

void ajouter_avis(Categorie *categorie) {
    if (categorie->nbMedia < MAX_TITRE) {
        printf("Titre du média : ");
        char titreMedia[MAX_TITRE];
        fgets(titreMedia, sizeof(titreMedia), stdin);
        titreMedia[strcspn(titreMedia, "\n")] = '\0';

        int mediaIndex = -1;
        for (int i = 0; i < categorie->nbMedia; i++) {
            if (strcmp(categorie->medias[i].titre, titreMedia) == 0) {
                mediaIndex = i;
                break;
            }
        }

        if (mediaIndex != -1) {
            printf("Avis : ");
            fgets(categorie->medias[mediaIndex].avis, sizeof(categorie->medias[mediaIndex].avis), stdin);
            categorie->medias[mediaIndex].avis[strcspn(categorie->medias[mediaIndex].avis, "\n")] = '\0';

            printf("L'avis a été ajouté avec succès.\n\n");
        } else {
            printf("Aucun média avec le titre \"%s\" n'a été trouvé.\n\n", titreMedia);
        }
    } else {
        printf("La liste des médias est pleine. Impossible d'ajouter un nouvel avis.\n\n");
    }
}

void afficher_avis(const Categorie *categorie) {
    printf("----- Liste des avis dans la catégorie %s -----\n", categorie->nom);

    if (categorie->nbMedia == 0) {
        printf("Aucun média n'a été ajouté dans cette catégorie.\n\n");
        return;
    }

    for (int i = 0; i < categorie->nbMedia; i++) {
        if (strlen(categorie->medias[i].avis) > 0) {
            printf("Avis pour le média \"%s\" :\n", categorie->medias[i].titre);
            printf("Avis : %s\n", categorie->medias[i].avis);
            printf("\n");
        }
    }
}

int main() {
    Categorie categories[MAX_CATEGORIES] = {
        {"Films", {}, 0},
        {"Series", {}, 0},
        {"Animes", {}, 0}
    };

    int choix;

    do {
        printf("----- Menu -----\n");
        printf("1. Ajouter un média\n");
        printf("2. Afficher la liste des médias par catégorie\n");
        printf("3. Ajouter un avis\n");
        printf("4. Afficher les avis par catégorie\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        getchar();  // Capture du caractère newline

        switch (choix) {
            case 1:
                printf("----- Ajout d'un nouveau média -----\n");
                printf("Catégories disponibles : Films, Series, Animes\n");
                printf("Catégorie : ");
                char categorie[MAX_TITRE];
                fgets(categorie, sizeof(categorie), stdin);
                categorie[strcspn(categorie, "\n")] = '\0';

                int categorieIndex = -1;
                for (int i = 0; i < MAX_CATEGORIES; i++) {
                    if (strcmp(categories[i].nom, categorie) == 0) {
                        categorieIndex = i;
                        break;
                    }
                }

                if (categorieIndex != -1) {
                    ajouter_media(&categories[categorieIndex]);
                } else {
                    printf("Catégorie invalide. Veuillez sélectionner une catégorie valide.\n\n");
                }

                break;
            case 2:
                printf("----- Affichage des médias par catégorie -----\n");
                printf("Catégories disponibles : Films, Series, Animes\n");
                printf("Catégorie : ");
                fgets(categorie, sizeof(categorie), stdin);
                categorie[strcspn(categorie, "\n")] = '\0';

                categorieIndex = -1;
                for (int i = 0; i < MAX_CATEGORIES; i++) {
                    if (strcmp(categories[i].nom, categorie) == 0) {
                        categorieIndex = i;
                        break;
                    }
                }

                if (categorieIndex != -1) {
                    afficher_media(&categories[categorieIndex]);
                } else {
                    printf("Catégorie invalide. Veuillez sélectionner une catégorie valide.\n\n");
                }

                break;
            case 3:
                printf("----- Ajout d'un nouvel avis -----\n");
                printf("Catégories disponibles : Films, Series, Animes\n");
                printf("Catégorie : ");
                fgets(categorie, sizeof(categorie), stdin);
                categorie[strcspn(categorie, "\n")] = '\0';

                categorieIndex = -1;
                for (int i = 0; i < MAX_CATEGORIES; i++) {
                    if (strcmp(categories[i].nom, categorie) == 0) {
                        categorieIndex = i;
                        break;
                    }
                }

                if (categorieIndex != -1) {
                    ajouter_avis(&categories[categorieIndex]);
                } else {
                    printf("Catégorie invalide. Veuillez sélectionner une catégorie valide.\n\n");
                }

                break;
            case 4:
                printf("----- Affichage des avis par catégorie -----\n");
                printf("Catégories disponibles : Films, Series, Animes\n");
                printf("Catégorie : ");
                fgets(categorie, sizeof(categorie), stdin);
                categorie[strcspn(categorie, "\n")] = '\0';

                categorieIndex = -1;
                for (int i = 0; i < MAX_CATEGORIES; i++) {
                    if (strcmp(categories[i].nom, categorie) == 0) {
                        categorieIndex = i;
                        break;
                    }
                }

                if (categorieIndex != -1) {
                    afficher_avis(&categories[categorieIndex]);
                } else {
                    printf("Catégorie invalide. Veuillez sélectionner une catégorie valide.\n\n");
                }

                break;
            case 5:
                printf("Arrêt de l'application.\n");
                break;
            default:
                printf("Choix invalide. Veuillez sélectionner une option valide.\n\n");
        }
    } while (choix != 5);

    return 0;
}
