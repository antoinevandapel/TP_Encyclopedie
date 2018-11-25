#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EncyclopedieBST.h"

EncyclopedieBST * creer_encyclopedieBST(){
    EncyclopedieBST * e = (EncyclopedieBST *) malloc(sizeof(EncyclopedieBST));
    e->article.id=-1;
    e->left=NULL;
    e->right=NULL;

    return e;
}


EncyclopedieBST * insererBST(EncyclopedieBST *e, Article a)
{

    if(e == NULL)
    {
        e = creer_encyclopedieBST();
        e->article=a;
        //printf("ID :%d\n", e->article.id);
    }
    else
    {
        int is_left  = 0;
        int r        = 0;
        EncyclopedieBST* curseur = e;
        EncyclopedieBST* prev   = NULL;

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
            prev->left = creer_encyclopedieBST();
            prev->left->article = a;
        }
        else{
            prev->right = creer_encyclopedieBST();
            prev->right->article = a;
        }

    }
    return e;
}

EncyclopedieBST * supprimerBST(EncyclopedieBST* e, int id)
{
    if(e == NULL)
        return;

    EncyclopedieBST *cursor;
    int r;
    if(e->article.id<id) r=-1;
    else if(e->article.id>id) r=1;
    else r=0;

    if( r < 0)
        e->left = supprimerBST( e->left, id);
    else if( r > 0 )
        e->right = supprimerBST(e->right,id);
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
            EncyclopedieBST *parent = NULL;

            while(cursor->left != NULL)
            {
                parent = cursor;
                cursor = cursor->left;
            }
            e->article = cursor->article;
            if (parent != NULL)
                parent->left = supprimerBST(parent->left, parent->left->article.id);
            else
                e->right = supprimerBST(e->right, e->right->article.id);
        }
    }
    return e;
}

Article rechercher_articleBST(EncyclopedieBST *e ,int id)
{
    if(e == NULL)
        return;

    int r;
    EncyclopedieBST* cursor = e;
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

void afficherBST(EncyclopedieBST* e)
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

    afficherBST(e->left);
    afficherBST(e->right);
}

void detruire_bibliothequeBST(EncyclopedieBST* e)
{
    if(e != NULL)
    {
        detruire_bibliothequeBST(e->left);
        detruire_bibliothequeBST(e->right);
        free(e);
    }
}

EncyclopedieBST * rechercher_article_plein_texteBST(EncyclopedieBST * e, EncyclopedieBST * res, char * mot){
    if(strstr(e->article.titre, mot) || strstr(e->article.contenu, mot)) res = insererBST(res, e->article);
    if(e->left!=NULL) rechercher_article_plein_texteBST(e->left,res,mot);
    if(e->right!=NULL) rechercher_article_plein_texteBST(e->right,res,mot);
    return res;
}
