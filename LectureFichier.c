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


    char str[80000];

    if(fichier){
        char * element;
        char * titreArticle;
        char * contenuArticle;
        int idArticle = 0;
        int i;
        int comptLigne=0;
        while((fgets(str,tailleAllou[comptLigne],fichier)!=NULL)&&(comptLigne<=20)){
            /*titreArticle = (char *) calloc(sizeof(char), 25);
            contenuArticle = (char *) calloc(sizeof(char), 50000);*/
            element = strtok(str,"|");
            //printf("tailleAllou : %d\n",tailleAllou[comptLigne]);
            //printf("%s\n",element);

            Article * a = (Article*)malloc(sizeof(Article));

            a->id=atoi(element);

            while(element!=NULL){
                if(i==1){
                    a->titre=(char *) malloc((sizeof(char)*strlen(element))+1);
                    strcpy(a->titre,element);
                }
                else{
                    a->contenu=(char *) malloc((sizeof(char)*strlen(element))+1);
                    strcpy(a->contenu,element);
                }
                i++;
                element = strtok(NULL,"|");
            }

           /*a->id=idArticle;
            a->titre = titreArticle;
            a->contenu = contenuArticle;
*/
            lc = insererLC(lc,*a);
            a=NULL;
            comptLigne++;
            i=0;
        }
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

