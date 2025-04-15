#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h> 

#define ENTER 10  // Code ASCII de la touche Entrée

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

void ouvrirFichier(const char* programme) { //permet d'ouvrir le fichier voulu
    char commande[256];  //taille suffisamment grand pour contenir le chemin du programme 
    snprintf(commande, sizeof(commande), "./%s", programme); //defini le chemin vers le fichier a executer
    int status = system(commande); //permet d'executer le fichier exe voulu contenu dans le tab commande
}

int main() {
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

"- Type Feu :\n"
"  - Défense : résistant aux type Plante, mais faible face aux types Eau.\n"
"  - Attaque : très efficace contre le type Plante, peu efficace contre les types Eau.\n\n"

"- Type Eau :\n"
"  - Défense : résistant aux types Feu, mais faible face aux types Plante.\n"
"  - Attaque : très efficace contre le type Feu, peu efficace contre les type Plante.\n\n"

"- Type Plante :\n"
"  - Défense : résistant aux types eau, mais faible face aux types Feu.\n"
"  - Attaque : très efficace contre les types Eau, peu efficace contre les type Feu.\n\n"

"- Type Électrique :\n"
"  - Défense : résistant au type Électrique, mais faible face au type Sol.\n"
"  - Attaque : très efficace contre les types Eau , peu efficace contre le type Électrique et\n"
"    inefficace contre le type Sol.\n\n"

"- Type sol :\n"
"  - Défense : résistant au type Électrique, mais faible face au type Sol.\n"
"  - Attaque : très efficace contre les types Eau , peu efficace contre le type Électrique et\n\n"

"- Type Normal :\n"
"  - Ce type n'a ni faiblesse, ni résistance, et ses attaques ne sont ni peu efficaces, ni très efficaces.\n\n"

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
    int touche;
    while(1) {
        touche = getch();
            if(touche == ENTER) {
                break;
            }
    }
    ouvrirFichier("accueil");
    return 0;
}