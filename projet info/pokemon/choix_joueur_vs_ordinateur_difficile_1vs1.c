#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h>
#include <time.h> 

#define UP    65  
#define DOWN  66  
#define ENTER 10  


typedef struct{
    char* name; // nom de l'espece du pokemon
    int type; //0 pour normal, 1 pour sol, 2 pour electrique, 3 pour feu, 4 pour eau et 5 pour plante
    char* repgraph[13]; //dessin modelisant le pokemon
    int pvmax; // pv au debut du combat et qui ne peuvent etre depasser
    int pvactuel; // pv au tour actuel
    int attmax; // permet calculer les degats infligés (peut etre reduit de moitie au max ou a l'inverse doublé)
    int attactuel; //attaque au tour actuel
    int defmax; // permet calcul le pourcentage des degat parrer (peut etre reduit de moitie au max ou a l'inverse doublé)
    int defactuel; //defense au tour actuel
    int agi; // permet de calculer la chance d'eviter une attaque
    int vitmax; // permet de determiner le premier a attaquer (peut etre reduit de moitie au max ou a l'inverse doublé)
    int vitactuel; //vitesses au tour actuel
    int talent; //O pour tempete de sable, 1 pour pression, 2 pour chanceux et 3 intimidation
    char* description; //donne comme info le type et une petite description et rep graphique
} Poke;

void afficherTitre1() {
    system("clear");
    printf("                     ______     __  __     ______     __     __  __        __    \n");
    printf("                    /\\  ___\\   /\\ \\_\\ \\   /\\  __ \\   /\\ \\   /\\_\\_\\_\\      /\\ \\   \n");
    printf("                    \\ \\ \\____  \\ \\  __ \\  \\ \\ \\/\\ \\  \\ \\ \\  \\/_/\\_\\/_     \\ \\ \\  \n");
    printf("                     \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\   /\\_\\/\\_\\     \\ \\_\\ \n");
    printf("                      \\/_____/   \\/_/\\/_/   \\/_____/   \\/_/   \\/_/\\/_/      \\/_/ \n\n");
}


int getch() {
    struct termios ancient, nouveaut; 
    int ch; 
    tcgetattr(STDIN_FILENO, &ancient); 
    nouveaut = ancient; 
    nouveaut.c_lflag &= ~(ICANON | ECHO);  
    tcsetattr(STDIN_FILENO, TCSANOW, &nouveaut); 
    ch = getchar();  
    tcsetattr(STDIN_FILENO, TCSANOW, &ancient); 
    return ch; 
}

int afficherMenu(char* menu[], int tailleMenu, int joueur, Poke* Pokemon[18]) { 
    int choix = 0;  
    int touche;

    while (1) { 
        afficherTitre1(); // affichage choix j1 si c'est a lui de choisir
        for (int i = 0; i < tailleMenu; i++) {
            if (i == choix) {
                printf("                                               > %s <\n", menu[i]);
            } else {
                printf("                                                %s\n", menu[i]);  
            }
        }
        printf("\n%s", Pokemon[choix]->description);
        for(int i=0; i<13 ; i++) {
            printf("\n                     %s", Pokemon[choix]->repgraph[i]);
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
        system("clear");
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


int main() { //fonction principale
      srand(time(NULL));
    Poke* Pokemon[18];
    for (int i = 0; i < 18; i++) {
         Pokemon[i] = malloc(sizeof(Poke));
    }

    Pokemon[0]->name="Evoli"; // structure pokemon évoli
    Pokemon[0]->type=0;  // type correspondant ici normal
    Pokemon[0]->pvmax=100; // nombre pv
    Pokemon[0]->pvactuel=Pokemon[0]->pvmax; // pv actuel mis au max
    Pokemon[0]->vitmax=rand()%101+80; // vit aleatoire entre 80 et 100
    Pokemon[1]->vitactuel=Pokemon[0]->vitmax; // vit actuelle mis a vitmax
    Pokemon[0]->attmax=rand()%101+80; // att aleatoire entre 80 et 100
    Pokemon[1]->attactuel=Pokemon[0]->attmax; // att actuel mis a att max
    Pokemon[0]->agi=rand()%6; // aleatoire entre O et 6 %
    Pokemon[0]->defmax=rand()%21+10; // def aleatoire entre 10 et 20
    Pokemon[0]->defactuel=Pokemon[0]->defmax; // def actuel mis a defmax
    char* graphevoli[13]= {"        \\ '.           .' /","         \\  \\ .---. .-' /","          '. '     `\\_.'","            |(),()  |     ,","            (  __   /   .' \\","           .''.___.'--,/\\_,|","          {  /     \\   }   |","           '.\\     /_.'    /","            |'-.-',  `; _.'","            |  |  |   |`","            `\"\"`\"\"`\"\"\"`","",""}; //rep graphique du pokemon
    for(int i=0 ; i<13 ; i++) {
         Pokemon[0]->repgraph[i]=graphevoli[i]; // rep graphique transmis au tableau
    }
    Pokemon[0]->description="Pokemon de type normal \nUn Pokémon rare qui change d'apparence et d'aptitudes \nau moment d'évoluer en fonction du milieu hostile auquel il veut s'adapter.\n"; // breve description
    Pokemon[0]->talent=3; // talent du pokemon


    Pokemon[1]->name="Miaouss"; // structure pokemon miaouss
    Pokemon[1]->type=0;
    Pokemon[1]->pvmax=100;
    Pokemon[1]->pvactuel=Pokemon[1]->pvmax;
    Pokemon[1]->vitmax=rand()%101+80;
    Pokemon[1]->vitactuel=Pokemon[1]->vitmax;
    Pokemon[1]->attmax=rand()%101+80;
    Pokemon[1]->attactuel=Pokemon[1]->vitmax;
    Pokemon[1]->agi=rand()%6;
    Pokemon[1]->defmax=rand()%21+10;
    Pokemon[1]->defactuel=Pokemon[1]->defmax;
    char* graphmiaouss[13]= {"               .-. \\_/ .-. ","               \\.-\\/=\\/.-/","            '-./___|=|___\\.-'","           .--| \\|/`\"`\\|/ |--.","          (((_)\\  .---.  /(_)))","           `\\ \\_`-.   .-'_/ /`_","             '.__       __.'(_))", "                 /     \\     //","                |       |__.'/","                \\       /--'`","            .--,-' .--. '----.","           '----`--'  '--`----'",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[1]->repgraph[i]=graphmiaouss[i];
    }
    Pokemon[1]->description="Pokemon de type normal \nMiaouss peut rentrer ses griffes dans ses pattes pour \nrôder gracieusement sans laisser de traces. Étrangement, ce Pokémon raffole\ndes pièces d'or qui brillent à la lumière.\n";
    Pokemon[1]->talent=2;


    Pokemon[2]->name="Porygon"; // structure pokemon porygon
    Pokemon[2]->type=0;
    Pokemon[2]->pvmax=100;
    Pokemon[2]->pvactuel=Pokemon[2]->pvmax;
    Pokemon[2]->vitmax=rand()%101+80;
    Pokemon[2]->vitactuel=Pokemon[2]->vitmax;
    Pokemon[2]->attmax=rand()%101+80;
    Pokemon[2]->attactuel=Pokemon[2]->vitmax;
    Pokemon[2]->agi=rand()%6;
    Pokemon[2]->defmax=rand()%21+10;
    Pokemon[2]->defactuel=Pokemon[2]->defmax;
    char* graphporygon[13]={"                ______    __","               / .__. \\  /  /","               \\__\\/__/ /  /","               /      \\/  /","            ___|      |__/","           /    \\____/    \\","          /____/      \\____\\","","","","","",""};
    for(int i=0 ; i<13 ; i++) {
           Pokemon[2]->repgraph[i]=graphporygon[i];
    }
    Pokemon[2]->description="Pokemon de type noraml \nPorygon est capable de se décompiler et de retourner à\n l'état de programme informatique pour entrer dans le cyberespace. Ce Pokémon\n est protégé contre le piratage, il est donc impossible de le copier.\n";
    Pokemon[2]->talent=2;

    Pokemon[3]->name="Aspicot"; // structure pokemon aspicot
    Pokemon[3]->type=5;
    Pokemon[3]->pvmax=100;
    Pokemon[3]->pvactuel=Pokemon[3]->pvmax;
    Pokemon[3]->vitmax=rand()%101+80;
    Pokemon[3]->vitactuel=Pokemon[3]->vitmax;
    Pokemon[3]->attmax=rand()%101+80;
    Pokemon[3]->agi=rand()%6;
    Pokemon[3]->defmax=rand()%21+10;
    Pokemon[3]->defactuel=Pokemon[3]->defmax;
    char* graphaspicot[13]= {"              _/\\___//","            _/ O   @=","           (__     /\\\\     ___________","              O   |       /    ____   \\","              |   \\      /    /    \\   \\","              \\    \\----/    /      | /","               \\____________/     <oO/","","","","","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[3]->repgraph[i]=graphaspicot[i];
    }
    Pokemon[3]->description="Pokemon de type plante \nL'odorat d'Aspicot est extrêmement développé. Il lui \nsuffit de renifler ses feuilles préférées avec son gros appendice nasal pour les \nreconnaître entre mille.\n";
    Pokemon[3]->talent=1;


    Pokemon[4]->name="Mystherbe"; // structure pokemon mystherbe
    Pokemon[4]->type=0;
    Pokemon[4]->pvmax=100;
    Pokemon[4]->pvactuel=Pokemon[4]->pvmax;
    Pokemon[4]->vitmax=rand()%101+80;
    Pokemon[4]->vitactuel=Pokemon[4]->vitmax;
    Pokemon[4]->attmax=rand()%101+80;
    Pokemon[4]->attactuel=Pokemon[4]->vitmax;
    Pokemon[4]->agi=rand()%6;
    Pokemon[4]->defmax=rand()%21+10;
    Pokemon[4]->defactuel=Pokemon[4]->defmax;
    char* graphmystherbe[13]={"      /\\/\\ |\\","      \\ \\ \\//","      / o_o\\","      \\____/","      /_\\/_\\","","","","","","","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[4]->repgraph[i]=graphmystherbe[i];
    }
    Pokemon[4]->description="Pokemon de type plante \nPendant la journée, Mystherbe s'enterre dans le sol pour\n absorber avec son corps tout entier les nutriments présents dans la terre. Plus \nle sol est fertile, plus ses feuilles sont brillantes.\n";
    Pokemon[4]->talent=2;


    Pokemon[5]->name="Bulbizarre"; // structure pokemon bulbizarre
    Pokemon[5]->type=5;
    Pokemon[5]->pvmax=100;
    Pokemon[5]->pvactuel=Pokemon[5]->pvmax;
    Pokemon[5]->vitmax=rand()%101+80;
    Pokemon[5]->vitactuel=Pokemon[5]->vitmax;
    Pokemon[5]->attmax=rand()%101+80;
    Pokemon[5]->attactuel=Pokemon[5]->vitmax;
    Pokemon[5]->agi=rand()%6;
    Pokemon[5]->defmax=rand()%21+10;
    Pokemon[5]->defactuel=Pokemon[5]->defmax;
    char* graphbulbi[13]= {"               __","          ____-  -____","         /            \\","        /\\____________/\\","       /  /´¯\\    /¯`\\  \\","       \\  \\ º/    \\º / /","        \\ .·´¯`v´¯`·. /","       / \\¨\\______/¨ /  \\","      |  |¯¯¯¯¯¯¯¯¯¯¯|  |","      IooI           IooI","","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[5]->repgraph[i]=graphbulbi[i];
    }
    Pokemon[5]->description="Pokemon de type plante \nBulbizarre passe son temps à faire la sieste sous le \nsoleil. Il y a une graine sur son dos. Il absorbe les rayons du soleil pour faire \ndoucement pousser la graine.";
    Pokemon[5]->talent=3;


    Pokemon[6]->name="Onix"; // structure pokemon onix
    Pokemon[6]->type=0;
    Pokemon[6]->pvmax=100;
    Pokemon[6]->pvactuel=Pokemon[6]->pvmax;
    Pokemon[6]->vitmax=rand()%101+80;
    Pokemon[6]->vitactuel=Pokemon[6]->vitmax;
    Pokemon[6]->attmax=rand()%101+80;
    Pokemon[6]->attactuel=Pokemon[6]->vitmax;
    Pokemon[6]->agi=rand()%6;
    Pokemon[6]->defmax=rand()%21+10;
    Pokemon[6]->defactuel=Pokemon[6]->defmax;
    char* graphonix[13]= {"       _____   _______","     /       \\/   |    \\","   / |        |   |    |","  |  \\_______/\\,__|__, /","   \\____/    / _.\\|  /._\\","   /    \\    \\_  ,     _/","   |    |      \\__|.__/","   \\___/_       \\!!!!/         ()","    /    \\               ___  _/\\","    |    |    ____  ___ /   \\/ \\/","    \\____/,,_/    \\/   \\     \\_/","      \\     |     |     |\\__/","       \\____\\_____\\/___/"};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[6]->repgraph[i]=graphonix[i];
    }
    Pokemon[6]->description="Pokemon de type sol \nOnix a dans le cerveau un aimant qui lui sert de boussole. \nIl permet à ce Pokémon de ne pas se perdre pendant qu'il creuse. En prenant de \nl'âge, son corps s'arrondit et se polit.";
    Pokemon[6]->talent=0;


    Pokemon[7]->name="Taupiqueur"; // strducture pokemon taupiqueur
    Pokemon[7]->type=1;
    Pokemon[7]->pvmax=100;
    Pokemon[7]->pvactuel=Pokemon[7]->pvmax;
    Pokemon[7]->vitmax=rand()%101+80;
    Pokemon[7]->vitactuel=Pokemon[7]->vitmax;
    Pokemon[7]->attmax=rand()%101+80;
    Pokemon[7]->attactuel=Pokemon[7]->vitmax;
    Pokemon[7]->agi=rand()%6;
    Pokemon[7]->defmax=rand()%21+10;
    Pokemon[7]->defactuel=Pokemon[7]->defmax;
    char* graphtaupi[13]= {"                .'''''.         ","               ;        ;        ","              ;  HP  HP  ;       ","             ;   H   H    ;      ","             ;     ___    ;      ","             ;    (___)   ;      ","             ;            ;      ","             ;            ;      ","            h;            ;g     ","          jg ggh      hgj gggf   ","        og  h   hgfgfj   f  j ghg","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[7]->repgraph[i]=graphtaupi[i];
    }
    Pokemon[7]->description="Pokemon de type sol \nCe Pokémon creuse sous terre à faible profondeur. La terre \nqu'il laisse dans son sillage le rend facile à repérer.";
    Pokemon[7]->talent=0;
    

    Pokemon[8]->name="Racaillou"; // structure pokemon racaillou
    Pokemon[8]->type=1;
    Pokemon[8]->pvmax=100;
    Pokemon[8]->pvactuel=Pokemon[8]->pvmax;
    Pokemon[8]->vitmax=rand()%101+80;
    Pokemon[8]->vitactuel=Pokemon[8]->vitmax;
    Pokemon[8]->attmax=rand()%101+80;
    Pokemon[8]->attactuel=Pokemon[8]->vitmax;
    Pokemon[8]->agi=rand()%6;
    Pokemon[8]->defmax=rand()%21+10;
    Pokemon[8]->defactuel=Pokemon[8]->defmax;
    char* graphcaillou[13] = {"  ______"," / _\\_\\_\\"," \\_;  ,()                     ______","  |  |        _______        /\\_\\_\\_\\","  \\  \\       ,       ,       ()    _/","   \\  \\     /         \\       \\   _|","    \\  \\__,/.  .\\  /. /\\       / /","     \\_=____\\  ______/\\ \\_____/ /","             \\/_____,| \\___==__/","","","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[8]->repgraph[i]=graphcaillou[i];
    }
    Pokemon[8]->description="Pokemon de type sol \nLorsqu'un Racaillou prend de l'âge, ses bords s'ébrèchent et \ns'usent, ce qui lui donne une apparence plus ronde. Cependant, le cœur de ce \nPokémon reste dur, rocailleux et rugueux.";
    Pokemon[8]->talent=0;


    Pokemon[9]->name="Pikachu"; // structure pokemon pikachu
    Pokemon[9]->type=2;
    Pokemon[9]->pvmax=100;
    Pokemon[9]->pvactuel=Pokemon[9]->pvmax;
    Pokemon[9]->vitmax=rand()%101+80;
    Pokemon[9]->vitactuel=Pokemon[9]->vitmax;
    Pokemon[9]->attmax=rand()%101+80;
    Pokemon[9]->attactuel=Pokemon[9]->vitmax;
    Pokemon[9]->agi=rand()%6;
    Pokemon[9]->defmax=rand()%21+10;
    Pokemon[9]->defactuel=Pokemon[9]->defmax;
    char* graphpikachu[13]= {"        /\\       __","        | \\_____/ /","        /         |",    "       / ^.   ^   |",   "       \\0 _   0   |     _","       _\\   _   __|    | |","       \\/   \\  <__|  _/ /","        |       __|_/ _/","        |      <__|__/",   "         \\______/","         /__||__\\","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[9]->repgraph[i]=graphpikachu[i];
    }
    Pokemon[9]->description="Pokemon de type electrique \nSon corps peut accumuler de l'électricité. Les forêts \nabritant des groupes de Pikachu sont d'ailleurs souvent frappées par la foudre.";
    Pokemon[9]->talent=2;


    Pokemon[10]->name="Magneti"; //structure pokemon magneti
    Pokemon[10]->type=2;
    Pokemon[10]->pvmax=100;
    Pokemon[10]->pvactuel=Pokemon[10]->pvmax;
    Pokemon[10]->vitmax=rand()%101+80;
    Pokemon[10]->vitactuel=Pokemon[10]->vitmax;
    Pokemon[10]->attmax=rand()%101+80;
    Pokemon[10]->attactuel=Pokemon[10]->vitmax;
    Pokemon[10]->agi=rand()%6;
    Pokemon[10]->defmax=rand()%21+10;
    Pokemon[10]->defactuel=Pokemon[10]->defmax;
    char* graphmagneti[13]= {"               ____","               \\__/","       ___    _I///I_    __","       I_I\\__/       \\__/I_I","         _ )__ ( o )  __(_","       I_I_/ /\\_____/\\ \\_I_I","         _/I/         \\I\\_","         \\ I          I  /","","","","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[10]->repgraph[i]=graphmagneti[i];
    }
    Pokemon[10]->description="Pokemon de type electrique \nMagnéti s'attache aux lignes à haute tension pour se \ncharger en électricité. Si une maison a une panne de courant, il est conseillé de \nvérifier les fusibles car on trouve parfois ces Pokémon amassés sur la boîte à fusibles.";
    Pokemon[10]->talent=1;


    Pokemon[11]->name="Electrode"; // structure pokemon electrode
    Pokemon[11]->type=0;
    Pokemon[11]->pvmax=100;
    Pokemon[11]->pvactuel=Pokemon[11]->pvmax;
    Pokemon[11]->vitmax=rand()%101+80;
    Pokemon[11]->vitactuel=Pokemon[11]->vitmax;
    Pokemon[11]->attmax=rand()%101+80;
    Pokemon[11]->attactuel=Pokemon[11]->vitmax;
    Pokemon[11]->agi=rand()%6;
    Pokemon[11]->defmax=rand()%21+10;
    Pokemon[11]->defactuel=Pokemon[11]->defmax;
    char* graphelectrode[13]= {"                   ..-----..       ","                 .'_        '.    ","                : ( O-_)  .-~~:    ","               :  `-..'   `O_.-:   ","              :   __--~~~~--..  :  ","              :-~~            ~~: ","              :                 : ","               :               :  ","                :     ...     :   ","                 '.  '...'  .'    ","                   ''-----''      ","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[11]->repgraph[i]=graphelectrode[i];
    }
    Pokemon[11]->description="Pokemon de type electrique \nPlus il accumule de l'énergie de type Électrik, plus il \nest rapide. Mais il a aussi davantage de chances d'exploser.";
    Pokemon[11]->talent=3;


    Pokemon[12]->name="Carapuce"; // structure pokemon carapuce
    Pokemon[12]->type=4;
    Pokemon[12]->pvmax=100;
    Pokemon[12]->pvactuel=Pokemon[12]->pvmax;
    Pokemon[12]->vitmax=rand()%101+80;
    Pokemon[12]->vitactuel=Pokemon[12]->vitmax;
    Pokemon[12]->attmax=rand()%101+80;
    Pokemon[12]->attactuel=Pokemon[12]->vitmax;
    Pokemon[12]->agi=rand()%6;
    Pokemon[12]->defmax=rand()%21+10;
    Pokemon[12]->defactuel=Pokemon[12]->defmax;
    char* graphcarapuce[13]= {"             _____","           ,`o   o \\","          ` \\____/ ‘","          `,______,`","  ,--------/   \\  \\____,","  ‘--------|___|__|____/","    /  \\   | __  _\\","    |  /__\\/  \\ /  \\","    \\_____ \\  / \\  |","           ^^^^ ^^^^","","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[12]->repgraph[i]=graphcarapuce[i];
    }
    Pokemon[12]->description="Pokemon de type eau \nLa carapace de Carapuce ne sert pas qu'à le protéger. La forme \nronde de sa carapace et ses rainures lui permettent d'améliorer son \nhydrodynamisme. Ce Pokémon nage extrêmement vite.";
    Pokemon[12]->talent=2;


    Pokemon[13]->name="Psykokwak"; // structure pokemon psykokwak
    Pokemon[13]->type=4;
    Pokemon[13]->pvmax=100;
    Pokemon[13]->pvactuel=Pokemon[13]->pvmax;
    Pokemon[13]->vitmax=rand()%101+80;
    Pokemon[13]->vitactuel=Pokemon[13]->vitmax;
    Pokemon[13]->attmax=rand()%101+80;
    Pokemon[13]->attactuel=Pokemon[13]->vitmax;
    Pokemon[13]->agi=rand()%6;
    Pokemon[13]->defmax=rand()%21+10;
    Pokemon[13]->defactuel=Pokemon[13]->defmax;
    char* graphpsyko[13]={"           ____ ","         /(')(')\\","       /\\  \\''/ //\\","       \\/        \\/","         \\      />","          \\_/\\_/","","","","","","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[13]->repgraph[i]=graphpsyko[i];
    }
    Pokemon[13]->description="Pokemon de type eau \nPsykokwak utilise un mystérieux pouvoir. Ce Pokémon peut générer \ndes ondes cérébrales normalement observées chez les dormeurs. Cette \ndécouverte a lancé une polémique dans le milieu universitaire.";
    Pokemon[13]->talent=1;
        

    Pokemon[14]->name="Wailmer"; // structure pokemon wailmer
    Pokemon[14]->type=4;
    Pokemon[14]->pvmax=100;
    Pokemon[14]->pvactuel=Pokemon[14]->pvmax;
    Pokemon[14]->vitmax=rand()%101+80;
    Pokemon[14]->vitactuel=Pokemon[14]->vitmax;
    Pokemon[14]->attmax=rand()%101+80;
    Pokemon[14]->attactuel=Pokemon[14]->vitmax;
    Pokemon[14]->agi=rand()%6;
    Pokemon[14]->defmax=rand()%21+10;
    Pokemon[14]->defactuel=Pokemon[14]->defmax;
    char* graphwailmer[13]= {"       .","      \":\"","    ___:____     |\"\\/\"|","  ,'        `.    \\  /","  |  O        \\___/  |","~^~^~^~^~^~^~^~^~^~^~^~^~","","","","","","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[14]->repgraph[i]=graphwailmer[i];
    }
    Pokemon[14]->description="Pokemon de type eau \nLes narines de Wailmer sont situées au-dessus de ses yeux. Ce joyeux \nPokémon adore effrayer les gens en expulsant de l'eau de mer \npar les narines.";
    Pokemon[14]->talent=3;
    

    Pokemon[15]->name="Flamiaou"; // structure pokemon flamiaou
    Pokemon[15]->type=3;
    Pokemon[15]->pvmax=100;
    Pokemon[15]->pvactuel=Pokemon[15]->pvmax;
    Pokemon[15]->vitmax=rand()%101+80;
    Pokemon[15]->vitactuel=Pokemon[15]->vitmax;
    Pokemon[15]->attmax=rand()%101+80;
    Pokemon[15]->attactuel=Pokemon[15]->vitmax;
    Pokemon[15]->agi=rand()%6;
    Pokemon[15]->defmax=rand()%21+10;
    Pokemon[15]->defactuel=Pokemon[15]->defmax;
    char* graphflamiaou[13]= {" /\\     /\\","{  `---'  }","{  O   O  }","~~>  V  <~~"," \\  \\|/  /","  `-----'____","  /     \\    \\_"," {       }\\  )_\\_   _"," |  \\_/  |/ /  \\_\\_/ )","  \\__/  /(_/     \\__/","    (__/","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[15]->repgraph[i]=graphflamiaou[i];
    }
    Pokemon[15]->description="Pokemon de type feu \n Dès qu'il a un instant, il fait sa toilette. Il déclenche ses attaques \nFeu en enflammant les poils qu'il a avalés en se léchant.";
    Pokemon[15]->talent=2;


    Pokemon[16]->name="Funecire"; // structure pokemon funecire
    Pokemon[16]->type=4;
    Pokemon[16]->pvmax=100;
    Pokemon[16]->pvactuel=Pokemon[16]->pvmax;
    Pokemon[16]->vitmax=rand()%101+80;
    Pokemon[16]->vitactuel=Pokemon[16]->vitmax;
    Pokemon[16]->attmax=rand()%101+80;
    Pokemon[16]->attactuel=Pokemon[16]->vitmax;
    Pokemon[16]->agi=rand()%6;
    Pokemon[16]->defmax=rand()%21+10;
    Pokemon[16]->defactuel=Pokemon[16]->defmax;
    char* graphfunecire[13]={"       )\\","       {_}","      .-;-.","     |'-=-'|","     |     |","     | ° ° |","     |     |","     |     |","     '.___.'","","","",""};
    for(int i=0 ; i<13 ; i++) {
         Pokemon[16]->repgraph[i]=graphfunecire[i];
    }
    Pokemon[16]->description="Pokemon de type feu \nSon corps est tiède, réchauffé par sa flamme. Il prend les personnes égarées \npar la main et les guide vers le monde des esprits.";
    Pokemon[16]->talent=3;


    Pokemon[17]->name="Chartor"; // structure pokemon chartor
    Pokemon[17]->type=4;
    Pokemon[17]->pvmax=100;
    Pokemon[17]->pvactuel=Pokemon[17]->pvmax;
    Pokemon[17]->vitmax=rand()%101+80;
    Pokemon[17]->vitactuel=Pokemon[17]->vitmax;
    Pokemon[17]->attmax=rand()%101+80;
    Pokemon[17]->attactuel=Pokemon[17]->vitmax;
    Pokemon[17]->agi=rand()%6;
    Pokemon[17]->defmax=rand()%21+10;
    Pokemon[17]->defactuel=Pokemon[17]->defmax;
    char* graphchartor[13]={"                  __","       .,-;-;-,. /'_\\","     _/_/_/_|_\\_) /","   '-<_><_><_><_>=/\\","     `/_/====/_/-'\\_\\","      \"\"     \"\"    \"\"","","","","","","",""};
    for(int i=0 ; i<13 ; i++) {
        Pokemon[17]->repgraph[i]=graphchartor[i];
    }
    Pokemon[17]->description="Pokemmon de type feu \nUn bon indicateur de sa santé est le débit de la fumée qui s'échappe de sa \ncarapace: s'il est important, c'est qu'il est en pleine forme.";
    Pokemon[17]->talent=1;
    

    char* menu[18] = {"Evoli", "Miaouss", "Porygon","Aspicot","Mystherbe","Bbulbizarre","Onix","Taupiqueur","Racaillou","Pikachu","Magneti","Electrode","Carapuce","Psykokwak","Wailmer","Flamiaou","Funecire","Chartor"}; //diferent element du menu
    int choix = afficherMenu(menu, 18, 1, Pokemon); // choix du pokemon du j1
    Poke* joueur=Pokemon[choix]; // pokemon choisi inserer dans l'equipe
    system("clear");
    return 0;
}