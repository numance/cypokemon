#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h> 

#define UP    65 
#define DOWN  66  
#define ENTER 10  

void afficherTitre() {
    system("clear");
    printf(" ______   __  __     ______   ______        ______     ______     __    __     ______     ______     ______  \n");
    printf("/\\__  _\\ /\\ \\_\\ \\   /\\  == \\ /\\  ___\\      /\\  ___\\   /\\  __ \\   /\\ \"-./  \\   /\\  == \\   /\\  __ \\   /\\__  _\\ \n");
    printf("\\/_/\\ \\/ \\ \\____ \\  \\ \\  _-/ \\ \\  __\\      \\ \\ \\____  \\ \\ \\/\\ \\  \\ \\ \\-./\\ \\  \\ \\  __<   \\ \\  __ \\  \\/_/\\ \\/ \n");
    printf("   \\ \\_\\  \\/\\_____\\  \\ \\_\\    \\ \\_____\\     \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\    \\ \\_\\  \n");
    printf("    \\/_/   \\/_____/   \\/_/     \\/_____/      \\/_____/   \\/_____/   \\/_/  \\/_/   \\/_____/   \\/_/\\/_/     \\/_/  \n\n\n");
}

int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar(); 
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int afficherMenu(char* menu[], int tailleMenu) {
    int choix = 0;  
    int touche;

    while (1) {
        afficherTitre();
        for (int i = 0; i < tailleMenu; i++) {
            if (i == choix) {
                printf("                                                  > %s <\n\n", menu[i]); 
            } else {
                printf("                                                   %s\n\n", menu[i]);  
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
                    if (choix < tailleMenu - 1) choix++;  
                    break;
            }
        } else if (touche == ENTER) {  
            break;  
        }
    }

    return choix;  
}

void ouvrirFichier(const char* programme) {
    char commande[256];
    snprintf(commande, sizeof(commande), "./%s", programme);
    int status = system(commande);
}

int main() {
    
    
    char* menu[4] = {"1 VS 1", "2 VS 2","3 VS 3","Retour"};
    int choix = afficherMenu(menu, 4);
    system("clear");
    if (choix==0) {
        ouvrirFichier("../pokemon/choix_joueur_vs_ordinateur_difficile_1vs1"); 
    } else if (choix == 1) {
        ouvrirFichier("../pokemon/choix_joueur_vs_ordinateur_difficile_2vs2");
    } else if (choix == 2) {
        ouvrirFichier("../pokemon/choix_joueur_vs_ordinateur_difficile_3vs3");

    } else if (choix == 3) {
        ouvrirFichier("jouerdifficulte");
    }
    return 0;
}