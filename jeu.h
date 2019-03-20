#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#pragma once

//Implémentation des bibliothèques
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Déclaration des constantes
#define UP -12
#define DOWN 12
#define LONGECRAN 640
#define TAILLEBALLE 32
#define DEMIBALLE 16
#define RAQLARG 10
#define RAQHAUT 100
#define ESPACE 25
#define BALLEX 304
#define BALLEY 224
#define UN 1
#define COEFFX 3
#define MAXRAND 7
#define MIDRAND 3
#define DELAI 8


//Déclaration d'un type énumération
typedef enum tDirection {gauche,droite} tDirection;



//Prototypes des méthodes
extern void setRaquette1Y(SDL_Rect *raquette1, const int nAxis);
extern void initJeu(SDL_Rect *raquette1, SDL_Rect *raquette2, SDL_Rect *balle);
extern void setRaquette2Y(SDL_Rect *raquette2, const SDL_Rect balle);
extern void setBalleDroite(SDL_Rect *balle, const int nCoeffY);
extern void setBalleGauche(SDL_Rect *balle, const int nCoeffY);

#endif // JEU_H_INCLUDED
