#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

printf("hhhhhh");
void afficher() {
    printf("\033[1;31m\n\n\t\tMini-Projet : Systeme de Gestion de Stock dans une Librairie\n");
    printf("\n\t\t\033[0mLe programme offre les fonctionnalites suivantes :\n\n");
    printf("\t\033[1;32m1: Ajouter un livre au stock.\n");
    printf("\t\033[1;32m2: Afficher tous les livres disponibles\n");
    printf("\t\033[1;32m3: Rechercher un livre par son titre\n");
    printf("\t\033[1;32m4: Mettre a jour la quantite d'un livre\n");
    printf("\t\033[1;32m5: Supprimer un livre du stock\n");
    printf("\t\033[1;32m6: Afficher le nombre total de livres en stock\n");
    printf("\t\033[1;32m0: Quitter le programme\n\n\033[0m");
}
void choisir_nb_choix(int *choix) {
    int valide;
    do {
        printf("-->\t\033[0mChoisir un nombre entre 0 et 6 : ");
        valide = scanf("%d", choix);

        if (valide != 1 || *choix < 0 || *choix > 6) {
            printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer un nombre valide entre 0 et 6.\033[0m\n\n");
            while (getchar() != '\n');  // Vide les entrée incorrecte
        }
    } while (valide != 1 || *choix < 0 || *choix > 6);
}

void switch_cas(int choix) { //fonction pour le traitement de cas de choix 
    char titre[100][100];
    char auteur[100][100];
    float prix[100];
    int quantite[100];
    int nmb = 0;
    int valide;

    do {
        switch (choix) {
            case 1: {
                if (nmb >= 100) {
                    printf("!!!!Erreur : La capacite maximale de livres est atteinte.\n");
                    break;
                }

                printf("\033[1;36m\n\t\tBienvenue sur la phase d'ajout d'un livre au stock\033[0m\n\n");
                int nb_saisir;
                printf("\tEst-ce que vous voulez ajouter un livre ou plusieurs livres ?\n");
                
                g:  
                printf("\t\t0: Ajouter un livre\n");
                printf("\t\t1: Ajouter plusieurs livres\n\n");

                // traiter le choix entre 0 et 1
                while (1) {
                    printf("\tDonnez-moi un numero de votre choix (0 ou 1) : ");
                    if (scanf("%d", &nb_saisir) != 1 || (nb_saisir != 0 && nb_saisir != 1)) {
                        printf("\033[1;31m\n\n\t\tErreur : Veuillez entrer 0 ou 1.\033[0m\n\n");
                        while (getchar() != '\n'); // Vider le buffer
                    } else {
                        break; 
                    }
                }

                // Traitement selon le choix
                if (nb_saisir == 0) {
                    nb_saisir = 1;  // Si ajoute un seul livre
                } else if (nb_saisir == 1) {
                    do {
                        printf("\tCombien de livres voulez-vous ajouter ? ");
                        valide = scanf("%d", &nb_saisir);

                        // traiter condition 
                        while (getchar() != '\n');

                        if (valide != 1 || nb_saisir < 2) {
                            printf("\033[1;31m\n\n\t\tErreur : veuillez entrer un entier superieur ou egal à 2.\033[0m\n\n");
                        }
                    } while (valide != 1 || nb_saisir < 2);
                } else {
                    printf("\033[1;31m\nErreur : Veuillez bien respecter les consignes de choix.\033[0m\n\n");
                    goto g;  // Retour à la saisie en cas de mauvais choix
                }

                // ajouter chaque livre
                for (int i = 0; i < nb_saisir; i++) {
                    int existe = 0;  // V .vérifier l'existence du livre

                    printf("\tSaisir les informations du livre %d :\n\n", nmb + 1);
                e:  // Saisie du titre
                    do {
                        printf("\t\tTitre : ");
                        scanf(" %[^\n]", titre[nmb]);  // syntax  d'accepter des espaces

                        for (int j = 0; j < nmb; j++) {
                            if (strcmp(titre[nmb], titre[j]) == 0) {
                                printf("\t\t\033[1;31mLe livre '%s' existe deja dans le stock.\033[0m\n", titre[nmb]);
                                existe = 1;
                                break;
                            }
                        }

                        if (existe) {
                            continue;  // Passer à l'itération suivante si le livre existe déjà
                        }
                    } while (existe);

                    // Vérifier : Est ce que  le titre contient uniquement des alphabets ou espaces
                    for (int j = 0; titre[nmb][j] != '\0'; j++) {
                        if (!isalpha(titre[nmb][j]) && titre[nmb][j] != ' ') {
                            printf("\n\t\033[1;31m!!!!! Erreur : Le titre contient des caracteres non valides.\033[0m\n");
                            printf("\n\n\033[1;35m\t\tResaisir le titre !!!!\033[0m\n");
                            goto e;  // Retour  la saisie du titre
                        }
                    }

                    //  l'auteur
                a:
                    printf("\t\tAuteur : ");
                    scanf(" %[^\n]", auteur[nmb]);

                    // Traiter l'auteur entrer 
                    for (int j = 0; auteur[nmb][j] != '\0'; j++) {
                        if (!isalpha(auteur[nmb][j]) && auteur[nmb][j] != ' ') {
                            printf("\n\t\033[1;31m!!!!! Erreur : l'auteur contient des caracteres non valides.\033[0m\n");
                            printf("\n\n\033[1;35m\t\tResaisir le nom de l'auteur !!!!\033[0m\n");
                            goto a;  
                        }
                    }

                    // Traite la valeur de traitement 
                    
                    do {
                        printf("\t\tPrix : ");
                        valide = scanf("%f", &prix[nmb]);
                        if (valide != 1 || prix[nmb] < 0) {
                            printf("\033[1;31m\n\t\t!!! Erreur : Vous devez entrer un nombre valide pour le prix.\033[0m\n\n");
                            while (getchar() != '\n');  // detruit 
                        }
                    } while (valide != 1 || prix[nmb] < 0);

                    // Traiter la valeur de quantite
                    do {
                        printf("\t\tQuantite : ");
                        valide = scanf("%d", &quantite[nmb]);
                        if (valide != 1 || quantite[nmb] < 0) {
                            printf("\033[1;31m\n\t\t!!!! Erreur : Vous devez entrer un nombre valide pour la quantite.\033[0m\n\n");
                            while (getchar() != '\n');  // Vide  entrée
                        }
                    } while (valide != 1 || quantite[nmb] < 0);

                    nmb++;  // Incrémenter Nb. livres
                    printf("\t\t\033[1;33mLivre ajoute avec succes !\033[0m\n");
                }
                break;
            }

            case 2: {
                if (nmb == 0) {
                    printf("\n\t\t\033[1;31m Ooops!!!!! Aucun livre n'a ete ajoute au stock.\n\n");
                } else {
                    printf("\n\n\t***** Affichage de Tous les Livres Disponibles *****\n\n");

                    // 
                    printf("\t%-15s %-15s %-10s %-10s\n", "Titre", "Auteur", "Prix", "Quantite");
                    printf("\t-----------------------------------------------------\n");

                    // Affichage des livres
                    for (int i = 0; i < nmb; i++) {
                        printf("\t%-15s %-15s %-10.2f %-10d\n", titre[i], auteur[i], prix[i], quantite[i]);
                    }
                    printf("\n\t***********************************************\n\n");
                }
                break;
            }

            // Recherche 
            case 3: {
                char recherche[100];
                printf("Saisir le titre du livre a rechercher : ");
                scanf(" %[^\n]", recherche);
                int trouve = 0;

                // Affichage
                printf("\n\t***** Resultats de la Recherche *****\n\n");
                printf("\t%-15s %-15s %-10s %-10s\n", "Titre", "Auteur", "Prix", "Quantite");
                printf("\t-----------------------------------------------------\n");

                for (int i = 0; i < nmb; i++) {
                    if (strstr(titre[i], recherche) != NULL) {
                        printf("\t%-15s %-15s %-10.2f %-10d\n", titre[i], auteur[i], prix[i], quantite[i]);
                        trouve = 1;
                    }
                }
                if (!trouve) {
                    printf("\033[1;31m\n\t\tAucun livre trouve avec le titre '%s'.\033[0m\n", recherche);
                }

                printf("\n\t***********************************************\n\n");
                break;
            }

            case 4: {
                char titre_a_modifier[100];
                printf("Saisir le titre du livre a modifier : ");
                scanf(" %[^\n]", titre_a_modifier);
                int trouve = 0;

                for (int i = 0; i < nmb; i++) {
                    if (strcmp(titre[i], titre_a_modifier) == 0) {
                        printf("Saisir la nouvelle quantite pour le livre '%s' : ", titre[i]);
                        scanf("%d", &quantite[i]);
                        trouve = 1;
                        printf("\033[1;32m\n\t\tQuantite mise a jour avec succes !\033[0m\n");
                        break;
                    }
                }
                if (!trouve) {
                    printf("\033[1;31m\n\t\tAucun livre trouve avec le titre '%s'.\033[0m\n", titre_a_modifier);
                }
                break;
            }

            case 5: {
                char titre_a_supprimer[100];
                printf("Saisir le titre du livre a supprimer : ");
                scanf(" %[^\n]", titre_a_supprimer);
                int trouve = 0;

                for (int i = 0; i < nmb; i++) {
                    if (strcmp(titre[i], titre_a_supprimer) == 0) {
                        for (int j = i; j < nmb - 1; j++) {
                            strcpy(titre[j], titre[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            prix[j] = prix[j + 1];
                            quantite[j] = quantite[j + 1];
                        }
                        nmb--;
                        trouve = 1;
                        printf("\033[1;32m\n\t\tLivre '%s' supprime avec succes !\033[0m\n", titre_a_supprimer);
                        break;
                    }
                }
                if (!trouve) {
                    printf("\033[1;31m\n\t\tAucun livre trouve avec le titre '%s'.\033[0m\n", titre_a_supprimer);
                }
                break;
            }

            case 6: {
                printf("\n\t\t\033[1;36mLe nombre total de livres en stock est : %d\033[0m\n", nmb);
                break;
            }

            case 0:
                printf("\033[1;32m\n\t\tMerci d'avoir utilise notre programme !\033[0m\n");
                exit(0);

            default:
                printf("\033[1;31m\n\t\tChoix non valide ! Veuillez reessayer.\033[0m\n");
                break;
        }

        printf("\n\n");
        afficher();  // Repeter l' Afficher  
        choisir_nb_choix(&choix);
    } while (choix != 0);
}
int main() {
    int choix;
    afficher();
    choisir_nb_choix(&choix);
    switch_cas(choix);
    return 0;
}

