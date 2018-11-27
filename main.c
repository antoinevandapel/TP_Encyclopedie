#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EncyclopedieLC.h"
#include "EncyclopedieHT.h"
#include "EncyclopedieBST.h"


int main()
{
    EncyclopedieBST * e= creer_encyclopedieBST();
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

    e=insererBST(e,*a);
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
    printf("\nLa bibliotheque search a ete detruite\n");

    //Article b = rechercher_article(e,2);

    //Encyclopedie * toz=NULL;
    //toz=rechercher_article_plein_texte(e,toz,"c");

    //afficher(toz);
    //printf()
    return 0;
}
