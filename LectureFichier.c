#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LectureFichier.h"
#include "EncyclopedieLC.h"
#include "EncyclopedieHT.h"
#include "EncyclopedieBST.h"

ptrLC lire_fichier(){
    FILE* fichier = NULL;
    ptrLC lc= creer_encyclopedieLC();
    int * tailleAllou;
    char * nomFichier = "B46_wikipedia_test.dat";

    fichier = fopen(nomFichier, "r");
    tailleAllou = compteurLigne(nomFichier);


    char str[120000];

    if(fichier){
        char * element;
        char * titreArticle;
        char * contenuArticle;
        int idArticle = 0;
        int i;
        int comptLigne=0;
        while((fgets(str,120000,fichier)!=NULL)){
            //printf("%s", str);
            /*titreArticle = (char *) calloc(sizeof(char), 25);
            contenuArticle = (char *) calloc(sizeof(char), 50000);*/
            //printf("tailleAllou : %d\n",tailleAllou[comptLigne]);
            //printf("%s\n",element);

            Article * a = (Article*)malloc(sizeof(Article));
            a->id=atoi(strtok(str,"|"));
            printf("strtok id : %d\n", a->id);
            i=0;
                //element = strtok(NULL,"|");

                    //a->titre=(char *) malloc((sizeof(char)*strlen(element))+1);
                    //strcpy(a->titre,element);
                    titreArticle=strtok(NULL,"|");
                    a->titre = (char*) malloc(sizeof(char)*strlen(titreArticle)+1);
                    strcpy(a->titre, titreArticle);
                    printf("strtok titre : %s\n", a->titre);

                    //a->contenu=(char *) malloc((sizeof(char)*strlen(element))+1);
                    //strcpy(a->contenu,element);
                    contenuArticle=strtok(NULL,"|");
                    a->contenu = (char*) malloc(sizeof(char)*strlen(contenuArticle)+1);
                    strcpy(a->contenu, contenuArticle);
                    printf("strtok contenu : %s\n", a->contenu);


           /*a->id=idArticle;
            a->titre = titreArticle;
            a->contenu = contenuArticle;
*/
            lc = insererLC(lc,*a);
            a=NULL;
            comptLigne++;
            i=0;
        }
        printf("\n%d\n",comptLigne);
        //insererLC(lc, a);
    }
    else{
        printf("Erreur lecture fichier");
    }
    close(fichier);
    return lc;
}

int * compteurLigne(char * nomfichier){
    FILE* fichier = NULL;
    int * tabTaille=(int *)malloc(sizeof(int)*600);
    int * tmp = tabTaille;
    int nbLignes=0;
    int cpt=0;
    int car;
    fichier = fopen(nomfichier, "r");
    if(!fichier){
        printf("Erreur ouverture fichier\n");
    }
    else{
        do{
            car=fgetc(fichier);
            cpt++;
            //printf("%c", car);
            if(car=='\n'){
                //printf("\n%d", nbLignes);
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

        //printf("nb lignes : %d", nbLignes);
        fclose(fichier);
        return tabTaille;
    }
}

