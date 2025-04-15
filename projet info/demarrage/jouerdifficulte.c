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
    printf("                                                                                       __      \n");
    printf("                                                                                      /_/    \n");
    printf(" _____     __     ______   ______   __     ______     __  __     __         ______   ______    \n");
    printf("/\\  __-.  /\\ \\   /\\  ___\\ /\\  ___\\ /\\ \\   /\\  ___\\   /\\ \\/\\ \\   /\\ \\       /\\__  _\\ /\\  ___\\   \n");
    printf("\\ \\ \\/\\ \\ \\ \\ \\  \\ \\  __\\ \\ \\  __\\ \\ \\ \\  \\ \\ \\____  \\ \\ \\_\\ \\  \\ \\ \\___   \\/_/\\ \\/ \\ \\  __\\   \n");
    printf(" \\ \\____-  \\ \\_\\  \\ \\_\\    \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\    \\ \\_\\  \\ \\_____\\ \n");
    printf("  \\/____/   \\/_/   \\/_/     \\/_/     \\/_/   \\/_____/   \\/_____/   \\/_____/     \\/_/   \\/_____/    \n\n\n");
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
                printf("                                           > %s <\n\n", menu[i]); 
            } else {
                printf("                                            %s\n\n", menu[i]);  
            }
        }

        touche = getch();

        if (touche == '\033' ) {  
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
    

    char* menu[4] = {"Simple", "Moyen","Difficile","Retour"};
    int choix = afficherMenu(menu, 4);
    system("clear");
    if (choix==0) {
        ouvrirFichier("nombreperso_joueur_vs_ordi_simple"); 
    } else if (choix==1) {
        ouvrirFichier("nombreperso_joueur_vs_ordi_moyen");
    } else if (choix==2) {
        ouvrirFichier("nombreperso_joueur_vs_ordi_moyen");
    } else if (choix==3) {
        ouvrirFichier("choixmodejeu");
    }
    return 0;
}