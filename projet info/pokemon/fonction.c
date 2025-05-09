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
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);  // Désactive saisie ligne et affichage
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void activerSaisie() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= (ICANON | ECHO);  // Réactive saisie ligne et affichage
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}



