#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h>
#include <time.h> 

#define UP    65  
#define DOWN  66  
#define ENTER 10  

typedef struct {
    char* nom; // nom correspondant
    float degat; // degat inflige par l'attaque
    int reussite; // plus l attaque est puissante moins le taux de reussite est elever
    int fonction; // 0 pour des degat, 1 pour regen, 2 pour augmenter attaque, 3 pour baisser attaque, 4 pour augmenter def et 5 pour baisser def

} Attaque;

typedef struct {
    char* name; // nom de l'espece du pokemon
    int type; //0 pour normal, 1 pour sol, 2 pour electrique, 3 pour feu, 4 pour eau et 5 pour plante
    char* repgraph[13]; //dessin modelisant le pokemon
    int pvmax; // pv au debut du combat et qui ne peuvent etre depasser
    int pvactuel; // pv au tour actuel
    float attmax; // permet calculer les degats infligés (peut etre reduit de moitie au max ou a l'inverse doublé)
    float attactuel; //attaque au tour actuel
    float defmax; // permet calcul le pourcentage des degat parrer (peut etre reduit de moitie au max ou a l'inverse doublé)
    float defactuel; //defense au tour actuel
    int agi; // permet de calculer la chance d'eviter une attaque
    int vit; // permet de determiner le premier a attaquer (peut etre reduit de moitie au max ou a l'inverse doublé)
    char* description; //donne comme info le type et une petite description et rep graphique
    Attaque* attaque[4];
} Poke;

typedef struct {
    int actif1;
    int actif2;
} Actif;


void gagnantj1() {
    system("clear");
    printf("             __     ______     __  __     ______     __  __     ______        __        ______    \n");
    printf("            /\\ \\   /\\  __ \\   /\\ \\/\\ \\   /\\  ___\\   /\\ \\/\\ \\   /\\  == \\      /\\ \\      /\\  __ \\   \n");
    printf("           _\\_\\ \\  \\ \\ \\/\\ \\  \\ \\ \\_\\ \\  \\ \\  __\\   \\ \\ \\_\\ \\  \\ \\  __<      \\ \\ \\     \\ \\  __ \\  \n");
    printf("          /\\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\     \\ \\_\\     \\ \\_\\ \\_\\ \n");
    printf("          \\/_____/   \\/_____/   \\/_____/   \\/_____/   \\/_____/   \\/_/ /_/      \\/_/      \\/_/\\/_/ \n");
    printf("                                                                                        \n");
    printf("                          ______     ______     ______     __   __     ______                     \n");
    printf("                         /\\  ___\\   /\\  __ \\   /\\  ___\\   /\\ \"-.\\ \\   /\\  ___\\                    \n");
    printf("                         \\ \\ \\__ \\  \\ \\  __ \\  \\ \\ \\__ \\  \\ \\ \\-.  \\  \\ \\  __\\                    \n");
    printf("                          \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\\\\"\\_\\  \\ \\_____\\                  \n");
    printf("                           \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/                  \n");
    sleep(4);
}          

void gagnantj2() {
    system("clear");
    printf("             __     ______     __  __     ______     __  __     ______        ______        ______    \n");
    printf("            /\\ \\   /\\  __ \\   /\\ \\/\\ \\   /\\  ___\\   /\\ \\/\\ \\   /\\  == \\      /\\___  \\      /\\  __ \\   \n");
    printf("           _\\_\\ \\  \\ \\ \\/\\ \\  \\ \\ \\_\\ \\  \\ \\  __\\   \\ \\ \\_\\ \\  \\ \\  __<      \\/_/  /__     \\ \\  __ \\  \n");
    printf("          /\\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\      /\\_____\\     \\ \\_\\ \\_\\ \n");
    printf("          \\/_____/   \\/_____/   \\/_____/   \\/_____/   \\/_____/   \\/_/ /_/      \\/_____/      \\/_/\\/_/ \n");
    printf("                                                                                            \n");
    printf("                          ______     ______     ______     __   __     ______                         \n");
    printf("                         /\\  ___\\   /\\  __ \\   /\\  ___\\   /\\ \"-.\\ \\   /\\  ___\\                        \n");
    printf("                         \\ \\ \\__ \\  \\ \\  __ \\  \\ \\ \\__ \\  \\ \\ \\-.  \\  \\ \\  __\\                        \n");
    printf("                          \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\\\\"\\_\\  \\ \\_____\\                      \n");
    printf("                           \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/                      \n");
    sleep(4);
}

void affichagePokepv(Poke* j1[3], Poke* j2[3], int tour, Actif* actif) {
    system("clear");
    printf("\n     %s        %d/%d      tour: %d       %s        %d/%d\n", j1[actif->actif1]->name, j1[actif->actif1]->pvactuel, j1[actif->actif1]->pvmax, tour, j2[actif->actif2]->name, j2[actif->actif2]->pvactuel, j2[actif->actif2]->pvmax);
    int barrepvj1=j1[actif->actif1]->pvactuel/4;
    int barrepvj2=j2[actif->actif2]->pvactuel/4;
    printf("     ");
    for(int i=1; i<=25; i++) {
        if(barrepvj1>=i) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("                    ");
    for(int i=1; i<=25; i++) {
        if(barrepvj2>=i) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("\n     ");
    for(int i=0; i<2 ; i++) {
        if(j1[i]->pvactuel==0) {
            printf("X ");
        } else {
            printf("O ");
        }
    }
    printf("                                         ");
    for(int i=0; i<2 ; i++) {
        if(j2[i]->pvactuel==0) {
            printf("X ");
        } else {
            printf("O ");
        }
    }


    printf("\n\n");
    for(int i=0; i<13 ; i++) {
        printf("                                        %s\n", j2[actif->actif2]->repgraph[i]);
    }
    for(int i=0; i<13 ; i++) {
        printf("%s\n", j1[actif->actif1]->repgraph[i]);
    }
    printf("\n");

    
}

int getch() {
    struct termios ancient, nouveaut; // def structure ancien et nouveau attribut du terminal
    int ch; // variable qui sera associer a une touche
    tcgetattr(STDIN_FILENO, &ancient); // sauvegarde attribut de base du terminnal
    nouveaut = ancient; // sauvegarde des anciens attributs pour les remettre a la fin
    nouveaut.c_lflag &= ~(ICANON | ECHO);  // Désactive le mode canonique et l'écho (pour traitement imediat et pas affichage de touche)
    tcsetattr(STDIN_FILENO, TCSANOW, &nouveaut); // application fonctionalité vu av (entree clavier appliquer direct avec canon et echo desactivé)
    ch = getchar();  // Lit une touche
    tcsetattr(STDIN_FILENO, TCSANOW, &ancient); // remet les ancien attribut du terminal donc canonique et echo
    return ch; // retourne la touche
}





int choixattj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) { //permet de se deplacer dans le menu pour choisir notre choix
    int choix = 0;  //l'option sélectionnée à la base
    int touche;
    int nbratt=4;
    while (1) { //boucle infini tant que touche diiferent de entrée
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("  choix de l'attaque joueur 1\n\n");
        for (int i = 0; i < nbratt; i++) {
            if (i == choix) {
                printf("    > %s <\n", joueur2[actif->actif1]->attaque[i]->nom); //option selectionnés
            } else {
                printf("      %s\n", joueur2[actif->actif1]->attaque[i]->nom);  // Autres options
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
                    if (choix < nbratt - 1) choix++;  // Déplacer vers le bas sauf si tout en bas
                    break;
            }
        } else if (touche == ENTER) {  // Si appuie sur entrée met fin a la boucle
            break;
        }
    }

    return choix;  // Retourner l'option sélectionnée
}


int choixchangementpoke2restantj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) { //permet de se deplacer dans le menu pour choisir notre choix
    int choix = 0;  //l'option sélectionnée à la base
    int touche;
    int nbrpoke=1;
    while (1) { //boucle infini tant que touche diiferent de entrée
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("  choix du pokemon joueur 1\n\n");
        if (joueur1[0]->pvactuel==0 ) {
            if(actif->actif1==1) {
                printf("    > %s  %d/%d <\n", joueur1[2]->name, joueur1[2]->pvactuel, joueur1[2]->pvmax); //option selectionnés
                choix=2;
            } else {
                printf("    > %s  %d/%d <\n", joueur1[1]->name, joueur1[1]->pvactuel, joueur1[1]->pvmax);
                choix=1;
            }
        } else if(joueur1[1]->pvactuel==0 ) {
            if(actif->actif1==2) {
                printf("    > %s  %d/%d <\n", joueur1[0]->name, joueur1[0]->pvactuel, joueur1[0]->pvmax); //option selectionnés
                choix=0;
            } else {
                printf("    > %s  %d/%d <\n", joueur1[2]->name, joueur1[2]->pvactuel, joueur1[2]->pvmax);
                choix=2;
            }
        } else {
            if(actif->actif1==0) {
                printf("    > %s  %d/%d <\n", joueur1[1]->name, joueur1[1]->pvactuel, joueur1[1]->pvmax);
                choix=1;
            } else {
                printf("    > %s  %d/%d <\n", joueur1[0]->name, joueur1[0]->pvactuel, joueur1[0]->pvmax);
                choix=0;
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
                    if (choix < nbrpoke - 1) choix++;  // Déplacer vers le bas sauf si tout en bas
                    break;
            }
        } else if (touche == ENTER) {  // Si appuie sur entrée met fin a la boucle
            break;
        }
    }
    return choix+4;  // Retourner l'option sélectionnée
}



int choixchangementpoke3restantj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) {
    int choix = 0;
    int touche;
    int nbrpoke = 3;

    // S'assurer qu'on ne commence pas sur le Pokémon actif
    if (choix == actif->actif1) choix++;

    while (1) {
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("  Choix du Pokémon joueur 1 (hors actif actuel)\n\n");

        for (int i = 0; i < nbrpoke; i++) {
            if (i == actif->actif1) continue;

            if (i == choix) {
                printf("> %s  %d/%d\n", joueur2[i]->name, joueur2[i]->pvactuel, joueur2[i]->pvmax);
            } else {
                printf("  %s  %d/%d\n", joueur2[i]->name, joueur2[i]->pvactuel, joueur2[i]->pvmax);
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
                return choix;
            }
        }
    }
}





int choixtypeactionj1(Poke* joueur1[2], Poke* joueur2[2], int tour, Actif* actif) { //permet de se deplacer dans le menu pour choisir notre choix
    int choix = 0;  //l'option sélectionnée à la base
    int touche;
    int nbrtype=2;
    char* type[2]={"attaque","changer de pokemon"};
    printf("test");
    while (1) { //boucle infini tant que touche diiferent de entrée
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("  choix du type d'action joueur 1\n\n");
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
    int choix2;
    int choix1;
    if(joueur1[0]->pvactuel!=0 && joueur1[1]->pvactuel!=0 && joueur1[2]!=0) {
        choix1=choixtypeactionj1(joueur1, joueur2, tour, actif);
        if(choix1==1) {
            choixchangementpoke3restantj1(joueur1, joueur2, tour, actif);
         } else {
            choix2=choixattj1(joueur1, joueur2, tour, actif);
         }
    } else if((joueur1[0]->pvactuel!=0 && joueur1[1]->pvactuel!=0) || (joueur1[1]->pvactuel!=0 && joueur1[2]!=0) || (joueur1[0]->pvactuel!=0 && joueur1[2]->pvactuel!=0)) {
        choixchangementpoke2restantj1(joueur1, joueur2, tour, actif);  
    } else {
        choix2=choixattj1(joueur1, joueur2, tour, actif);
    }
    return choix2;
}













int choixattj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) { //permet de se deplacer dans le menu pour choisir notre choix
    int choix = 0;  //l'option sélectionnée à la base
    int touche;
    int nbratt=4;
    while (1) { //boucle infini tant que touche diiferent de entrée
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("  choix de l'attaque joueur 2\n\n");
        for (int i = 0; i < nbratt; i++) {
            if (i == choix) {
                printf("    > %s <\n", joueur2[actif->actif2]->attaque[i]->nom); //option selectionnés
            } else {
                printf("      %s\n", joueur2[actif->actif2]->attaque[i]->nom);  // Autres options
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
                    if (choix < nbratt - 1) choix++;  // Déplacer vers le bas sauf si tout en bas
                    break;
            }
        } else if (touche == ENTER) {  // Si appuie sur entrée met fin a la boucle
            break;
        }
    }

    return choix;  // Retourner l'option sélectionnée
}


int choixchangementpoke2restantj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) { //permet de se deplacer dans le menu pour choisir notre choix
    int choix = 0;  //l'option sélectionnée à la base
    int touche;
    int nbrpoke=1;
    while (1) { //boucle infini tant que touche diiferent de entrée
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("  choix du pokemon joueur 2\n\n");
        if (joueur2[0]->pvactuel==0 ) {
            if(actif->actif2==1) {
                printf("    > %s  %d/%d <\n", joueur2[2]->name, joueur2[2]->pvactuel, joueur2[2]->pvmax); //option selectionnés
                choix=2;
            } else {
                printf("    > %s  %d/%d <\n", joueur2[1]->name, joueur2[1]->pvactuel, joueur2[1]->pvmax);
                choix=1;
            }
        } else if(joueur2[1]->pvactuel==0 ) {
            if(actif->actif2==2) {
                printf("    > %s  %d/%d <\n", joueur2[0]->name, joueur2[0]->pvactuel, joueur2[0]->pvmax); //option selectionnés
                choix=0;
            } else {
                printf("    > %s  %d/%d <\n", joueur2[2]->name, joueur2[2]->pvactuel, joueur2[2]->pvmax);
                choix=2;
            }
        } else {
            if(actif->actif2==0) {
                printf("    > %s  %d/%d <\n", joueur2[1]->name, joueur2[1]->pvactuel, joueur2[1]->pvmax);
                choix=1;
            } else {
                printf("    > %s  %d/%d <\n", joueur2[0]->name, joueur2[0]->pvactuel, joueur2[0]->pvmax);
                choix=0;
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
                    if (choix < nbrpoke - 1) choix++;  // Déplacer vers le bas sauf si tout en bas
                    break;
            }
        } else if (touche == ENTER) {  // Si appuie sur entrée met fin a la boucle
            break;
        }
    }
    return choix+4;  // Retourner l'option sélectionnée
}



int choixchangementpoke3restantj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) {
    int choix = 0;
    int touche;
    int nbrpoke = 3;

    // S'assurer qu'on ne commence pas sur le Pokémon actif
    if (choix == actif->actif2) choix++;

    while (1) {
        affichagePokepv(joueur1, joueur2, tour, actif);
        printf("  Choix du Pokémon joueur 2 (hors actif actuel)\n\n");

        for (int i = 0; i < nbrpoke; i++) {
            if (i == actif->actif2) continue;

            if (i == choix) {
                printf("> %s  %d/%d\n", joueur2[i]->name, joueur2[i]->pvactuel, joueur2[i]->pvmax);
            } else {
                printf("  %s  %d/%d\n", joueur2[i]->name, joueur2[i]->pvactuel, joueur2[i]->pvmax);
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
                return choix;
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
        printf("  choix du type d'action joueur 2\n\n");
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
    int choix2;
    int choix1;
    if(joueur2[0]->pvactuel!=0 && joueur2[1]->pvactuel!=0 && joueur2[2]!=0) {
        choix1=choixtypeactionj2(joueur1, joueur2, tour, actif);
        if(choix1==1) {
            choixchangementpoke3restantj2(joueur1, joueur2, tour, actif);
         } else {
            choix2=choixattj2(joueur1, joueur2, tour, actif);
         }
    } else if((joueur2[0]->pvactuel!=0 && joueur2[1]->pvactuel!=0) || (joueur2[1]->pvactuel!=0 && joueur2[2]!=0) || (joueur2[0]->pvactuel!=0 && joueur2[2]->pvactuel!=0)) {
        choixchangementpoke2restantj2(joueur1, joueur2, tour, actif);  
    } else {
        choix2=choixattj2(joueur1, joueur2, tour, actif);
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
        printf("%s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(4);
        if(joueur2[actif->actif2]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(4);
        } else if(joueur1[actif->actif1]->agi>=esquive1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a esquivé l'attaque\n", joueur1[actif->actif1]->name);
            sleep(4);
        } else {
            joueur1[actif->actif1]->pvactuel-=(calculerEfficacite(joueur2[actif->actif2]->type, joueur1[actif->actif1]->type)*joueur2[actif->actif2]->attaque[actionj2]->degat)/(joueur1[actif->actif1]->defactuel)*(joueur2[actif->actif2]->attactuel);
            if(joueur1[actif->actif1]->pvactuel<=0) {
                joueur1[actif->actif1]->pvactuel=0;
            }
            affichagePokepv(joueur1, joueur2, tour, actif);
            if (effi2==2.0) {
                printf("super efficace\n");
            } else if (effi2==1.0) {
                printf("efficace\n");
            } else if(effi2==0.5) {
                printf("peu efficace\n");
            } else if(effi2==0.0){
                printf("inefficace\n");
            }
            sleep(4);
        }
        return 0;
} 


int attfonction0j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int esquive2, int reussite1, Actif* actif) { // pour attaque du j1
    affichagePokepv(joueur1, joueur2, tour, actif);
    float effi1=calculerEfficacite(joueur1[actif->actif1]->type, joueur2[actif->actif2]->type);
        printf("%s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(4);
        } else if(joueur2[actif->actif2]->agi>=esquive2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a esquivé l'attaque\n", joueur2[actif->actif2]->name);
            sleep(4);
        } else {
            joueur2[actif->actif2]->pvactuel-=(calculerEfficacite(joueur1[actif->actif1]->type, joueur2[actif->actif2]->type)*joueur1[actif->actif1]->attaque[actionj1]->degat)/(joueur2[actif->actif2]->defactuel)*(joueur1[actif->actif1]->attactuel);
            if(joueur2[actif->actif2]->pvactuel<=0) {
                joueur2[actif->actif2]->pvactuel=0;
            }
            affichagePokepv(joueur1, joueur2, tour, actif);
            if (effi1==2.0) {
                printf("super efficace\n");
            } else if (effi1==1.0) {
                printf("efficace\n");
            } else if(effi1==0.5) {
                printf("peu efficace\n");
            } else if(effi1==0.0){
                printf("inefficace\n");
            }
            sleep(4);
        }
        return 0;
}


int attfonction1j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int reussite1, Actif* actif) { // pour regeneration du joueur 1
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("%s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(4);
        } else {
            joueur1[actif->actif1]->pvactuel+=joueur1[actif->actif1]->attaque[actionj1]->degat;
            if(joueur1[actif->actif1]->pvactuel>joueur1[actif->actif1]->pvmax) {
                joueur1[actif->actif1]->pvactuel=joueur1[actif->actif1]->pvmax;
            }
            printf("%s a récuperer de la vie\n", joueur1[actif->actif1]->name);
            sleep(4);
        }
        return 0;
}       

int attfonction1j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int reussite2, Actif* actif) { // pour regeneration du j 2
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("%s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(4);
        if(joueur1[actif->actif1]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(4);
        } else {
            joueur2[actif->actif2]->pvactuel+=joueur2[actif->actif2]->attaque[actionj2]->degat;
            if(joueur2[actif->actif2]->pvactuel>joueur2[actif->actif2]->pvmax) {
                joueur2[actif->actif2]->pvactuel=joueur2[actif->actif2]->pvmax;
            }
            printf("%s a récuperer de la vie\n", joueur2[actif->actif2]->name);
            sleep(4);
        }
        return 0;
} 


int attfonction2j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int reussite2, Actif* actif) { // pour augm att du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("%s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(4);
        if(joueur2[actif->actif2]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(4);
        } else {
            joueur2[actif->actif2]->attactuel*=joueur2[actif->actif2]->attaque[actionj2]->degat;
            if(joueur2[actif->actif2]->attactuel>2*joueur2[actif->actif2]->attmax) {
                joueur2[actif->actif2]->attactuel=2*joueur2[actif->actif2]->attmax;
            }
            printf("%s a augmenté son attaque\n", joueur2[actif->actif2]->name);
            sleep(4);
        }
        return 0;
} 

int attfonction2j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int reussite1, Actif* actif) { // pour augm att du j1
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("%s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(4);
        } else {
            joueur1[actif->actif1]->attactuel*=joueur1[actif->actif1]->attaque[actionj1]->degat;
            if(joueur1[actif->actif1]->attactuel>2*joueur1[actif->actif1]->attmax) {
                joueur1[actif->actif1]->attactuel=2*joueur1[actif->actif1]->attmax;
            }
            printf("%s a augmenté son attaque\n", joueur1[actif->actif1]->name);
            sleep(4);
        }
        return 0;
} 


int attfonction3j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int esquive1, int reussite2, Actif* actif) { // pour baisse att du j1
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("%s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(4);
        if(joueur2[actif->actif2]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(4);
        } else if(joueur1[actif->actif1]->agi>=esquive1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a esquivé l'attaque\n", joueur1[actif->actif1]->name);
            sleep(4);
        } else {
            joueur1[actif->actif1]->attactuel*=joueur2[actif->actif2]->attaque[actionj2]->degat;
            if(joueur1[actif->actif1]->attactuel<0.5*joueur1[actif->actif1]->attmax) {
                joueur1[actif->actif1]->attactuel=0.5*joueur1[actif->actif1]->attmax;
            }
            printf("l'attaque de %s diminue\n", joueur1[actif->actif1]->name);
            sleep(4);
        }
        return 0;
} 


int attfonction3j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int esquive2, int reussite1, Actif* actif) { // pour baisse att du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("%s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(4);
        } else if(joueur2[actif->actif2]->agi>=esquive2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a esquivé l'attaque\n", joueur2[actif->actif2]->name);
            sleep(4);
        } else {
            joueur2[actif->actif1]->attactuel*=joueur1[actif->actif1]->attaque[actionj1]->degat;
            if(joueur2[actif->actif2]->attactuel<0.5*joueur2[actif->actif2]->attmax) {
                joueur2[actif->actif2]->attactuel=0.5*joueur2[actif->actif2]->attmax;
            }
            printf("l'attaque de %s diminue\n", joueur2[actif->actif2]->name);
            sleep(4);
        }
        return 0;
} 


int attfonction4j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int reussite2, Actif* actif) { // pour augm def du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("%s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(4);
        if(joueur2[actif->actif2]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(4);
        } else {
            joueur2[actif->actif2]->defactuel*=joueur2[actif->actif2]->attaque[actionj2]->degat;
            if(joueur2[actif->actif2]->defactuel>2*joueur2[actif->actif2]->defmax) {
                joueur2[actif->actif2]->defactuel=2*joueur2[actif->actif2]->defmax;
            }
            printf("%s a augmenté son attaque\n", joueur2[actif->actif2]->name);
            sleep(4);
        }
        return 0;
} 

int attfonction4j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int reussite1, Actif* actif) { // pour augm def du j1
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("%s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(4);
        } else {
            joueur1[actif->actif1]->defactuel*=joueur1[actif->actif1]->attaque[actionj1]->degat;
            if(joueur1[actif->actif1]->defactuel>2*joueur1[actif->actif1]->defmax) {
                joueur1[actif->actif1]->defactuel=2*joueur1[actif->actif1]->defmax;
            }
            printf("%s a augmenté son attaque\n", joueur1[actif->actif1]->name);
            sleep(4);
        }
        return 0;
} 


int attfonction5j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int esquive1, int reussite2, Actif* actif) { // pour baisse def du j1
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("%s utilise %s\n", joueur2[actif->actif2]->name, joueur2[actif->actif2]->attaque[actionj2]->nom);
        sleep(4);
        if(joueur2[actif->actif2]->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur2[actif->actif2]->name);
            sleep(4);
        } else if(joueur1[actif->actif1]->agi>=esquive1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a esquivé l'attaque\n", joueur1[actif->actif1]->name);
            sleep(4);
        } else {
            joueur1[actif->actif1]->defactuel*=joueur2[actif->actif2]->attaque[actionj2]->degat;
            if(joueur1[actif->actif1]->defactuel<0.5*joueur1[actif->actif1]->defmax) {
                joueur1[actif->actif1]->defactuel=0.5*joueur1[actif->actif1]->defmax;
            }
            printf("la defense de %s diminue\n", joueur1[actif->actif1]->name);
            sleep(4);
        }
        return 0;
} 


int attfonction5j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int esquive2, int reussite1, Actif* actif) { // pour baisse def du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
        printf("%s utilise %s\n", joueur1[actif->actif1]->name, joueur1[actif->actif1]->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1[actif->actif1]->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a raté son attaque\n", joueur1[actif->actif1]->name);
            sleep(4);
        } else if(joueur2[actif->actif2]->agi>=esquive2) {
            affichagePokepv(joueur1, joueur2, tour, actif);
            printf("%s a esquivé l'attaque\n", joueur2[actif->actif2]->name);
            sleep(4);
        } else {
            joueur2[actif->actif2]->attactuel*=joueur1[actif->actif1]->attaque[actionj1]->degat;
            if(joueur2[actif->actif2]->defactuel<0.5*joueur2[actif->actif2]->defmax) {
                joueur2[actif->actif2]->defactuel=0.5*joueur2[actif->actif2]->defmax;
            }
            printf("la defense de %s diminue\n", joueur2[actif->actif2]->name);
            sleep(4);
        }
        return 0;
} 



int changementcombatj2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, Actif* actif) { // pour augm att du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
    actionj2-=4;
    printf("le joueur 2 change de pokemon \n%s rentre dans sa pokeball\n%s rentre dans le combat\na", joueur2[actif->actif2]->name, joueur2[actionj2]->name);
    sleep(4);
    actif->actif2=actionj2;
    affichagePokepv(joueur1, joueur2, tour, actif);
 
    return 0;
} 

int changementcombatj1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, Actif* actif) { // pour augm att du j2
    affichagePokepv(joueur1, joueur2, tour, actif);
    actionj1-=4;
    printf("le joueur 1 change de pokemon \n%s rentre dans sa pokeball\n%s rentre dans le combat\na", joueur1[actif->actif1]->name, joueur1[actionj1]->name);
    sleep(4);
    actif->actif1=actionj1;
    affichagePokepv(joueur1, joueur2, tour, actif);   
    return 0;
} 


  void desactivesaisi() { //empeche de rentrer des caracteres
    struct termios attribut;
    tcgetattr(STDIN_FILENO, &attribut);
    attribut.c_lflag &= ~(ICANON | ECHO); // Désactive saisie ligne et affichage
    tcsetattr(STDIN_FILENO, TCSANOW, &attribut);
}

void activesaisi() { // permet de remettre la saisi de caractere
    struct termios attribut;
    tcgetattr(STDIN_FILENO, &attribut);
    attribut.c_lflag |= (ICANON | ECHO); // Réactive saisie ligne et affichage
    tcsetattr(STDIN_FILENO, TCSANOW, &attribut);
}


int phaseattaque(Poke* joueur1[2], Poke* joueur2[2], int actionj1, int actionj2, int tour, Actif* actif) {
    desactivesaisi();
    int esquive1=rand()%101;
    int esquive2=rand()%101;
    int reussite1=rand()%101;
    int reussite2=rand()%101;
    int choix;
    if(actionj1==4 && actionj2==4) {
        changementcombatj1(joueur1, joueur2, tour, actionj2, actif);
        changementcombatj2(joueur1, joueur2, tour, actionj2, actif);
    } else if(actionj1==4) {
        changementcombatj1(joueur1, joueur2, tour, actionj2, actif);
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
        if(joueur1[0]->pvactuel==0 && joueur1[1]->pvactuel==0 && joueur1[2]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 1 sont ko\n", joueur1[actif->actif1]->name);
            sleep(4);
            gagnantj2();
            return 1;
        } else if(joueur1[actif->actif1]->pvactuel==0 ) {
            printf("%s est ko", joueur1[actif->actif1]->name);
            if((joueur1[0]->pvactuel==0 && joueur1[1]->pvactuel==0) ||  (joueur1[1]->pvactuel==0 && joueur1[2]->pvactuel==0) || (joueur1[0]->pvactuel==0 && joueur1[2]->pvactuel==0)) {
                 actionj1=choixchangementpoke2restantj1(joueur1, joueur2, tour, actif);
                 changementcombatj1(joueur1, joueur2, tour, actionj1, actif);
                 return 0;
                 
            } else {
                actionj1=choixchangementpoke3restantj1(joueur1, joueur2, tour, actif);
                changementcombatj1(joueur1, joueur2, tour, actionj1, actif);
                return 0;
            }
        }
    } else if(actionj2==4) {
        changementcombatj2(joueur1, joueur2, tour, actionj2, actif);
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
        if(joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0 && joueur2[2]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 2 sont ko\n", joueur2[actif->actif2]->name);
            sleep(4);
            gagnantj2();
            return 1;
        } else if(joueur2[actif->actif2]->pvactuel==0 ) {
            printf("%s est ko", joueur2[actif->actif2]->name);
            if((joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0) ||  (joueur2[1]->pvactuel==0 && joueur2[2]->pvactuel==0) || (joueur2[0]->pvactuel==0 && joueur2[2]->pvactuel==0)) {
                 actionj2=choixchangementpoke2restantj2(joueur1, joueur2, tour, actif);
                 changementcombatj2(joueur1, joueur2, tour, actionj1, actif);
                 return 0;
                 
            } else {
                actionj1=choixchangementpoke3restantj2(joueur1, joueur2, tour, actif);
                changementcombatj2(joueur1, joueur2, tour, actionj1, actif);
                return 0;
            }
        }
    } else {
        if(joueur1[actif->actif1]->vit>=joueur2[actif->actif2]->vit) {
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
            if(joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0 && joueur2[2]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 2 sont ko\n", joueur2[actif->actif2]->name);
            sleep(4);
            gagnantj2();
            return 1;
            } else if(joueur2[actif->actif2]->pvactuel==0 ) {
                printf("%s est ko", joueur2[actif->actif2]->name);
                if((joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0) ||  (joueur2[1]->pvactuel==0 && joueur2[2]->pvactuel==0) || (joueur2[0]->pvactuel==0 && joueur2[2]->pvactuel==0)) {
                    actionj2=choixchangementpoke2restantj2(joueur1, joueur2, tour, actif);
                    changementcombatj2(joueur1, joueur2, tour, actionj1, actif);
                    return 0;
                    
                } else {
                    actionj1=choixchangementpoke3restantj2(joueur1, joueur2, tour, actif);
                    changementcombatj2(joueur1, joueur2, tour, actionj1, actif);
                    return 0;
                }   
            }
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
            if(joueur1[0]->pvactuel==0 && joueur1[1]->pvactuel==0 && joueur1[2]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 1 sont ko\n", joueur1[actif->actif1]->name);
            sleep(4);
            gagnantj2();
            return 1;
            } else if(joueur1[actif->actif1]->pvactuel==0 ) {
                printf("%s est ko", joueur1[actif->actif1]->name);
                if((joueur1[0]->pvactuel==0 && joueur1[1]->pvactuel==0) ||  (joueur1[1]->pvactuel==0 && joueur1[2]->pvactuel==0) || (joueur1[0]->pvactuel==0 && joueur1[2]->pvactuel==0)) {
                    actionj1=choixchangementpoke2restantj1(joueur1, joueur2, tour, actif);
                    changementcombatj1(joueur1, joueur2, tour, actionj1, actif);
                    return 0;
                    
                } else {
                    actionj1=choixchangementpoke3restantj1(joueur1, joueur2, tour, actif);
                    changementcombatj1(joueur1, joueur2, tour, actionj1, actif);
                    return 0;
                }
            }
        } else {
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
            if(joueur1[0]->pvactuel==0 && joueur1[1]->pvactuel==0 && joueur1[2]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 1 sont ko\n", joueur1[actif->actif1]->name);
            sleep(4);
            gagnantj2();
            return 1;
            } else if(joueur1[actif->actif1]->pvactuel==0 ) {
                printf("%s est ko", joueur1[actif->actif1]->name);
                if((joueur1[0]->pvactuel==0 && joueur1[1]->pvactuel==0) ||  (joueur1[1]->pvactuel==0 && joueur1[2]->pvactuel==0) || (joueur1[0]->pvactuel==0 && joueur1[2]->pvactuel==0)) {
                    actionj1=choixchangementpoke2restantj1(joueur1, joueur2, tour, actif);
                    changementcombatj1(joueur1, joueur2, tour, actionj1, actif);
                    return 0;
                    
                } else {
                    actionj1=choixchangementpoke3restantj1(joueur1, joueur2, tour, actif);
                    changementcombatj1(joueur1, joueur2, tour, actionj1, actif);
                    return 0;
                }
            }
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
            if(joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0 && joueur2[2]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 2 sont ko\n", joueur2[actif->actif2]->name);
            sleep(4);
            gagnantj2();
            return 1;
            } else if(joueur2[actif->actif2]->pvactuel==0 ) {
                printf("%s est ko", joueur2[actif->actif2]->name);
                if((joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0) ||  (joueur2[1]->pvactuel==0 && joueur2[2]->pvactuel==0) || (joueur2[0]->pvactuel==0 && joueur2[2]->pvactuel==0)) {
                    actionj2=choixchangementpoke2restantj2(joueur1, joueur2, tour, actif);
                    changementcombatj2(joueur1, joueur2, tour, actionj1, actif);
                    return 0;
                    
                } else {
                    actionj1=choixchangementpoke3restantj2(joueur1, joueur2, tour, actif);
                    changementcombatj2(joueur1, joueur2, tour, actionj1, actif);
                    return 0;
                }
            }
        }
    }
    activesaisi();
    return 0;
}




int tourn(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif) { // si pokemon ko retourne 1 et met fin a la boucle infini
    int ko;
    int actionj1=choixactionj1(joueur1, joueur2, tour, actif);
    int actionj2=choixactionj2(joueur1, joueur2, tour, actif);
    ko=phaseattaque(joueur1, joueur2, actionj1, actionj2, tour, actif);
    return ko;
}


int combat(Poke* joueur1[3], Poke* joueur2[3], Actif* actif) {
    int fin=0;
    int tour=1;
    while(fin!=1) { 
        fin=tourn(joueur1, joueur2, tour, actif); //retourne 0 si le combat continue, 1 si le combat est terminé
        tour+=1;
    }
    return 0;
}