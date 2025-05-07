#ifndef FONCTION_H
#define FONCTION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>


#define UP    65  
#define DOWN  66  
#define ENTER 10 



void maximizeTerminal();

int getch();

void ouvrirFichier(const char* programme);

void desactivesaisi();

void activesaisi();

void viderBuffer();


#endif