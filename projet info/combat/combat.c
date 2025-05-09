#include "../pokemon/structure.h"
#include "../pokemon/fonction.h"
#include "../pokemon/affichage.h"
#include "combat.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>


#define UP    65  
#define DOWN  66  
#define ENTER 10 





void affichagePokepv(Poke* j1[3], Poke* j2[3], int tour, Actif* actif) { // affiche les pv, atss spe chargement, rep graphique etc ...
    system("clear");
    printf("\n     %s        %d/%d      ", j1[actif->actif1]->name, j1[actif->actif1]->pvactuel, j1[actif->actif1]->pvmax); //affiche j1 nom poke pvact et pvmax
    if(j1[actif->actif1]->pvmax<100) { // pour centrer la ligne si pv prend plus ou moins de caractere
        printf(" ");
    }
    if(j1[actif->actif1]->pvactuel<100) {
        printf(" "); 
    }
    if(j1[actif->actif1]->pvactuel<10) {
        printf(" "); 
    }
    printf("tour: %d ", tour); // affiche tour
    if(tour<10) { // pour centrer si tour <10
        printf(" ");
    }
    printf("     %s        %d/%d\n", j2[actif->actif2]->name, j2[actif->actif2]->pvactuel, j2[actif->actif2]->pvmax); // affiche j2 nom poke pv act et pvmax
    int barrepvj1;
    int barrepvj2;
    if(j1[actif->actif1]->pvactuel<4 && j1[actif->actif1]->pvactuel>0) {  // j1 met a un si plus petit que 4 pour qu'on ne pense pas que poke soit mort
        barrepvj1=1;
    } else {
        barrepvj1=j1[actif->actif1]->pvactuel/4; // donne le nombre de barre a afficher
    }
    if(j2[actif->actif2]->pvactuel<5 && j2[actif->actif2]->pvactuel>0) { // j1 met a un si plus petit que 4 pour qu'on ne pense pas que poke soit mort
        barrepvj2=1;
    } else {
        barrepvj2=j2[actif->actif2]->pvactuel/4; // donne le nombre de barre a afficher
    printf("     ");
    }
    for(int i=1; i<=25; i++) { // j1 affiche une barre tout les 4pv et limiter a 25
        if(barrepvj1>=i) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("                    ");
    for(int i=1; i<=25; i++) { // j2 affiche une barre tout les 4pv et limiter a 25 
        if(barrepvj2>=i) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("\n     ");
    float barreattspej1;
    barreattspej1=((float)j1[actif->actif1]->attspe->tempsrechargeact/j1[actif->actif1]->attspe->tempsrecharge)*100; // donne barre att spe des 2j actif en pourcentage
    float barreattspej2;
    barreattspej2=((float)j2[actif->actif2]->attspe->tempsrechargeact/j2[actif->actif2]->attspe->tempsrecharge)*100;
    printf("Attspe: %.0f%%", barreattspej1); // affiche le % de charge pour j 1
    if(barreattspej1<10) {
        printf("  "); // pour le centrage en fonction des  pourcentage <10 <100 =100
    } else if(barreattspej1<100) {
        printf(" ");
    }
    printf("        ");
    if(j1[actif->actif1]->statut==4) { // affiche le statut du j1 si il en a un
        printf("virus");
    } else if(j1[actif->actif1]->statut>=1 && j1[actif->actif1]->statut<=3) {
        printf("para ");
    } else {
        printf("     "); // pour centrage
    }
    printf("                    ");

    printf("Attspe: %.0f%%", barreattspej2); // affiche le % de charge pour j 2
    if(barreattspej2<10) {
        printf("  "); // pour le centrage en fonction des pourcentage <10 <100 =100
    } else if(barreattspej2<100) {
        printf(" ");
    }
    printf("        ");
    if(j2[actif->actif2]->statut==4) { // affiche le statut du j2 si il en a un
        printf("virus");
    } else if(j2[actif->actif2]->statut>=1 && j2[actif->actif2]->statut<=3) {
        printf("para ");
    } else {
        printf("     "); // pour centrage
    }
    printf("\n     ");
    for(int i=0; i<3 ; i++) { // affiche le nombre de poke du j1 en vie represente par O
        if(j1[i]->pvactuel==0) {
            printf("  ");
        } else {
            printf("O ");
        }
    }
    printf("                                       ");
    for(int i=0; i<3 ; i++) {
        if(j2[i]->pvactuel==0) { // affiche le nombre de poke du j2 en vie represente par O
            printf("  ");
        } else {
            printf("O ");
        }
    }


    printf("\n\n");
    for(int i=0; i<13 ; i++) { // affiche rep graphique j2 en haur a droite
        printf("                                        %s\n", j2[actif->actif2]->repgraph[i]);
    }
    for(int i=0; i<13 ; i++) { //affiche rep graphique j1 en bas a gauche
        printf("%s\n", j1[actif->actif1]->repgraph[i]);
    }
    printf("\n");
}






int choixattj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) { // permet de se déplacer dans le menu pour choisir une attaque
    int choix = 0;  // option sélectionnée par défaut
    int touche;
    int nbratt = 4;

    while (1) { // boucle infinie tant qu'on n'appuie pas sur Entrée
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     Choix de l'attaque joueur 1\n\n");

        if (joueur1[actif->actif1]->attspe->tempsrechargeact != joueur1[actif->actif1]->attspe->tempsrecharge) { // si attspe pas chargé
            for (int i = 0; i < nbratt; i++) {
                if (i == choix) {
                    printf("    > %s <\n", joueur1[actif->actif1]->attaque[i]->nom); // att selectionné
                } else {
                    printf("      %s\n", joueur1[actif->actif1]->attaque[i]->nom); // autre att
                }
            }

            touche = getch(); // caractere choisi
            if (touche == '\033') {
                getch(); // ignore second caractère
                switch (getch()) {
                    case 'A': // fleche haut monte
                        if (choix > 0) choix--;
                        break;
                    case 'B': // fleche bas descend
                        if (choix < nbratt - 1) choix++;
                        break;
                }
            } else if (touche == ENTER) {
                break; // sort boucle
            }
        } else if (joueur1[actif->actif1]->attspe->tempsrechargeact == joueur1[actif->actif1]->attspe->tempsrecharge) { // si att spé chargé
            for (int i = 0; i < nbratt + 1; i++) { 
                if (i == choix) {
                    if (i < 4) {
                        printf("    > %s <\n", joueur1[actif->actif1]->attaque[i]->nom); // si choix <4
                    } else {
                        printf("    > %s (Attaque spéciale) <\n", joueur1[actif->actif1]->attspe->nom); // si choix = 5
                    }
                } else {
                    if (i < 4) {
                        printf("      %s\n", joueur1[actif->actif1]->attaque[i]->nom); // autres options
                    } else {
                        printf("      %s (Attaque spéciale)\n", joueur1[actif->actif1]->attspe->nom); // att spe non selectionné
                    }
                }
            }

            touche = getch();
            if (touche == '\033') {
                getch(); 
                switch (getch()) {
                    case 'A':
                        if (choix > 0) choix--;
                        break;
                    case 'B':
                        if (choix < nbratt) choix++;
                        break;
                }
            } else if (touche == ENTER) {
                break;
            }
        }
    }

    return choix;
}


int choixchangementpoke2restantj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) { //permet de se deplacer dans le menu pour choisir notre choix
    int choix = 0;  //l'option sélectionnée à la base
    int touche;
    while (1) { //boucle infini tant que touche diiferent de entrée
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     choix du pokemon joueur 1\n\n");
        if (joueur1[0]->pvactuel==0 && actif->actif1!=0 ) {
            if(actif->actif1==1) {
                printf("    > %s  %d/%d <\n", joueur1[2]->name, joueur1[2]->pvactuel, joueur1[2]->pvmax); 
                choix=2;
            } else {
                printf("    > %s  %d/%d <\n", joueur1[1]->name, joueur1[1]->pvactuel, joueur1[1]->pvmax);
                choix=1;
            }
        } else if(joueur1[1]->pvactuel==0 && actif->actif1!=1 ) {
            if(actif->actif1==2) {
                printf("    > %s  %d/%d <\n", joueur1[0]->name, joueur1[0]->pvactuel, joueur1[0]->pvmax); //option selectionnés
                choix=0;
            } else {
                printf("    > %s  %d/%d <\n", joueur1[2]->name, joueur1[2]->pvactuel, joueur1[2]->pvmax);
                choix=2;
            }
        } else if(joueur1[2]->pvactuel==0 && actif->actif1!=2) {
            if(actif->actif1==0) {
                printf("    > %s  %d/%d <\n", joueur1[1]->name, joueur1[1]->pvactuel, joueur1[1]->pvmax);
                choix=1;
            } else {
                printf("    > %s  %d/%d <\n", joueur1[0]->name, joueur1[0]->pvactuel, joueur1[0]->pvmax);
                choix=0;
            }
        }

        touche = getch(); // Lire la touche

        if (touche == ENTER) {  // Si appuie entrée
            break;
        }
    }
    return choix+5;  // Retourner l'option sélectionnée
}



int choixchangementpoke3restantj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) {
    int choix = 0;
    int touche;
    int nbrpoke = 3;

    // S'assurer qu'on ne commence pas sur le Pokémon actif
    if (choix == actif->actif1) choix++;

    while (1) {
        if(actif->actif1!=1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     Choix du Pokémon joueur 1 \n\n");

            for (int i = 0; i < nbrpoke; i++) {
                if (i == actif->actif1) continue;
                if (i == choix) {
                    printf("    > %s  %d/%d <\n", joueur1[i]->name, joueur1[i]->pvactuel, joueur1[i]->pvmax);
                } else {
                    printf("      %s  %d/%d \n", joueur1[i]->name, joueur1[i]->pvactuel, joueur1[i]->pvmax);
                }
            }

            touche = getch();

            if (touche == '\033') {
                getch();
                switch (getch()) {
                    case 'A': // flèche haut
                        if (choix > 0 && choix - 1 != actif->actif1) {
                            choix--;
                        }
                        break;

                    case 'B': // flèche bas
                        if (choix < nbrpoke - 1 && choix + 1 != actif->actif1) {
                            choix++;
                        }
                        break;
                }
            } else if (touche == ENTER) {
                if (choix != actif->actif1) {
                    return choix+5;
                }
            }
        } else {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("  Choix du Pokémon joueur 1 \n\n");

            for (int i = 0; i < nbrpoke; i++) {
                if (i == actif->actif1) continue;
                if (i == choix) {
                    printf("    > %s  %d/%d <\n", joueur1[i]->name, joueur1[i]->pvactuel, joueur1[i]->pvmax);
                } else {
                    printf("      %s  %d/%d \n", joueur1[i]->name, joueur1[i]->pvactuel, joueur1[i]->pvmax);
                }
            }

            touche = getch();

            if (touche == '\033') {
                getch();
                switch (getch()) {
                    case 'A': // flèche haut
                        if (choix == 2) {
                            choix-=2;
                        }
                        break;

                    case 'B': // flèche bas
                        if (choix == 0 ) {
                            choix+=2;
                        }
                        break;
                }
            } else if (touche == ENTER) {
                if (choix != actif->actif1) {
                    return choix+5;
                }
            }
        }
    }
}





int choixtypeactionj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) { //permet de se deplacer dans le menu pour choisir notre choix
    int choix = 0;  //l'option sélectionnée à la base
    int touche;
    int nbrtype=2;
    char* type[2]={"attaque","changer de pokemon"};
    while (1) { //boucle infini tant que touche diiferent de entrée
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     choix du type d'action joueur 1\n\n");
        for (int i = 0; i < nbrtype; i++) {
            if (i == choix) {
                printf("    > %s <\n", type[i]); //option selectionnés
            } else {
                printf("      %s\n", type[i]);  // Autres options
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
                    if (choix < nbrtype - 1) choix++;  // Déplacer vers le bas sauf si tout en bas
                    break;
            }
        } else if (touche == ENTER) {  // Si appuie sur entrée met fin a la boucle
            break;
        }
    }

    return choix;  // Retourner l'option sélectionnée
}



int choixactionj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) {
    int choix2=0;
    int choix1=0;
    int nb_vivants = 0;
    
    for (int i = 0; i < 3; i++) { // Compter le nombre de Pokémon encore en vie 
        if (joueur1[i]->pvactuel != 0) nb_vivants++;
    }

    if (nb_vivants == 3) { // Tous les Pokémon sont vivants
        choix1 = choixtypeactionj1(joueur1, joueur2, tour, actif);
        if(choix1 == 0) {
            choix2 = choixattj1(joueur1, joueur2, tour, actif);
        } else {
            choix2 = choixchangementpoke3restantj1(joueur1, joueur2, tour, actif);
        }
    }
    else if (nb_vivants == 2) { //  2 Pokémon vivants
        choix1 = choixtypeactionj1(joueur1, joueur2, tour, actif);
        if(choix1 == 0) {
            choix2 = choixattj1(joueur1, joueur2, tour, actif);
        } else {
            choix2 = choixchangementpoke2restantj1(joueur1, joueur2, tour, actif);
        }
    }
    else { // 1  Pokémon vivant 
        choix2 = choixattj1(joueur1, joueur2, tour, actif);
    }
    
    return choix2;
}








int choixattj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) { // permet de se déplacer dans le menu pour choisir une attaque
    int choix = 0;  // option sélectionnée par défaut
    int touche;
    int nbratt = 4;

    while (1) { // boucle infinie tant qu'on n'appuie pas sur Entrée
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     choix de l'attaque joueur 2\n\n");

        if (joueur2[actif->actif2]->attspe->tempsrechargeact != joueur2[actif->actif2]->attspe->tempsrecharge) {
            for (int i = 0; i < nbratt; i++) {
                if (i == choix) {
                    printf("    > %s <\n", joueur2[actif->actif2]->attaque[i]->nom);
                } else {
                    printf("      %s\n", joueur2[actif->actif2]->attaque[i]->nom);
                }
            }

            touche = getch();
            if (touche == '\033') {
                getch(); // ignore second caractère
                switch (getch()) {
                    case 'A':
                        if (choix > 0) choix--;
                        break;
                    case 'B':
                        if (choix < nbratt - 1) choix++;
                        break;
                }
            } else if (touche == ENTER) {
                break;
            }
        } else if (joueur2[actif->actif2]->attspe->tempsrechargeact == joueur2[actif->actif2]->attspe->tempsrecharge) {
            for (int i = 0; i < nbratt + 1; i++) {
                if (i == choix) {
                    if (i < 4) {
                        printf("    > %s <\n", joueur2[actif->actif2]->attaque[i]->nom);
                    } else {
                        printf("    > %s (Attaque spéciale) <\n", joueur2[actif->actif2]->attspe->nom);
                    }
                } else {
                    if (i < 4) {
                        printf("      %s\n", joueur2[actif->actif2]->attaque[i]->nom);
                    } else {
                        printf("      %s (Attaque spéciale)\n", joueur2[actif->actif2]->attspe->nom);
                    }
                }
            }

            touche = getch();
            if (touche == '\033') {
                getch(); // ignore second caractère
                switch (getch()) {
                    case 'A':
                        if (choix > 0) choix--;
                        break;
                    case 'B':
                        if (choix < nbratt) choix++;
                        break;
                }
            } else if (touche == ENTER) {
                break;
            }
        }
    }

    return choix;
}


int choixchangementpoke2restantj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) {
    int choix = 0;
    int touche;
    while (1) {
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     choix du pokemon joueur 2\n\n");

        if (joueur2[0]->pvactuel == 0 && actif->actif2 != 0) {
            if (actif->actif2 == 1) {
                printf("    > %s  %d/%d <\n", joueur2[2]->name, joueur2[2]->pvactuel, joueur2[2]->pvmax);
                choix = 2;
            } else {
                printf("    > %s  %d/%d <\n", joueur2[1]->name, joueur2[1]->pvactuel, joueur2[1]->pvmax);
                choix = 1;
            }
        } else if (joueur2[1]->pvactuel == 0 && actif->actif2 != 1) {
            if (actif->actif2 == 2) {
                printf("    > %s  %d/%d <\n", joueur2[0]->name, joueur2[0]->pvactuel, joueur2[0]->pvmax);
                choix = 0;
            } else {
                printf("    > %s  %d/%d <\n", joueur2[2]->name, joueur2[2]->pvactuel, joueur2[2]->pvmax);
                choix = 2;
            }
        } else if (joueur2[2]->pvactuel == 0 && actif->actif2 != 2) {
            if (actif->actif2 == 0) {
                printf("    > %s  %d/%d <\n", joueur2[1]->name, joueur2[1]->pvactuel, joueur2[1]->pvmax);
                choix = 1;
            } else {
                printf("    > %s  %d/%d <\n", joueur2[0]->name, joueur2[0]->pvactuel, joueur2[0]->pvmax);
                choix = 0;
            }
        }

        touche = getch(); // Lire la touche

        if (touche == ENTER) {  // Si appuie entrée
            break;
        }
    }
    return choix + 5;  // Retourne l'index du Pokémon sélectionné pour j2
}



int choixchangementpoke3restantj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) {
    int choix = 0;
    int touche;
    int nbrpoke = 3;

    // S'assurer qu'on ne commence pas sur le Pokémon actif
    if (choix == actif->actif2) choix++;

    while (1) {
        if(actif->actif2!=1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     Choix du Pokémon joueur 2 \n\n");

            for (int i = 0; i < nbrpoke; i++) {
                if (i == actif->actif2) continue;
                if (i == choix) {
                    printf("    > %s  %d/%d <\n", joueur2[i]->name, joueur2[i]->pvactuel, joueur2[i]->pvmax);
                } else {
                    printf("      %s  %d/%d \n", joueur2[i]->name, joueur2[i]->pvactuel, joueur2[i]->pvmax);
                }
            }

            touche = getch();

            if (touche == '\033') {
                getch();
                switch (getch()) {
                    case 'A': // flèche haut
                        if (choix > 0 && choix - 1 != actif->actif2) {
                            choix--;
                        }
                        break;

                    case 'B': // flèche bas
                        if (choix < nbrpoke - 1 && choix + 1 != actif->actif2) {
                            choix++;
                        }
                        break;
                }
            } else if (touche == ENTER) {
                if (choix != actif->actif2) {
                    return choix+5;
                }
            }
        } else {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     Choix du Pokémon joueur 2 \n\n");

            for (int i = 0; i < nbrpoke; i++) {
                if (i == actif->actif2) continue;
                if (i == choix) {
                    printf("    > %s  %d/%d <\n", joueur2[i]->name, joueur2[i]->pvactuel, joueur2[i]->pvmax);
                } else {
                    printf("      %s  %d/%d \n", joueur2[i]->name, joueur2[i]->pvactuel, joueur2[i]->pvmax);
                }
            }

            touche = getch();

            if (touche == '\033') {
                getch();
                switch (getch()) {
                    case 'A': // flèche haut
                        if (choix == 2) {
                            choix-=2;
                        }
                        break;

                    case 'B': // flèche bas
                        if (choix == 0 ) {
                            choix+=2;
                        }
                        break;
                }
            } else if (touche == ENTER) {
                if (choix != actif->actif2) {
                    return choix+5;
                }
            }
        }
    }
}





int choixtypeactionj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) { //permet de se deplacer dans le menu pour choisir notre choix
    int choix = 0;  //l'option sélectionnée à la base
    int touche;
    int nbrtype=2;
    char* type[2]={"attaque","changer de pokemon"};
    printf("test");
    while (1) { //boucle infini tant que touche diiferent de entrée
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     choix du type d'action joueur 2\n\n");
        for (int i = 0; i < nbrtype; i++) {
            if (i == choix) {
                printf("    > %s <\n", type[i]); //option selectionnés
            } else {
                printf("      %s\n", type[i]);  // Autres options
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
                    if (choix < nbrtype - 1) choix++;  // Déplacer vers le bas sauf si tout en bas
                    break;
            }
        } else if (touche == ENTER) {  // Si appuie sur entrée met fin a la boucle
            break;
        }
    }

    return choix;  // Retourner l'option sélectionnée
}



int choixactionj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) {
    int choix2=0;
    int choix1=0;
    int nb_vivants = 0;
    for (int i = 0; i < 3; i++) { // Compter le nombre de Pokémon encore en vie
        if (joueur2[i]->pvactuel != 0) nb_vivants++;
    }
    if (nb_vivants == 3) { // Premier cas : tous les Pokémon sont vivants
        choix1 = choixtypeactionj2(joueur1, joueur2, tour, actif);
        if(choix1==0) {
            choix2=choixattj2(joueur1, joueur2, tour, actif);
        } else {
            choix2=choixchangementpoke3restantj2(joueur1, joueur2, tour, actif);
        }
    }
    else if (nb_vivants == 2) { // Deuxième cas : exactement 2 Pokémon vivants
        if(choix1==0) {
            choix2=choixattj2(joueur1, joueur2, tour, actif);
        } else {
            choix2=choixchangementpoke2restantj2(joueur1, joueur2, tour, actif);
        }
    }
    else { // Dernier cas : 1 seul Pokémon vivant (obligé d'attaquer)
        choix2 = choixattj2(joueur1, joueur2, tour, actif);
    }
    
    return choix2;
}






float calculerEfficacite(int typeAttaquant, int typeDefenseur) {
    // Valeurs de retour :
    // 2.0 : super efficace
    // 1.0 : normal
    // 0.5 : peu efficace
    // 0.0 : aucune efficacité (optionnel selon les règles)

    if (typeAttaquant == 0) { // Normal
        return 1.0;
    }
    else if (typeAttaquant == 1) { // Sol
        if (typeDefenseur == 2) {
             return 2.0; // Super efficace contre Électrique
        } else if (typeDefenseur == 5) {
             return 0.5; // Peu efficace contre Plante
        } else {
            return 1.0;
        }
    }
    else if (typeAttaquant == 2) { // Électrique
        if (typeDefenseur == 4) {
            return 2.0; // Efficace contre Eau
        } else if (typeDefenseur == 1) {
            return 0.0; // Inefficace contre Sol
        } else if (typeDefenseur == 5) {
            return 0.5; // Peu efficace contre Plante
        } else {
            return 1.0;
        }
    }
    else if (typeAttaquant == 3) { // Feu
        if (typeDefenseur == 5) {
             return 2.0; // Efficace contre Plante
        } else if (typeDefenseur == 4) {
             return 0.5; // Peu efficace contre Eau
        } else {
            return 1.0;
        }
    }
    else if (typeAttaquant == 4) { // Eau
        if (typeDefenseur == 3) {
            return 2.0; // Efficace contre Feu
        } else if (typeDefenseur == 5) {
             return 0.5; // Peu efficace contre Plante
        } else if (typeDefenseur == 1) {
             return 2.0; // Efficace contre Sol
        } else {
             return 1.0;
        }
    }
    else if (typeAttaquant == 5) { // Plante
        if (typeDefenseur == 1) {
            return 2.0; // Efficace contre Sol
        } else if (typeDefenseur == 4) {
            return 2.0; // Efficace contre Eau
        } else if (typeDefenseur == 3) {
            return 0.5; // Peu efficace contre Feu
        } else {
            return 1.0;
        }
    }
    return 1.0;
}


int attfonction0j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int esquive1, int reussite2, Actif* actif) { // pour attaque du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
    float effi2=calculerEfficacite(joueur2[actif->actif2]->type, joueur1[actif->actif1]->type);
        printf("     %s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(2);
        if(joueur2[actif->actif2]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else if(joueur1[actif->actif1]->agi>=esquive1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a esquivé l'attaque\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else {
            joueur1[actif->actif1]->pvactuel-=(calculerEfficacite(joueur2[actif->actif2]->type, joueur1[actif->actif1]->type)*joueur2[actif->actif2]->attaque[actionj2]->degat)/(joueur1[actif->actif1]->defactuel)*(joueur2[actif->actif2]->attactuel);
            if(joueur1[actif->actif1]->pvactuel<=0) {
                joueur1[actif->actif1]->pvactuel=0;
            }
            affichagePokepv(joueur1, joueur2, tour, actif);
            if (effi2==2.0) {
                printf("     Super efficace\n");
            } else if (effi2==1.0) {
                printf("     Efficace\n");
            } else if(effi2==0.5) {
                printf("     Peu efficace\n");
            } else if(effi2==0.0){
                printf("     Inefficace\n");
            }
            sleep(2);
        }
        return 0;
} 


int attfonction0j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int esquive2, int reussite1, Actif* actif) { // pour attaque du j1
    affichagePokepv(joueur1, joueur2, tour, actif);
    float effi1=calculerEfficacite(joueur1[actif->actif1]->type, joueur2[actif->actif2]->type);
        printf("     %s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(2);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else if(joueur2[actif->actif2]->agi>=esquive2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a esquivé l'attaque\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else {
            joueur2[actif->actif2]->pvactuel-=(calculerEfficacite(joueur1[actif->actif1]->type, joueur2[actif->actif2]->type)*joueur1[actif->actif1]->attaque[actionj1]->degat)/(joueur2[actif->actif2]->defactuel)*(joueur1[actif->actif1]->attactuel);
            if(joueur2[actif->actif2]->pvactuel<=0) {
                joueur2[actif->actif2]->pvactuel=0;
            }
            affichagePokepv(joueur1, joueur2, tour, actif);
            if (effi1==2.0) {
                printf("     Super efficace\n");
            } else if (effi1==1.0) {
                printf("     Efficace\n");
            } else if(effi1==0.5) {
                printf("     Peu efficace\n");
            } else if(effi1==0.0){
                printf("     Inefficace\n");
            }
            sleep(2);
        }
        return 0;
}


int attfonction1j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int reussite1, Actif* actif) { // pour regeneration du joueur 1
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     %s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(2);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else {
            joueur1[actif->actif1]->pvactuel+=joueur1[actif->actif1]->attaque[actionj1]->degat;
            if(joueur1[actif->actif1]->pvactuel>joueur1[actif->actif1]->pvmax) {
                joueur1[actif->actif1]->pvactuel=joueur1[actif->actif1]->pvmax;
            }
            printf("     %s a récuperé de la vie\n", joueur1[actif->actif1]->name);
            sleep(2);
        }
        return 0;
}       

int attfonction1j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int reussite2, Actif* actif) { // pour regeneration du j 2
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     %s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(2);
        if(joueur1[actif->actif1]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else {
            joueur2[actif->actif2]->pvactuel+=joueur2[actif->actif2]->attaque[actionj2]->degat;
            if(joueur2[actif->actif2]->pvactuel>joueur2[actif->actif2]->pvmax) {
                joueur2[actif->actif2]->pvactuel=joueur2[actif->actif2]->pvmax;
            }
            printf("     %s a récuperé de la vie\n", joueur2[actif->actif2]->name);
            sleep(2);
        }
        return 0;
} 


int attfonction2j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int reussite2, Actif* actif) { // pour augm att du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     %s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(2);
        if(joueur2[actif->actif2]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else {
            joueur2[actif->actif2]->attactuel*=joueur2[actif->actif2]->attaque[actionj2]->degat;
            if(joueur2[actif->actif2]->attactuel>2*joueur2[actif->actif2]->attmax) {
                joueur2[actif->actif2]->attactuel=2*joueur2[actif->actif2]->attmax;
            }
            printf("     %s a augmenté son attaque\n", joueur2[actif->actif2]->name);
            sleep(2);
        }
        return 0;
} 

int attfonction2j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int reussite1, Actif* actif) { // pour augm att du j1
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     %s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(2);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else {
            joueur1[actif->actif1]->attactuel*=joueur1[actif->actif1]->attaque[actionj1]->degat;
            if(joueur1[actif->actif1]->attactuel>2*joueur1[actif->actif1]->attmax) {
                joueur1[actif->actif1]->attactuel=2*joueur1[actif->actif1]->attmax;
            }
            printf("     %s a augmenté son attaque\n", joueur1[actif->actif1]->name);
            sleep(2);
        }
        return 0;
} 


int attfonction3j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int esquive1, int reussite2, Actif* actif) { // pour baisse att du j1
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     %s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(2);
        if(joueur2[actif->actif2]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else if(joueur1[actif->actif1]->agi>=esquive1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a esquivé l'attaque\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else {
            joueur1[actif->actif1]->attactuel*=joueur2[actif->actif2]->attaque[actionj2]->degat;
            if(joueur1[actif->actif1]->attactuel<0.5*joueur1[actif->actif1]->attmax) {
                joueur1[actif->actif1]->attactuel=0.5*joueur1[actif->actif1]->attmax;
            }
            printf("     L'attaque de %s diminue\n", joueur1[actif->actif1]->name);
            sleep(2);
        }
        return 0;
} 


int attfonction3j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int esquive2, int reussite1, Actif* actif) { // pour baisse att du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     %s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(2);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else if(joueur2[actif->actif2]->agi>=esquive2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a esquivé l'attaque\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else {
            joueur2[actif->actif1]->attactuel*=joueur1[actif->actif1]->attaque[actionj1]->degat;
            if(joueur2[actif->actif2]->attactuel<0.5*joueur2[actif->actif2]->attmax) {
                joueur2[actif->actif2]->attactuel=0.5*joueur2[actif->actif2]->attmax;
            }
            printf("     L'attaque de %s diminue\n", joueur2[actif->actif2]->name);
            sleep(2);
        }
        return 0;
} 


int attfonction4j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int reussite2, Actif* actif) { // pour augm def du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     %s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(2);
        if(joueur2[actif->actif2]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else {
            joueur2[actif->actif2]->defactuel*=joueur2[actif->actif2]->attaque[actionj2]->degat;
            if(joueur2[actif->actif2]->defactuel>2*joueur2[actif->actif2]->defmax) {
                joueur2[actif->actif2]->defactuel=2*joueur2[actif->actif2]->defmax;
            }
            printf("     %s a augmenté son attaque\n", joueur2[actif->actif2]->name);
            sleep(2);
        }
        return 0;
}

int attfonction4j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int reussite1, Actif* actif) { // pour augm def du j1
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     %s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(2);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else {
            joueur1[actif->actif1]->defactuel*=joueur1[actif->actif1]->attaque[actionj1]->degat;
            if(joueur1[actif->actif1]->defactuel>2*joueur1[actif->actif1]->defmax) {
                joueur1[actif->actif1]->defactuel=2*joueur1[actif->actif1]->defmax;
            }
            printf("     %s a augmenté son attaque\n", joueur1[actif->actif1]->name);
            sleep(2);
        }
        return 0;
} 


int attfonction5j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int esquive1, int reussite2, Actif* actif) { // pour baisse def du j1
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     %s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(2);
        if(joueur2[actif->actif2]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else if(joueur1[actif->actif1]->agi>=esquive1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a esquivé l'attaque\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else {
            joueur1[actif->actif1]->defactuel*=joueur2[actif->actif2]->attaque[actionj2]->degat;
            if(joueur1[actif->actif1]->defactuel<0.5*joueur1[actif->actif1]->defmax) {
                joueur1[actif->actif1]->defactuel=0.5*joueur1[actif->actif1]->defmax;
            }
            printf("     La defense de %s diminue\n", joueur1[actif->actif1]->name);
            sleep(2);
        }
        return 0;
} 


int attfonction5j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int esquive2, int reussite1, Actif* actif) { // pour baisse def du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("     %s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(2);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else if(joueur2[actif->actif2]->agi>=esquive2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s a esquivé l'attaque\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else {
            joueur2[actif->actif2]->attactuel*=joueur1[actif->actif1]->attaque[actionj1]->degat;
            if(joueur2[actif->actif2]->defactuel<0.5*joueur2[actif->actif2]->defmax) {
                joueur2[actif->actif2]->defactuel=0.5*joueur2[actif->actif2]->defmax;
            }
            printf("     La defense de %s diminue\n", joueur2[actif->actif2]->name);
            sleep(2);
        }
        return 0;
} 



int changementcombatj2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, Actif* actif) { // pour augm att du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
    actionj2-=5;
    printf("     Le joueur 2 change de pokemon \n     %s rentre dans sa pokeball \n     %s rentre dans le combat\na", joueur2[actif->actif2]->name, joueur2[actionj2]->name);
    sleep(2);
    actif->actif2=actionj2;
    affichagePokepv(joueur1, joueur2, tour, actif);
 
    return 0;
} 

int changementcombatj1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, Actif* actif) { // pour augm att du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
    actionj1-=5;
    printf("     Le joueur 1 change de pokemon \n     %s rentre dans sa pokeball\n     %s rentre dans le combat\na", joueur1[actif->actif1]->name, joueur1[actionj1]->name);
    sleep(2);
    actif->actif1=actionj1;
    affichagePokepv(joueur1, joueur2, tour, actif);   
    return 0;
} 


int attspecialej1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, Actif* actif) {
    affichagePokepv(joueur1, joueur2, tour, actif);
    printf("     %s utilise son attaque spéciale %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attspe->nom);
    if(joueur1[actif->actif1]->attspe->fonction==0) {
        joueur2[actif->actif2]->pvactuel=0;
    } else if (joueur1[actif->actif1]->attspe->fonction==1) {
        joueur1[actif->actif1]->pvactuel=joueur1[actif->actif1]->pvmax;
    } else if(joueur1[actif->actif1]->attspe->fonction==2) {
        joueur2[actif->actif2]->statut=3;
        printf("     %s est maintenant paralysé", joueur2[actif->actif2]->name);
    } else {
        joueur2[actif->actif2]->statut=4;
        printf("     %s est maintenant malade", joueur2[actif->actif2]->name);
    }
    joueur1[actif->actif1]->attspe->tempsrechargeact=0;
    sleep(2);
    affichagePokepv(joueur1, joueur2, tour, actif);
    return 0;
}

int attspecialej2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, Actif* actif) {
    affichagePokepv(joueur1, joueur2, tour, actif);
    printf("     %s utilise son attaque spéciale %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attspe->nom);
    if(joueur2[actif->actif2]->attspe->fonction==0) {
        joueur1[actif->actif1]->pvactuel=0;
    } else if (joueur2[actif->actif2]->attspe->fonction==1) {
        joueur2[actif->actif2]->pvactuel=joueur2[actif->actif2]->pvmax;
    } else if(joueur2[actif->actif2]->attspe->fonction==2) {
        joueur1[actif->actif1]->statut=3;
        printf("     %s est maintenant paralysé", joueur1[actif->actif1]->name);
    } else {
        joueur1[actif->actif1]->statut=4;
        printf("     %s est maintenant malade", joueur1[actif->actif1]->name);
    }
    joueur2[actif->actif2]->attspe->tempsrechargeact=0;
    sleep(2);
    affichagePokepv(joueur1, joueur2, tour, actif);
    return 0;
}

// nouvelle fonction att


int attj2(Poke* joueur1[3], Poke* joueur2[3], int actionj1, int actionj2, int tour, Actif* actif, int esquive1, int reussite2) {
    if(joueur2[actif->actif2]->attaque[actionj2]->fonction==0) { // joueur 2 attaque
        attfonction0j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif);
    } else if(joueur2[actif->actif2]->attaque[actionj2]->fonction==1) {
        attfonction1j2(joueur1, joueur2, tour, actionj2, reussite2, actif);
    } else if(joueur2[actif->actif2]->attaque[actionj2]->fonction==2) {
        attfonction2j2(joueur1, joueur2, tour, actionj2, reussite2, actif);
    } else if(joueur2[actif->actif2]->attaque[actionj2]->fonction==3) {
        attfonction3j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif);
    } else if(joueur2[actif->actif2]->attaque[actionj2]->fonction==4) {
        attfonction4j2(joueur1, joueur2, tour, actionj2, reussite2, actif);
    } else {
        attfonction5j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif);
    }
    return 0;
}

int attj1(Poke* joueur1[3], Poke* joueur2[3], int actionj1, int actionj2, int tour, Actif* actif, int esquive2, int reussite1) {
    if(joueur1[actif->actif1]->attaque[actionj1]->fonction==0) { // joueur 1 attaque
        attfonction0j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif);
    } else if(joueur1[actif->actif1]->attaque[actionj1]->fonction==1) {
        attfonction1j1(joueur1, joueur2, tour, actionj1, reussite1, actif);
    } else if(joueur1[actif->actif1]->attaque[actionj1]->fonction==2) {
        attfonction2j1(joueur1, joueur2, tour, actionj1, reussite1, actif);
    } else if(joueur1[actif->actif1]->attaque[actionj1]->fonction==3) {
        attfonction3j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif);
    } else if(joueur1[actif->actif1]->attaque[actionj1]->fonction==4) {
        attfonction4j1(joueur1, joueur2, tour, actionj1, reussite1, actif);
    } else {
        attfonction5j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif);
    }
    return 0;
}


int virus(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) {
    if(joueur1[actif->actif1]->statut == 4) {
        joueur1[actif->actif1]->pvactuel-=joueur1[actif->actif1]->pvmax*0.1;
        printf("     %s souffre d'un virus\n", joueur1[actif->actif1]->name); // virus a reporté partout
        sleep(2);
        if(joueur1[actif->actif1]->pvactuel<0) {
            joueur1[actif->actif1]->pvactuel=0;
        }
        affichagePokepv(joueur1, joueur2, tour, actif);
    }
    if(joueur2[actif->actif2]->statut == 4) {
        joueur2[actif->actif2]->pvactuel-=joueur2[actif->actif2]->pvmax*0.1;
        printf("     %s souffre d'un virus\n", joueur2[actif->actif2]->name); // virus a reporté partout
        sleep(2);
        if(joueur2[actif->actif2]->pvactuel<0) {
            joueur2[actif->actif2]->pvactuel=0;
        }
        affichagePokepv(joueur1, joueur2, tour, actif);
    }
    return 0;
}

int verifmortj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) {
    int actionj1=0;
    if(joueur1[0]->pvactuel==0 && joueur1[1]->pvactuel==0 && joueur1[2]->pvactuel==0) {
        printf("     %s est ko\n     Tout les pokemon du joueur 1 sont ko\n", joueur1[actif->actif1]->name);
        sleep(2);
        gagnantj2();
        return 2;
    } else if(joueur1[actif->actif1]->pvactuel==0 ) {
        printf("     %s est ko\n", joueur1[actif->actif1]->name);
        sleep(2);
        if((joueur1[0]->pvactuel==0 && joueur1[1]->pvactuel==0) ||  (joueur1[1]->pvactuel==0 && joueur1[2]->pvactuel==0) || (joueur1[0]->pvactuel==0 && joueur1[2]->pvactuel==0)) {
            actionj1=choixchangementpoke2restantj1(joueur1, joueur2, tour, actif);
            changementcombatj1(joueur1, joueur2, tour, actionj1, actif);
            return 1;         
        } else {
            actionj1=choixchangementpoke3restantj1(joueur1, joueur2, tour, actif);
            changementcombatj1(joueur1, joueur2, tour, actionj1, actif);
            return 1;
        }
    }
    return 0;
}

int verifmortj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif, int choixmenu) {
    int actionj2;
    if(choixmenu == 10 || choixmenu == 11 || choixmenu == 12) { // pour j vs j
        if(joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0 && joueur2[2]->pvactuel==0) {
            printf("     %s est ko\n     Tout les pokemon du joueur 2 sont ko\n", joueur2[actif->actif2]->name);
            sleep(2);
            gagnantj1();
            return 2;
        } else if(joueur2[actif->actif2]->pvactuel==0 ) {
            printf("     %s est ko\n", joueur2[actif->actif2]->name);
            sleep(2);
            if((joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0) ||  (joueur2[1]->pvactuel==0 && joueur2[2]->pvactuel==0) || (joueur2[0]->pvactuel==0 && joueur2[2]->pvactuel==0)) {
                actionj2=choixchangementpoke2restantj2(joueur1, joueur2, tour, actif);
                changementcombatj2(joueur1, joueur2, tour, actionj2, actif);
                return 1;
            } else {
                actionj2=choixchangementpoke3restantj2(joueur1, joueur2, tour, actif);
                changementcombatj2(joueur1, joueur2, tour, actionj2, actif);
                return 1;
            }
        }
    } else { // pour j vs ordi
        if(joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0 && joueur2[2]->pvactuel==0) {
            printf("     %s est ko\n     Tout les pokemon du joueur 2 sont ko\n", joueur2[actif->actif2]->name);
            sleep(2);
            gagnantj1();
            return 2;
        } else if(joueur2[actif->actif2]->pvactuel==0 ) {
            printf("     %s est ko\n", joueur2[actif->actif2]->name);
            sleep(2);
            if((joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0) ||  (joueur2[1]->pvactuel==0 && joueur2[2]->pvactuel==0) || (joueur2[0]->pvactuel==0 && joueur2[2]->pvactuel==0)) {
                if(joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0) {
                    actionj2=7;
                } else if (joueur2[1]->pvactuel==0 && joueur2[2]->pvactuel==0) {
                    actionj2=5;
                } else {
                    actionj2=6;
                }
                changementcombatj2(joueur1, joueur2, tour, actionj2, actif);
                return 1;         
            } else {
                if(joueur2[0]->pvactuel==0) {
                    actionj2=rand()%2+6;
                } else if (joueur2[1]->pvactuel==0) {
                    actionj2=(rand() % 2 == 0) ? 5 : 7;
                } else {
                    actionj2=rand()%2+5;
                }
                changementcombatj2(joueur1, joueur2, tour, actionj2, actif);
                return 1;
            }
        }

    }
    return 0;
}

// si un poke meurt doit return donc on renvoie 0 si aucun mort, on renvoie 1 si un mort et 2 si tous mort
// penser a ajouter possibilité deux pokemon ko en meme temps egalité


int phaseattaque(Poke* joueur1[3], Poke* joueur2[3], int actionj1, int actionj2, int tour, Actif* actif, int choixmenu) {
    int esquive1=rand()%101;
    int esquive2=rand()%101;
    int reussite1=rand()%101;
    int reussite2=rand()%101;
    int ko=0;
    if (actionj1 >= 5 && actionj2 >= 5) { // Changement et Changement  00
        changementcombatj1(joueur1, joueur2, tour, actionj1, actif);
        changementcombatj2(joueur1, joueur2, tour, actionj2, actif);
    }
    else if (actionj1 >= 5 && actionj2 == 4) { // Changement vs Attaque Spéciale  00
        changementcombatj1(joueur1, joueur2, tour, actionj1, actif);
        if(joueur2[actif->actif2]->statut>=1 && joueur2[actif->actif2]->statut<=3) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s est paralysé il n'a pas pu attaquer\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else {
            attspecialej2(joueur1, joueur2, tour, actionj2, actif);
            ko=verifmortj1(joueur1, joueur2, tour, actif);
            if(ko==1) {
                return 1;
            } else if(ko==2) {
                return 2;
            }
        }
        virus(joueur1, joueur2, tour, actif);
        ko=verifmortj1(joueur1, joueur2, tour, actif);
        if(ko==2) {
            return 2;
        }
        ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
        if(ko==2) {
            return 2;
        }
        return 0;
    } else if (actionj1 >= 5 && actionj2<=3) { // Changement vs Attaque Normale 00
        changementcombatj1(joueur1, joueur2, tour, actionj1, actif);
        if(joueur2[actif->actif2]->statut>=1 && joueur2[actif->actif2]->statut<=3) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s est paralysé il n'a pas pu attaquer\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else {
            attj2(joueur1, joueur2, actionj1, actionj2, tour, actif, esquive1, reussite2);
            ko=verifmortj1(joueur1, joueur2, tour, actif);
            if(ko==1) {
                return 1;
            } else if(ko==2) {
                return 2;
            }
        }
        virus(joueur1, joueur2, tour, actif);
        ko=verifmortj1(joueur1, joueur2, tour, actif);
        if(ko==2) {
            return 2;
        }
        ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
        if(ko==2) {
            return 2;
        }
        return 0;
    } else if (actionj1==4 && actionj2 >= 5) { // Attaque Spéciale vs Changement 00
        changementcombatj2(joueur1, joueur2, tour, actionj2, actif);
        if(joueur1[actif->actif1]->statut>=1 && joueur1[actif->actif1]->statut<=3) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s est paralysé il n'a pas pu attaquer\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else {
            attspecialej1(joueur1, joueur2, tour, actionj1, actif);
            ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
            if(ko==1) {
                return 1;
            } else if(ko==2) {
                return 2;
            }
        }
        virus(joueur1, joueur2, tour, actif);
        ko=verifmortj1(joueur1, joueur2, tour, actif);
        if(ko==2) {
            return 2;
        }
        ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
        if(ko==2) {
            return 2;
        }
        return 0;
    } else if (actionj1<=3 && actionj2 >= 5) {  // Attaque Normale vs Changement 00
        changementcombatj2(joueur1, joueur2, tour, actionj2, actif);
        if(joueur1[actif->actif1]->statut>=1 && joueur1[actif->actif1]->statut<=3) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s est paralysé il n'a pas pu attaquer\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else {
            attj1(joueur1, joueur2, actionj1, actionj2, tour, actif, esquive2, reussite1);
            ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
            if(ko==1) {
                return 1;
            } else if(ko==2) {
                return 2;
            }
        }
        virus(joueur1, joueur2, tour, actif);
        ko=verifmortj1(joueur1, joueur2, tour, actif);
        if(ko==2) {
            return 2;
        }
        ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
        if(ko==2) {
            return 2;
        }
        return 0;
    } else if (actionj1 == 4 && actionj2 == 4) { // Attaque Spéciale vs Attaque Spéciale doit rajouté
        int randompremier=0;
        if(joueur1[actif->actif1]->vit==joueur2[actif->actif2]->vit) { 
            randompremier=rand()%2+1;
        }
        if(joueur1[actif->actif1]->vit > joueur2[actif->actif2]->vit || randompremier==1) {
            if(joueur1[actif->actif1]->statut>=1 && joueur1[actif->actif1]->statut<=3) {
                affichagePokepv(joueur1, joueur2, tour, actif);
                printf("     %s est paralysé il n'a pas pu attaquer\n", joueur1[actif->actif1]->name);
                sleep(2);
            } else {
                attspecialej1(joueur1, joueur2, tour, actionj1, actif);
                ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
                if(ko==1) {
                    return 1;
                } else if(ko==2) {
                    return 2;
                }
            }
            if(joueur2[actif->actif2]->statut>=1 && joueur2[actif->actif2]->statut<=3) {
                affichagePokepv(joueur1, joueur2, tour, actif);
                printf("     %s est paralysé il n'a pas pu attaquer\n", joueur2[actif->actif2]->name);
                sleep(2);
            } else {
                attspecialej2(joueur1, joueur2, tour, actionj2, actif);
                ko=verifmortj1(joueur1, joueur2, tour, actif);
                if(ko==1) {
                    return 1;
                } else if(ko==2) {
                    return 2;
                }
            }
        } else if(joueur1[actif->actif1]->vit < joueur2[actif->actif2]->vit || randompremier==2) {
            if(joueur2[actif->actif2]->statut>=1 && joueur2[actif->actif2]->statut<=3) {
                affichagePokepv(joueur1, joueur2, tour, actif);
                printf("     %s est paralysé il n'a pas pu attaquer\n", joueur2[actif->actif2]->name);
                sleep(2);
            } else {
                attspecialej2(joueur1, joueur2, tour, actionj2, actif);
                ko=verifmortj1(joueur1, joueur2, tour, actif);
                if(ko==1) {
                    return 1;
                } else if(ko==2) {
                    return 2;
                }
            }
            if(joueur1[actif->actif1]->statut>=1 && joueur1[actif->actif1]->statut<=3) {
                affichagePokepv(joueur1, joueur2, tour, actif);
                printf("     %s est paralysé il n'a pas pu attaquer\n", joueur1[actif->actif1]->name);
                sleep(2);
            } else {
                attspecialej1(joueur1, joueur2, tour, actionj1, actif);
                ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
                if(ko==1) {
                    return 1;
                } else if(ko==2) {
                    return 2;
                }
            }  
        }
        virus(joueur1, joueur2, tour, actif);
        ko=verifmortj1(joueur1, joueur2, tour, actif);
        if(ko==2) {
            return 2;
        }
        ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
        if(ko==2) {
            return 2;
        }
        return 0;
    } else if (actionj1 == 4 && actionj2 <= 3) { // Attaque Spéciale vs Attaque Normale 00 doit rajouté
        if(joueur1[actif->actif1]->statut>=1 && joueur1[actif->actif1]->statut<=3) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s est paralysé il n'a pas pu attaquer\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else {
            attspecialej1(joueur1, joueur2, tour, actionj1, actif);
            ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
            if(ko==1) {
                return 1;
            } else if(ko==2) {
                return 2;
            }
        }
        if(joueur2[actif->actif2]->statut>=1 && joueur2[actif->actif2]->statut<=3) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s est paralysé il n'a pas pu attaquer\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else {
            attj2(joueur1, joueur2, actionj1, actionj2, tour, actif, esquive1, reussite2);
            ko=verifmortj1(joueur1, joueur2, tour, actif);
            if(ko==1) {
                return 1;
            } else if(ko==2) {
                return 2;
            }
        }
        virus(joueur1, joueur2, tour, actif);
        ko=verifmortj1(joueur1, joueur2, tour, actif);
        if(ko==2) {
            return 2;
        }
        ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
        if(ko==2) {
            return 2;
        }
        return 0;
    } else if (actionj1 <=3 && actionj2 == 4) { // Attaque Normale vs Attaque Spéciale 00 doit rajouté
        if(joueur2[actif->actif2]->statut>=1 && joueur2[actif->actif2]->statut<=3) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s est paralysé il n'a pas pu attaquer\n", joueur2[actif->actif2]->name);
            sleep(2);
        } else {
            attspecialej2(joueur1, joueur2, tour, actionj2, actif);
            ko=verifmortj1(joueur1, joueur2, tour, actif);
            if(ko==1) {
                return 1;
            } else if(ko==2) {
                return 2;
            }
        }
        if(joueur1[actif->actif1]->statut>=1 && joueur1[actif->actif1]->statut<=3) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("     %s est paralysé il n'a pas pu attaquer\n", joueur1[actif->actif1]->name);
            sleep(2);
        } else {
            attj1(joueur1, joueur2, actionj1, actionj2, tour, actif, esquive2, reussite1);
            ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
            if(ko==1) {
                return 1;
            } else if(ko==2) {
                return 2;
            }
        }
        virus(joueur1, joueur2, tour, actif);
        ko=verifmortj1(joueur1, joueur2, tour, actif);
        if(ko==2) {
            return 2;
        }
        ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
        if(ko==2) {
            return 2;
        }
        return 0; 
    } else if (actionj1 <= 3 && actionj2 <= 3) { //Attaque Normale vs Attaque Normale 00 doit rajouté
        int randompremier=0;
        if(joueur1[actif->actif1]->vit==joueur2[actif->actif2]->vit) { 
            randompremier=rand()%2+1;
        }
        if(joueur1[actif->actif1]->vit > joueur2[actif->actif2]->vit || randompremier==1) {
            if(joueur1[actif->actif1]->statut>=1 && joueur1[actif->actif1]->statut<=3) {
                affichagePokepv(joueur1, joueur2, tour, actif);
                printf("     %s est paralysé il n'a pas pu attaquer\n", joueur1[actif->actif1]->name);
                sleep(2);
            } else {
                attj1(joueur1, joueur2, actionj1, actionj2, tour, actif, esquive2, reussite1);
                ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
                if(ko==1) {
                    return 1;
                } else if(ko==2) {
                    return 2;
                }
            }
            if(joueur2[actif->actif2]->statut>=1 && joueur2[actif->actif2]->statut<=3) {
                affichagePokepv(joueur1, joueur2, tour, actif);
                printf("     %s est paralysé il n'a pas pu attaquer\n", joueur2[actif->actif2]->name);
                sleep(2);
            } else {
                attj2(joueur1, joueur2, actionj1, actionj2, tour, actif, esquive1, reussite2);
                ko=verifmortj1(joueur1, joueur2, tour, actif);
                if(ko==1) {
                    return 1;
                } else if(ko==2) {
                    return 2;
                }
            }
        } else if(joueur1[actif->actif1]->vit < joueur2[actif->actif2]->vit || randompremier==2) {
            if(joueur2[actif->actif2]->statut>=1 && joueur2[actif->actif2]->statut<=3) {
                affichagePokepv(joueur1, joueur2, tour, actif);
                printf("     %s est paralysé il n'a pas pu attaquer\n", joueur2[actif->actif2]->name);
                sleep(2);
            } else {
                attj2(joueur1, joueur2, actionj1, actionj2, tour, actif, esquive1, reussite2);
                ko=verifmortj1(joueur1, joueur2, tour, actif);
                if(ko==1) {
                    return 1;
                } else if(ko==2) {
                    return 2;
                }
            }
            if(joueur1[actif->actif1]->statut>=1 && joueur1[actif->actif1]->statut<=3) {
                affichagePokepv(joueur1, joueur2, tour, actif);
                printf("     %s est paralysé il n'a pas pu attaquer\n", joueur1[actif->actif1]->name);
                sleep(2);
            } else {
                attj1(joueur1, joueur2, actionj1, actionj2, tour, actif, esquive2, reussite1);
                ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
                if(ko==1) {
                    return 1;
                } else if(ko==2) {
                    return 2;
                }
            }
        }
        virus(joueur1, joueur2, tour, actif);
        ko=verifmortj1(joueur1, joueur2, tour, actif);
        if(ko==2) {
            return 2;
        }
        ko=verifmortj2(joueur1, joueur2, tour, actif, choixmenu);
        if(ko==2) {
            return 2;
        }
        return 0;
    }
    return 0;
}



int tourn_jvsj(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif, int choixmenu) { // si pokemon ko retourne 1 et met fin a la boucle infini
    int ko;
    int actionj1=choixactionj1(joueur1, joueur2, tour, actif); // choix action j1
    int actionj2=choixactionj2(joueur1, joueur2, tour, actif); // choix action j2
    desactiverSaisie();
    ko=phaseattaque(joueur1, joueur2, actionj1, actionj2, tour, actif, choixmenu);
    activerSaisie();
    if(joueur1[actif->actif1]->attspe->tempsrechargeact<joueur1[actif->actif1]->attspe->tempsrecharge) { // recharge att spe sauf si deja a 100%
        joueur1[actif->actif1]->attspe->tempsrechargeact+=1;
    }
    if(joueur2[actif->actif2]->attspe->tempsrechargeact<joueur2[actif->actif2]->attspe->tempsrecharge) { // recharge att spe sauf si deja a 100%}
        joueur2[actif->actif2]->attspe->tempsrechargeact+=1;
    }
    if(joueur1[actif->actif1]->statut>=1 && joueur1[actif->actif1]->statut<=3) {
        joueur1[actif->actif1]->statut-=1;
    }
    if(joueur2[actif->actif2]->statut>=1 && joueur2[actif->actif2]->statut<=3) {
        joueur2[actif->actif2]->statut-=1;
    }
    return ko;
}


int tourn_jvsordi(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif, int choixmenu) { // si pokemon ko retourne 1 et met fin a la boucle infini
    int ko;
    int actionj2;
    int actionj1=choixactionj1(joueur1, joueur2, tour, actif); // choix action j1
    int nb_vivants = 0;
    for (int i = 0; i < 3; i++) { // Compter le nombre de Pokémon encore en vie
        if (joueur2[i]->pvactuel != 0) nb_vivants++;
    }
    if(joueur2[actif->actif2]->attspe->tempsrechargeact==joueur2[actif->actif2]->attspe->tempsrecharge) {
            actionj2=4;
    } else {
        if(nb_vivants == 3) { // si tout les poke ordi en vie
            if(actif->actif2==2) { // si actif 2 choisi att entre 0 et 3 ou change vers poke 0 ou 1
                do {
                    actionj2 = rand() % 7;
                } while (actionj2 == 4);
            } else if(actif->actif2==1) { // si actif 1 choisi att ou poke 0 ou 2
                do {
                    actionj2 = rand() % 8;
                } while (actionj2 == 6 || actionj2 == 4);
            } else { // si actif 0 choisi att ou change vers poke 1 ou 2
                do {
                    actionj2 = rand() % 8;
                } while (actionj2 == 4 || actionj2 == 5);
            }
        } else if(nb_vivants == 2) { // si deux poke en vie sur 3
            if((joueur2[1]->pvactuel==0 && actif->actif2==2) || (joueur2[2]->pvactuel==0 && actif->actif2==1)) { // si poke 1 et 2 mort ou actif
                do {
                    actionj2 = rand() % 6;
                } while (actionj2 == 4 );
            } else if ((joueur2[1]->pvactuel==0 && actif->actif2==0) || (joueur2[0]->pvactuel==0 && actif->actif2==1)) { // si poke 0 et 1 mort ou actif
                do {
                    actionj2 = rand() % 8;
                } while (actionj2 == 4 || actionj2 == 5 || actionj2 == 6);
            } else { // si poke 0 et 2 mort ou actif
                do {
                    actionj2 = rand() % 7;
                } while (actionj2 == 4 || actionj2 == 5);
            }
        } else {
            actionj2=rand()%4;
        }
    }
    desactiverSaisie();
    ko=phaseattaque(joueur1, joueur2, actionj1, actionj2, tour, actif, choixmenu);
    activerSaisie();
    if(joueur1[actif->actif1]->attspe->tempsrechargeact<joueur1[actif->actif1]->attspe->tempsrecharge) { // recharge att spe sauf si deja a 100%
        joueur1[actif->actif1]->attspe->tempsrechargeact+=1;
    }
    if(joueur2[actif->actif2]->attspe->tempsrechargeact<joueur2[actif->actif2]->attspe->tempsrecharge) { // recharge att spe sauf si deja a 100%
        joueur2[actif->actif2]->attspe->tempsrechargeact+=1;
    }
    if(joueur1[actif->actif1]->statut>=1 && joueur1[actif->actif1]->statut<=3) {
        joueur1[actif->actif1]->statut-=1;
    }
    if(joueur2[actif->actif2]->statut>=1 && joueur2[actif->actif2]->statut<=3) {
        joueur2[actif->actif2]->statut-=1;
    }
    return ko;
}



void combat_jvsj(Poke* joueurs[], Actif* actif, int choixmenu){
    Poke* joueur1[3];
    Poke* joueur2[3];
    for(int i=0; i<3 ; i++) { // rempli les structure par celle choisi av
        joueur1[i]=joueurs[i];
        joueur2[i]=joueurs[i+3];
    }

    int fin=0; // ini fin pour pas de bug
    int tour=1; // ini tour
    while(fin!=2) { 
        fin=tourn_jvsj(joueur1, joueur2, tour, actif, choixmenu); //retourne 0 si le combat continue, 1 si le combat est terminé
        tour+=1;
    }
}


void combat_jvsordi(Poke* joueurs[], Actif* actif, int choixmenu){
    Poke* joueur1[3];
    Poke* joueur2[3];
    for(int i=0; i<3 ; i++) { // rempli les structure par celle choisi av
        joueur1[i]=joueurs[i];
        joueur2[i]=joueurs[i+3];
    }
    int fin=0; // ini fin pour pas de bug
    int tour=1; // ini tour
    while(fin!=2) { 
        fin=tourn_jvsordi(joueur1, joueur2, tour, actif, choixmenu); //retourne 0 si le combat continue, 1 si le combat est terminé
        tour+=1;
    }
}





void combat(int choixmenu, Poke* joueurs[6]) {
    Actif a;
    a.actif1=0; // met les poke actif a 0 soit premier poke selectionné
    a.actif2=0;
    if(choixmenu==10 || choixmenu==11 || choixmenu==12) { // si j vs j lance ce mode de combat
        combat_jvsj(joueurs, &a, choixmenu);
    } else { // sinon lance combat j vs ordi
        combat_jvsordi(joueurs, &a, choixmenu);
    }
}