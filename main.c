#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encyclopedie.h"


int main()
{
    Encyclopedie * e = creer_encyclopedie();
    Article * a = (Article *) malloc(sizeof(Article));
    a->id=1;
    a->contenu="tata toto";
    a->titre="Titre 1";

    Article * b = (Article *) malloc(sizeof(Article));
    b->id=2;
    b->contenu="toto titi";
    b->titre="Titre 2";

    Article * c = (Article *) malloc(sizeof(Article));
    c->id=3;
    c->contenu="toto titi tata";
    c->titre="Titre 3";

    e=inserer(e,a);
    e=inserer(e,b);
    e=inserer(e,c);
    afficher(e);

    //e=supprimer(e,2);
    //printf("%d\n",e->article->id);
    //printf("%d\n",e->right->article->id);

    //printf("%s\n", rechercher_article(e,3));

    printf("\nRecherche\n");
    Encyclopedie * search = creer_encyclopedie();
    search = rechercher_article_plein_texte(e,"titi");
    afficher(search);

    printf("\nDestruction de la table");
    detruire_bibliotheque(e);

    return 0;
}
