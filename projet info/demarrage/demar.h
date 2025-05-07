#ifndef DEMAR_H
#define DEMAR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include "../pokemon/fonction.h"

int afficherMenu(char* menu[], int menu_n);

int menu();

#endif