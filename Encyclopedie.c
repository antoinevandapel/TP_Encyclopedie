#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Article Article;
struct Article
{
    int id;
    string titre;
    string contenu;
};

typedef struct Encyclopedie Encyclopedie;
struct Encyclopedie
{
    Article article;
    Encyclopedie * up;
    Encyclopedie * left;
    Encyclopedie * right;
};
