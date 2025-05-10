#include "affichage.h"
#include "fonction.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include "fonction.h"

void aide() { // affiche menu aide et infos pour jouer
    system("clear");
    printf("Bonjour, et bienvenue dans le jeu CY Pokémon ! Si vous vous trouvez ici, c'est probablement que vous ne connaissez pas\n"
    "les règles de notre jeu. Ne vous inquiétez pas, vous trouverez ici tout le nécessaire pour en devenir un\n"
    "professionnel, point par point.\n\n"

    "Tout d'abord, lorsque vous sélectionnez 'Jouer', on vous demandera si vous préférez jouer avec un ami qui est avec\n"
    "vous ou bien contre un ordinateur (dans ce cas, on vous demandera de choisir un niveau de difficulté). Enfin, on vous\n"
    "demandera le nombre de Pokémon combattants : il y a 3 possibilités : 1vs1, 2vs2 ou 3vs3.\n\n"

    "Ensuite, vous devrez constituer une équipe en fonction du nombre de combattants que vous avez choisi : 1, 2 ou 3.\n"
    "Sachez qu'il existe des faiblesses et des résistances pour la défense, ainsi que des attaques peu ou très efficaces\n"
    "entre certains types. Voici les interactions :\n\n"

    "Attaque de type Sol\n"
    "   -Elle est super efficace contre les Pokémon de type Électrique.\n"
    "   -Elle est peu efficace contre les Pokémon de type Plante.\n\n"
    "Attaque de type Électrique\n"
    "   -Elle est super efficace contre les Pokémon de type Eau.\n"
    "   -Elle est inefficace contre les Pokémon de type Sol.\n"
    "   -Elle est peu efficace contre les Pokémon de type Plante.\n\n"
    "Attaque de type Feu\n"
    "   -Elle est super efficace contre les Pokémon de type Plante.\n"
    "   -Elle est peu efficace contre les Pokémon de type Eau.\n\n"
    "Attaque de type Eau"
    "   -Elle est super efficace contre les Pokémon de type Feu.\n"
    "   -Elle est super efficace contre les Pokémon de type Sol.\n"
    "   -Elle est peu efficace contre les Pokémon de type Plante.\n\n"
    "Attaque de type Plante\n"
    "   -Elle est super efficace contre les Pokémon de type Sol.\n"
    "   -Elle est super efficace contre les Pokémon de type Eau.\n"
    "   -Elle est peu efficace contre les Pokémon de type Feu.\n\n"

    "Il est conseillé, si vous faites un combat avec plusieurs combattants, de prendre des Pokémon de types différents\n"
    "afin de varier, mieux encaisser les coups et frapper plus fort si vous avez un avantage. Cela permet aussi d'éviter\n"
    "d'être désavantagé face à un Pokémon adverse.\n\n"

    "Maintenant, entrons dans le vif du sujet : le combat. Chaque joueur (Joueur 1 et Joueur 2, ou Joueur et Ordinateur)\n"
    "détermine son action pour le tour. Ensuite, les attaques sont lancées : le Pokémon le plus rapide attaque en premier.\n"
    "Dans de rares cas (moins de 5 pourcent de chance sauf contre ordinateur complique qui a plus de chance), une attaque peut"
    "être esquivée.\n\n"

    "Lorsqu'un Pokémon n'a plus de points de vie, il est mis K.O. À chaque tour, vous pouvez choisir d'attaquer ou\n"
    "de changer de Pokémon. Si vous changez, vous ne pourrez pas attaquer ce tour-là. Quand tous les Pokémon d'une équipe\n"
    "sont K.O., le combat est terminé et le gagnant est annoncé.\n\n"

    "Si vous perdez, vous pouvez toujours retenter votre chance pour devenir un grand champion, battre tous vos amis\n"
    "et même vaincre l'ordinateur en mode difficile.\n\n"

    "Pour retourner à l'accueil : appuyez sur entrée\n");
    int touche; // quand appuie sur la touche entréé retourne sur menu principal
    while(1) {
        touche = getch();
            if(touche == ENTER) {
                break;
            }
    }
}







void afficherMenu0() { // affiche choix du mode de jeu
    printf(" ______     __  __     ______   ______     __  __     ______     __    __     ______     __   __   \n");
    printf("/\\  ___\\   /\\ \\_\\ \\   /\\  == \\ /\\  __ \\   /\\ \\/ /    /\\  ___\\   /\\ \\-./  \\   /\\  __ \\   /\\ \\-.\\ \\  \n");
    printf("\\ \\ \\____  \\ \\____ \\  \\ \\  _-/ \\ \\ \\/\\ \\  \\ \\   --.  \\ \\  __\\   \\ \\ \\-./\\ \\  \\ \\ \\/\\ \\  \\ \\ \\-.  \\ \n");
    printf(" \\ \\_____\\  \\/_____\\   \\ \\_\\    \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\-\\_\\ \n");
    printf("  \\/_____/   \\/_____/   \\/_/     \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/ \n\n");
    printf("                             __    __     ______     __   __     __  __    \n");
    printf("                            /\\ \"-./  \\   /\\  ___\\   /\\ \"-.\\ \\   /\\ \\/\\ \\   \n");
    printf("                            \\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\_\\ \\  \n");
    printf("                             \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\\"\\_\\   \\ \\_____\\ \n");
    printf("                              \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/ \n");
}


void afficherMenu1(void) { // affiche mode de jeu
    printf("  __    __     ______     _____     ______        _____     ______          __     ______     __  __    \n");
    printf(" /\\ \"-./  \\   /\\  __ \\   /\\  __-.  /\\  ___\\      /\\  __-.  /\\  ___\\        /\\ \\   /\\  ___\\   /\\ \\/\\ \\   \n");
    printf(" \\ \\ \\-./\\ \\  \\ \\ \\/\\ \\  \\ \\ \\/\\ \\ \\ \\  __\\      \\ \\ \\/\\ \\ \\ \\  __\\       _\\_\\ \\  \\ \\  __\\   \\ \\ \\_\\ \\  \n");
    printf("  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\____-  \\ \\_____\\     \\ \\____-  \\ \\_____\\    /\\_____\\  \\ \\_____\\  \\ \\_____\\ \n");
    printf("   \\/_/  \\/_/   \\/_____/   \\/____/   \\/_____/      \\/____/   \\/_____/    \\/_____/   \\/_____/   \\/_____/  \n");
}



void afficherMenu2(void) { // affiche dificulté
    printf("                                                                                       __      \n");
    printf("                                                                                      /_/    \n");
    printf(" _____     __     ______   ______   __     ______     __  __     __         ______   ______    \n");
    printf("/\\  __-.  /\\ \\   /\\  ___\\ /\\  ___\\ /\\ \\   /\\  ___\\   /\\ \\/\\ \\   /\\ \\       /\\__  _\\ /\\  ___\\   \n");
    printf("\\ \\ \\/\\ \\ \\ \\ \\  \\ \\  __\\ \\ \\  __\\ \\ \\ \\  \\ \\ \\____  \\ \\ \\_\\ \\  \\ \\ \\___   \\/_/\\ \\/ \\ \\  __\\   \n");
    printf(" \\ \\____-  \\ \\_\\  \\ \\_\\    \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\    \\ \\_\\  \\ \\_____\\ \n");
    printf("  \\/____/   \\/_/   \\/_/     \\/_/     \\/_/   \\/_____/   \\/_____/   \\/_____/     \\/_/   \\/_____/    \n");
}



void afficherMenu3(void) { // affiche type de combat
    printf(" ______   __  __     ______   ______        ______     ______     __    __     ______     ______     ______  \n");
    printf("/\\__  _\\ /\\ \\_\\ \\   /\\  == \\ /\\  ___\\      /\\  ___\\   /\\  __ \\   /\\ \"-./  \\   /\\  == \\   /\\  __ \\   /\\__  _\\ \n");
    printf("\\/_/\\ \\/ \\ \\____ \\  \\ \\  _-/ \\ \\  __\\      \\ \\ \\____  \\ \\ \\/\\ \\  \\ \\ \\-./\\ \\  \\ \\  __<   \\ \\  __ \\  \\/_/\\ \\/ \n");
    printf("   \\ \\_\\  \\/\\_____\\  \\ \\_\\    \\ \\_____\\     \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\    \\ \\_\\  \n");
    printf("    \\/_/   \\/_____/   \\/_/     \\/_____/      \\/_____/   \\/_____/   \\/_/  \\/_/   \\/_____/   \\/_/\\/_/     \\/_/  \n");
}




void afficherTitrej1_1() { // affiche choix j1 1
    system("clear");
    printf("                ______     __  __     ______     __     __  __          __     __        __    \n");
    printf("               /\\  ___\\   /\\ \\_\\ \\   /\\  __ \\   /\\ \\   /\\_\\_\\_\\        /\\ \\   /\\ \\      /\\ \\   \n");
    printf("               \\ \\ \\____  \\ \\  __ \\  \\ \\ \\/\\ \\  \\ \\ \\  \\/_/\\_\\/_      _\\_\\ \\  \\ \\ \\     \\ \\ \\  \n");
    printf("                \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\   /\\_\\/\\_\\    /\\_____\\  \\ \\_\\     \\ \\_\\ \n");
    printf("                 \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/   \\/_/\\/_/    \\/_____/   \\/_/      \\/_/ \n\n");
}

void afficherTitrej1_2() { // affiche choix j1 2
    system("clear");
    printf("                ______     __  __     ______     __     __  __          __     __        ______    \n");
    printf("               /\\  ___\\   /\\ \\_\\ \\   /\\  __ \\   /\\ \\   /\\_\\_\\_\\        /\\ \\   /\\ \\      /\\___  \\   \n");
    printf("               \\ \\ \\____  \\ \\  __ \\  \\ \\ \\/\\ \\  \\ \\ \\  \\/_/\\_\\/_      _\\_\\ \\  \\ \\ \\     \\/_/  /__  \n");
    printf("                \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\   /\\_\\/\\_\\    /\\_____\\  \\ \\_\\      /\\_____\\ \n");
    printf("                 \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/   \\/_/\\/_/    \\/_____/   \\/_/      \\/_____/ \n\n");
}

void afficherTitrej1_3() { //affiche choix j1 3
    system("clear");
    printf("                ______     __  __     ______     __     __  __          __     __        ______    \n");
    printf("               /\\  ___\\   /\\ \\_\\ \\   /\\  __ \\   /\\ \\   /\\_\\_\\_\\        /\\ \\   /\\ \\      /\\___  \\   \n");
    printf("               \\ \\ \\____  \\ \\  __ \\  \\ \\ \\/\\ \\  \\ \\ \\  \\/_/\\_\\/_      _\\_\\ \\  \\ \\ \\     \\ \\___  \\   \n");
    printf("                \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\   /\\_\\/\\_\\    /\\_____\\  \\ \\_\\     \\ \\_____\\ \n");
    printf("                 \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/   \\/_/\\/_/    \\/_____/   \\/_/      \\/_____/ \n\n");
}

void afficherTitrej2_1() { // affiche choix j2 1
    system("clear");
    printf("                ______     __  __     ______     __     __  __          __     ______        __    \n");
    printf("               /\\  ___\\   /\\ \\_\\ \\   /\\  __ \\   /\\ \\   /\\_\\_\\_\\        /\\ \\   /\\___  \\      /\\ \\   \n");
    printf("               \\ \\ \\____  \\ \\  __ \\  \\ \\ \\/\\ \\  \\ \\ \\  \\/_/\\_\\/_      _\\_\\ \\  \\/_/  /__     \\ \\ \\  \n");
    printf("                \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\   /\\_\\/\\_\\    /\\_____\\   /\\_____\\     \\ \\_\\ \n");
    printf("                 \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/   \\/_/\\/_/    \\/_____/   \\/_____/      \\/_/ \n\n");
}

void afficherTitrej2_2() { //affiche choix j2 2
    system("clear");
    printf("                ______     __  __     ______     __     __  __          __     ______        ______    \n");
    printf("               /\\  ___\\   /\\ \\_\\ \\   /\\  __ \\   /\\ \\   /\\_\\_\\_\\        /\\ \\   /\\___  \\      /\\___  \\   \n");
    printf("               \\ \\ \\____  \\ \\  __ \\  \\ \\ \\/\\ \\  \\ \\ \\  \\/_/\\_\\/_      _\\_\\ \\  \\/_/  /__     \\/_/  /__  \n");
    printf("                \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\   /\\_\\/\\_\\    /\\_____\\   /\\_____\\      /\\_____\\ \n");
    printf("                 \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/   \\/_/\\/_/    \\/_____/   \\/_____/      \\/_____/ \n\n");
}

void afficherTitrej2_3() { // afffiche choix j2 3
    system("clear");
    printf("                ______     __  __     ______     __     __  __          __     ______        ______    \n");
    printf("               /\\  ___\\   /\\ \\_\\ \\   /\\  __ \\   /\\ \\   /\\_\\_\\_\\        /\\ \\   /\\___  \\      /\\___  \\   \n");
    printf("               \\ \\ \\____  \\ \\  __ \\  \\ \\ \\/\\ \\  \\ \\ \\  \\/_/\\_\\/_      _\\_\\ \\  \\/_/  /__     \\ \\___  \\   \n");
    printf("                \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\   /\\_\\/\\_\\    /\\_____\\   /\\_____\\     \\ \\_____\\ \n");
    printf("                 \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/   \\/_/\\/_/    \\/_____/   \\/_____/      \\/_____/\n\n");
}


void gagnantj1() { // affiche joueur 1 a gagné
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

void gagnantj2() { // affiche joueur 2 a gagné
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