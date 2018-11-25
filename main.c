#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EncyclopedieLC.h"


int main()
{
    ptrLC e= creer_encyclopedieLC();
    Article * a = (Article*)malloc(sizeof(Article));
    a->id=1;
    a->contenu="contenu article 1";
    a->titre="Test";
    e=insererLC(e, *a);
    a->id=2;
    a->contenu="contenu article 2 mot";
    a->titre="Test2";
    /* Insérer fonctionne qu'une fois ? */
    e=insererLC(e,*a);
    a->id=3;
    a->contenu="contenu article 3";
    a->titre="Test3";
    e=insererLC(e,*a);
    a->id=4;
    a->contenu="contenu article 4 mot";
    a->titre="Test4";
    e=insererLC(e,*a);

    afficherLC(e);
    printf("\nSuppresion du 3\n");
    e=supprimerLC(e,3);
    afficherLC(e);
    printf("\nRecherche du 1\n");
    printf("Titre trouvé : %s\n",rechercher_articleLC(e,1));

    printf("\nRecherche du mot : 'mot'\n");
    ptrLC search= creer_encyclopedieLC();
    search = rechercher_article_plein_texteLC(e, "mot");
    afficherLC(search);

    detruire_bibliothequeLC(search);
    printf("\nLa bibliotheque search a ete detruite\n");

    //Article b = rechercher_article(e,2);

    //Encyclopedie * toz=NULL;
    //toz=rechercher_article_plein_texte(e,toz,"c");

    //afficher(toz);
    //printf()
    return 0;
}
