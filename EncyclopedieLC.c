#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EncyclopedieLC.h"

ptrLC creer_encyclopedieLC(){
    ptrLC e = (ptrLC) malloc(sizeof(EncyclopedieLC));
    e->article.id=NULL;
    e->article.contenu=NULL;
    e->article.titre=NULL;
    e->suivant=NULL;
    return e;
}

ptrLC insererLC(ptrLC e, Article a){
    ptrLC tmp;
    if(e->article.id==NULL){
        e->article = a;
        e->suivant=NULL;
    }
    else if(e->suivant!=NULL){
        tmp=insererLC(e->suivant, a);
    }
    else{
        e->suivant=(ptrLC) malloc(sizeof(EncyclopedieLC));
        e->suivant->article=a;
        e->suivant->suivant=NULL;
    }
    return e;
}

ptrLC supprimerLC(ptrLC e, int id){
    ptrLC tmp;
    if(e->article.id==id){
        printf("trouvé en 1");
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

char * rechercher_articleLC(ptrLC e, int id){
    Article tmp;
    //printf("passage");
    if(e->article.id==id){
        tmp=e->article;
    }
    else if(e->suivant!=NULL){
        tmp.contenu=rechercher_articleLC(e->suivant,id);
    }

    return tmp.contenu;
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
    printf("\n---- Article n%d----",e->article.id);
    printf("\nTitre : %s",e->article.titre);
    printf("\nContenu : %s\n",e->article.contenu);

    if(e->suivant!=NULL){
        e=e->suivant;
        afficherLC(e);
    }
}
