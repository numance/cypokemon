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
    printf("  __    __     ______     _____     ______        _____     ______          __     ______     __  __    \n");
    printf(" /\\ \"-./  \\   /\\  __ \\   /\\  __-.  /\\  ___\\      /\\  __-.  /\\  ___\\        /\\ \\   /\\  ___\\   /\\ \\/\\ \\   \n");
    printf(" \\ \\ \\-./\\ \\  \\ \\ \\/\\ \\  \\ \\ \\/\\ \\ \\ \\  __\\      \\ \\ \\/\\ \\ \\ \\  __\\       _\\_\\ \\  \\ \\  __\\   \\ \\ \\_\\ \\  \n");
    printf("  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\____-  \\ \\_____\\     \\ \\____-  \\ \\_____\\    /\\_____\\  \\ \\_____\\  \\ \\_____\\ \n");
    printf("   \\/_/  \\/_/   \\/_____/   \\/____/   \\/_____/      \\/____/   \\/_____/    \\/_____/   \\/_____/   \\/_____/  \n\n\n");
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
                printf("                                         > %s <\n\n", menu[i]); 
            } else {
                printf("                                          %s\n\n", menu[i]); 
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
    

    char* menu[3] = {"Joueur vs Joueur", "Joueur vs Ordinateur","Retour"};
    int choix = afficherMenu(menu, 3);
    system("clear");
    if (choix == 0) {
        ouvrirFichier("nombreperso_joueur_vs_joueur"); 
    } else if (choix == 1) {
        ouvrirFichier("jouerdifficulte");
    } else {
        ouvrirFichier("accueil");
    }
    
    return 0;
}


                