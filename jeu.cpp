#include "jeu.h"

//Implémentation
//BUT : Set la position y de la raquette du joueur (MUTATEUR)
//ENTREE : La valeur courante de la position y de la raquette1
//SORTIE : La nouvelle valeur de la position y de la raquette1
extern void setRaquette1Y(SDL_Rect *raquette1, const int nAxis)
{
    raquette1->y += nAxis;
}


//Implémentation
//BUT : Set la position y de la raquette de l'IA (MUTATEUR)
//ENTREE : La valeur courante de la position y de la raquette2
//SORTIE : La nouvelle valeur de la position y de la raquette2
extern void setRaquette2Y(SDL_Rect *raquette2, const SDL_Rect balle)
{
    raquette2->y = balle.y - RAQHAUT/2;
}


//Implémentation de la fonction
//BUT : Initialise l'écran de jeu à un instant T=0 (tout début d'une partie)
//ENTREE : Le rendu ainsi que les différents composants du jeu
//SORTIES : La fenêtre avec son rendu
extern void initJeu(SDL_Rect *raquette1, SDL_Rect *raquette2, SDL_Rect *balle)
{
    //Dimensions, positions et couleur de la balle
    balle->x = BALLEX;
    balle->y = BALLEY;
    balle->w = UN;
    balle->h = UN;

    //Dimensions, positions et couleur de la raquette1
    raquette1->x = ESPACE;
    raquette1->y = ESPACE;
    raquette1->w = RAQLARG;
    raquette1->h = RAQHAUT;

    //Dimensions, positions et couleur de la raquette2
    raquette2->x = LONGECRAN-(ESPACE+RAQLARG);
    raquette2->y = balle->y - RAQHAUT/2;
    raquette2->w = RAQLARG;
    raquette2->h = RAQHAUT;
}


//Implémentation de la fonction
//BUT : Fait déplacer la balle vers la droite (MUTATEUR)
//ENTREE : La balle et le coefficient directeur Y en cours
//SORTIES : La nouvelle position de la balle
extern void setBalleDroite(SDL_Rect *balle, const int nCoeffY)
{
    balle->x += COEFFX;
    balle->y += nCoeffY;
}


//Implémentation de la fonction
//BUT : Fait déplacer la balle vers la gauche (MUTATEUR)
//ENTREE : La balle et le coefficient directeur Y en cours
//SORTIES : La nouvelle position de la balle
extern void setBalleGauche(SDL_Rect *balle, const int nCoeffY)
{
    balle->x -= COEFFX;
    balle->y += nCoeffY;
}
