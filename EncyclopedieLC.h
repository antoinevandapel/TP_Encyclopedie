#ifndef ENCYCLOPEDIELC_H_INCLUDED
#define ENCYCLOPEDIELC_H_INCLUDED

#include "Article.h"

typedef struct EncyclopedieLC
{
    Article article;
    struct EncyclopedieLC * suivant;
} EncyclopedieLC, *ptrLC;

ptrLC creer_encyclopedieLC();
ptrLC insererLC(ptrLC e, Article a);
ptrLC supprimerLC(ptrLC e, int id);
char * rechercher_articleLC(ptrLC e, int id);
ptrLC rechercher_article_plein_texteLC(ptrLC e, char * mot);
void detruire_bibliothequeLC(ptrLC e);
void afficherLC(ptrLC e);

#endif // ENCYCLOPEDIE_LC_INCLUDED
