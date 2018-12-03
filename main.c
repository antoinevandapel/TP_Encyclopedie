#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EncyclopedieLC.h"
#include "EncyclopedieHT.h"
#include "EncyclopedieBST.h"

int encycloCreated = 0;

void affichageMenu()
{
    int choixMenu;

    printf("---Menu---\n\n");
    printf("1.Liste chainee\n");
    printf("2.Arbre de recherche\n");
    printf("3.Table de hashage\n\n");
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
    default:
        affichageMenu();
        break;
    }
}

void affichageMenu2(int type)
{
    ptrLC lc= creer_encyclopedieLC();
    EncyclopedieBST * bst= creer_encyclopedieBST();
    EncyclopedieHT * ht= creer_encyclopedieHT(5);

    int choixMenu;
    int idSel = 0;
    char * motRech = (char *)malloc (25*sizeof(char));


    while(choixMenu != 8){
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
    printf("2.Lire le fichier\n");
    printf("3.Afficher toute l'encyclopedie\n");
    printf("4.Supprimer un article\n");
    printf("5.Rechercher un article par id\n");
    printf("6.Rechercher un mot\n");
    printf("7.Detruire la bibliotheque\n");
    printf("8.Revenir au menu precedent\n\n");
    printf("\nAction a effectuer :\n");
    scanf("%d", &choixMenu);

    switch (choixMenu)
    {
        case 1:
            printf("Ajout d'un article\n\n");
            int idArticle = 0;
            char * titreArticle = (char *)malloc (25*sizeof(char));
            char * contenuArticle = (char *)malloc (200*sizeof(char)); ;

            printf("Id de l'article :\n");
            scanf("%d",&idArticle);
            printf("Titre de l'article :\n");
            scanf("%s",titreArticle);
            printf("Contenu de l'article :\n");
            scanf("%s",contenuArticle);

            Article * a = (Article*)malloc(sizeof(Article));

            a->id=idArticle;
            a->contenu=contenuArticle;
            a->titre=titreArticle;


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
            break;
        case 2:
            printf("Lecture du fichier\n");

            break;
        case 3:
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
                printf("Aucun encyclopedie n'a ete cree");
            }
            break;
        case 4:
            printf("Supprimer un article\n");
            printf("id de l'article a supprimer\n");
            scanf("%d",&idSel);
            if(type == 1){
                lc = supprimerLC(lc,idSel);
            }
            else if(type == 2){
                bst = supprimerBST(bst,idSel);
            }
            else if(type == 3){
                ht = supprimerHT(ht,idSel);
            }
            break;
        case 5:
            printf("Recherche par id\n");
            printf("Id de l'article a rechercher : ");
            scanf("%d",&idSel);
            if(type == 1){
                *a = rechercher_articleLC(lc,idSel);
            }
            else if(type == 2){
                *a = rechercher_articleBST(bst,idSel);
            }
            else if(type == 3){
                *a = rechercher_articleHT(ht,idSel);
            }
            printf("\nArticle trouve :\n");
            printf("\n---- Article %d----",a->id);
            printf("\nTitre : %s",a->titre);
            printf("\nContenu : %s\n",a->contenu);
            printf("\n");
            break;
        case 6:
            printf("Recherche par mot\n");
            printf("Mot a rechercher : ");
            scanf("%s",motRech);
            if(type == 1){
                lc = rechercher_article_plein_texteLC(lc, motRech);
            }
            else if(type == 2){
                //*a = rechercher_articleBST(bst,idSel);
            }
            else if(type == 3){
                //*a = rechercher_articleHT(ht,idSel);
            }
            break;
        case 7:
            printf("Destruction de la bibliotheque");
            break;
        case 8:
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


    /** Séparation **/
    /*EncyclopedieBST * e= creer_encyclopedieBST();
    Article * a = (Article*)malloc(sizeof(Article));
    a->id=1;
    a->contenu="contenu article 1";
    a->titre="Test";
//    printf("pointeur avant : %d\n", e);
    e=insererBST(e, *a);
//    printf("pointeur apres : %d\n", e);
//    printf("id :%d\n",e->article.id);
//    //afficherBST(e);
    a->id=11;
    a->contenu="contenu article 11 mot";
    a->titre="Test2";
    /* Insérer fonctionne qu'une fois ? */

    /*e=insererBST(e,*a);
    a->id=3;
    a->contenu="contenu article 3";
    a->titre="Test3";
    e=insererBST(e,*a);
    a->id=4;
    a->contenu="contenu article 4 mot";
    a->titre="Test4";
    e=insererBST(e,*a);

    afficherBST(e);
    printf("\nSuppresion du 1\n");
    e=supprimerBST(e,1);
    afficherBST(e);

    printf("\nRecherche du 1\n");
    Article b = rechercher_articleBST(e,1);
    printf("Article recherché : %s",b.titre);


    printf("\nRecherche du mot : 'mot'\n");
    EncyclopedieBST * search= creer_encyclopedieBST(5);
    search = rechercher_article_plein_texteBST(e,search, "mot");
    afficherBST(search);


    detruire_bibliothequeBST(search);
    printf("\nLa bibliotheque search a ete detruite\n");*/

    //Article b = rechercher_article(e,2);

    //Encyclopedie * toz=NULL;
    //toz=rechercher_article_plein_texte(e,toz,"c");

    //afficher(toz);
    //printf()
    return 0;
}
