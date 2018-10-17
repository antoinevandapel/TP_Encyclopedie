#ifndef ENCYCLOPEDIE_H_INCLUDED
#define ENCYCLOPEDIE_H_INCLUDED
#include "Encyclopedie.c"

Encyclopedie * creer_encyclopedie();
Encyclopedie * inserer(Encyclopedie * e, Article * a);
Encyclopedie * supprimer(Encyclopedie * e, int id);
char * rechercher_article(Encyclopedie * e, int id);
Encyclopedie * rechercher_article_plein_texte(Encyclopedie * e, char * mot);
void detruire_bibliotheque(Encyclopedie * e);

#endif // ENCYCLOPEDIE_H_INCLUDED
