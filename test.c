#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LectureFichier.h"
#include "EncyclopedieLC.h"
#include "EncyclopedieHT.h"
#include "EncyclopedieBST.h"

ptrLC lire_fichie(ptrLC e){
    FILE* fichier = NULL;
    int * tabTaille=(int *)malloc(sizeof(int)*500);
    int * tmp = tabTaille;
    int nbLignes=0;
    int cpt=0;
    int car;
    fichier = fopen("B46_wikipedia_test.dat", "r");
    if(!fichier){
        printf("Erreur\n");
    }
    else{
        do{
            car=fgetc(fichier);
            cpt++;
            //printf("%c", car);
            if(car=='\n'){
                printf("\n%d", nbLignes);
                *tmp=cpt;
                tmp++;
                nbLignes++;
                cpt=0;
            }
        }while(car!= EOF);
        /*
        int i;
        for(i=0;i<500;i++){
            printf("%d\n", tabTaille[i]);
        }
        */

        printf("nb lignes : %d", nbLignes);

    }

    /*
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
    */
    fclose(fichier);
    return e;
}

