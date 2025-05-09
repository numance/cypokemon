#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include "fonction.h"

int afficherMenu(char* menu[], int menu_n);

void aide();

void afficherMenu0();

void afficherMenu1();

void afficherMenu2();

void afficherMenu3();

void afficherTitrej1_1();

void afficherTitrej1_2();

void afficherTitrej1_3();

void afficherTitrej2_1();

void afficherTitrej2_2();

void afficherTitrej2_3();

void gagnantj1();

void gagnantj2();

#endif