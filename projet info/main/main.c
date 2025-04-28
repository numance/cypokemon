#include "../demarrage/demar.c"
#include "../pokemon/structure.h"
#include "../pokemon/choixpokes.c"
#include "../combat/combat.c"

    int main() {
        int choixmenu=menu(); // on choisit le type de combat qu on veut
        Poke** joueurs=choixpokes(choixmenu); // on choisit ces poke et l'ordi aussi si j vs ordi
        combat(choixmenu, joueurs);
        return 0;
    }




    // probleme a regler si deux meme pokemon selectionner les pv des deux baisse si il y a une attaque 
    // probleme pour les fonctions 2vs2 et 1vs1