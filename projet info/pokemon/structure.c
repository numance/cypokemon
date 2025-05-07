#include "structure.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

Poke* listepoke(int i) {
      srand(time(NULL));
    Poke* Pokemon[18];
    for (int i = 0; i < 18; i++) {
         Pokemon[i] = malloc(sizeof(Poke));
    }

    
    Pokemon[0]->name = "Evoli     "; 
    Pokemon[0]->type = 0;  
    Pokemon[0]->pvmax = 100; 
    Pokemon[0]->pvactuel = Pokemon[0]->pvmax;
    Pokemon[0]->vit = rand() % 21 + 120; 
    Pokemon[0]->attmax = (rand() % 3 + 10) / 10.0;
    Pokemon[0]->attactuel = Pokemon[0]->attmax; 
    Pokemon[0]->agi = rand() % 6; 
    Pokemon[0]->defmax = (rand() % 3 + 10) / 10.0;
    Pokemon[0]->defactuel = Pokemon[0]->defmax; 
    Pokemon[0]->statut=0;

    // Graphique du Pokémon
    char* graphevoli[13] = {
    "",
    "        \\ '.           .' /",
    "         \\  \\ .---. .-' /",
    "          '. '     `\\_.'",
    "            |(),()  |     ,",
    "            (  __   /   .' \\",
    "           .''.___.'--,/\\_,|",
    "          {  /     \\   }   |",
    "           '.\\     /_.'    /",
    "            |'-.-',  `; _.'",
    "            |  |  |   |`",
    "            `\"\"`\"\"`\"\"\"`",
    "",
    };
    for (int i = 0; i < 13; i++) {
        Pokemon[0]->repgraph[i] = graphevoli[i]; 
    }

    Pokemon[0]->description = "Pokemon de type normal \nUn Pokémon rare qui change d'apparence et d'aptitudes \nau moment d'évoluer en fonction du milieu hostile auquel il veut s'adapter.\n"; // Brève description
    for (int i = 0; i < 4; i++) {
        Pokemon[0]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[0]->attaque[0]->nom = "mimi-queue";
    Pokemon[0]->attaque[0]->degat = 0.8;
    Pokemon[0]->attaque[0]->reussite = 80;
    Pokemon[0]->attaque[0]->fonction = 5;

    Pokemon[0]->attaque[1]->nom = "charge";
    Pokemon[0]->attaque[1]->degat = 25;
    Pokemon[0]->attaque[1]->reussite = 90;
    Pokemon[0]->attaque[1]->fonction = 0;

    Pokemon[0]->attaque[2]->nom = "vive-attaque";
    Pokemon[0]->attaque[2]->degat = 30;
    Pokemon[0]->attaque[2]->reussite = 80;
    Pokemon[0]->attaque[2]->fonction = 0;

    Pokemon[0]->attaque[3]->nom = "bélier";
    Pokemon[0]->attaque[3]->degat = 35;
    Pokemon[0]->attaque[3]->reussite = 70;
    Pokemon[0]->attaque[3]->fonction = 0;

    Pokemon[0]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[0]->attspe->nom="vitesse lumiere";
    Pokemon[0]->attspe->fonction=0;
    Pokemon[0]->attspe->effet_spe_tempo=0;
    Pokemon[0]->attspe->tempsrecharge=5;
    Pokemon[0]->attspe->tempsrechargeact=0;


    Pokemon[1]->name="Miaouss   "; // structure pokemon miaouss
    Pokemon[1]->type=0;
    Pokemon[1]->pvmax=110;
    Pokemon[1]->pvactuel=Pokemon[1]->pvmax;
    Pokemon[1]->vit=rand()%21 + 110;
    Pokemon[1]->attmax=(rand() % 3 + 10) / 10.0;
    Pokemon[1]->attactuel=Pokemon[1]->attmax;
    Pokemon[1]->agi=rand()%6;
    Pokemon[1]->defmax=(rand() % 3 + 10) / 10.0;
    Pokemon[1]->defactuel=Pokemon[1]->defmax;
    Pokemon[1]->statut=0;
    char* graphmiaouss[13] = {
    "",
    "               .-. \\_/ .-. ",
    "               \\.-\\/=\\/.-/",
    "            '-./___|=|___\\.-'",
    "           .--| \\|/`\"`\\|/ |--.",
    "          (((_)\\  .---.  /(_)))",
    "           `\\ \\_`-.   .-'_/ /`_",
    "             '.__       __.'(_))",
    "                 /     \\     //",
    "                |       |__.'/",
    "                \\       /--'`",
    "            .--,-' .--. '----.",
    "           '----`--'  '--`----'",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[1]->repgraph[i]=graphmiaouss[i];
    }
    Pokemon[1]->description="Pokemon de type normal \nMiaouss peut rentrer ses griffes dans ses pattes pour \nrôder gracieusement sans laisser de traces. Étrangement, ce Pokémon raffole\ndes pièces d'or qui brillent à la lumière.\n";
    for(int i=0; i<4 ; i++) {
        Pokemon[1]->attaque[i] = malloc(sizeof(Attaque));
    }
    Pokemon[1]->attaque[0]->nom="soin";
    Pokemon[1]->attaque[0]->degat=30;
    Pokemon[1]->attaque[0]->reussite=80;
    Pokemon[1]->attaque[0]->fonction=1;

    Pokemon[1]->attaque[1]->nom="charge";
    Pokemon[1]->attaque[1]->degat=25;
    Pokemon[1]->attaque[1]->reussite=90;
    Pokemon[1]->attaque[1]->fonction=0;

    Pokemon[1]->attaque[2]->nom="damocles";
    Pokemon[1]->attaque[2]->degat=1.2;
    Pokemon[1]->attaque[2]->reussite=80;
    Pokemon[1]->attaque[2]->fonction=3;

    Pokemon[1]->attaque[3]->nom="plaquage";
    Pokemon[1]->attaque[3]->degat=35;
    Pokemon[1]->attaque[3]->reussite=70;
    Pokemon[1]->attaque[3]->fonction=0;

    Pokemon[1]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[1]->attspe->nom="griffure ultime";
    Pokemon[1]->attspe->fonction=0;
    Pokemon[1]->attspe->effet_spe_tempo=0;
    Pokemon[1]->attspe->tempsrecharge=5;
    Pokemon[1]->attspe->tempsrechargeact=0;



    Pokemon[2]->name="Porygon   "; // structure pokemon porygon
    Pokemon[2]->type=0;
    Pokemon[2]->pvmax=100;
    Pokemon[2]->pvactuel=Pokemon[2]->pvmax;
    Pokemon[2]->vit=rand()%21 + 100;
    Pokemon[2]->attmax=(rand() % 3 + 10) / 10.0;
    Pokemon[2]->attactuel=Pokemon[2]->attmax;
    Pokemon[2]->agi=rand()%6;
    Pokemon[2]->defmax=(rand() % 3 + 10) / 10.0;
    Pokemon[2]->defactuel=Pokemon[2]->defmax;
    Pokemon[2]->statut=0;
    char* graphporygon[13] = {
    "",
    "",
    "",
    "                ______    __",
    "               / .__. \\  /  /",
    "               \\__\\/__/ /  /",
    "               /      \\/  /",
    "            ___|      |__/",
    "           /    \\____/    \\",
    "          /____/      \\____\\",
    "",
    "",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[2]->repgraph[i]=graphporygon[i];
    }
    Pokemon[2]->description="Pokemon de type noraml \nPorygon est capable de se décompiler et de retourner à\n l'état de programme informatique pour entrer dans le cyberespace. Ce Pokémon\n est protégé contre le piratage, il est donc impossible de le copier.\n";
    for (int i = 0; i < 4; i++) {
        Pokemon[2]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[2]->attaque[0]->nom = "intimidation";
    Pokemon[2]->attaque[0]->degat = 0.8;
    Pokemon[2]->attaque[0]->reussite = 80;
    Pokemon[2]->attaque[0]->fonction = 5;

    Pokemon[2]->attaque[1]->nom = "impact";
    Pokemon[2]->attaque[1]->degat = 25;
    Pokemon[2]->attaque[1]->reussite = 90;
    Pokemon[2]->attaque[1]->fonction = 0;

    Pokemon[2]->attaque[2]->nom = "high tech";
    Pokemon[2]->attaque[2]->degat = 1.2;
    Pokemon[2]->attaque[2]->reussite = 80;
    Pokemon[2]->attaque[2]->fonction = 2;

    Pokemon[2]->attaque[3]->nom = "decoupage";
    Pokemon[2]->attaque[3]->degat = 35;
    Pokemon[2]->attaque[3]->reussite = 70;
    Pokemon[2]->attaque[3]->fonction = 0;

    Pokemon[2]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[2]->attspe->nom="bug technologique";
    Pokemon[2]->attspe->fonction=3;
    Pokemon[2]->attspe->effet_spe_tempo=2;
    Pokemon[2]->attspe->tempsrecharge=3;
    Pokemon[2]->attspe->tempsrechargeact=0;



    Pokemon[3]->name="Aspicot   "; // structure pokemon aspicot
    Pokemon[3]->type=5;
    Pokemon[3]->pvmax=90;
    Pokemon[3]->pvactuel=Pokemon[3]->pvmax;
    Pokemon[3]->vit=rand()%21 + 95;
    Pokemon[3]->attmax=(rand() % 3 + 10) / 10.0;
    Pokemon[3]->attactuel=Pokemon[3]->attmax;
    Pokemon[3]->agi=rand()%6;
    Pokemon[3]->defmax=(rand() % 3 + 10) / 10.0;
    Pokemon[3]->defactuel=Pokemon[3]->defmax;
    Pokemon[3]->statut=0;
    char* graphaspicot[13] = {
    "",
    "",
    "",
    "              _/\\___//",
    "            _/ O   @=",
    "           (__     /\\\\     ___________",
    "              O   |       /    ____   \\",
    "              |   \\      /    /    \\   \\",
    "              \\    \\----/    /      | /",
    "               \\____________/     <oO/",
    "",
    "",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[3]->repgraph[i]=graphaspicot[i];
    }
    Pokemon[3]->description="Pokemon de type plante \nL'odorat d'Aspicot est extrêmement développé. Il lui \nsuffit de renifler ses feuilles préférées avec son gros appendice nasal pour les \nreconnaître entre mille.\n";
    for (int i = 0; i < 4; i++) {
        Pokemon[3]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[3]->attaque[0]->nom = "soin";
    Pokemon[3]->attaque[0]->degat = 20;
    Pokemon[3]->attaque[0]->reussite = 90;
    Pokemon[3]->attaque[0]->fonction = 1;

    Pokemon[3]->attaque[1]->nom = "fouet liane";
    Pokemon[3]->attaque[1]->degat = 25;
    Pokemon[3]->attaque[1]->reussite = 90;
    Pokemon[3]->attaque[1]->fonction = 0;

    Pokemon[3]->attaque[2]->nom = "lance toile";
    Pokemon[3]->attaque[2]->degat = 0.8;
    Pokemon[3]->attaque[2]->reussite = 80;
    Pokemon[3]->attaque[2]->fonction = 2;

    Pokemon[3]->attaque[3]->nom = "feuillage";
    Pokemon[3]->attaque[3]->degat = 35;
    Pokemon[3]->attaque[3]->reussite = 70;
    Pokemon[3]->attaque[3]->fonction = 0;

    Pokemon[3]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[3]->attspe->nom="poison venimeux";
    Pokemon[3]->attspe->fonction=3;
    Pokemon[3]->attspe->effet_spe_tempo=2;
    Pokemon[3]->attspe->tempsrecharge=3;
    Pokemon[3]->attspe->tempsrechargeact=3;




    Pokemon[4]->name="Mystherbe "; // structure pokemon mystherbe
    Pokemon[4]->type=5;
    Pokemon[4]->pvmax=90;
    Pokemon[4]->pvactuel=Pokemon[4]->pvmax;
    Pokemon[4]->vit=rand()%21 + 100;
    Pokemon[4]->attmax=(rand() % 3 + 10) / 10.0;
    Pokemon[4]->attactuel=Pokemon[4]->attmax;
    Pokemon[4]->agi=rand()%6;
    Pokemon[4]->defmax=(rand() % 3 + 10) / 10.0;
    Pokemon[4]->defactuel=Pokemon[4]->defmax;
    Pokemon[4]->statut=0;
    char* graphmystherbe[13] = {
    "",
    "",
    "",
    "",
    "              /\\/\\ |\\",
    "              \\ \\ \\//",
    "              / o_o\\",
    "              \\____/",
    "              /_\\/_\\",
    "",
    "",
    "",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[4]->repgraph[i]=graphmystherbe[i];
    }
    Pokemon[4]->description="Pokemon de type plante \nPendant la journée, Mystherbe s'enterre dans le sol pour\n absorber avec son corps tout entier les nutriments présents dans la terre. Plus \nle sol est fertile, plus ses feuilles sont brillantes.\n";
    for(int i = 0; i < 4; i++) {
        Pokemon[4]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[4]->attaque[0]->nom = "mimi-queue";
    Pokemon[4]->attaque[0]->degat = 0.8;
    Pokemon[4]->attaque[0]->reussite = 80;
    Pokemon[4]->attaque[0]->fonction = 5;

    Pokemon[4]->attaque[1]->nom = "graine";
    Pokemon[4]->attaque[1]->degat = 25;
    Pokemon[4]->attaque[1]->reussite = 90;
    Pokemon[4]->attaque[1]->fonction = 0;

    Pokemon[4]->attaque[2]->nom = "racine";
    Pokemon[4]->attaque[2]->degat = 30;
    Pokemon[4]->attaque[2]->reussite = 80;
    Pokemon[4]->attaque[2]->fonction = 0;

    Pokemon[4]->attaque[3]->nom = "photosynthese";
    Pokemon[4]->attaque[3]->degat = 40;
    Pokemon[4]->attaque[3]->reussite = 70;
    Pokemon[4]->attaque[3]->fonction = 1;

    Pokemon[4]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[4]->attspe->nom="lianne enlacante";
    Pokemon[4]->attspe->fonction=2;
    Pokemon[4]->attspe->effet_spe_tempo=1;
    Pokemon[4]->attspe->tempsrecharge=5;
    Pokemon[4]->attspe->tempsrechargeact=0;



    Pokemon[5]->name="Bulbizarre"; // structure pokemon bulbizarre
    Pokemon[5]->type=5;
    Pokemon[5]->pvmax=110;
    Pokemon[5]->pvactuel=Pokemon[5]->pvmax;
    Pokemon[5]->vit=rand()%21 + 100;
    Pokemon[5]->attmax=(rand() % 2 + 10) / 10.0;
    Pokemon[5]->attactuel=Pokemon[5]->attmax;
    Pokemon[5]->agi=rand()%6;
    Pokemon[5]->defmax=(rand() % 4 + 10) / 10.0;
    Pokemon[5]->defactuel=Pokemon[5]->defmax;
    Pokemon[5]->statut=0;
    char* graphbulbi[13] = {
    "",
    "",
    "                    __",
    "               ____-  -____",
    "              /            \\",
    "             /\\____________/\\",
    "            /  /´¯\\    /¯`\\  \\",
    "            \\  \\ º/    \\º / /",
    "             \\ .·´¯`v´¯`·. /",
    "            / \\¨\\______/¨ /  \\",
    "           |  |¯¯¯¯¯¯¯¯¯¯¯|  |",
    "           IooI           IooI",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[5]->repgraph[i]=graphbulbi[i];
    }
    Pokemon[5]->description="Pokemon de type plante \nBulbizarre passe son temps à faire la sieste sous le \nsoleil. Il y a une graine sur son dos. Il absorbe les rayons du soleil pour faire \ndoucement pousser la graine.";
    for(int i = 0; i < 4; i++) {
        Pokemon[5]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[5]->attaque[0]->nom = "mimi-queue";
    Pokemon[5]->attaque[0]->degat = 0.8;
    Pokemon[5]->attaque[0]->reussite = 80;
    Pokemon[5]->attaque[0]->fonction = 5;

    Pokemon[5]->attaque[1]->nom = "fouet";
    Pokemon[5]->attaque[1]->degat = 25;
    Pokemon[5]->attaque[1]->reussite = 90;
    Pokemon[5]->attaque[1]->fonction = 0;

    Pokemon[5]->attaque[2]->nom = "lance feuille";
    Pokemon[5]->attaque[2]->degat = 30;
    Pokemon[5]->attaque[2]->reussite = 80;
    Pokemon[5]->attaque[2]->fonction = 0;

    Pokemon[5]->attaque[3]->nom = "photosynthese";
    Pokemon[5]->attaque[3]->degat = 40;
    Pokemon[5]->attaque[3]->reussite = 70;
    Pokemon[5]->attaque[3]->fonction = 1;

    Pokemon[5]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[5]->attspe->nom="bourgeon renaissant";
    Pokemon[5]->attspe->fonction=1;
    Pokemon[5]->attspe->effet_spe_tempo=0;
    Pokemon[5]->attspe->tempsrecharge=4;
    Pokemon[5]->attspe->tempsrechargeact=0;



    Pokemon[6]->name="Onix      "; // structure pokemon onix
    Pokemon[6]->type=1;
    Pokemon[6]->pvmax=120;
    Pokemon[6]->pvactuel=Pokemon[6]->pvmax;
    Pokemon[6]->vit=rand()%21 + 70;
    Pokemon[6]->attmax=(rand() % 1 + 10) / 10.0;
    Pokemon[6]->attactuel=Pokemon[6]->attmax;
    Pokemon[6]->agi=rand()%6;
    Pokemon[6]->defmax=(rand() % 5 + 10) / 10.0;
    Pokemon[6]->defactuel=Pokemon[6]->defmax;
    Pokemon[6]->statut=0;
    char* graphonix[13] = {
    "          _____   _______",
    "        /       \\/   |    \\",
    "      / |        |   |    |",
    "     |  \\_______/\\,__|__, /",
    "      \\____/    / _.\\|  /._\\",
    "      /    \\    \\_  ,     _/",
    "      |    |      \\__|.__/",
    "      \\___/_       \\!!!!/         ()",
    "       /    \\               ___  _/\\",
    "       |    |    ____  ___ /   \\/ \\/",
    "       \\____/,,_/    \\/   \\     \\_/",
    "         \\     |     |     |\\__/",
    "          \\____\\_____\\/___/",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[6]->repgraph[i]=graphonix[i];
    }
    Pokemon[6]->description="Pokemon de type sol \nOnix a dans le cerveau un aimant qui lui sert de boussole. \nIl permet à ce Pokémon de ne pas se perdre pendant qu'il creuse. En prenant de \nl'âge, son corps s'arrondit et se polit.";
    for(int i = 0; i < 4; i++) {
        Pokemon[6]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[6]->attaque[0]->nom = "renforcement";
    Pokemon[6]->attaque[0]->degat = 0.8;
    Pokemon[6]->attaque[0]->reussite = 80;
    Pokemon[6]->attaque[0]->fonction = 4;

    Pokemon[6]->attaque[1]->nom = "lance pierre";
    Pokemon[6]->attaque[1]->degat = 25;
    Pokemon[6]->attaque[1]->reussite = 90;
    Pokemon[6]->attaque[1]->fonction = 0;

    Pokemon[6]->attaque[2]->nom = "eboulement";
    Pokemon[6]->attaque[2]->degat = 30;
    Pokemon[6]->attaque[2]->reussite = 75;
    Pokemon[6]->attaque[2]->fonction = 0;

    Pokemon[6]->attaque[3]->nom = "eclate roc";
    Pokemon[6]->attaque[3]->degat = 35;
    Pokemon[6]->attaque[3]->reussite = 65;
    Pokemon[6]->attaque[3]->fonction = 0;

    Pokemon[6]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[6]->attspe->nom="roche antique";
    Pokemon[6]->attspe->fonction=0;
    Pokemon[6]->attspe->effet_spe_tempo=0;
    Pokemon[6]->attspe->tempsrecharge=5;
    Pokemon[6]->attspe->tempsrechargeact=0;


    Pokemon[7]->name="Taupiqueur"; // strducture pokemon taupiqueur
    Pokemon[7]->type=1;
    Pokemon[7]->pvmax=90;
    Pokemon[7]->pvactuel=Pokemon[7]->pvmax;
    Pokemon[7]->vit=rand()%21+90;
    Pokemon[7]->attmax=(rand() % 2 + 10) / 10.0;
    Pokemon[7]->attactuel=Pokemon[7]->attmax;
    Pokemon[7]->agi=rand()%6;
    Pokemon[7]->defmax=(rand() % 3 + 10) / 10.0;
    Pokemon[7]->defactuel=Pokemon[7]->defmax;
    Pokemon[7]->statut=0;
    char* graphtaupi[13] = {
    "",
    "                .'''''.         ",
    "               ;        ;        ",
    "              ;  HP  HP  ;       ",
    "             ;   H   H    ;      ",
    "             ;     ___    ;      ",
    "             ;    (___)   ;      ",
    "             ;            ;      ",
    "             ;            ;      ",
    "            h;            ;g     ",
    "          jg ggh      hgj gggf   ",
    "        og  h   hgfgfj   f  j ghg",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[7]->repgraph[i]=graphtaupi[i];
    }
    Pokemon[7]->description="Pokemon de type sol \nCe Pokémon creuse sous terre à faible profondeur. La terre \nqu'il laisse dans son sillage le rend facile à repérer.";
    for(int i = 0; i < 4; i++) {
        Pokemon[7]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[7]->attaque[0]->nom = "lance boue";
    Pokemon[7]->attaque[0]->degat = 0.8;
    Pokemon[7]->attaque[0]->reussite = 80;
    Pokemon[7]->attaque[0]->fonction = 3;

    Pokemon[7]->attaque[1]->nom = "pouvoir antique";
    Pokemon[7]->attaque[1]->degat = 25;
    Pokemon[7]->attaque[1]->reussite = 90;
    Pokemon[7]->attaque[1]->fonction = 0;

    Pokemon[7]->attaque[2]->nom = "lame de roc";
    Pokemon[7]->attaque[2]->degat = 30;
    Pokemon[7]->attaque[2]->reussite = 80;
    Pokemon[7]->attaque[2]->fonction = 0;

    Pokemon[7]->attaque[3]->nom = "tunnel";
    Pokemon[7]->attaque[3]->degat = 40;
    Pokemon[7]->attaque[3]->reussite = 70;
    Pokemon[7]->attaque[3]->fonction = 0;

    Pokemon[7]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[7]->attspe->nom="piege de terre";
    Pokemon[7]->attspe->fonction=2;
    Pokemon[7]->attspe->effet_spe_tempo=1;
    Pokemon[7]->attspe->tempsrecharge=5;
    Pokemon[7]->attspe->tempsrechargeact=0;
    

    Pokemon[8]->name="Racaillou "; // structure pokemon racaillou
    Pokemon[8]->type=1;
    Pokemon[8]->pvmax=110;
    Pokemon[8]->pvactuel=Pokemon[8]->pvmax;
    Pokemon[8]->vit=rand()%21+80;
    Pokemon[8]->attmax=(rand() % 2 + 10) / 10.0;
    Pokemon[8]->attactuel=Pokemon[8]->attmax;
    Pokemon[8]->agi=rand()%6;
    Pokemon[8]->defmax=(rand() % 4 + 10) / 10.0;
    Pokemon[8]->defactuel=Pokemon[8]->defmax;
    Pokemon[8]->statut=0;
    char* graphcaillou[13] = {
    "",
    "",
    "       ______",
    "      / _\\_\\_\\",
    "      \\_;  ,()                     ______",
    "       |  |        _______        /\\_\\_\\_\\",
    "       \\  \\       ,       ,       ()    _/",
    "        \\  \\     /         \\       \\   _|",
    "         \\  \\__,/.  .\\  /. /\\       / /",
    "          \\_=____\\  ______/\\ \\_____/ /",
    "                  \\/_____,| \\___==__/",
    "",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[8]->repgraph[i]=graphcaillou[i];
    }
    Pokemon[8]->description="Pokemon de type sol \nLorsqu'un Racaillou prend de l'âge, ses bords s'ébrèchent et \ns'usent, ce qui lui donne une apparence plus ronde. Cependant, le cœur de ce \nPokémon reste dur, rocailleux et rugueux.";
    for(int i = 0; i < 4; i++) {
        Pokemon[8]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[8]->attaque[0]->nom = "goudronnage";
    Pokemon[8]->attaque[0]->degat = 0.8;
    Pokemon[8]->attaque[0]->reussite = 80;
    Pokemon[8]->attaque[0]->fonction = 3;

    Pokemon[8]->attaque[1]->nom = "roulade";
    Pokemon[8]->attaque[1]->degat = 25;
    Pokemon[8]->attaque[1]->reussite = 90;
    Pokemon[8]->attaque[1]->fonction = 0;

    Pokemon[8]->attaque[2]->nom = "fracass'tete";
    Pokemon[8]->attaque[2]->degat = 30;
    Pokemon[8]->attaque[2]->reussite = 80;
    Pokemon[8]->attaque[2]->fonction = 0;

    Pokemon[8]->attaque[3]->nom = "eboulement";
    Pokemon[8]->attaque[3]->degat = 40;
    Pokemon[8]->attaque[3]->reussite = 70;
    Pokemon[8]->attaque[3]->fonction = 0;

    Pokemon[8]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[8]->attspe->nom="régeneration";
    Pokemon[8]->attspe->fonction=1;
    Pokemon[8]->attspe->effet_spe_tempo=0;
    Pokemon[8]->attspe->tempsrecharge=4;
    Pokemon[8]->attspe->tempsrechargeact=0;


    Pokemon[9]->name="Pikachu   "; // structure pokemon pikachu
    Pokemon[9]->type=2;
    Pokemon[9]->pvmax=110;
    Pokemon[9]->pvactuel=Pokemon[9]->pvmax;
    Pokemon[9]->vit=rand()%21+80;
    Pokemon[9]->attmax=(rand() % 4 + 10) / 10.0;
    Pokemon[9]->attactuel=Pokemon[9]->attmax;
    Pokemon[9]->agi=rand()%6;
    Pokemon[9]->defmax=(rand() % 2 + 10) / 10.0;
    Pokemon[9]->defactuel=Pokemon[9]->defmax;
    Pokemon[9]->statut=0;
    char* graphpikachu[13] = {
    "",
    "          /\\       __",
    "          | \\_____/ /",
    "          /         |",
    "         / ^.   ^   |",
    "         \\0 _   0   |     _",
    "         _\\   _   __|    | |",
    "         \\/   \\  <__|  _/ /",
    "          |       __|_/ _/",
    "          |      <__|__/",
    "           \\______/ ",
    "           /__||__\\",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[9]->repgraph[i]=graphpikachu[i];
    }
    Pokemon[9]->description="Pokemon de type electrique \nSon corps peut accumuler de l'électricité. Les forêts \nabritant des groupes de Pikachu sont d'ailleurs souvent frappées par la foudre.";
    for(int i = 0; i < 4; i++) {
        Pokemon[9]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[9]->attaque[0]->nom = "mimi-queue";
    Pokemon[9]->attaque[0]->degat = 0.8;
    Pokemon[9]->attaque[0]->reussite = 80;
    Pokemon[9]->attaque[0]->fonction = 5;

    Pokemon[9]->attaque[1]->nom = "coup d'jus";
    Pokemon[9]->attaque[1]->degat = 25;
    Pokemon[9]->attaque[1]->reussite = 90;
    Pokemon[9]->attaque[1]->fonction = 0;

    Pokemon[9]->attaque[2]->nom = "eclair";
    Pokemon[9]->attaque[2]->degat = 30;
    Pokemon[9]->attaque[2]->reussite = 80;
    Pokemon[9]->attaque[2]->fonction = 0;

    Pokemon[9]->attaque[3]->nom = "boule elek";
    Pokemon[9]->attaque[3]->degat = 40;
    Pokemon[9]->attaque[3]->reussite = 70;
    Pokemon[9]->attaque[3]->fonction = 0;

    Pokemon[9]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[9]->attspe->nom="tonnerre ultime";
    Pokemon[9]->attspe->fonction=0;
    Pokemon[9]->attspe->effet_spe_tempo=0;
    Pokemon[9]->attspe->tempsrecharge=5;
    Pokemon[9]->attspe->tempsrechargeact=0;



    Pokemon[10]->name="Magneti   "; //structure pokemon magneti
    Pokemon[10]->type=2;
    Pokemon[10]->pvmax=95;
    Pokemon[10]->pvactuel=Pokemon[10]->pvmax;
    Pokemon[10]->vit=rand()%21+80;
    Pokemon[10]->attmax=(rand() % 2 + 10) / 10.0;
    Pokemon[10]->attactuel=Pokemon[10]->attmax;
    Pokemon[10]->agi=rand()%6;
    Pokemon[10]->defmax=(rand() % 2 + 10) / 10.0;
    Pokemon[10]->defactuel=Pokemon[10]->defmax;
    Pokemon[10]->statut=0;
    char* graphmagneti[13] = {
    "",
    "",
    "",
    "                 ____",
    "                 \\__/",
    "         ___    _I///I_    __",
    "         I_I\\__/       \\__/I_I",
    "           _ )__ ( o )  __(_",
    "         I_I_/ /\\_____/\\ \\_I_I",
    "           _/I/         \\I\\_",
    "           \\ I          I  /",
    "",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[10]->repgraph[i]=graphmagneti[i];
    }
    Pokemon[10]->description="Pokemon de type electrique \nMagnéti s'attache aux lignes à haute tension pour se \ncharger en électricité. Si une maison a une panne de courant, il est conseillé de \nvérifier les fusibles car on trouve parfois ces Pokémon amassés sur la boîte à fusibles.";
    for(int i = 0; i < 4; i++) {
        Pokemon[10]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[10]->attaque[0]->nom = "cage eclair";
    Pokemon[10]->attaque[0]->degat = 0.8;
    Pokemon[10]->attaque[0]->reussite = 80;
    Pokemon[10]->attaque[0]->fonction = 5;

    Pokemon[10]->attaque[1]->nom = "etincelle";
    Pokemon[10]->attaque[1]->degat = 25;
    Pokemon[10]->attaque[1]->reussite = 90;
    Pokemon[10]->attaque[1]->fonction = 0;

    Pokemon[10]->attaque[2]->nom = "onde de choc";
    Pokemon[10]->attaque[2]->degat = 30;
    Pokemon[10]->attaque[2]->reussite = 80;
    Pokemon[10]->attaque[2]->fonction = 0;

    Pokemon[10]->attaque[3]->nom = "elecanon";
    Pokemon[10]->attaque[3]->degat = 40;
    Pokemon[10]->attaque[3]->reussite = 70;
    Pokemon[10]->attaque[3]->fonction = 0;

    Pokemon[10]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[10]->attspe->nom="cage eclair";
    Pokemon[10]->attspe->fonction=2;
    Pokemon[10]->attspe->effet_spe_tempo=1;
    Pokemon[10]->attspe->tempsrecharge=5;
    Pokemon[10]->attspe->tempsrechargeact=0;



    Pokemon[11]->name="Electrode "; // structure pokemon electrode
    Pokemon[11]->type=2;
    Pokemon[11]->pvmax=100;
    Pokemon[11]->pvactuel=Pokemon[11]->pvmax;
    Pokemon[11]->vit=rand()%21+80;
    Pokemon[11]->attmax=(rand() % 4 + 10) / 10.0;
    Pokemon[11]->attactuel=Pokemon[11]->attmax;
    Pokemon[11]->agi=rand()%6;
    Pokemon[11]->defmax=(rand() % 2 + 10) / 10.0;
    Pokemon[11]->defactuel=Pokemon[11]->defmax;
    Pokemon[11]->statut=0;
    char* graphelectrode[13] = {
    "",
    "                 ..-----..       ",
    "               .'_        '.    ",
    "              : ( O-_)  .-~~:    ",
    "             :  `-..'   `O_.-:   ",
    "            :   __--~~~~--..  :  ",
    "            :-~~            ~~: ",
    "            :                 : ",
    "             :               :  ",
    "              :     ...     :   ",
    "               '.  '...'  .'    ",
    "                 ''-----''      ",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[11]->repgraph[i]=graphelectrode[i];
    }
    Pokemon[11]->description="Pokemon de type electrique \nPlus il accumule de l'énergie de type Électrik, plus il \nest rapide. Mais il a aussi davantage de chances d'exploser.";
    for(int i = 0; i < 4; i++) {
        Pokemon[11]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[11]->attaque[0]->nom = "surcharge";
    Pokemon[11]->attaque[0]->degat = 0.8;
    Pokemon[11]->attaque[0]->reussite = 80;
    Pokemon[11]->attaque[0]->fonction = 2;

    Pokemon[11]->attaque[1]->nom = "croc magnetique";
    Pokemon[11]->attaque[1]->degat = 25;
    Pokemon[11]->attaque[1]->reussite = 90;
    Pokemon[11]->attaque[1]->fonction = 0;

    Pokemon[11]->attaque[2]->nom = "eclair";
    Pokemon[11]->attaque[2]->degat = 30;
    Pokemon[11]->attaque[2]->reussite = 80;
    Pokemon[11]->attaque[2]->fonction = 0;

    Pokemon[11]->attaque[3]->nom = "tonnerre";
    Pokemon[11]->attaque[3]->degat = 40;
    Pokemon[11]->attaque[3]->reussite = 70;
    Pokemon[11]->attaque[3]->fonction = 0;

    Pokemon[11]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[11]->attspe->nom="cage eclair";
    Pokemon[11]->attspe->fonction=2;
    Pokemon[11]->attspe->effet_spe_tempo=1;
    Pokemon[11]->attspe->tempsrecharge=5;
    Pokemon[11]->attspe->tempsrechargeact=0;



    Pokemon[12]->name="Carapuce  "; // structure pokemon carapuce
    Pokemon[12]->type=4;
    Pokemon[12]->pvmax=110;
    Pokemon[12]->pvactuel=Pokemon[12]->pvmax;
    Pokemon[12]->vit=rand()%21+80;
    Pokemon[12]->attmax=(rand() % 4 + 10) / 10.0;
    Pokemon[12]->attactuel=Pokemon[12]->attmax;
    Pokemon[12]->agi=rand()%6;
    Pokemon[12]->defmax=(rand() % 2 + 10) / 10.0;
    Pokemon[12]->defactuel=Pokemon[12]->defmax;
    Pokemon[12]->statut=0;
    char* graphcarapuce[13] = {
    "",
    "",
    "                  _____",
    "                ,`o   o \\",
    "               ` \\____/ ‘",
    "               `,______,`",
    "       ,--------/   \\  \\____,",
    "       ‘--------|___|__|____/",
    "         /  \\   | __  _\\",
    "         |  /__\\/  \\ /  \\",
    "         \\_____ \\  / \\  |",
    "                ^^^^ ^^^^",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[12]->repgraph[i]=graphcarapuce[i];
    }
    Pokemon[12]->description="Pokemon de type eau \nLa carapace de Carapuce ne sert pas qu'à le protéger. La forme \nronde de sa carapace et ses rainures lui permettent d'améliorer son \nhydrodynamisme. Ce Pokémon nage extrêmement vite.";
    for(int i = 0; i < 4; i++) {
        Pokemon[12]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[12]->attaque[0]->nom = "mimi-queue";
    Pokemon[12]->attaque[0]->degat = 0.8;
    Pokemon[12]->attaque[0]->reussite = 80;
    Pokemon[12]->attaque[0]->fonction = 5;

    Pokemon[12]->attaque[1]->nom = "bulle d'eau";
    Pokemon[12]->attaque[1]->degat = 25;
    Pokemon[12]->attaque[1]->reussite = 90;
    Pokemon[12]->attaque[1]->fonction = 0;

    Pokemon[12]->attaque[2]->nom = "surf";
    Pokemon[12]->attaque[2]->degat = 30;
    Pokemon[12]->attaque[2]->reussite = 80;
    Pokemon[12]->attaque[2]->fonction = 0;

    Pokemon[12]->attaque[3]->nom = "aquajet";
    Pokemon[12]->attaque[3]->degat = 40;
    Pokemon[12]->attaque[3]->reussite = 70;
    Pokemon[12]->attaque[3]->fonction = 0;

    Pokemon[12]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[12]->attspe->nom="tsunami ravageur";
    Pokemon[12]->attspe->fonction=0;
    Pokemon[12]->attspe->effet_spe_tempo=0;
    Pokemon[12]->attspe->tempsrecharge=5;
    Pokemon[12]->attspe->tempsrechargeact=0;


    Pokemon[13]->name="Psykokwak "; // structure pokemon psykokwak
    Pokemon[13]->type=4;
    Pokemon[13]->pvmax=90;
    Pokemon[13]->pvactuel=Pokemon[13]->pvmax;
    Pokemon[13]->vit=rand()%101+80;
    Pokemon[13]->attmax=(rand() % 2 + 10) / 10.0;
    Pokemon[13]->attactuel=Pokemon[13]->attmax;
    Pokemon[13]->agi=rand()%6;
    Pokemon[13]->defmax=(rand() % 2 + 10) / 10.0;
    Pokemon[13]->defactuel=Pokemon[13]->defmax;
    Pokemon[13]->statut=0;
    char* graphpsyko[13] = {
    "",
    "",
    "",
    "",
    "               ____ ",
    "             /(')(')\\",
    "           /\\  \\''/ //\\",
    "           \\/        \\/",
    "             \\      />",
    "              \\_/\\_/",
    "",
    "",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[13]->repgraph[i]=graphpsyko[i];
    }
    Pokemon[13]->description="Pokemon de type eau \nPsykokwak utilise un mystérieux pouvoir. Ce Pokémon peut générer \ndes ondes cérébrales normalement observées chez les dormeurs. Cette \ndécouverte a lancé une polémique dans le milieu universitaire.";
    for(int i = 0; i < 4; i++) {
        Pokemon[13]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[13]->attaque[0]->nom = "mimi-queue";
    Pokemon[13]->attaque[0]->degat = 0.8;
    Pokemon[13]->attaque[0]->reussite = 80;
    Pokemon[13]->attaque[0]->fonction = 5;

    Pokemon[13]->attaque[1]->nom = "bulle d'eau";
    Pokemon[13]->attaque[1]->degat = 25;
    Pokemon[13]->attaque[1]->reussite = 90;
    Pokemon[13]->attaque[1]->fonction = 0;

    Pokemon[13]->attaque[2]->nom = "ebullition";
    Pokemon[13]->attaque[2]->degat = 30;
    Pokemon[13]->attaque[2]->reussite = 80;
    Pokemon[13]->attaque[2]->fonction = 0;

    Pokemon[13]->attaque[3]->nom = "cascade";
    Pokemon[13]->attaque[3]->degat = 40;
    Pokemon[13]->attaque[3]->reussite = 70;
    Pokemon[13]->attaque[3]->fonction = 0;

    Pokemon[13]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[13]->attspe->nom="hypnose";
    Pokemon[13]->attspe->fonction=2;
    Pokemon[13]->attspe->effet_spe_tempo=1;
    Pokemon[13]->attspe->tempsrecharge=5;
    Pokemon[13]->attspe->tempsrechargeact=0;
        

    Pokemon[14]->name="Wailmer   "; // structure pokemon wailmer
    Pokemon[14]->type=4;
    Pokemon[14]->pvmax=130;
    Pokemon[14]->pvactuel=Pokemon[14]->pvmax;
    Pokemon[14]->vit=rand()%21+80;
    Pokemon[14]->attmax=(rand() % 2 + 10) / 10.0;
    Pokemon[14]->attactuel=Pokemon[14]->attmax;
    Pokemon[14]->agi=rand()%6;
    Pokemon[14]->defmax=(rand() % 5 + 10) / 10.0;
    Pokemon[14]->defactuel=Pokemon[14]->defmax;
    Pokemon[14]->statut=0;
    char* graphwailmer[13] = {
    "",
    "",
    "",
    "",
    "               .",
    "              \":\"",
    "            ___:____     |\"\\/\"|",
    "          ,'        `.    \\  /",
    "          |  O        \\___/  |",
    "        ~^~^~^~^~^~^~^~^~^~^~^~^~",
    "",
    "",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[14]->repgraph[i]=graphwailmer[i];
    }
    Pokemon[14]->description="Pokemon de type eau \nLes narines de Wailmer sont situées au-dessus de ses yeux. Ce joyeux \nPokémon adore effrayer les gens en expulsant de l'eau de mer \npar les narines.";
    for(int i = 0; i < 4; i++) {
        Pokemon[14]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[14]->attaque[0]->nom = "pression";
    Pokemon[14]->attaque[0]->degat = 0.8;
    Pokemon[14]->attaque[0]->reussite = 80;
    Pokemon[14]->attaque[0]->fonction = 3;

    Pokemon[14]->attaque[1]->nom = "soin";
    Pokemon[14]->attaque[1]->degat = 40;
    Pokemon[14]->attaque[1]->reussite = 80;
    Pokemon[14]->attaque[1]->fonction = 1;

    Pokemon[14]->attaque[2]->nom = "hydroqueue";
    Pokemon[14]->attaque[2]->degat = 30;
    Pokemon[14]->attaque[2]->reussite = 80;
    Pokemon[14]->attaque[2]->fonction = 0;

    Pokemon[14]->attaque[3]->nom = "tsunami";
    Pokemon[14]->attaque[3]->degat = 40;
    Pokemon[14]->attaque[3]->reussite = 70;
    Pokemon[14]->attaque[3]->fonction = 0;

    Pokemon[14]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[14]->attspe->nom="eau de jouvence";
    Pokemon[14]->attspe->fonction=1;
    Pokemon[14]->attspe->effet_spe_tempo=0;
    Pokemon[14]->attspe->tempsrecharge=5;
    Pokemon[14]->attspe->tempsrechargeact=0;    
    

    Pokemon[15]->name="Flamiaou  "; // structure pokemon flamiaou
    Pokemon[15]->type=3;
    Pokemon[15]->pvmax=110;
    Pokemon[15]->pvactuel=Pokemon[15]->pvmax;
    Pokemon[15]->vit=rand()%101+80;
    Pokemon[15]->attmax=(rand() % 5 + 10) / 10.0;
    Pokemon[15]->attactuel=Pokemon[15]->attmax;
    Pokemon[15]->agi=rand()%6;
    Pokemon[15]->defmax=(rand() % 1 + 10) / 10.0;
    Pokemon[15]->defactuel=Pokemon[15]->defmax;
    Pokemon[15]->statut=0;
    char* graphflamiaou[13] = {
    "",
    "         /\\     /\\",
    "        {  `---'  }",
    "        {  O   O  }",
    "        ~~>  V  <~~",
    "         \\  \\|/  /",
    "          `-----'____",
    "          /     \\    \\_",
    "         {       }\\  )_\\_   _",
    "         |  \\_/  |/ /  \\_\\_/ )",
    "          \\__/  /(_/     \\__/",
    "            (__/",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[15]->repgraph[i]=graphflamiaou[i];
    }
    Pokemon[15]->description="Pokemon de type feu \n Dès qu'il a un instant, il fait sa toilette. Il déclenche ses attaques \nFeu en enflammant les poils qu'il a avalés en se léchant.";
    for(int i = 0; i < 4; i++) {
        Pokemon[15]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[15]->attaque[0]->nom = "danse flamme";
    Pokemon[15]->attaque[0]->degat = 0.8;
    Pokemon[15]->attaque[0]->reussite = 80;
    Pokemon[15]->attaque[0]->fonction = 2;

    Pokemon[15]->attaque[1]->nom = "flameche";
    Pokemon[15]->attaque[1]->degat = 25;
    Pokemon[15]->attaque[1]->reussite = 90;
    Pokemon[15]->attaque[1]->fonction = 0;

    Pokemon[15]->attaque[2]->nom = "feu follet";
    Pokemon[15]->attaque[2]->degat = 30;
    Pokemon[15]->attaque[2]->reussite = 80;
    Pokemon[15]->attaque[2]->fonction = 0;

    Pokemon[15]->attaque[3]->nom = "lance flamme";
    Pokemon[15]->attaque[3]->degat = 40;
    Pokemon[15]->attaque[3]->reussite = 70;
    Pokemon[15]->attaque[3]->fonction = 0;

    Pokemon[15]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[15]->attspe->nom="feu deferlant";
    Pokemon[15]->attspe->fonction=0;
    Pokemon[15]->attspe->effet_spe_tempo=0;
    Pokemon[15]->attspe->tempsrecharge=5;
    Pokemon[15]->attspe->tempsrechargeact=0;


    Pokemon[16]->name="Funecire  "; // structure pokemon funecire
    Pokemon[16]->type=3;
    Pokemon[16]->pvmax=95;
    Pokemon[16]->pvactuel=Pokemon[16]->pvmax;
    Pokemon[16]->vit=rand()%21+80;
    Pokemon[16]->attmax=(rand() % 2 + 10) / 10.0;
    Pokemon[16]->attactuel=Pokemon[16]->attmax;
    Pokemon[16]->agi=rand()%6;
    Pokemon[16]->defmax=(rand() % 2 + 10) / 10.0;
    Pokemon[16]->defactuel=Pokemon[16]->defmax;
    Pokemon[16]->statut=0;
    char* graphfunecire[13] = {
    "",
    "",
    "             )\\",
    "             {_}",
    "            .-;-.",
    "           |'-=-'|",
    "           |     |",
    "           | ° ° |",
    "           |     |",
    "           |     |",
    "           '.___.'",
    "",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[16]->repgraph[i]=graphfunecire[i];
    }
    Pokemon[16]->description="Pokemon de type feu \nSon corps est tiède, réchauffé par sa flamme. Il prend les personnes égarées \npar la main et les guide vers le monde des esprits.";
    for(int i = 0; i < 4; i++) {
        Pokemon[16]->attaque[i] = malloc(sizeof(Attaque));
    }

    Pokemon[16]->attaque[0]->nom = "mimi-queue";
    Pokemon[16]->attaque[0]->degat = 0.8;
    Pokemon[16]->attaque[0]->reussite = 80;
    Pokemon[16]->attaque[0]->fonction = 5;

    Pokemon[16]->attaque[1]->nom = "flameche";
    Pokemon[16]->attaque[1]->degat = 25;
    Pokemon[16]->attaque[1]->reussite = 90;
    Pokemon[16]->attaque[1]->fonction = 0;

    Pokemon[16]->attaque[2]->nom = "roue de feu";
    Pokemon[16]->attaque[2]->degat = 30;
    Pokemon[16]->attaque[2]->reussite = 80;
    Pokemon[16]->attaque[2]->fonction = 0;

    Pokemon[16]->attaque[3]->nom = "boutefeu";
    Pokemon[16]->attaque[3]->degat = 40;
    Pokemon[16]->attaque[3]->reussite = 70;
    Pokemon[16]->attaque[3]->fonction = 0;

    Pokemon[16]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[16]->attspe->nom="flamme brulante";
    Pokemon[16]->attspe->fonction=3;
    Pokemon[16]->attspe->effet_spe_tempo=2;
    Pokemon[16]->attspe->tempsrecharge=3;
    Pokemon[16]->attspe->tempsrechargeact=0;  



    Pokemon[17]->name="Chartor   "; // structure pokemon miaouss
    Pokemon[1]->type=3;
    Pokemon[17]->pvmax=100;
    Pokemon[17]->pvactuel=Pokemon[17]->pvmax;
    Pokemon[17]->vit=rand()%21+80;
    Pokemon[17]->attmax=(rand() % 2 + 10) / 10.0;
    Pokemon[17]->attactuel=Pokemon[17]->attmax;
    Pokemon[17]->agi=rand()%6;
    Pokemon[17]->defmax=(rand() % 4 + 10) / 10.0;
    Pokemon[17]->defactuel=Pokemon[17]->defmax;
    Pokemon[17]->statut=0;
    char* graphchartor[13] = {
    "",
    "",
    "",
    "",
    "                       __",
    "            .,-;-;-,. /'_\\",
    "          _/_/_/_|_\\_) /",
    "        '-<_><_><_><_>=/\\",
    "          `/_/====/_/-'\\_\\",
    "           \"\"     \"\"    \"\"",
    "",
    "",
    "",
    };
    for(int i=0 ; i<13 ; i++) {
        Pokemon[17]->repgraph[i]=graphchartor[i];
    }
    Pokemon[17]->description="Pokemmon de type feu \nUn bon indicateur de sa santé est le débit de la fumée qui s'échappe de sa \ncarapace: s'il est important, c'est qu'il est en pleine forme.\n";
    for(int i=0; i<4 ; i++) {
        Pokemon[17]->attaque[i] = malloc(sizeof(Attaque));
    }
    Pokemon[17]->attaque[0]->nom="lance flamme";
    Pokemon[17]->attaque[0]->degat=30;
    Pokemon[17]->attaque[0]->reussite=80;
    Pokemon[17]->attaque[0]->fonction=0;

    Pokemon[17]->attaque[1]->nom="flameche";
    Pokemon[17]->attaque[1]->degat=25;
    Pokemon[17]->attaque[1]->reussite=90;
    Pokemon[17]->attaque[1]->fonction=0;

    Pokemon[17]->attaque[2]->nom="damocles";
    Pokemon[17]->attaque[2]->degat=1.2;
    Pokemon[17]->attaque[2]->reussite=80;
    Pokemon[17]->attaque[2]->fonction=3;

    Pokemon[17]->attaque[3]->nom="boule de feu";
    Pokemon[17]->attaque[3]->degat=35;
    Pokemon[17]->attaque[3]->reussite=70;
    Pokemon[17]->attaque[3]->fonction=0;

    Pokemon[17]->attspe=malloc(sizeof(Attaquespecial));

    Pokemon[17]->attspe->nom="phoenix rennaissant";
    Pokemon[17]->attspe->fonction=1;
    Pokemon[17]->attspe->effet_spe_tempo=0;
    Pokemon[17]->attspe->tempsrecharge=5;
    Pokemon[17]->attspe->tempsrechargeact=0;

    return Pokemon[i];
}