#ifndef ENCYCLOPEDIEHT_H_INCLUDED
#define ENCYCLOPEDIEHT_H_INCLUDED
#include "EncyclopedieLC.h"

typedef struct EncyclopedieHT EncyclopedieHT;
struct EncyclopedieHT
{
    EncyclopedieLC ** e;
    int size;
};

EncyclopedieHT * creer_encyclopedieHT(int size);
EncyclopedieHT * insererHT(EncyclopedieHT * e, Article a);
EncyclopedieHT * supprimerHT(EncyclopedieHT * e, int id);
Article rechercher_articleHT(EncyclopedieHT * e, int id);
EncyclopedieHT * rechercher_article_plein_texteHT(EncyclopedieHT * e, EncyclopedieHT * res, char * mot);
void detruire_bibliothequeHT(EncyclopedieHT * e);
void afficherHT(EncyclopedieHT * e);


#endif // ENCYCLOPEDIEHT_H_INCLUDED
