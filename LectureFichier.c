#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LectureFichier.h"
#include "EncyclopedieLC.h"
#include "EncyclopedieHT.h"
#include "EncyclopedieBST.h"

ptrLC lire_fichierLC(char * nomFichier){
    FILE* fichier = NULL;
    ptrLC lc= creer_encyclopedieLC();
    int * tailleAllou;
    fichier = fopen(nomFichier, "r");
    if(nomFichier=="B46_wikipedia_test.dat"){
        tailleAllou = compteurLigne(nomFichier);
    }

    char str[800000];

    if(fichier){
        char * element;
        char * titreArticle;
        char * contenuArticle;
        int idArticle = 0;
        int i;
        int comptLigne=0;
        while((fgets(str,800000,fichier)!=NULL)){

            Article * a = (Article*)malloc(sizeof(Article));
            a->id=atoi(strtok(str,"|"));
            i=0;
                //element = strtok(NULL,"|");

                    //a->titre=(char *) malloc((sizeof(char)*strlen(element))+1);
                    //strcpy(a->titre,element);
                    titreArticle=strtok(NULL,"|");
                    a->titre = (char*) malloc(sizeof(char)*strlen(titreArticle)+1);
                    strcpy(a->titre, titreArticle);

                    //a->contenu=(char *) malloc((sizeof(char)*strlen(element))+1);
                    //strcpy(a->contenu,element);
                    contenuArticle=strtok(NULL,"|");
                    a->contenu = (char*) malloc(sizeof(char)*strlen(contenuArticle)+1);
                    strcpy(a->contenu, contenuArticle);


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

EncyclopedieBST * lire_fichierBST(char * nomFichier){
    FILE* fichier = NULL;
    EncyclopedieBST * bst= creer_encyclopedieBST();
    int * tailleAllou;

    fichier = fopen(nomFichier, "r");
    if(nomFichier=="B46_wikipedia_test.dat"){
        tailleAllou = compteurLigne(nomFichier);
    }


    char str[800000];

    if(fichier){
        char * element;
        char * titreArticle;
        char * contenuArticle;
        int idArticle = 0;
        int i;
        int comptLigne=0;
        while((fgets(str,800000,fichier)!=NULL)){
            Article * a = (Article*)malloc(sizeof(Article));
            a->id=atoi(strtok(str,"|"));
            i=0;

            titreArticle=strtok(NULL,"|");
            a->titre = (char*) malloc(sizeof(char)*strlen(titreArticle)+1);
            strcpy(a->titre, titreArticle);

            contenuArticle=strtok(NULL,"|");
            a->contenu = (char*) malloc(sizeof(char)*strlen(contenuArticle)+1);
            strcpy(a->contenu, contenuArticle);

            bst = insererBST(bst,*a);
            a=NULL;
            comptLigne++;
            i=0;
        }
    }
    else{
        printf("Erreur lecture fichier");
    }
    close(fichier);
    return bst;
}

EncyclopedieHT * lire_fichierHT(char * nomFichier){
    FILE* fichier = NULL;
    EncyclopedieHT * ht= creer_encyclopedieHT(10);
    int * tailleAllou;

    fichier = fopen(nomFichier, "r");
    if(nomFichier=="B46_wikipedia_test.dat"){
        tailleAllou = compteurLigne(nomFichier);
    }


    char str[800000];

    if(fichier){
        char * element;
        char * titreArticle;
        char * contenuArticle;
        int idArticle = 0;
        int i;
        int comptLigne=0;
        while((fgets(str,800000,fichier)!=NULL)){
            Article * a = (Article*)malloc(sizeof(Article));
            a->id=atoi(strtok(str,"|"));
            i=0;

            titreArticle=strtok(NULL,"|");
            a->titre = (char*) malloc(sizeof(char)*strlen(titreArticle)+1);
            strcpy(a->titre, titreArticle);

            contenuArticle=strtok(NULL,"|");
            a->contenu = (char*) malloc(sizeof(char)*strlen(contenuArticle)+1);
            strcpy(a->contenu, contenuArticle);

            ht = insererHT(ht,*a);
            a=NULL;
            comptLigne++;
            i=0;
        }
    }
    else{
        printf("Erreur lecture fichier");
    }
    close(fichier);
    return ht;
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
            if(car=='\n'){
                *tmp=cpt;
                tmp++;
                nbLignes++;
                cpt=0;
            }
        }while(car!= EOF);

        fclose(fichier);
        return tabTaille;
    }
}

