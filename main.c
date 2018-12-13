#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LectureFichier.h"
#include "EncyclopedieLC.h"
#include "EncyclopedieHT.h"
#include "EncyclopedieBST.h"

int encycloCreated = 0;

void affichageMenu()
{
    int choixMenu;

    clock_t begin;
    clock_t end;
    clock_t beginAll;
    clock_t endAll;

    printf("---Menu---\n\n");
    printf("1.Liste chainee\n");
    printf("2.Arbre de recherche\n");
    printf("3.Table de hashage\n");
    printf("4.Lancer un jeu de tests\n\n");
    printf("\nVeuillez choisir un type de traitement :\n");
    scanf("%d", &choixMenu);

    switch (choixMenu)
    {
    case 1:
        printf("Vous avez choisis la liste chainee\n\n");
        affichageMenu2(1);
        break;
    case 2:
        printf("Vous avez choisis l'arbre de recherche\n");
        affichageMenu2(2);
        break;
    case 3:
        printf("Vous avez choisis la table de hashage\n");
        affichageMenu2(3);
        break;
    case 4:
        printf("Debut du jeu de test:\n\n");
        // Création d'un article permettant de tester l'insertion
        Article * a = (Article*)malloc(sizeof(Article));
        a->id=1;
        a->contenu="Contenu Test";
        a->titre="Titre Test";

        ptrLC lc= creer_encyclopedieLC();
        ptrLC searchlc= creer_encyclopedieLC();
        EncyclopedieBST * bst= creer_encyclopedieBST();
        EncyclopedieBST * searchbst= creer_encyclopedieBST();
        EncyclopedieHT * ht= creer_encyclopedieHT(5);
        EncyclopedieHT * searchht= creer_encyclopedieHT(5);

        /*** Test pour liste chainée ***/
        printf("---Liste chainee---\n");
        beginAll = clock();

        begin = clock();
        lc = insererLC(lc,*a);
        end = clock();
        printf("Insertion d'un article : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        begin = clock();
        lc = lire_fichierLC("B46_wikipedia_test.dat");
        end = clock();
        printf("Lecture du fichier wikipedia test : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        begin = clock();
        lc = lire_fichierLC("B46_wikipedia_500K_randomold.dat");
        end = clock();
        printf("Lecture du fichier wikipedia random : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        /*begin = clock();
        Article b = rechercher_articleLC(lc,3860272);
        end = clock();
        printf("Recherche d'un article par id : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);*/

        begin = clock();
        searchlc = rechercher_article_plein_texteLC(lc,"Antoine");
        end = clock();
        printf("Recherche d'un mot: %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        /*begin = clock();
        lc = supprimerLC(lc,3860272);
        end = clock();
        printf("Suppression d'un article: %f\n",(double)(end - begin)/CLOCKS_PER_SEC);*/
        endAll=clock();
        printf("Temps total liste chainee: %f\n\n",(double)(endAll - beginAll)/CLOCKS_PER_SEC);
        /*** Fin test pour liste chainée ***/

        /*** Test pour arbre de recherche***/
        printf("---Arbre de recherche---\n");
        beginAll = clock();

        begin = clock();
        bst = insererBST(bst,*a);
        end = clock();
        printf("Insertion d'un article : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        begin = clock();
        bst = lire_fichierBST("B46_wikipedia_test.dat");
        end = clock();
        printf("Lecture du fichier wikipedia test : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        begin = clock();
        bst = lire_fichierBST("B46_wikipedia_500K_randomold.dat");
        end = clock();
        printf("Lecture du fichier wikipedia random : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        /*begin = clock();
        Article b = rechercher_articleBST(bst,3860272);
        end = clock();
        printf("Recherche d'un article par id : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);*/

        begin = clock();
        searchbst = rechercher_article_plein_texteBST(bst,searchbst,"Antoine");
        end = clock();
        printf("Recherche d'un mot: %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        /*begin = clock();
        bst = supprimerBST(bst,3860272);
        end = clock();
        printf("Suppression d'un article: %f\n",(double)(end - begin)/CLOCKS_PER_SEC);*/
        endAll=clock();
        printf("Temps total arbre de recherche: %f\n\n",(double)(endAll - beginAll)/CLOCKS_PER_SEC);
        /*** Fin test pour arbre de recherche ***/

        /*** Test pour table de hashage***/
        printf("---Table de hashage---\n");
        beginAll = clock();

        begin = clock();
        ht = insererHT(ht,*a);
        end = clock();
        printf("Insertion d'un article : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        begin = clock();
        ht = lire_fichierHT("B46_wikipedia_test.dat");
        end = clock();
        printf("Lecture du fichier wikipedia test : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        begin = clock();
        ht = lire_fichierHT("B46_wikipedia_500K_randomold.dat");
        end = clock();
        printf("Lecture du fichier wikipedia random : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        /*begin = clock();
        Article b = rechercher_articleHT(ht,3860272);
        end = clock();
        printf("Recherche d'un article par id : %f\n",(double)(end - begin)/CLOCKS_PER_SEC);*/

        begin = clock();
        searchht = rechercher_article_plein_texteHT(ht,searchht,"Antoine");
        end = clock();
        printf("Recherche d'un mot: %f\n",(double)(end - begin)/CLOCKS_PER_SEC);

        /*begin = clock();
        ht = supprimerHT(ht,3860272);
        end = clock();
        printf("Suppression d'un article: %f\n",(double)(end - begin)/CLOCKS_PER_SEC);*/
        endAll=clock();
        printf("Temps total arbre de recherche: %f\n\n",(double)(endAll - beginAll)/CLOCKS_PER_SEC);
        /*** Fin test pour table de hashage ***/


        affichageMenu();
        break;
    default:
        affichageMenu();
        break;
    }
}

void affichageMenu2(int type)
{
    ptrLC lc= creer_encyclopedieLC();
    EncyclopedieBST * bst= creer_encyclopedieBST();
    EncyclopedieHT * ht= creer_encyclopedieHT(100);

    EncyclopedieLC * searchLC = creer_encyclopedieLC();
    EncyclopedieBST * searchBST= creer_encyclopedieBST();
    EncyclopedieHT * searchHT = creer_encyclopedieHT(100);

    clock_t begin;
    clock_t end;
    double time_spent;

    int choixMenu;
    int idSel = 0;
    char * motRech = (char *)malloc (25*sizeof(char));


    while(choixMenu != 9){
    if(type == 1){
        printf("---Liste chainee---\n\n");
    }
    else if(type == 2){
        printf("---Arbre de recherche---\n\n");
    }
    else if(type == 3){
       printf("---Table de hashage---\n\n");
    }
    printf("1.Ajouter un article manuellement\n");
    printf("2.Lire le fichier de test wikipedia\n");
    printf("3.Lire le fichier complet\n");
    printf("4.Afficher toute l'encyclopedie\n");
    printf("5.Supprimer un article\n");
    printf("6.Rechercher un article par id\n");
    printf("7.Rechercher un mot\n");
    printf("8.Detruire la bibliotheque\n");
    printf("9.Revenir au menu precedent\n\n");
    printf("\nAction a effectuer :\n");
    scanf("%d", &choixMenu);

    switch (choixMenu)
    {
        case 1:
            printf("Ajout d'un article\n\n");
            int idArticle = 0;
            char * titreArticle = (char *) calloc(sizeof(char), 25);
            char * contenuArticle = (char *) calloc(sizeof(char), 25);

            printf("Id de l'article :\n");
            scanf("%d",&idArticle);
            printf("Titre de l'article (25 caracteres maximum) :\n");
            fflush(stdin);
            fgets(titreArticle, 25, stdin);

            printf("Contenu de l'article (256 caracteres maximum) :\n");
            fgets(contenuArticle, 256, stdin);

            Article * a = (Article*)malloc(sizeof(Article));

            a->id=idArticle;
            a->contenu=contenuArticle;
            a->titre=titreArticle;
            begin = clock();
            if(type == 1){

                lc = insererLC(lc,*a);
                encycloCreated++;
                printf("\n");
            }
            else if(type == 2){
                bst = insererBST(bst,*a);
                encycloCreated++;
                printf("\n");
            }
            else if(type == 3){
                ht = insererHT(ht,*a);
                encycloCreated++;
                printf("\n");
            }
            else{
                printf("ERROR");
            }
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Temps execution : %f\n",time_spent);
            break;
        case 2:
            printf("Lecture du fichier de test ...\n");
            begin = clock();
            if(type == 1){

                lc = lire_fichierLC("B46_wikipedia_test.dat");
                encycloCreated=encycloCreated+500;
            }
            else if(type == 2){
                bst = lire_fichierBST("B46_wikipedia_test.dat");
                encycloCreated=encycloCreated+500;
            }
            else if(type == 3){
                ht = lire_fichierHT("B46_wikipedia_test.dat");
                encycloCreated=encycloCreated+500;
            }
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Temps execution : %f\n",time_spent);
            break;
        case 3:
            printf("Lecture du fichier\n");
            begin = clock();
            if(type == 1){
                lc = lire_fichierLC("B46_wikipedia_500K_randomold.dat");
                encycloCreated=encycloCreated+500;
            }
            else if(type == 2){
                bst = lire_fichierBST("B46_wikipedia_500K_randomold.dat");
                encycloCreated=encycloCreated+500;
            }
            else if(type == 3){
                ht = lire_fichierHT("B46_wikipedia_500K_randomold.dat");
                encycloCreated=encycloCreated+500;
            }
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("Temps execution : %f\n",time_spent);
            break;
        case 4:
            printf("Contenu de l'encyclopédie\n");
            if(encycloCreated >= 1){
                if(type == 1){
                    afficherLC(lc);
                    printf("\n");
                }
                else if(type == 2){
                    afficherBST(bst);
                    printf("\n");
                }
                else if(type == 3){
                    afficherHT(ht);
                    printf("\n");
                }
            }
            else{
                printf("Aucun encyclopedie n'a ete cree\n");
            }
            break;
        case 5:
            printf("Supprimer un article\n");
            printf("Id de l'article a supprimer\n");
            scanf("%d",&idSel);
            if(encycloCreated >= 1){
                if(type == 1){
                    lc = supprimerLC(lc,idSel);
                    encycloCreated--;
                }
                else if(type == 2){
                    bst = supprimerBST(bst,idSel);
                    encycloCreated--;
                }
                else if(type == 3){
                    ht = supprimerHT(ht,idSel);
                    encycloCreated--;
                }
            }
            else{
                printf("Aucun encyclopedie n'a ete cree\n");
            }
            break;
        case 6:
            printf("Recherche par id\n");
            printf("Id de l'article a rechercher : ");
            scanf("%d",&idSel);
            begin = clock();
            if(encycloCreated >= 1){
                if(type == 1){
                    *a = rechercher_articleLC(lc,idSel);
                }
                else if(type == 2){
                    *a = rechercher_articleBST(bst,idSel);
                }
                else if(type == 3){
                    *a = rechercher_articleHT(ht,idSel);
                }
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

                printf("\nArticle trouve :\n");
                printf("\n---- Article %d----",a->id);
                printf("\nTitre : %s",a->titre);
                printf("\nContenu : %s\n",a->contenu);
                printf("Temps execution : %f\n",time_spent);
                printf("\n");

            }
            else{
                printf("Aucun encyclopedie n'a ete cree\n");
            }
            break;
        case 7:
            printf("Recherche par mot\n");
            printf("Mot a rechercher : ");
            scanf("%s",motRech);
            begin = clock();
            if(encycloCreated >= 1){
                if(type == 1){
                    searchLC = rechercher_article_plein_texteLC(lc, motRech);
                    afficherLC(searchLC);
                }
                else if(type == 2){
                    searchBST = rechercher_article_plein_texteBST(bst,searchBST, motRech);
                    afficherBST(searchBST);
                }
                else if(type == 3){
                    searchHT = rechercher_article_plein_texteHT(ht,searchHT,motRech);
                    afficherHT(searchHT);
                }
                end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("Temps execution : %f\n",time_spent);
            }
            else{
                printf("Aucun encyclopedie n'a ete cree");
            }
            break;
        case 8:
            printf("Destruction de la bibliotheque\n");
            if(encycloCreated >= 1){
                if(type == 1){
                    detruire_bibliothequeLC(lc);
                    encycloCreated = 0;
                }
                else if(type == 2){
                    detruire_bibliothequeBST(bst);
                    encycloCreated = 0;
                }
                else if(type == 3){
                    detruire_bibliothequeHT(ht);
                    encycloCreated = 0;
                }
            }
            else{
                printf("Aucun encyclopedie n'a ete cree");
            }
            break;
        case 9:
            if(encycloCreated >= 1){
                if(type == 1){
                    detruire_bibliothequeLC(lc);
                    encycloCreated = 0;
                }
                else if(type == 2){
                    detruire_bibliothequeBST(bst);
                    encycloCreated = 0;
                }
                else if(type == 3){
                    detruire_bibliothequeHT(ht);
                    encycloCreated = 0;
                }
            }
            encycloCreated = 0;
            affichageMenu();
            break;
        default:
            affichageMenu2(type);
            break;
        }
    }
}

int main()
{

    affichageMenu();
    return 0;
}
