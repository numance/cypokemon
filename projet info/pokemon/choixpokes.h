#ifndef CHOIXPOKES_H
#define CHOIXPOKES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include "fonction.h"
#include "structure.h"

int afficherPoke(char* menu[], int tailleMenu, int numpoke, Poke* Pokemon[18]);

int choixpokeordi_difsimple(int typejoueur);

int choixpokeordi_difmoyen(int typejoueur);

int choixpokeordi_difdifficile(int typejoueur);

Poke* copierPokemon(Poke* original);

Poke** choixpokes(int choixmenu);

#endif