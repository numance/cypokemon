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

void affichagePokepv(Poke* j1, Poke* j2, int tour) {
    system("clear");
    printf("\n     %s        %d/%d      tour: %d       %s        %d/%d\n", j1->name, j1->pvactuel, j1->pvmax, tour, j2->name, j2->pvactuel, j2->pvmax);
    int barrepvj1=j1->pvactuel/4;
    int barrepvj2=j2->pvactuel/4;
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
    printf("\n\n");
    for(int i=0; i<13 ; i++) {
        printf("                                        %s\n", j2->repgraph[i]);
    }
    for(int i=0; i<13 ; i++) {
        printf("%s\n", j1->repgraph[i]);
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



int choixactionj1(Poke* joueur1, Poke* joueur2, int tour) { //permet de se deplacer dans le menu pour choisir notre choix
    int choix = 0;  //l'option sélectionnée à la base
    int touche;
    int nbratt=4;
    while (1) { //boucle infini tant que touche diiferent de entrée
        affichagePokepv(joueur1, joueur2, tour);
        printf("  choix de l'attaque joueur 1\n\n");
        for (int i = 0; i < nbratt; i++) {
            if (i == choix) {
                printf("    > %s <\n", joueur1->attaque[i]->nom); //option selectionnés
            } else {
                printf("      %s\n", joueur1->attaque[i]->nom);  // Autres options
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


int attfonction0j2(Poke* joueur1, Poke* joueur2, int tour, int actionj2, int esquive1, int reussite2) { // pour attaque du j2
    affichagePokepv(joueur1, joueur2, tour);
    float effi2=calculerEfficacite(joueur2->type, joueur1->type);
        printf("%s utilise %s\n", joueur2->name, joueur2->attaque[actionj2]->nom);
        sleep(4);
        if(joueur2->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur2->name);
            sleep(4);
        } else if(joueur1->agi>=esquive1) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a esquivé l'attaque\n", joueur1->name);
            sleep(4);
        } else {
            joueur1->pvactuel-=(calculerEfficacite(joueur2->type, joueur1->type)*joueur2->attaque[actionj2]->degat)/(joueur1->defactuel)*(joueur2->attactuel);
            if(joueur1->pvactuel<=0) {
                joueur1->pvactuel=0;
            }
            affichagePokepv(joueur1, joueur2, tour);
            if (effi2==2.0) {
                printf("super efficace\n");
            } else if (effi2==1.0) {
                printf("efficace\n");
            } else if(effi2==0.5) {
                printf("peu efficace\n");
            } else if (effi2==0.0){
                printf("inefficace\n");
            }
            sleep(4);
        }
        return 0;
} 


int attfonction0j1(Poke* joueur1, Poke* joueur2, int tour, int actionj1, int esquive2, int reussite1) { // pour attaque du j1
    affichagePokepv(joueur1, joueur2, tour);
    float effi1=calculerEfficacite(joueur1->type, joueur2->type);
        printf("%s utilise %s\n", joueur1->name, joueur1->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur1->name);
            sleep(4);
        } else if(joueur2->agi>=esquive2) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a esquivé l'attaque\n", joueur2->name);
            sleep(4);
        } else {
            joueur2->pvactuel-=(calculerEfficacite(joueur1->type, joueur2->type)*joueur1->attaque[actionj1]->degat)/(joueur2->defactuel)*(joueur1->attactuel);
            if(joueur2->pvactuel<=0) {
                joueur2->pvactuel=0;
            }
            affichagePokepv(joueur1, joueur2, tour);
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


int attfonction1j1(Poke* joueur1, Poke* joueur2, int tour, int actionj1, int reussite1) { // pour regeneration du joueur 1
    affichagePokepv(joueur1, joueur2, tour);
        printf("%s utilise %s\n", joueur1->name, joueur1->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur1->name);
            sleep(4);
        } else {
            joueur1->pvactuel+=joueur1->attaque[actionj1]->degat;
            if(joueur1->pvactuel>joueur1->pvmax) {
                joueur1->pvactuel=joueur1->pvmax;
            }
            printf("%s a récuperer de la vie\n", joueur1->name);
            sleep(4);
        }
        return 0;
}       

int attfonction1j2(Poke* joueur1, Poke* joueur2, int tour, int actionj2, int reussite2) { // pour regeneration du j 2
    affichagePokepv(joueur1, joueur2, tour);
        printf("%s utilise %s\n", joueur2->name, joueur2->attaque[actionj2]->nom);
        sleep(4);
        if(joueur1->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur2->name);
            sleep(4);
        } else {
            joueur2->pvactuel+=joueur2->attaque[actionj2]->degat;
            if(joueur2->pvactuel>joueur2->pvmax) {
                joueur2->pvactuel=joueur2->pvmax;
            }
            printf("%s a récuperer de la vie\n", joueur2->name);
            sleep(4);
        }
        return 0;
} 


int attfonction2j2(Poke* joueur1, Poke* joueur2, int tour, int actionj2, int reussite2) { // pour augm att du j2
    affichagePokepv(joueur1, joueur2, tour);
        printf("%s utilise %s\n", joueur2->name, joueur2->attaque[actionj2]->nom);
        sleep(4);
        if(joueur2->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur2->name);
            sleep(4);
        } else {
            joueur2->attactuel*=joueur2->attaque[actionj2]->degat;
            if(joueur2->attactuel>2*joueur2->attmax) {
                joueur2->attactuel=2*joueur2->attmax;
            }
            printf("%s a augmenté son attaque\n", joueur2->name);
            sleep(4);
        }
        return 0;
} 

int attfonction2j1(Poke* joueur1, Poke* joueur2, int tour, int actionj1, int reussite1) { // pour augm att du j1
    affichagePokepv(joueur1, joueur2, tour);
        printf("%s utilise %s\n", joueur1->name, joueur1->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur1->name);
            sleep(4);
        } else {
            joueur1->attactuel*=joueur1->attaque[actionj1]->degat;
            if(joueur1->attactuel>2*joueur1->attmax) {
                joueur1->attactuel=2*joueur1->attmax;
            }
            printf("%s a augmenté son attaque\n", joueur1->name);
            sleep(4);
        }
        return 0;
} 


int attfonction3j2(Poke* joueur1, Poke* joueur2, int tour, int actionj2, int esquive1, int reussite2) { // pour baisse att du j1
    affichagePokepv(joueur1, joueur2, tour);
        printf("%s utilise %s\n", joueur2->name, joueur2->attaque[actionj2]->nom);
        sleep(4);
        if(joueur2->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur2->name);
            sleep(4);
        } else if(joueur1->agi>=esquive1) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a esquivé l'attaque\n", joueur1->name);
            sleep(4);
        } else {
            joueur1->attactuel*=joueur2->attaque[actionj2]->degat;
            if(joueur1->attactuel<0.5*joueur1->attmax) {
                joueur1->attactuel=0.5*joueur1->attmax;
            }
            printf("l'attaque de %s diminue\n", joueur1->name);
            sleep(4);
        }
        return 0;
} 


int attfonction3j1(Poke* joueur1, Poke* joueur2, int tour, int actionj1, int esquive2, int reussite1) { // pour baisse att du j2
    affichagePokepv(joueur1, joueur2, tour);
        printf("%s utilise %s\n", joueur1->name, joueur1->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur1->name);
            sleep(4);
        } else if(joueur2->agi>=esquive2) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a esquivé l'attaque\n", joueur2->name);
            sleep(4);
        } else {
            joueur2->attactuel*=joueur1->attaque[actionj1]->degat;
            if(joueur2->attactuel<0.5*joueur2->attmax) {
                joueur2->attactuel=0.5*joueur2->attmax;
            }
            printf("l'attaque de %s diminue\n", joueur2->name);
            sleep(4);
        }
        return 0;
} 


int attfonction4j2(Poke* joueur1, Poke* joueur2, int tour, int actionj2, int reussite2) { // pour augm def du j2
    affichagePokepv(joueur1, joueur2, tour);
        printf("%s utilise %s\n", joueur2->name, joueur2->attaque[actionj2]->nom);
        sleep(4);
        if(joueur2->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur2->name);
            sleep(4);
        } else {
            joueur2->defactuel*=joueur2->attaque[actionj2]->degat;
            if(joueur2->defactuel>2*joueur2->defmax) {
                joueur2->defactuel=2*joueur2->defmax;
            }
            printf("%s a augmenté son attaque\n", joueur2->name);
            sleep(4);
        }
        return 0;
} 

int attfonction4j1(Poke* joueur1, Poke* joueur2, int tour, int actionj1, int reussite1) { // pour augm def du j1
    affichagePokepv(joueur1, joueur2, tour);
        printf("%s utilise %s\n", joueur1->name, joueur1->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur1->name);
            sleep(4);
        } else {
            joueur1->defactuel*=joueur1->attaque[actionj1]->degat;
            if(joueur1->defactuel>2*joueur1->defmax) {
                joueur1->defactuel=2*joueur1->defmax;
            }
            printf("%s a augmenté son attaque\n", joueur1->name);
            sleep(4);
        }
        return 0;
} 


int attfonction5j2(Poke* joueur1, Poke* joueur2, int tour, int actionj2, int esquive1, int reussite2) { // pour baisse def du j1
    affichagePokepv(joueur1, joueur2, tour);
        printf("%s utilise %s\n", joueur2->name, joueur2->attaque[actionj2]->nom);
        sleep(4);
        if(joueur2->attaque[actionj2]->reussite<reussite2) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur2->name);
            sleep(4);
        } else if(joueur1->agi>=esquive1) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a esquivé l'attaque\n", joueur1->name);
            sleep(4);
        } else {
            joueur1->defactuel*=joueur2->attaque[actionj2]->degat;
            if(joueur1->defactuel<0.5*joueur1->defmax) {
                joueur1->defactuel=0.5*joueur1->defmax;
            }
            printf("la defense de %s diminue\n", joueur1->name);
            sleep(4);
        }
        return 0;
} 


int attfonction5j1(Poke* joueur1, Poke* joueur2, int tour, int actionj1, int esquive2, int reussite1) { // pour baisse def du j2
    affichagePokepv(joueur1, joueur2, tour);
        printf("%s utilise %s\n", joueur1->name, joueur1->attaque[actionj1]->nom);
        sleep(4);
        if(joueur1->attaque[actionj1]->reussite<reussite1) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a raté son attaque\n", joueur1->name);
            sleep(4);
        } else if(joueur2->agi>=esquive2) {
            affichagePokepv(joueur1, joueur2, tour);
            printf("%s a esquivé l'attaque\n", joueur2->name);
            sleep(4);
        } else {
            joueur2->attactuel*=joueur1->attaque[actionj1]->degat;
            if(joueur2->defactuel<0.5*joueur2->defmax) {
                joueur2->defactuel=0.5*joueur2->defmax;
            }
            printf("la defense de %s diminue\n", joueur2->name);
            sleep(4);
        }
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


int phaseattaque(Poke* joueur1, Poke* joueur2, int actionj1, int actionj2, int tour) {
    desactivesaisi();
    int esquive1=rand()%101;
    int esquive2=rand()%101;
    int reussite1=rand()%101;
    int reussite2=rand()%101;
    if(joueur1->vit>=joueur2->vit) {
        if(joueur1->attaque[actionj1]->fonction==0) { // joueur 1 attaque
            attfonction0j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1);
        } else if(joueur1->attaque[actionj1]->fonction==1) {
            attfonction1j1(joueur1, joueur2, tour, actionj1, reussite1);
        } else if(joueur1->attaque[actionj1]->fonction==2) {
            attfonction2j1(joueur1, joueur2, tour, actionj1, reussite1);
        } else if(joueur1->attaque[actionj1]->fonction==3) {
            attfonction3j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1);
        } else if(joueur1->attaque[actionj1]->fonction==4) {
            attfonction4j1(joueur1, joueur2, tour, actionj1, reussite1);
        } else {
            attfonction5j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1);
        }
        if(joueur2->pvactuel==0) {
            printf("%s est ko\n", joueur2->name);
            sleep(4);
            gagnantj1();
            return 1;
        }
        if(joueur2->attaque[actionj2]->fonction==0) { // joueur 2 attaque
            attfonction0j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2);
        } else if(joueur2->attaque[actionj2]->fonction==1) {
            attfonction1j2(joueur1, joueur2, tour, actionj2, reussite2);
        } else if(joueur2->attaque[actionj2]->fonction==2) {
            attfonction2j2(joueur1, joueur2, tour, actionj2, reussite2);
        } else if(joueur2->attaque[actionj2]->fonction==3) {
            attfonction3j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2);
        } else if(joueur2->attaque[actionj2]->fonction==4) {
            attfonction4j2(joueur1, joueur2, tour, actionj2, reussite2);
        } else {
            attfonction5j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2);
        }
        if(joueur1->pvactuel==0) {
            printf("%s est ko\n", joueur1->name);
            sleep(4);
            gagnantj2();
            return 1;
        }
    } else {
        if(joueur2->attaque[actionj2]->fonction==0) { // joueur 2 attaque
            attfonction0j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2);
        } else if(joueur2->attaque[actionj2]->fonction==1) {
            attfonction1j2(joueur1, joueur2, tour, actionj2, reussite2);
        } else if(joueur2->attaque[actionj2]->fonction==2) {
            attfonction2j2(joueur1, joueur2, tour, actionj2, reussite2);
        } else if(joueur2->attaque[actionj2]->fonction==3) {
            attfonction3j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2);
        } else if(joueur2->attaque[actionj2]->fonction==4) {
            attfonction4j2(joueur1, joueur2, tour, actionj2, reussite2);
        } else {
            attfonction5j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2);
        }
        if(joueur1->pvactuel==0) {
            printf("%s est ko\n", joueur1->name);
            sleep(4);
            gagnantj2();
            return 1;
        }
        if(joueur1->attaque[actionj1]->fonction==0) { // joueur 1 attaque
            attfonction0j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1);
        } else if(joueur1->attaque[actionj1]->fonction==1) {
            attfonction1j1(joueur1, joueur2, tour, actionj1, reussite1);
        } else if(joueur1->attaque[actionj1]->fonction==2) {
            attfonction2j1(joueur1, joueur2, tour, actionj1, reussite1);
        } else if(joueur1->attaque[actionj1]->fonction==3) {
            attfonction3j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1);
        } else if(joueur1->attaque[actionj1]->fonction==4) {
            attfonction4j1(joueur1, joueur2, tour, actionj1, reussite1);
        } else {
            attfonction5j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1);
        }
        if(joueur2->pvactuel==0) {
            printf("%s est ko\n", joueur2->name);
            sleep(4);
            gagnantj1();
            return 1;
        }
    }
    activesaisi();
    return 0;
}

int tourn(Poke* joueur1, Poke* joueur2, int tour) { // si pokemon ko retourne 1 et met fin a la boucle infini
    int ko;
    int actionj1=choixactionj1(joueur1, joueur2, tour);
    int actionj2=rand()%4;
    ko=phaseattaque(joueur1, joueur2, actionj1, actionj2, tour);
    return ko;
}


int combat(Poke* joueur1, Poke* joueur2) {
    int fin;
    int tour=1;
    while(fin!=1) { 
        fin=tourn(joueur1, joueur2, tour); //retourne 0 si le combat continue, 1 si le combat est terminé
        tour+=1;
    }
    return 0;
}





int main() {
    //on choisit le pokemon de l'adversaire de sorte à ce qu'il ai une faiblesse face au pokemon du joueur

    Poke joueur1;
    joueur1.name="Evoli     "; // structure pokemon évoli
    joueur1.type=3;  // type correspondant ici normal
    joueur1.pvmax=110; // nombre pv
    joueur1.pvactuel=joueur1.pvmax; // pv actuel mis au max
    joueur1.vit=rand()%101+80; // vit aleatoire entre 80 et 100
    joueur1.attmax=(rand() % 3 + 10) / 10.0;// att aleatoire entre 80 et 100
    joueur1.attactuel=joueur1.attmax; // att actuel mis a att max
    joueur1.agi=rand()%6; // aleatoire entre O et 6 %
    joueur1.defmax=(rand() % 3 + 10) / 10.0;
    joueur1.defactuel=joueur1.defmax; // def actuel mis a defmax
    char* graphevoli[13]= {"        \\ '.           .' /","         \\  \\ .---. .-' /","          '. '     `\\_.'","            |(),()  |     ,","            (  __   /   .' \\","           .''.___.'--,/\\_,|","          {  /     \\   }   |","           '.\\     /_.'    /","            |'-.-',  `; _.'","            |  |  |   |`","            `\"\"`\"\"`\"\"\"`","",""}; //rep graphique du pokemon
    for(int i=0 ; i<13 ; i++) {
         joueur1.repgraph[i]=graphevoli[i]; // rep graphique transmis au tableau
    }
    joueur1.description="Pokemon de type normal \nUn Pokémon rare qui change d'apparence et d'aptitudes \nau moment d'évoluer en fonction du milieu hostile auquel il veut s'adapter.\n"; // breve description
    for(int i=0; i<4 ; i++) {
        joueur1.attaque[i] = malloc(sizeof(Attaque));
    }
    joueur1.attaque[0]->nom="mimi-queue";
    joueur1.attaque[0]->degat=0.8;
    joueur1.attaque[0]->reussite=80;
    joueur1.attaque[0]->fonction=5;

    joueur1.attaque[1]->nom="charge";
    joueur1.attaque[1]->degat=25;
    joueur1.attaque[1]->reussite=90;
    joueur1.attaque[1]->fonction=0;

    joueur1.attaque[2]->nom="vive-attaque";
    joueur1.attaque[2]->degat=30;
    joueur1.attaque[2]->reussite=80;
    joueur1.attaque[2]->fonction=0;

    joueur1.attaque[3]->nom="bélier";
    joueur1.attaque[3]->degat=35;
    joueur1.attaque[3]->reussite=70;
    joueur1.attaque[3]->fonction=0;


    Poke joueur2;
    joueur2.name="Miaouss   "; // structure pokemon miaouss
    joueur2.type=5;
    joueur2.pvmax=100;
    joueur2.pvactuel=joueur2.pvmax;
    joueur2.vit=rand()%101+80;
    joueur2.attmax=(rand() % 3 + 10) / 10.0;
    joueur2.attactuel=joueur2.attmax;
    joueur2.agi=rand()%6;
    joueur2.defmax=(rand() % 3 + 10) / 10.0;
    joueur2.defactuel=joueur2.defmax;
    char* graphmiaouss[13]= {"               .-. \\_/ .-. ","               \\.-\\/=\\/.-/","            '-./___|=|___\\.-'","           .--| \\|/`\"`\\|/ |--.","          (((_)\\  .---.  /(_)))","           `\\ \\_`-.   .-'_/ /`_","             '.__       __.'(_))", "                 /     \\     //","                |       |__.'/","                \\       /--'`","            .--,-' .--. '----.","           '----`--'  '--`----'",""};
    for(int i=0 ; i<13 ; i++) {
         joueur2.repgraph[i]=graphmiaouss[i];
    }
    joueur2.description="Pokemon de type normal \nMiaouss peut rentrer ses griffes dans ses pattes pour \nrôder gracieusement sans laisser de traces. Étrangement, ce Pokémon raffole\ndes pièces d'or qui brillent à la lumière.\n";
    for(int i=0; i<4 ; i++) {
        joueur2.attaque[i] = malloc(sizeof(Attaque));
    }
    joueur2.attaque[0]->nom="soin";
    joueur2.attaque[0]->degat=30;
    joueur2.attaque[0]->reussite=80;
    joueur2.attaque[0]->fonction=1;

    joueur2.attaque[1]->nom="charge";
    joueur2.attaque[1]->degat=25;
    joueur2.attaque[1]->reussite=90;
    joueur2.attaque[1]->fonction=0;

    joueur2.attaque[2]->nom="damocles";
    joueur2.attaque[2]->degat=1.2;
    joueur2.attaque[2]->reussite=80;
    joueur2.attaque[2]->fonction=3;

    joueur2.attaque[3]->nom="plaquage";
    joueur2.attaque[3]->degat=35;
    joueur2.attaque[3]->reussite=70;
    joueur2.attaque[3]->fonction=0;

    combat(&joueur1, &joueur2);
    system("clear");

    return 0;
}