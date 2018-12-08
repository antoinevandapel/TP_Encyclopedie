#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EncyclopedieLC.h"

ptrLC creer_encyclopedieLC(){
    ptrLC e = (ptrLC) malloc(sizeof(EncyclopedieLC));
    e->article.id=-1;
    e->suivant=NULL;
    return e;
}

ptrLC insererLC(ptrLC e, Article a){
    ptrLC tmp = creer_encyclopedieLC();

    tmp->article = a;

    if(e->article.id==-1){
        tmp->suivant = NULL;
    }
    else{
        tmp->suivant=e;
    }

    return tmp;
}

ptrLC supprimerLC(ptrLC e, int id){
    ptrLC tmp;
    if(e->article.id==id){
        printf("trouvé en 1\n");
        tmp=e->suivant;
        free(e);
        e=tmp;
    }
    if(e->suivant!=NULL){
        if(e->suivant->article.id==id){
            tmp=e->suivant->suivant;
            free(e->suivant);
            e->suivant=tmp;
        }
        else{
            tmp=supprimerLC(e->suivant, id);
        }
    }

    return e;
}

Article rechercher_articleLC(ptrLC e, int id){
    Article tmp;
    tmp.contenu="";
    tmp.titre="";
    tmp.id=-1;
    //printf("passage");
    if(e->article.id==id){
        tmp=e->article;
    }
    else if(e->suivant!=NULL){
        tmp=rechercher_articleLC(e->suivant,id);
    }

    return tmp;
}

ptrLC rechercher_article_plein_texteLC(ptrLC e, char * mot){
    ptrLC tmp = e;
    ptrLC res = creer_encyclopedieLC();
    while(tmp->article.id!=NULL){

        if(strstr(tmp->article.contenu,mot)!=NULL){
            //printf("passage");
            res=insererLC(res,tmp->article);

        }if(tmp->suivant!=NULL)
            tmp=tmp->suivant;
            else
                break;
    }
    //printf("res : %d",res->article->id);
    return res;
}

void detruire_bibliothequeLC(ptrLC e){
    if(e->suivant!=NULL)
        detruire_bibliothequeLC(e->suivant);
    free(e);
}

void afficherLC(ptrLC e){
    if(e->article.id!=-1){
    printf("\n---- Article %d----",e->article.id);
    printf("\nTitre : %s",e->article.titre);
    printf("\nContenu : %s\n",e->article.contenu);
    }

    if(e->suivant!=NULL){
        e=e->suivant;
        afficherLC(e);
    }
}
