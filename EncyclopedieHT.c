#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EncyclopedieHT.h"

EncyclopedieHT * creer_encyclopedieHT(int size){
    EncyclopedieHT * e =(EncyclopedieHT *)malloc(sizeof(EncyclopedieHT));
    e->size=size;
    int i;
    e->e=(EncyclopedieLC**)malloc(sizeof(EncyclopedieLC*)*size);
    for(i=0; i<size;i++){
        e->e[i]=creer_encyclopedieLC();
    }
    return e;
}

EncyclopedieHT * insererHT(EncyclopedieHT * e, Article a){
    int mod = a.id%e->size;
    e->e[mod]=insererLC(e->e[mod],a);
    return e;
}
EncyclopedieHT * supprimerHT(EncyclopedieHT * e, int id){
    int mod = id%e->size;
    e->e[mod]=supprimerLC(e->e[mod],id);
    return e;
}
Article rechercher_articleHT(EncyclopedieHT * e, int id){
    int mod = id%e->size;
    return rechercher_articleLC(e->e[mod],id);
}
EncyclopedieHT * rechercher_article_plein_texteHT(EncyclopedieHT * e, EncyclopedieHT * res, char * mot){
    res=creer_encyclopedieHT(e->size);
    EncyclopedieLC * tmp=NULL;
    int i;
    for(i=0;i<e->size;i++){
            tmp=e->e[i];
        while(tmp->article.id!=NULL){

            if(strstr(tmp->article.contenu,mot)!=NULL || strstr(tmp->article.titre,mot)!=NULL){
                //printf("passage");
                res=insererHT(res,tmp->article);

            }if(tmp->suivant!=NULL)
                tmp=tmp->suivant;
                else
                    break;
        }
    }
    return res;
}
void detruire_bibliothequeHT(EncyclopedieHT * e){
    int i;
    for(i=0;i<e->size;i++){
        detruire_bibliothequeLC(e->e[i]);
    }
    free(e);
}

void afficherHT(EncyclopedieHT * e){
    int i;
    for(i=0;i<e->size;i++){
        afficherLC(e->e[i]);
    }
}

