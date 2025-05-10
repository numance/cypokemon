#include "fonction.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

struct termios oldt, newt;


#define UP    65  
#define DOWN  66  
#define ENTER 10 

void maximizeTerminal() {
    // Séquence ANSI pour passer en plein écran (peut ne pas marcher partout)
    printf("\033[9;1t");  // Essaye de maximiser la fenêtre
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


void desactiverSaisie() {
    struct termios t;      // Déclare une structure pour stocker les paramètres du terminal
    tcgetattr(STDIN_FILENO, &t);  // Récupère les paramètres actuels du terminal
    t.c_lflag &= ~(ICANON | ECHO);  // Désactive le mode canonique (saisie ligne) et l'affichage des caractères
    tcsetattr(STDIN_FILENO, TCSANOW, &t);       // Applique immédiatement les nouveaux paramètres
}

void activerSaisie() {
    struct termios t;    // Déclare une structure pour stocker les paramètres du terminal
    tcgetattr(STDIN_FILENO, &t);  // Récupère les paramètres actuels du terminal
    t.c_lflag |= (ICANON | ECHO);     // Réactive le mode canonique (saisie ligne) et l'affichage des caractères
    tcsetattr(STDIN_FILENO, TCSANOW, &t);  // Applique immédiatement les nouveaux paramètres
}



