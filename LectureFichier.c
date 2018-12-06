#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LectureFichier.h"
#include "EncyclopedieLC.h"
#include "EncyclopedieHT.h"
#include "EncyclopedieBST.h"

ptrLC lire_fichier(ptrLC e){
    FILE* fichier = NULL;
    char * str = (char *) calloc(sizeof(char), 2000);
    ptrLC lc= creer_encyclopedieLC();

    fichier = fopen("B46_wikipedia_test.dat", "r+");

    if(fichier){
        fgets(str,2000,fichier);
        int i = 0;
        while(str[i] != '\0')
        {
            i++;

        }
        strtok(str,'|');
        str[i-1] = '\0';
        printf("%s",str);

        insererLC(lc, a);
    }
    else{
        printf("Erreur lecture fichier");
    }
    return e;
}

