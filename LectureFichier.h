//#include "LectureFichier.c"
#include "EncyclopedieLC.h"
#include "EncyclopedieHT.h"
#include "EncyclopedieBST.h"

#ifndef LECTUREFICHIER_H_INCLUDED
#define LECTUREFICHIER_H_INCLUDED

ptrLC lire_fichierLC(char * nomFichier);
EncyclopedieBST * lire_fichierBST(char * nomFichier);
EncyclopedieHT * lire_fichierHT(char * nomFichier);
int * compteurLigne(char * nomFichier);

#endif // LECTUREFICHIER_H_INCLUDED
