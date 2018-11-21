#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encyclopedie.h"


int main()
{
    Encyclopedie * e=NULL;
    /*
    Article * a = (Article*)malloc(sizeof(Article));
    a->id=1;
    a->contenu="c";
    a->titre="";
    e=inserer(e, *a);
    a->id=4;
    a->contenu="c";
    a->titre="";
    e=inserer(e,*a);
    a->id=2;
    a->contenu="toz";
    a->titre="";
    e=inserer(e,*a);

    //afficher(e);

    Article b = rechercher_article(e,2);

    Encyclopedie * toz=NULL;
    toz=rechercher_article_plein_texte(e,toz,"c");

    afficher(toz);
    */
    e=integrer_article(e, "B46_wikipedia_test.dat");
    printf("%d", e);
    afficher(e);
    //printf()
    return ;
}
