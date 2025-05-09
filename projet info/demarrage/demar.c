#include "../pokemon/fonction.h"
#include "../pokemon/affichage.h"
#include "../pokemon/structure.h"
#include "demar.h"



int afficherMenu(char* menu[], int menu_n) { //permet de se deplacer dans le menu pour choisir notre choix
    int choix = 0;  //l'option sélectionnée à la base
    int touche;
    int tailleMenu=0;
    while(menu[tailleMenu]!=NULL) {
        tailleMenu+=1;
    }
    while (1) { //boucle infini tant que touche diferent de entrée
        system("clear");
        if(menu_n==0) { // affiche le menu voulu en fonction de menu_n
            afficherMenu0();
        } else if(menu_n==1) {
            afficherMenu1();
        } else if(menu_n==2) {
            afficherMenu2();
        } else if(menu_n==3) {
            afficherMenu3();
        }
        printf("\n\n\n");
        for (int i = 0; i < tailleMenu; i++) {
            if (i == choix) {
                printf("                                               > %s <\n\n", menu[i]); //option selectionnés
            } else {
                printf("                                                %s\n\n", menu[i]);  // Autres options
            }
        }

        touche = getch(); // Lire la touche

        if (touche == '\033') {  // Si c'est une touche correspondant a une fleche
            getch();  // Ignore le second caractère
            switch (getch()) {
                case 'A':  // pour la flèche du haut \033[A
                    if (choix > 0) choix--;  // Déplacer vers le haut sauf si tout en haut
                    break;
                case 'B':  // pour la flèche du bas \033[B
                    if (choix < tailleMenu - 1) choix++;  // Déplacer vers le bas sauf si tout en bas
                    break;
            }
        } else if (touche == ENTER) {  // Si appuie sur entrée met fin a la boucle
            break;
        }
    }

    return choix;  // Retourner l'option sélectionnée
}



int menu() { //fonction principale
    
    system("clear");
    char* menus[4][5] = { // les différents menu de l'accueil
    {"Jouer", "Aide/Info", "Quitter", NULL},        
    {"Joueur vs Joueur", "Joueur vs Ordinateur","Retour", NULL},                  
    {"Simple", "Moyen","Difficile","Retour", NULL},  
    {"1 VS 1", "2 VS 2","3 VS 3","Retour", NULL},  
    };
    int choix=0;
    int choix_x=0;
    while(1) {
        if(choix==0) {
            choix_x=afficherMenu(menus[0], 0); // afiche le 1er menu
            if(choix_x==0) {
                choix=2; // lance choix mode
            } else if(choix_x==1) {
                choix=1; // lance aide
            } else {
                return 0; // quitte programme
            }
        } else if(choix==1) { // affiche aide
            aide();
            choix=0; // retourne menu principal
        } else if(choix==2) { 
            choix_x=afficherMenu(menus[1], 1); // afiche 2eme menu
            if(choix_x==0) {
                choix=10; // pour j vs j compris entre 10 et 12 
            } else if(choix_x==1) {
                choix=3; // lance choix difficulte pour j vs ordi
            } else {
                choix=0; // retourne 1er menu
            }
        } else if(choix==3) {
            choix_x=afficherMenu(menus[2], 2); // affiche 3eme menu
            if(choix_x==0) {
                choix=13; // pour j vs ordi simple compris entre 13 et 15
            } else if(choix_x==1) {
                choix=16; // pour j vs ordi moyen compris entre 16 et 18
            } else if(choix_x==2) {
                choix=19; // pour j vs ordi difficile compris entre 19 et 21
            } else {
                choix=2; // retourne 2eme menu
            }
        } else if(choix==10 || choix==13 || choix==16 || choix==19) { // plus qu' a choisir le nombre de poke par equipe
            choix_x=afficherMenu(menus[3], 3); // afiche le dernier menu
            if(choix_x==0) {
                system("clear");
                return choix; // pour 1vs1 conserve le nombre
            } else if(choix_x==1) {
                system("clear");
                return choix+=1; // pour 2vs2 conserve et ajoute 1
            } else if(choix_x==2) {
                system("clear");
                return choix+=2; // pour 3vs3 conserve et ajoute 2
            } else {
                if(choix==10) { // si avant dans choix j vs ordi ou j vs j
                    choix=2; // retourne a choix mode
                } else { // si avant dans choix difficulté
                    choix=3; // retourne a choix difficulté
                }
            }
        }
    }
    return 0;
}