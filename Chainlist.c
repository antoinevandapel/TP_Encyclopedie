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
    if(e->article==NULL){
        e->article = a;
    }
    else if(e->right!=NULL){
        e=inserer(e->right, a);
    }
    else{
        e->right=(Encyclopedie *) malloc(sizeof(Encyclopedie));
        e->right->article=a;
    }
    return e;
}

