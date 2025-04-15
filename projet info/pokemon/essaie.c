#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h> 
#include <unistd.h>
#include <time.h> 

#define UP    65  
#define DOWN  66  
#define ENTER 10  

typedef struct {
    char* nom; // nom correspondant
    float degat; // degat inflige par l'attaque
    int reussite; // plus l attaque est puissante moins le taux de reussite est elever
    int fonction; // 0 pour des degat, 1 pour regen, 2 pour augmenter attaque, 3 pour baisser attaque, 4 pour augmenter def et 5 pour baisser def

} Attaque;

typedef struct {
    char* name; // nom de l'espece du pokemon
    int type; //0 pour normal, 1 pour sol, 2 pour electrique, 3 pour feu, 4 pour eau et 5 pour plante
    char* repgraph[13]; //dessin modelisant le pokemon
    int pvmax; // pv au debut du combat et qui ne peuvent etre depasser
    int pvactuel; // pv au tour actuel
    float attmax; // permet calculer les degats infligés (peut etre reduit de moitie au max ou a l'inverse doublé)
    float attactuel; //attaque au tour actuel
    float defmax; // permet calcul le pourcentage des degat parrer (peut etre reduit de moitie au max ou a l'inverse doublé)
    float defactuel; //defense au tour actuel
    int agi; // permet de calculer la chance d'eviter une attaque
    int vit; // permet de determiner le premier a attaquer (peut etre reduit de moitie au max ou a l'inverse doublé)
    char* description; //donne comme info le type et une petite description et rep graphique
    Attaque* attaque[4];
} Poke;



int phaseattaque(Poke* joueur1[2], Poke* joueur2[2], int actionj1, int actionj2, int tour, int actif1, int actif2) {
    desactivesaisi();
    int esquive1=rand()%101;
    int esquive2=rand()%101;
    int reussite1=rand()%101;
    int reussite2=rand()%101;
    if(actionj1==4 && actionj2==4) {
        changementcombatj1(joueur1, joueur2, tour, actionj2, actif1, actif2);
        changementcombatj2(joueur1, joueur2, tour, actionj2, actif1, actif2);
    } else if(actionj1==4) {
        changementcombatj1(joueur1, joueur2, tour, actionj2, actif1, actif2);
        if(joueur2[actif2]->attaque[actionj2]->fonction==0) { // joueur 2 attaque
            attfonction0j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==1) {
            attfonction1j2(joueur1, joueur2, tour, actionj2, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==2) {
            attfonction2j2(joueur1, joueur2, tour, actionj2, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==3) {
            attfonction3j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==4) {
            attfonction4j2(joueur1, joueur2, tour, actionj2, reussite2, actif1, actif2);
        } else {
            attfonction5j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif1, actif2);
        }
        if(joueur1[0]->pvactuel==0 && joueur1[1]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 2 sont ko\n", joueur1[actif1]->name);
            sleep(4);
            gagnantj2();
            return 1;
        } else if(joueur1[actif1]->pvactuel==0) {
            printf("%s est ko\n", joueur1[actif1]->name);
            sleep(2);
            if(actif1==0) {
                printf("%s rentre dans le combat pour le remplacer", joueur1[actif1+1]->name);
                sleep(2);
                actif1+=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            } else {
                printf("%s rentre dans le combat pour le remplacer", joueur1[actif1-1]->name);
                sleep(2);
                actif1-=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            }
        }
    } else if(actionj2==4) {
        changementcombatj2(joueur1, joueur2, tour, actionj2, actif1, actif2);
        if(joueur1[actif1]->attaque[actionj1]->fonction==0) { // joueur 1 attaque
            attfonction0j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==1) {
            attfonction1j1(joueur1, joueur2, tour, actionj1, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==2) {
            attfonction2j1(joueur1, joueur2, tour, actionj1, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==3) {
            attfonction3j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==4) {
            attfonction4j1(joueur1, joueur2, tour, actionj1, reussite1, actif1, actif2);
        } else {
            attfonction5j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif1, actif2);
        }
        if(joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 2 sont ko\n", joueur2[actif2]->name);
            sleep(4);
            gagnantj1();
            return 1;
        } else if(joueur2[actif2]->pvactuel==0) {
            printf("%s est ko\n", joueur2[actif2]->name);
            sleep(2);
            if(actif2==0) {
                printf("%s rentre dans le combat pour le remplacer", joueur2[actif2+1]->name);
                sleep(2);
                actif2+=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            } else {
                printf("%s rentre dans le combat pour le remplacer", joueur2[actif2-1]->name);
                sleep(2);
                actif2-=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            }
        }
    } else {
        if(joueur1[actif1]->vit>=joueur2[actif2]->vit) {
        if(joueur1[actif1]->attaque[actionj1]->fonction==0) { // joueur 1 attaque
            attfonction0j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==1) {
            attfonction1j1(joueur1, joueur2, tour, actionj1, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==2) {
            attfonction2j1(joueur1, joueur2, tour, actionj1, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==3) {
            attfonction3j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==4) {
            attfonction4j1(joueur1, joueur2, tour, actionj1, reussite1, actif1, actif2);
        } else {
            attfonction5j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif1, actif2);
        }
        if(joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 2 sont ko\n", joueur2[actif2]->name);
            sleep(4);
            gagnantj1();
            return 1;
        } else if(joueur2[actif2]->pvactuel==0) {
            printf("%s est ko\n", joueur2[actif2]->name);
            sleep(2);
            if(actif2==0) {
                printf("%s rentre dans le combat pour le remplacer", joueur2[actif2+1]->name);
                sleep(2);
                actif2+=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            } else {
                printf("%s rentre dans le combat pour le remplacer", joueur2[actif2-1]->name);
                sleep(2);
                actif2-=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            }
        }
        if(joueur2[actif2]->attaque[actionj2]->fonction==0) { // joueur 2 attaque
            attfonction0j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==1) {
            attfonction1j2(joueur1, joueur2, tour, actionj2, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==2) {
            attfonction2j2(joueur1, joueur2, tour, actionj2, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==3) {
            attfonction3j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==4) {
            attfonction4j2(joueur1, joueur2, tour, actionj2, reussite2, actif1, actif2);
        } else {
            attfonction5j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif1, actif2);
        }
        if(joueur1[0]->pvactuel==0 && joueur1[1]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 2 sont ko\n", joueur1[actif1]->name);
            sleep(4);
            gagnantj2();
            return 1;
        } else if(joueur1[actif1]->pvactuel==0) {
            printf("%s est ko\n", joueur1[actif1]->name);
            sleep(2);
            if(actif1==0) {
                printf("%s rentre dans le combat pour le remplacer", joueur1[actif1+1]->name);
                sleep(2);
                actif1+=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            } else {
                printf("%s rentre dans le combat pour le remplacer", joueur1[actif1-1]->name);
                sleep(2);
                actif1-=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            }
        }
    } else {
        if(joueur2[actif2]->attaque[actionj2]->fonction==0) { // joueur 2 attaque
            attfonction0j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==1) {
            attfonction1j2(joueur1, joueur2, tour, actionj2, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==2) {
            attfonction2j2(joueur1, joueur2, tour, actionj2, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==3) {
            attfonction3j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif1, actif2);
        } else if(joueur2[actif2]->attaque[actionj2]->fonction==4) {
            attfonction4j2(joueur1, joueur2, tour, actionj2, reussite2, actif1, actif2);
        } else {
            attfonction5j2(joueur1, joueur2, tour, actionj2, esquive1, reussite2, actif1, actif2);
        }
        if(joueur1[0]->pvactuel==0 && joueur1[1]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 2 sont ko\n", joueur1[actif1]->name);
            sleep(4);
            gagnantj2();
            return 1;
        } else if(joueur1[actif1]->pvactuel==0) {
            printf("%s est ko\n", joueur1[actif1]->name);
            sleep(2);
            if(actif1==0) {
                printf("%s rentre dans le combat pour le remplacer", joueur1[actif1+1]->name);
                sleep(2);
                actif1+=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            } else {
                printf("%s rentre dans le combat pour le remplacer", joueur1[actif1-1]->name);
                sleep(2);
                actif1-=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            }
        }
        if(joueur1[actif1]->attaque[actionj1]->fonction==0) { // joueur 1 attaque
            attfonction0j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==1) {
            attfonction1j1(joueur1, joueur2, tour, actionj1, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==2) {
            attfonction2j1(joueur1, joueur2, tour, actionj1, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==3) {
            attfonction3j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif1, actif2);
        } else if(joueur1[actif1]->attaque[actionj1]->fonction==4) {
            attfonction4j1(joueur1, joueur2, tour, actionj1, reussite1, actif1, actif2);
        } else {
            attfonction5j1(joueur1, joueur2, tour, actionj1, esquive2, reussite1, actif1, actif2);
        }
        if(joueur2[0]->pvactuel==0 && joueur2[1]->pvactuel==0) {
            printf("%s est ko\ntout les pokemon du joueur 2 sont ko\n", joueur2[actif2]->name);
            sleep(4);
            gagnantj1();
            return 1;
        } else if(joueur2[actif2]->pvactuel==0) {
            printf("%s est ko\n", joueur2[actif2]->name);
            sleep(2);
            if(actif2==0) {
                printf("%s rentre dans le combat pour le remplacer", joueur2[actif2+1]->name);
                sleep(2);
                actif2+=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            } else {
                printf("%s rentre dans le combat pour le remplacer", joueur2[actif2-1]->name);
                sleep(2);
                actif2-=1;
                affichagePokepv(joueur1, joueur2, tour, actif1, actif2);

            }
        }
    }
    activesaisi();
    return 0;
}













