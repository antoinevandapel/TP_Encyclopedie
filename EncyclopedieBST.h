#ifndef ENCYCLOPEDIEBST_H_INCLUDED
#define ENCYCLOPEDIEBST_H_INCLUDED

#include "Article.h"

typedef struct EncyclopedieBST EncyclopedieBST;
struct EncyclopedieBST
{
    Article article;
    EncyclopedieBST * left;
    EncyclopedieBST * right;
};

EncyclopedieBST * creer_encyclopedieBST();
EncyclopedieBST * insererBST(EncyclopedieBST * e, Article a);
EncyclopedieBST * supprimerBST(EncyclopedieBST * e, int id);
Article rechercher_articleBST(EncyclopedieBST * e, int id);
EncyclopedieBST * rechercher_article_plein_texteBST(EncyclopedieBST * e, EncyclopedieBST * res, char * mot);
void detruire_bibliothequeBST(EncyclopedieBST * e);
void afficherBST(EncyclopedieBST * e);

#endif // ENCYCLOPEDIE_H_INCLUDED
