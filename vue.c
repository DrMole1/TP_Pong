#include "vue.h"


//Implémentation de la fonction
//BUT : Créer un fond d'écran d'une couleur unie
//ENTREE : L'environnement
//SORTIES : La fenêtre
void renduMenu(SDL_Window **pWindow)
{
    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(*pWindow, 0, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, RGBAMAX, RGBAMIN, RGBAMAX, RGBAMAX);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Surface *screen;
    TTF_Font *police = NULL;
    SDL_Rect position;
    police = TTF_OpenFont("angela.ttf", 65);
    SDL_Color couleur = {55, 255, 55};
    texte = TTF_RenderText_Solid(police, "PONG", couleur);
    position.x = 60;
    position.y = 370;
    SDL_BlitSurface(texte, NULL, screen, &position);
}
