#ifndef ENCYCLOPEDIE_H_INCLUDED
#define ENCYCLOPEDIE_H_INCLUDED

typedef struct Article Article;
struct Article
{
    int id;
    char * titre;
    char * contenu;
};

typedef struct Encyclopedie Encyclopedie;
struct Encyclopedie
{
    Article article;
    Encyclopedie * up;
    Encyclopedie * left;
    Encyclopedie * right;
};

Encyclopedie * creer_encyclopedie();
Encyclopedie * inserer(Encyclopedie * e, Article a);
Encyclopedie * supprimer(Encyclopedie * e, int id);
Article rechercher_article(Encyclopedie * e, int id);
Encyclopedie * rechercher_article_plein_texte(Encyclopedie * e, Encyclopedie * res, char * mot);
void detruire_bibliotheque(Encyclopedie * e);
void afficher(Encyclopedie * e);

#endif // ENCYCLOPEDIE_H_INCLUDED
