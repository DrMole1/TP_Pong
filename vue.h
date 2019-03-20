#ifndef VUE_H_INCLUDED
#define VUE_H_INCLUDED
#pragma once

//Implémentation des bibliothèques
#include "jeu.h"


//Déclaration des constantes
#define LARGECRAN 480
#define LONGECRAN 640
#define RGBAMAX 255
#define RGBAMIN 0
#define RGBAMOY 128
#define UN 1
#define DEUX 2
#define DEMIBALLE 16
#define LARGETEXT 200
#define HAUTEURTEXT 100
#define TAILLETEXT 65
#define TAILLESCORE 50


//Prototypes des méthodes
extern void renduMenu(SDL_Renderer **renderer);
extern void renduJeu(SDL_Renderer **renderer, SDL_Rect *raquette1, SDL_Rect *raquette2, SDL_Rect *balle, const int nScore1, const int nScore2);


#endif // VUE_H_INCLUDED
