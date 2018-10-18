#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encyclopedie.h"

Encyclopedie * creer_encyclopedie(){
    Encyclopedie * e = (Encyclopedie *) malloc(sizeof(Encyclopedie));
    e->article=NULL;
    e->left=NULL;
    e->right=NULL;
    e->up=NULL;
    return e;
}

Encyclopedie * inserer(Encyclopedie * e, Article * a){
    Encyclopedie * tmp;
    if(e->article==NULL){
        e->article = a;
    }
    else if(e->right!=NULL){
        tmp=inserer(e->right, a);
    }
    else{
        e->right=(Encyclopedie *) malloc(sizeof(Encyclopedie));
        e->right->article=a;
    }
    return e;
}

Encyclopedie * supprimer(Encyclopedie * e, int id){
    Encyclopedie * tmp;
    if(e->right!=NULL){
        if(e->right->article->id==id){
            tmp=e->right->right;
            free(e->right);
            e->right=tmp;
        }
        else{
            tmp=supprimer(e->right, id);
        }
    }

    return e;
}

char * rechercher_article(Encyclopedie * e, int id){
    char * tmp="";
    //printf("passage");
    if(e->article->id==id){
        tmp=  e->article->contenu;
    }
    else if(e->right!=NULL){
        tmp=rechercher_article(e->right,id);
    }

    return tmp;
}

Encyclopedie * rechercher_article_plein_texte(Encyclopedie * e, char * mot){
    Encyclopedie * tmp = e;
    Encyclopedie * res = creer_encyclopedie();
    while(tmp->article!=NULL){

        if(strstr(tmp->article->contenu,mot)!=NULL){
            //printf("passage");
            res=inserer(res,tmp->article);

        }if(tmp->right!=NULL)
            tmp=tmp->right;
            else
                break;
    }
    //printf("res : %d",res->article->id);
    return res;
}

void detruire_bibliotheque(Encyclopedie * e){
    if(e->right!=NULL)
        detruire_bibliotheque(e->right);
    free(e);
}

void afficher(Encyclopedie * e){
    printf("\n---- Article n%d----",e->article->id);
    printf("\nTitre : %s",e->article->titre);
    printf("\nContenu : %s\n",e->article->contenu);

    if(e->right!=NULL){
        e=e->right;
        afficher(e);
    }
}
