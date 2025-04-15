#ifndef MON_FICHIER_H
#define MON_FICHIER_H

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
    char* nom; 
    float degat; 
    int reussite; 
    int fonction; 

} Attaque;

typedef struct {
    char* name;
    int type; 
    char* repgraph[13]; 
    int pvmax; 
    int pvactuel; 
    float attmax; 
    float attactuel; 
    float defmax; 
    float defactuel; 
    int agi;
    int vit; 
    char* description; 
    Attaque* attaque[4];
} Poke;

typedef struct {
    int actif1;
    int actif2;
} Actif;




#endif