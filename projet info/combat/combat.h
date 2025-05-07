#ifndef COMBAT_H
#define COMBAT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include "../pokemon/structure.h"


void affichagePokepv(Poke* j1[3], Poke* j2[3], int tour, Actif* actif);

int choixattj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

int choixchangementpoke2restantj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

int choixchangementpoke3restantj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

int choixtypeactionj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

int choixactionj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

int choixattj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

int choixchangementpoke2restantj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

int choixchangementpoke3restantj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

int choixtypeactionj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

int choixactionj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

float calculerEfficacite(int typeAttaquant, int typeDefenseur);

int attfonction0j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int esquive1, int reussite2, Actif* actif);

int attfonction0j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int esquive2, int reussite1, Actif* actif);

int attfonction1j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int reussite1, Actif* actif);

int attfonction1j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int reussite2, Actif* actif);

int attfonction2j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int reussite2, Actif* actif);

int attfonction2j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int reussite1, Actif* actif);

int attfonction3j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int esquive1, int reussite2, Actif* actif);

int attfonction3j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int esquive2, int reussite1, Actif* actif);

int attfonction4j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int reussite2, Actif* actif);

int attfonction4j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int reussite1, Actif* actif);

int attfonction5j2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, int esquive1, int reussite2, Actif* actif);

int attfonction5j1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, int esquive2, int reussite1, Actif* actif);

int changementcombatj2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, Actif* actif);

int changementcombatj1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, Actif* actif);

int attspecialej1(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj1, Actif* actif);

int attspecialej2(Poke* joueur1[3], Poke* joueur2[3], int tour, int actionj2, Actif* actif);

int virus(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

int attj2(Poke* joueur1[3], Poke* joueur2[3], int actionj1, int actionj2, int tour, Actif* actif, int esquive1, int reussite2);

int attj1(Poke* joueur1[3], Poke* joueur2[3], int actionj1, int actionj2, int tour, Actif* actif, int esquive2, int reussite1);

int verifmortj2(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif, int choixmenu);

int verifmortj1(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif);

int phaseattaque(Poke* joueur1[3], Poke* joueur2[3], int actionj1, int actionj2, int tour, Actif* actif, int choixmenu);

int tourn_jvsj(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif, int choixmenu);

int tourn_jvsordi(Poke* joueur1[3], Poke* joueur2[3], int tour, Actif* actif, int choixmenu);

void combat_jvsj(Poke* joueurs[], Actif* actif, int choixmenu);

void combat_jvsordi(Poke* joueurs[], Actif* actif, int choixmenu);

void combat(int choixmenu, Poke* joueurs[6]);



#endif