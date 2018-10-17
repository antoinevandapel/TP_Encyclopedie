#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encyclopedie.h"


int main()
{
    printf("Hello world!\n");

    Encyclopedie * e = creer_encyclopedie();
    Article * a = (Article *) malloc(sizeof(Article));
    a->id=1;
    a->contenu="blc";
    a->titre="fezfzfrgrfrgergrgegrgr";

    Article * b = (Article *) malloc(sizeof(Article));
    b->id=2;
    b->contenu="blc";
    b->titre="fezfzfrgrfrgergrgegrgr";

    e=inserer(e,a);
    e=inserer(e,b);
    printf("%d\n",e->right->article->id);
    printf("%d\n",e->article->id);
    //printf("%d", a->id);
    return 0;
}
