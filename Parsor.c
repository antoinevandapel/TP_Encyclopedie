#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EncyclopedieBST.h"
/*
EncyclopedieBST* integrer_article(EncyclopedieBST * e, char * c){

    Article * art = (Article *)malloc(sizeof(Article));
    FILE* fic ;
    char * token;
    int  i, len;
    int result=0;
    char ligne[15000];
    char num[50];

    fic = fopen(c, "rt") ;
    if (fic==NULL)
    {
        printf("Pb d'ouverture du fichier!");
        exit(0);
    }
    while ( fgets( ligne, 15000, fic) != NULL )
    {
        token = strtok(ligne, "|");
        art->id = atoi(token);

        token = strtok(NULL, "|");
        art->titre=token;

        token = strtok(NULL, "|");
        art->contenu=token;

        e=inserer(e,*art);
        if(e==NULL)printf("%d", art->id);
    }
    fclose( fic ) ;
    return e;
}
*/
