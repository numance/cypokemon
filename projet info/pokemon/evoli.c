#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



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
} Pokemon;

int main() {
  srand(time(NULL));
    Pokemon** Pokemon;
    Pokemon[0]->name="Evoli";
    Pokemon[0]->type=0;
    Pokemon[0]->pvmax=100;
    Pokemon[0]->pvactuel=Pokemon[0]->pvmax;
    Pokemon[0]->vitmax=rand()%101+80;
    Pokemon[1]->vitactuel=Pokemon[0]->vitmax;
    Pokemon[0]->attmax=rand()%101+80;
    Pokemon[1]->attactuel=Pokemon[0]->attmax;
    Pokemon[0]->agi=rand()%6;
    Pokemon[0]->defmax=rand()%21+10;
    Pokemon[0]->defactuel=Pokemon[0]->defmax;
    char* graphevoli[11]= {"        \\ '.           .' /","         \\  \\ .---. .-' /","          '. '     `\\_.'","            |(),()  |     ,","            (  __   /   .' \\","           .''.___.'--,/\\_,|","          {  /     \\   }   |","           '.\\     /_.'    /","            |'-.-',  `; _.'","            |  |  |   |`","            `\"\"`\"\"`\"\"\"`"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[0]->repgraph[i]=graphevoli[i];
    }
    Pokemon[0]->description="Pokemon de type normal \nUn Pokémon rare qui change d'apparence et d'aptitudes \nau moment d'évoluer en fonction du milieu hostile auquel il veut s'adapter.\n";
    Pokemon[0]->talent=3;


    Pokemon[1]->name="Miaouss";
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
    char* graphmiaouss[12]= {"               .-. \\_/ .-. ","               \\.-\\/=\\/.-/","            '-./___|=|___\\.-'","           .--| \\|/`\"`\\|/ |--.","          (((_)\\  .---.  /(_)))","           `\\ \\_`-.   .-'_/ /`_","             '.__       __.'(_))", "                 /     \\     //","                |       |__.'/","                \\       /--'`","            .--,-' .--. '----.","           '----`--'  '--`----'"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[1]->repgraph[i]=graphmiaouss[i];
    }
    Pokemon[1]->description="Pokemon de type normal \nMiaouss peut rentrer ses griffes dans ses pattes pour \nrôder gracieusement sans laisser de traces. Étrangement, ce Pokémon raffole\ndes pièces d'or qui brillent à la lumière.\n";
    Pokemon[1]->talent=2;


    Pokemon[2]->name="Porygon";
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
    char* graphporygon[7]={"                ______    __","               / .__. \\  /  /","               \\__\\/__/ /  /","               /      \\/  /","            ___|      |__/","           /    \\____/    \\","          /____/      \\____\\"};
    for(int i=0 ; i<11 ; i++) {
           Pokemon[2]->repgraph[i]=graphporygon[i];
    }
    Pokemon[2]->description="Pokemon de type noraml \nPorygon est capable de se décompiler et de retourner à\n l'état de programme informatique pour entrer dans le cyberespace. Ce Pokémon\n est protégé contre le piratage, il est donc impossible de le copier.\n";
    Pokemon[2]->talent=2;

    Pokemon[3]->name="Aspicot";
    Pokemon[3]->type=5;
    Pokemon[3]->pvmax=100;
    Pokemon[3]->pvactuel=Pokemon[3]->pvmax;
    Pokemon[3]->vitmax=rand()%101+80;
    Pokemon[3]->vitactuel=Pokemon[3]->vitmax;
    Pokemon[3]->attmax=rand()%101+80;
    Pokemon[3]->agi=rand()%6;
    Pokemon[3]->defmax=rand()%21+10;
    Pokemon[3]->defactuel=Pokemon[3]->defmax;
    char* graphaspicot[7]= {"              _/\\___//","            _/ O   @=","           (__     /\\\\     ___________","              O   |       /    ____   \\","              |   \\      /    /    \\   \\","              \\    \\----/    /      | /","               \\____________/     <oO/"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[3]->repgraph[i]=graphaspicot[i];
    }
    Pokemon[3]->description="Pokemon de type plante \nL'odorat d'Aspicot est extrêmement développé. Il lui \nsuffit de renifler ses feuilles préférées avec son gros appendice nasal pour les \nreconnaître entre mille.\n";
    Pokemon[3]->talent=1;


    Pokemon[4]->name="Mystherbe";
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
    char* graphmystherbe[5]={"      /\\/\\ |\\","      \\ \\ \\//","      / o_o\\","      \\____/","      /_\\/_\\"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[4]->repgraph[i]=graphmystherbe[i];
    }
    Pokemon[4]->description="";
    Pokemon[4]->talent=2;


    Pokemon[5]->name="Bulbizarre";
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
    char* graphbulbi[10]= {"               __","          ____-  -____","         /            \\","        /\\____________/\\","       /  /´¯\\    /¯`\\  \\","       \\  \\ º/    \\º / /","        \\ .·´¯`v´¯`·. /","       / \\¨\\______/¨ /  \\","      |  |¯¯¯¯¯¯¯¯¯¯¯|  |","      IooI           IooI"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[5]->repgraph[i]=graphbulbi[i];
    }
    Pokemon[5]->description="";
    Pokemon[5]->talent=3;


    Pokemon[6]->name="Onix";
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
    for(int i=0 ; i<11 ; i++) {
         Pokemon[6]->repgraph[i]=graphonix[i];
    }
    Pokemon[6]->description="";
    Pokemon[6]->talent=0;


    Pokemon[7]->name="Taupiqueur";
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
    char* graphtaupi[11]= {"                .'''''.         ","               ;        ;        ","              ;  HP  HP  ;       ","             ;   H   H    ;      ","             ;     ___    ;      ","             ;    (___)   ;      ","             ;            ;      ","             ;            ;      ","            h;            ;g     ","          jg ggh      hgj gggf   ","        og  h   hgfgfj   f  j ghg"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[7]->repgraph[i]=graphtaupi[i];
    }
    Pokemon[7]->description="";
    Pokemon[7]->talent=0;
    

    Pokemon[8]->name="Racaillou";
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
    char* graphcaillou[9] = {"  ______"," / _\\_\\_\\"," \\_;  ,()                     ______","  |  |        _______        /\\_\\_\\_\\","  \\  \\       ,       ,       ()    _/","   \\  \\     /         \\       \\   _|","    \\  \\__,/.  .\\  /. /\\       / /","     \\_=____\\  ______/\\ \\_____/ /","             \\/_____,| \\___==__/"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[8]->repgraph[i]=graphcaillou[i];
    }
    Pokemon[8]->description="";
    Pokemon[8]->talent=0;


    Pokemon[9]->name="Pikachu";
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
    char* graphpikachu[11]= {"        /\\       __","        | \\_____/ /","        /         |",    "       / ^.   ^   |",   "       \\0 _   0   |     _","       _\\   _   __|    | |","       \\/   \\  <__|  _/ /","        |       __|_/ _/","        |      <__|__/",   "         \\______/","         /__||__\\"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[9]->repgraph[i]=graphpikachu[i];
    }
    Pokemon[9]->description="";
    Pokemon[9]->talent=2;


    Pokemon[10]->name="Magneti";
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
    char* graphmagneti[8]= {"               ____","               \\__/","       ___    _I///I_    __","       I_I\\__/       \\__/I_I","         _ )__ ( o )  __(_","       I_I_/ /\\_____/\\ \\_I_I","         _/I/         \\I\\_","         \\ I          I  /"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[10]->repgraph[i]=graphmagneti[i];
    }
    Pokemon[10]->description="";
    Pokemon[10]->talent=1;


    Pokemon[11]->name="Electrode";
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
    char* graphelectrode[11]= {"                   ..-----..       ","                 .'_        '.    ","                : ( O-_)  .-~~:    ","               :  `-..'   `O_.-:   ","              :   __--~~~~--..  :  ","              :-~~            ~~: ","              :                 : ","               :               :  ","                :     ...     :   ","                 '.  '...'  .'    ","                   ''-----''      "};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[11]->repgraph[i]=graphelectrode[i];
    }
    Pokemon[11]->description="";
    Pokemon[11]->talent=3;


    Pokemon[12]->name="Carapuce";
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
    char* graphcarapuce= {"             _____","           ,`o   o \\","          ` \\____/ ‘","          `,______,`","  ,--------/   \\  \\____,","  ‘--------|___|__|____/","    /  \\   | __  _\\","    |  /__\\/  \\ /  \\","    \\_____ \\  / \\  |","           ^^^^ ^^^^"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[12]->repgraph[i]=graphcarapuce[i];
    }
    Pokemon[12]->description="";
    Pokemon[12]->talent=2;


    Pokemon[13]->name="Psykokwak";
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
    char* graphpsyko[6]={"           ____ ","         /(')(')\\","       /\\  \\''/ //\\","       \\/        \\/","         \\      />","          \\_/\\_/"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[13]->repgraph[i]=graphpsyko[i];
    }
    Pokemon[13]->description="";
    Pokemon[13]->talent=1;
        

    Pokemon[14]->name="Wailmer";
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
    char* graphwailmer[6]= {"       .","      \":\"","    ___:____     |\"\\/\"|","  ,'        `.    \\  /","  |  O        \\___/  |","~^~^~^~^~^~^~^~^~^~^~^~^~"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[14]->repgraph[i]=graphwailmer[i];
    }
    Pokemon[14]->description="";
    Pokemon[14]->talent=3;
    

    Pokemon[15]->name="Flamiaou";
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
    char* graphflamiaou[11]= {" /\\     /\\","{  `---'  }","{  O   O  }","~~>  V  <~~"," \\  \\|/  /","  `-----'____","  /     \\    \\_"," {       }\\  )_\\_   _"," |  \\_/  |/ /  \\_\\_/ )","  \\__/  /(_/     \\__/","    (__/"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[15]->repgraph[i]=graphflamiaou[i];
    }
    Pokemon[15]->description="";
    Pokemon[15]->talent=2;


    Pokemon[16]->name="Funecire";
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
    char* graphfunecire[9]={"       )\\","       {_}","      .-;-.","     |'-=-'|","     |     |","     | ° ° |","     |     |","     |     |","     '.___.'"};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[16]->repgraph[i]=graphfunecire[i];
    }
    Pokemon[16]->description="";
    Pokemon[16]->talent=3;


    Pokemon[17]->name="Chartor";
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
    char* graphchartor[6]={"                  __","       .,-;-;-,. /'_\\","     _/_/_/_|_\\_) /","   '-<_><_><_><_>=/\\","     `/_/====/_/-'\\_\\","      \"\"     \"\"    \"\""};
    for(int i=0 ; i<11 ; i++) {
         Pokemon[17]->repgraph[i]=graphchartor[i];
    }
    Pokemon[17]->description="";
    Pokemon[17]->talent=1;

    return 0;
}
        