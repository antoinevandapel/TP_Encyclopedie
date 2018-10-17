#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
