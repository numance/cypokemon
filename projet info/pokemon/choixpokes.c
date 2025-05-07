#include "structure.h"
#include "fonction.h"
#include "affichage.h"
#include "choixpokes.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

#define UP    65  
#define DOWN  66  
#define ENTER 10 

int afficherPoke(char* menu[], int tailleMenu, int numpoke, Poke* Pokemon[18]) { // permet afficher liste pokemon ainsi que de voir le pokemon selectionné
    int choix = 0;  
    int touche;
    while (1) { 
        if(numpoke==1) { // affiche un titre diffferent selon le joueur qui choisi son pokemon
            afficherTitrej1_1(); 
        } else if(numpoke==2) {
            afficherTitrej1_2(); 
        } else if(numpoke==3) {
            afficherTitrej1_3();
        } else if(numpoke==4) {
            afficherTitrej2_1();
        } else if(numpoke==5) {
            afficherTitrej2_2();
        } else if(numpoke==6) {
            afficherTitrej2_3();
        }
        for (int i = 0; i < tailleMenu; i++) {
            if (i == choix) {
                printf("                                               > %s <\n", menu[i]); // pour visualiser le pokemon selectionné
            } else {
                printf("                                                %s\n", menu[i]);  // affiche le nom des autres pokemon
            }
        }
        printf("\n%s", Pokemon[choix]->description); // affiche une description du pokemon selectionné
        for(int i=0; i<13 ; i++) {
            printf("\n                     %s", Pokemon[choix]->repgraph[i]); // affiche la rep graphique du pokemon selectionné
        }

        touche = getch(); // prend une touche rentré par utilisateur

        if (touche == '\033') {  
            getch();  
            switch (getch()) {
                case 'A':  
                    if (choix > 0) choix--;  // fleche du bas sauf tout en bas
                    break;
                case 'B':  
                    if (choix < tailleMenu - 1) choix++;  // flechhe du haut sauf tout en haut 
                    break;
            }
        system("clear"); // supprime pour pas que s'affiche a la suite les menus
        } else if (touche == ENTER) { 
            break;
        }
    }

    return choix;  
}


int choixpokeordi_difsimple(int typejoueur) { // donne a l'ordi un pokemon qui a faiblesse face a celle du joueur si possible
    if (typejoueur == 0) { // Normal
        return rand()%3; // Donne poke type normal
    }
    else if (typejoueur == 1) { // Sol
        return rand()%3+9; // donne poke type electrique
    }
    else if (typejoueur == 2) { // Électrique
        return rand()%3+12; // donne poke de type eau
    }
    else if (typejoueur == 3) { // Feu
        return rand()%3+3; // donne poke de type plante
    }
    else if (typejoueur == 4) { // Eau
        return rand()%3+15; // donne poke de type feu
    }
    else if (typejoueur == 5) { // Plante
        return rand()%3+6; // donne poke de type sol

    }
    return 0;
}



int choixpokeordi_difmoyen(int typejoueur) { // donne a l'ordi un pokemon qui a le meme type que celui du joueur si possible
    if (typejoueur == 0) { // Normal
        return rand()%3; // Donne poke type normal
    }
    else if (typejoueur == 1) { // Sol
        return rand()%3+6; // donne poke type sol
    }
    else if (typejoueur == 2) { // Électrique
        return rand()%3+9; // donne poke de type electrique
    }
    else if (typejoueur == 3) { // Feu
        return rand()%3+15; // donne poke de type feu
    }
    else if (typejoueur == 4) { // Eau
        return rand()%3+12; // donne poke de type eau
    }
    else if (typejoueur == 5) { // Plante
        return rand()%3+3; // donne poke de type plante

    }
    return 0;
}


int choixpokeordi_difdifficile(int typejoueur) { // donne a l'ordi un pokemon qui a resistance face a celle du joueur
    if (typejoueur == 0) { // Normal
        return rand()%3; // Donne poke type normal
    }
    else if (typejoueur == 1) { // Sol
        return rand()%3+3; // donne poke type plante
    }
    else if (typejoueur == 2) { // Électrique
        return rand()%3+6; // donne poke de type sol
    }
    else if (typejoueur == 3) { // Feu
        return rand()%3+12; // donne poke de type eau
    }
    else if (typejoueur == 4) { // Eau
        return rand()%3+9; // donne poke de type electrique
    }
    else if (typejoueur == 5) { // Plante
        return rand()%3+15; // donne poke de type feu

    }
    return 0;
}



Poke* copierPokemon(Poke* original) { // copie le joueur de sorte qu'il ne soit pas lier a la structure de base sinon tout la structure changé en cas d'attaque pour j1 et j2
    Poke* copie = malloc(sizeof(Poke));
    if (!copie) {
        perror("Erreur d'allocation de mémoire");
        exit(1);
    }
    // Copier champ par champ
    copie->name = strdup(original->name);
    copie->type = original->type;
    copie->pvmax = original->pvmax;
    copie->pvactuel = original->pvactuel;
    copie->vit = original->vit;
    copie->attmax = original->attmax;
    copie->attactuel = original->attactuel;
    copie->agi = original->agi;
    copie->defmax = original->defmax;
    copie->defactuel = original->defactuel;
    copie->statut= original->statut;

    // Copie du graphisme si besoin
    for (int i = 0; i < 13; i++) {
        copie->repgraph[i] = strdup(original->repgraph[i]);
    }

    // Copie des attaques
    for (int i = 0; i < 4; i++) {
        copie->attaque[i] = malloc(sizeof(Attaque));
        copie->attaque[i]->nom = strdup(original->attaque[i]->nom);
        copie->attaque[i]->degat = original->attaque[i]->degat;
        copie->attaque[i]->reussite = original->attaque[i]->reussite;
        copie->attaque[i]->fonction = original->attaque[i]->fonction;
    }

    // Copie de la description
    copie->description = strdup(original->description);

    copie->attspe = malloc(sizeof(Attaquespecial));
    copie->attspe->nom=strdup(original->attspe->nom);
    copie->attspe->fonction=original->attspe->fonction;
    copie->attspe->effet_spe_tempo=original->attspe->effet_spe_tempo;
    copie->attspe->tempsrecharge=original->attspe->tempsrecharge;
    copie->attspe->tempsrechargeact=original->attspe->tempsrechargeact;

    return copie;
}


Poke** choixpokes(int choixmenu) { //fonction principale
    srand(time(NULL));
    Poke* Pokemon[18];
    int choixordi;
    int choixpoke;


    Poke* pokenul = malloc(sizeof(Pokemon));

    pokenul->name = "Null     "; // creation structure nul pour mettre si 1vs1 ou 2vs2 pour combler equipe
    pokenul->type = 0;
    pokenul->pvmax = 100;
    pokenul->pvactuel = 0;
    pokenul->vit = 0;
    pokenul->attmax = 0;
    pokenul->attactuel = pokenul->attmax;
    pokenul->agi = 0;
    pokenul->defmax = 0;
    pokenul->defactuel = pokenul->defmax;
    pokenul->statut=0;

    char* graphnul[13] = {
        "", "", "", "", "", "", "", "", "", "", "", "", ""
    };

    for (int i = 0; i < 13; i++) {
        pokenul->repgraph[i] = graphnul[i];
    }

    pokenul->description = "null \n";

    for (int i = 0; i < 4; i++) {
        pokenul->attaque[i] = malloc(sizeof(Attaque));
        pokenul->attaque[i]->nom = "null";
        pokenul->attaque[i]->degat = 0;
        pokenul->attaque[i]->reussite = 0;
        pokenul->attaque[i]->fonction = 0;
    }

    pokenul->attspe=malloc(sizeof(Attaquespecial));
    pokenul->attspe->nom="null  ";
    pokenul->attspe->fonction=0;
    pokenul->attspe->effet_spe_tempo=0;
    pokenul->attspe->tempsrecharge=0;
    pokenul->attspe->tempsrechargeact=0;




    for(int i=0; i<18 ; i++) { // remplis liste poke
        Pokemon[i]=listepoke(i);
    }
    char* menu[18] = {"Evoli", "Miaouss", "Porygon","Aspicot","Mystherbe","Bulbizarre","Onix","Taupiqueur","Racaillou","Pikachu","Magneti","Electrode","Carapuce","Psykokwak","Wailmer","Flamiaou","Funecire","Chartor"}; //diferent element du menu
    Poke** joueurs = malloc(sizeof(Poke*) * 6); // alloue 6 espace pour taille des deux equipe max combiné
        for(int i=0 ; i<6 ; i++) {
            joueurs[i] = malloc(sizeof(Poke));
        }
    if (choixmenu==10 || choixmenu==13 || choixmenu==16 || choixmenu==19) { // si choix 1vs1
        if(choixmenu==10) { // pour j vs j
            for(int i=0 ; i<4 ; i++) {
                if (i == 1 || i == 2) continue;
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]=copierPokemon(Pokemon[choixpoke]); 
            }
            joueurs[1]=pokenul;
            joueurs[2]=pokenul;
            joueurs[4]=pokenul;
            joueurs[5]=pokenul;
            return joueurs;
        } else if (choixmenu==13) { // pour j vs ordi simple
            choixpoke = afficherPoke(menu, 18, 1, Pokemon); 
            joueurs[0]=copierPokemon(Pokemon[choixpoke]);
            choixordi=choixpokeordi_difsimple(joueurs[0]->type);
            joueurs[3]=copierPokemon(Pokemon[choixordi]); ;
            joueurs[1]=pokenul;
            joueurs[2]=pokenul;
            joueurs[4]=pokenul;
            joueurs[5]=pokenul;
            return joueurs;
        } else if (choixmenu==16) { //pour j vs ordi moyen
            choixpoke = afficherPoke(menu, 18, 1, Pokemon); 
            joueurs[0]=copierPokemon(Pokemon[choixpoke]); 
            choixordi=choixpokeordi_difmoyen(joueurs[0]->type);
            joueurs[3]=copierPokemon(Pokemon[choixordi]); 
            joueurs[1]=pokenul;
            joueurs[2]=pokenul;
            joueurs[4]=pokenul;
            joueurs[5]=pokenul;
            return joueurs;
        } else if(choixmenu==19) { // pour j vs ordi difficile
            choixpoke = afficherPoke(menu, 18, 1, Pokemon); 
            joueurs[0]=copierPokemon(Pokemon[choixpoke]);  
            choixordi=choixpokeordi_difdifficile(joueurs[0]->type);
            joueurs[3]=copierPokemon(Pokemon[choixordi]); 
            joueurs[1]=pokenul;
            joueurs[2]=pokenul;
            joueurs[4]=pokenul;
            joueurs[5]=pokenul;
            return joueurs;
        }
    } else if (choixmenu==11 || choixmenu==14 || choixmenu==17 || choixmenu==20) { // si choix 2vs2
        if(choixmenu==11) { // si j vs j
            for(int i=0 ; i<5 ; i++) {
                if (i == 2 ) continue;
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]=copierPokemon(Pokemon[choixpoke]);  
            }
            joueurs[2]=pokenul;
            joueurs[5]=pokenul;
            return joueurs;
        } else if (choixmenu==14) { // si j vs ordi simple
            for(int i=0; i<2 ; i++) {
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]=copierPokemon(Pokemon[choixpoke]); 
            }
            for(int j=0; j<2 ; j++) {
                choixordi=choixpokeordi_difsimple(joueurs[j]->type);
                joueurs[j+2]=copierPokemon(Pokemon[choixordi]); 
            }
            joueurs[2]=pokenul;
            joueurs[5]=pokenul;
            return joueurs;
        } else if (choixmenu==17) { // si j vs ordi moyen
            for(int i=0; i<2 ; i++) {
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]=copierPokemon(Pokemon[choixpoke]); 
            }
            for(int j=0; j<2 ; j++) {
                choixordi=choixpokeordi_difmoyen(joueurs[j]->type);
                joueurs[j+2]=copierPokemon(Pokemon[choixordi]); 
            }
            joueurs[2]=pokenul;
            joueurs[5]=pokenul;
            return joueurs;
        } else if(choixmenu==20) { //si j vs ordi difficile
            for(int i=0; i<2 ; i++) {
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]=copierPokemon(Pokemon[choixpoke]); 
            }
            for(int j=0; j<2 ; j++) {
                choixordi=choixpokeordi_difdifficile(joueurs[j]->type);
                joueurs[j+2]=copierPokemon(Pokemon[choixordi]); 
            }
            joueurs[2]=pokenul;
            joueurs[5]=pokenul;
            return joueurs;
        }
    } else { // si choix 3vs3
        if(choixmenu==12) { // si j vs j
            for(int i=0 ; i<6 ; i++) {
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]=copierPokemon(Pokemon[choixpoke]); 
            }
            return joueurs;
        } else if (choixmenu==15) { // si j vs ordi simple
            for(int i=0; i<3 ; i++) {
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]=copierPokemon(Pokemon[choixpoke]);  
            }
            for(int j=0; j<3 ; j++) {
                choixordi=choixpokeordi_difsimple(joueurs[j]->type);
                joueurs[j+3]=copierPokemon(Pokemon[choixordi]); 
            }
            return joueurs;
        } else if (choixmenu==18) { // si j vs ordi moyen
            for(int i=0; i<3 ; i++) {
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]= copierPokemon(Pokemon[choixpoke]); 
            }
            for(int j=0; j<3 ; j++) {
                choixordi=choixpokeordi_difmoyen(joueurs[j]->type);
                joueurs[j+3]= copierPokemon(Pokemon[choixordi]); 
            }
            return joueurs;
        } else if(choixmenu==21) { // si j vs ordi difficile
            for(int i=0; i<3 ; i++) {
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]=copierPokemon(Pokemon[choixpoke]); 
            }
            for(int j=0; j<3 ; j++) {
                choixordi=choixpokeordi_difdifficile(joueurs[j]->type);
                joueurs[j+3]=copierPokemon(Pokemon[choixordi]); 
            }
            return joueurs;
        }
    }
    system("clear");
    return NULL;
}