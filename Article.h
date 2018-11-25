#ifndef ENCYCLOPEDIE_H_INCLUDED
#define ENCYCLOPEDIE_H_INCLUDED

typedef struct Article Article;
struct Article
{
    int id;
    char * titre;
    char * contenu;
};

#endif // ENCYCLOPEDIE_H_INCLUDED
