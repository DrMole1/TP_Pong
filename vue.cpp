#include "vue.h"



//Implémentation de la fonction
//BUT : Créer un fond d'écran d'une couleur unie
//ENTREE : Le rendu
//SORTIES : La fenêtre avec son rendu
extern void renduMenu(SDL_Renderer **renderer)
{
    SDL_SetRenderDrawColor(*renderer, RGBAMIN, RGBAMAX, RGBAMAX, RGBAMAX);
    SDL_RenderClear(*renderer);

    //Le code qui suit sert à afficher le titre PONG et la description en grand sur l'écran du menu
    //=============================================================================================
    // Déclaration des variables
    SDL_Surface *srfTexte = NULL;
    TTF_Font *police = NULL;
    SDL_Rect position;
    SDL_Texture *txTexte;
    SDL_Color couleur = {RGBAMIN, RGBAMIN, RGBAMIN};

    police = TTF_OpenFont("angelina.ttf", TAILLETEXT);  // Ouverture d'une police mise dans le dossier du jeu

    // Pour le titre
    srfTexte = TTF_RenderText_Blended(police, "PONG", couleur);
    position.x = LONGECRAN/10;
    position.y = LARGECRAN/4;
    position.w = LARGETEXT;
    position.h = HAUTEURTEXT;
    txTexte = SDL_CreateTextureFromSurface(*renderer, srfTexte);
    SDL_FreeSurface(srfTexte);
    SDL_RenderCopy(*renderer,txTexte,NULL,&position);

    // Pour l'indication
    srfTexte = TTF_RenderText_Blended(police, "press space", couleur);
    position.x = LONGECRAN/2;
    position.y = LARGECRAN/2;
    position.w = LARGETEXT;
    position.h = HAUTEURTEXT;
    txTexte = SDL_CreateTextureFromSurface(*renderer, srfTexte);
    SDL_FreeSurface(srfTexte);
    SDL_RenderCopy(*renderer,txTexte,NULL,&position);

    SDL_RenderPresent(*renderer);
    SDL_DestroyTexture(txTexte);

    TTF_CloseFont(police);
    //=============================================================================================
}


//Implémentation de la fonction
//BUT : Set l'écran de jeu à chaque instant T
//ENTREE : Le rendu ainsi que les différents composants du jeu
//SORTIES : La fenêtre avec son rendu
extern void renduJeu(SDL_Renderer **renderer, SDL_Rect *raquette1, SDL_Rect *raquette2, SDL_Rect *balle, const int nScore1, const int nScore2)
{
    //Déclaration des textures
    SDL_Texture *textureRaquette;
    SDL_Texture *textureBalle;

    //Mise en place d'un fond de couleur uni
    SDL_SetRenderDrawColor(*renderer, RGBAMIN, RGBAMAX, RGBAMAX, RGBAMAX);
    SDL_RenderClear(*renderer);

    //Mise en place de la raquette1
    SDL_SetRenderDrawColor(*renderer, RGBAMAX, RGBAMAX, RGBAMIN, RGBAMAX);
    SDL_RenderFillRect(*renderer, raquette1);

    //Mise en place de la raquette2
    SDL_SetRenderDrawColor(*renderer, RGBAMAX, RGBAMAX, RGBAMIN, RGBAMAX);
    SDL_RenderFillRect(*renderer, raquette2);

    //Mise en place de la balle
    for (double dy = UN; dy <= DEMIBALLE; dy += 1.0)
    {
        double dx = floor(sqrt((DEUX * DEMIBALLE * dy) - (dy * dy)));
        SDL_SetRenderDrawColor(*renderer, RGBAMOY, RGBAMOY, RGBAMAX, RGBAMAX);
        SDL_RenderDrawLine(*renderer, balle->x + DEMIBALLE - dx, balle->y + DEMIBALLE + dy - DEMIBALLE, balle->x + DEMIBALLE + dx, balle->y + DEMIBALLE + dy - DEMIBALLE);
        SDL_RenderDrawLine(*renderer, balle->x + DEMIBALLE - dx, balle->y + DEMIBALLE - dy + DEMIBALLE, balle->x + DEMIBALLE + dx, balle->y + DEMIBALLE - dy + DEMIBALLE);
    }


    //Traçage du split de terrain
    SDL_SetRenderDrawColor(*renderer, RGBAMOY, RGBAMOY, RGBAMOY, RGBAMAX);
    SDL_RenderDrawLine(*renderer, LONGECRAN/2, UN, LONGECRAN/2, LARGECRAN);

    //Création des textures
    textureRaquette = SDL_CreateTexture(*renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, RAQLARG, RAQHAUT);
    textureBalle = SDL_CreateTexture(*renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, TAILLEBALLE, TAILLEBALLE);

    // Déclaration des variables pour l'affichage du texte
    SDL_Surface *srfTexte = NULL;
    TTF_Font *police = NULL;
    SDL_Rect position;
    SDL_Texture *txTexte;
    SDL_Color couleur = {RGBAMIN, RGBAMIN, RGBAMIN};

    police = TTF_OpenFont("angelina.ttf", TAILLETEXT);  // Ouverture d'une police mise dans le dossier du jeu

    // Pour le score 1
    if (nScore1==0)
        srfTexte = TTF_RenderText_Blended(police, "0", couleur);
    else if (nScore1==1)
        srfTexte = TTF_RenderText_Blended(police, "1", couleur);
    else if (nScore1==2)
        srfTexte = TTF_RenderText_Blended(police, "2", couleur);
    else if (nScore1==3)
        srfTexte = TTF_RenderText_Blended(police, "3", couleur);
    position.x = LONGECRAN/4;
    position.y = LARGECRAN/5;
    position.w = TAILLESCORE;
    position.h = TAILLESCORE;
    txTexte = SDL_CreateTextureFromSurface(*renderer, srfTexte);
    SDL_FreeSurface(srfTexte);
    SDL_RenderCopy(*renderer,txTexte,NULL,&position);

    // Pour le score 2
    if (nScore2==0)
        srfTexte = TTF_RenderText_Blended(police, "0", couleur);
    else if (nScore2==1)
        srfTexte = TTF_RenderText_Blended(police, "1", couleur);
    else if (nScore2==2)
        srfTexte = TTF_RenderText_Blended(police, "2", couleur);
    else if (nScore2==3)
        srfTexte = TTF_RenderText_Blended(police, "3", couleur);
    position.x = LONGECRAN/1.5;
    position.y = LARGECRAN/5;
    position.w = TAILLESCORE;
    position.h = TAILLESCORE;
    txTexte = SDL_CreateTextureFromSurface(*renderer, srfTexte);
    SDL_FreeSurface(srfTexte);
    SDL_RenderCopy(*renderer,txTexte,NULL,&position);

    //Copie des éléments sur le rendu et publication du rendu
    SDL_RenderCopy(*renderer,textureRaquette,NULL,raquette1);
    SDL_RenderCopy(*renderer,textureRaquette,NULL,raquette2);
    SDL_RenderCopy(*renderer,textureBalle,NULL,balle);
    SDL_RenderPresent(*renderer);
}
