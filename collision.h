#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#pragma once

//Implémentation des bibliothèques
#include "vue.h"



//Prototype des méthodes
extern bool toucheRaq2(const SDL_Rect balle, const SDL_Rect raquette2);
extern bool toucheRaq1(const SDL_Rect balle, const SDL_Rect raquette1);
extern bool toucheMur(const SDL_Rect balle);
extern bool toucheBut(const SDL_Rect balle);

#endif // COLLISION_H_INCLUDED
