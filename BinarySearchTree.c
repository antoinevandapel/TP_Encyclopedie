#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Encyclopedie.h"

Encyclopedie * creer_encyclopedie(){
    Encyclopedie * e = (Encyclopedie *) malloc(sizeof(Encyclopedie));
    e->article.id=-1;
    e->left=NULL;
    e->right=NULL;

    return e;
}


Encyclopedie * inserer(Encyclopedie *e, Article a)
{

    if(e == NULL)
    {
        e = creer_encyclopedie();
        e->article=a;
        //printf("ID :%d\n", e->article.id);
    }
    else
    {
        int is_left  = 0;
        int r        = 0;
        Encyclopedie* curseur = e;
        Encyclopedie* prev   = NULL;

        while(curseur != NULL)
        {
            //Compare id article par rapport a celui du curseur
            if(a.id>curseur->article.id) r=1;
            else if(a.id<curseur->article.id) r=-1;
            else {
                return e;
            }
            prev = curseur;
            if(r < 0)
            {
                is_left = 1;
                curseur = curseur->left;
            }
            else if(r > 0)
            {
                is_left = 0;
                curseur = curseur->right;
            }

        }
        if(is_left){
            prev->left = creer_encyclopedie();
            prev->left->article = a;
        }
        else{
            prev->right = creer_encyclopedie();
            prev->right->article = a;
        }

    }
    return e;
}

Encyclopedie * supprimer(Encyclopedie* e, int id)
{
    if(e == NULL)
        return;

    Encyclopedie *cursor;
    int r;
    if(e->article.id<id) r=-1;
    else if(e->article.id>id) r=1;
    else r=0;

    if( r < 0)
        e->left = supprimer( e->left, id);
    else if( r > 0 )
        e->right = supprimer(e->right,id);
    else
    {
        if (e->left == NULL)
        {
            cursor = e->right;
            free(e);
            e = cursor;
        }
        else if (e->right == NULL)
        {
            cursor = e->left;
            free(e);
            e = cursor;
        }
        else    //2 children
        {
            cursor = e->right;
            Encyclopedie *parent = NULL;

            while(cursor->left != NULL)
            {
                parent = cursor;
                cursor = cursor->left;
            }
            e->article = cursor->article;
            if (parent != NULL)
                parent->left = supprimer(parent->left, parent->left->article.id);
            else
                e->right = supprimer(e->right, e->right->article.id);
        }
    }
    return e;
}

Article rechercher_article(Encyclopedie *e ,int id)
{
    if(e == NULL)
        return;

    int r;
    Encyclopedie* cursor = e;
    while(cursor != NULL)
    {
        if(cursor->article.id<id) r=1;
        else if(cursor->article.id>id) r=-1;
        else r=0;

        if(r < 0)
            cursor = cursor->left;
        else if(r > 0)
            cursor = cursor->right;
        else
            return cursor->article;
    }
    return cursor->article;

}

void afficher(Encyclopedie* e)
{
    if (e == NULL)
        return;
    /* display node data */
    printf("%d - %s",e->article.id, e->article.titre);
    if(e->left != NULL)
        printf("(L:%d - %s)",e->left->article.id, e->left->article.titre);
    if(e->right != NULL)
        printf("(R:%d - %s)",e->right->article.id, e->right->article.titre);
    printf("\n");

    afficher(e->left);
    afficher(e->right);
}

void detruire_bibliotheque(Encyclopedie* e)
{
    if(e != NULL)
    {
        detruire_bibliotheque(e->left);
        detruire_bibliotheque(e->right);
        free(e);
    }
}

Encyclopedie * rechercher_article_plein_texte(Encyclopedie * e, Encyclopedie * res, char * mot){
    if(strstr(e->article.titre, mot) || strstr(e->article.contenu, mot)) res = inserer(res, e->article);
    if(e->left!=NULL) rechercher_article_plein_texte(e->left,res,mot);
    if(e->right!=NULL) rechercher_article_plein_texte(e->right,res,mot);
    return res;
}
