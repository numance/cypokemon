#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>




typedef struct {
    char* nom; // nom de l'attaque
    float degat; // degat a infliger deduit de l'attaque du pokemon et de la defense de l'adversaire
    int reussite; // chance de reussite de l'attaque
    int fonction; //0 pour attaque, 1 pour soin, 2 pour augmenter attaque, 3 pour baisser celle de l adversaire, 4 augmenter defense et 5 la baisser pour l adversaire

} Attaque;

typedef struct {
    char* name; //nom
    int type; //type 0 pour normal, 1 pour sol, 2 pour electrique, 3 pour feu, 4 pour eau et 5 pour plante
    char* repgraph[13]; // dessin ascii
    int pvmax; //point de vie max
    int pvactuel;  // point de vie au tour actuel
    float attmax; //attaque max
    float attactuel; // attaqua actuel entre 0.5 et 2
    float defmax; //defense max
    float defactuel; // defense actuel entre 0.5 et 2
    int agi; // chance d'esquive une attaque
    int vit; // determine quia attaque en premier
    char* description; // courte description
    Attaque* attaque[4]; // les 4 attaque
} Poke;

typedef struct {
    int actif1; // pokemon actif du j1
    int actif2; // pokemon actif du j2
} Actif;


Poke* listepoke(int i);




#endif