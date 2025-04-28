#include "listepoke.c"
#include "fonction.h"
#include "affichage.h"

int afficherPoke(char* menu[], int tailleMenu, int numpoke, Poke* Pokemon[18]) { 
    int choix = 0;  
    int touche;
    while (1) { 
        if(numpoke==1) {
            afficherTitrej1_1(); // affichage choix j1 si c'est a lui de choisir
        } else if(numpoke==2) {
            afficherTitrej1_2(); // affichage j2 sii c est a lui e choisir
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
                printf("                                               > %s <\n", menu[i]);
            } else {
                printf("                                                %s\n", menu[i]);  
            }
        }
        printf("\n%s", Pokemon[choix]->description);
        for(int i=0; i<13 ; i++) {
            printf("\n                     %s", Pokemon[choix]->repgraph[i]);
        }

        touche = getch(); 

        if (touche == '\033') {  
            getch();  
            switch (getch()) {
                case 'A':  
                    if (choix > 0) choix--;  
                    break;
                case 'B':  
                    if (choix < tailleMenu - 1) choix++;  
                    break;
            }
        system("clear");
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



Poke* copierPokemon(Poke* original) {
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

    return copie;
}


Poke** choixpokes(int choixmenu) { //fonction principale
    srand(time(NULL));
    Poke* Pokemon[18];
    int choixordi;
    int choixpoke;


    Poke* pokenul = malloc(sizeof(Pokemon));

    pokenul->name = "Null     ";
    pokenul->type = 0;
    pokenul->pvmax = 100;
    pokenul->pvactuel = 0;
    pokenul->vit = 0;
    pokenul->attmax = 0;
    pokenul->attactuel = pokenul->attmax;
    pokenul->agi = 0;
    pokenul->defmax = 0;
    pokenul->defactuel = pokenul->defmax;

    // Graphique du Pokémon
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








    for(int i=0; i<18 ; i++) {
        Pokemon[i]=listepoke(i);
    }
    char* menu[18] = {"Evoli", "Miaouss", "Porygon","Aspicot","Mystherbe","Bbulbizarre","Onix","Taupiqueur","Racaillou","Pikachu","Magneti","Electrode","Carapuce","Psykokwak","Wailmer","Flamiaou","Funecire","Chartor"}; //diferent element du menu
    Poke** joueurs = malloc(sizeof(Poke*) * 6);
        for(int i=0 ; i<6 ; i++) {
            joueurs[i] = malloc(sizeof(Poke));
        }
    if (choixmenu==10 || choixmenu==13 || choixmenu==16 || choixmenu==19) {
        if(choixmenu==10) {
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
        } else if (choixmenu==13) {
            choixpoke = afficherPoke(menu, 18, 1, Pokemon); 
            joueurs[0]=copierPokemon(Pokemon[choixpoke]);
            choixordi=choixpokeordi_difsimple(joueurs[0]->type);
            joueurs[3]=copierPokemon(Pokemon[choixordi]); ;
            joueurs[1]=pokenul;
            joueurs[2]=pokenul;
            joueurs[4]=pokenul;
            joueurs[5]=pokenul;
            return joueurs;
        } else if (choixmenu==16) {
            choixpoke = afficherPoke(menu, 18, 1, Pokemon); 
            joueurs[0]=copierPokemon(Pokemon[choixpoke]); 
            choixordi=choixpokeordi_difmoyen(joueurs[0]->type);
            joueurs[3]=copierPokemon(Pokemon[choixordi]); 
            joueurs[1]=pokenul;
            joueurs[2]=pokenul;
            joueurs[4]=pokenul;
            joueurs[5]=pokenul;
            return joueurs;
        } else if(choixmenu==19) {
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
    } else if (choixmenu==11 || choixmenu==14 || choixmenu==17 || choixmenu==20) {
        if(choixmenu==11) {
            for(int i=0 ; i<5 ; i++) {
                if (i == 2 ) continue;
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]=copierPokemon(Pokemon[choixpoke]);  
            }
            joueurs[2]=pokenul;
            joueurs[5]=pokenul;
            return joueurs;
        } else if (choixmenu==14) {
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
        } else if (choixmenu==17) {
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
        } else if(choixmenu==20) {
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
    } else {
        if(choixmenu==12) {
            for(int i=0 ; i<6 ; i++) {
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]=copierPokemon(Pokemon[choixpoke]); 
            }
            return joueurs;
        } else if (choixmenu==15) {
            for(int i=0; i<3 ; i++) {
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]=copierPokemon(Pokemon[choixpoke]);  
            }
            for(int j=0; j<3 ; j++) {
                choixordi=choixpokeordi_difsimple(joueurs[j]->type);
                joueurs[j+3]=copierPokemon(Pokemon[choixordi]); 
            }
            return joueurs;
        } else if (choixmenu==18) {
            for(int i=0; i<3 ; i++) {
                choixpoke = afficherPoke(menu, 18, 1+i, Pokemon); 
                joueurs[i]= copierPokemon(Pokemon[choixpoke]); 
            }
            for(int j=0; j<3 ; j++) {
                choixordi=choixpokeordi_difmoyen(joueurs[j]->type);
                joueurs[j+3]= copierPokemon(Pokemon[choixordi]); 
            }
            return joueurs;
        } else if(choixmenu==21) {
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