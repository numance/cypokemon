#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h> // Pour déplacer dans le terminal 
#include <unistd.h> 

#define UP    65  // Code ASCII de la flèche du haut
#define DOWN  66  // Code ASCII de la flèche du bas
#define ENTER 10  // Code ASCII de la touche Entrée

void afficherTitre() {
    system("clear");
    printf(" ______     __  __     ______   ______     __  __     ______     __    __     ______     __   __   \n");
    printf("/\\  ___\\   /\\ \\_\\ \\   /\\  == \\ /\\  __ \\   /\\ \\/ /    /\\  ___\\   /\\ \\-./  \\   /\\  __ \\   /\\ \\-.\\ \\  \n");
    printf("\\ \\ \\____  \\ \\____ \\  \\ \\  _-/ \\ \\ \\/\\ \\  \\ \\   --.  \\ \\  __\\   \\ \\ \\-./\\ \\  \\ \\ \\/\\ \\  \\ \\ \\-.  \\ \n");
    printf(" \\ \\_____\\  \\/_____\\   \\ \\_\\    \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\-\\_\\ \n");
    printf("  \\/_____/   \\/_____/   \\/_/     \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/ \n\n");
    printf("                             __    __     ______     __   __     __  __    \n");
    printf("                            /\\ \"-./  \\   /\\  ___\\   /\\ \"-.\\ \\   /\\ \\/\\ \\   \n");
    printf("                            \\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\_\\ \\  \n");
    printf("                             \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\\"\\_\\   \\ \\_____\\ \n");
    printf("                              \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/ \n\n\n\n");
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

int afficherMenu(char* menu[], int tailleMenu) { //permet de se deplacer dans le menu pour choisir notre choix
    int choix = 0;  //l'option sélectionnée à la base
    int touche;

    while (1) { //boucle infini tant que touche diiferent de entrée
        afficherTitre();
        for (int i = 0; i < tailleMenu; i++) {
            if (i == choix) {
                printf("                                               > %s <\n\n", menu[i]); //option selectionnés
            } else {
                printf("                                                %s\n\n", menu[i]);  // Autres options
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
                    if (choix < tailleMenu - 1) choix++;  // Déplacer vers le bas sauf si tout en bas
                    break;
            }
        } else if (touche == ENTER) {  // Si appuie sur entrée met fin a la boucle
            break;
        }
    }

    return choix;  // Retourner l'option sélectionnée
}

void ouvrirFichier(const char* programme) { //permet d'ouvrir le fichier voulu  
    char commande[256];  //taille suffisamment grand pour contenir le chemin du programme 
    snprintf(commande, sizeof(commande), "./%s", programme); //defini le chemin vers le fichier a executer
    int status = system(commande); //permet d'executer le fichier exe voulu contenu dans le tab commande
}

int main() { //fonction principale
    
    system("clear");
    char* menu[3] = {"Jouer", "Aide/Info", "Quitter"}; //diferent element du menu
    int choix = afficherMenu(menu, 3);
    system("clear");
    if (choix == 0) {
        ouvrirFichier("choixmodejeu"); 
    } else if (choix == 1) {
        ouvrirFichier("aide");
    }
    return 0;
}