#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>


#define UP    65  
#define DOWN  66  
#define ENTER 10 

#include "../pokemon/structure.h"
#include "../pokemon/fonction.h"
#include "../pokemon/affichage.h"
#include "../pokemon/choixpokes.h"
#include "../demarrage/demar.h"
#include "../combat/combat.h"


int main() {
    maximizeTerminal(); // met le terminal en grand ecran si ce n'est pas deja le cas
    int choixmenu=menu(); // on choisit le type de combat qu on veut
    if(choixmenu==0) {
        system("clear");
        return 0;
    }
    Poke** joueurs=choixpokes(choixmenu); // on choisit ces poke et l'ordi aussi si j vs ordi
    combat(choixmenu, joueurs); // lance combat
    system("clear");
    return 0;
}


// prblm avec touche entréé saisi bcp de fois a la suite 