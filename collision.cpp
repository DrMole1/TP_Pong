#include "collision.h"

//Implémentation de la fonction
//BUT : Renvoie un booléen si la balle touche la raquette droite
//ENTREE : La balle et la raquette droite
//SORTIES : Un booléen
extern bool toucheRaq2(const SDL_Rect balle, const SDL_Rect raquette2)
{
    bool blTemp = false;
    if (balle.x+TAILLEBALLE >= raquette2.x && balle.y >= raquette2.y - TAILLEBALLE && balle.y <= raquette2.y + raquette2.h)
    {
        blTemp = true;
    }
    return blTemp;
}


//Implémentation de la fonction
//BUT : Renvoie un booléen si la balle touche la raquette gauche
//ENTREE : La balle et la raquette gauche
//SORTIES : Un booléen
extern bool toucheRaq1(const SDL_Rect balle, const SDL_Rect raquette1)
{
    bool blTemp = false;
    if (balle.x <= raquette1.x + raquette1.w && balle.y >= raquette1.y - TAILLEBALLE && balle.y <= raquette1.y + raquette1.h)
    {
        blTemp = true;
    }
    return blTemp;
}


//Implémentation de la fonction
//BUT : Renvoie un booléen si la balle touche le mur de jeu
//ENTREE : La balle
//SORTIES : Un booléen
extern bool toucheMur(const SDL_Rect balle)
{
    bool blTemp = false;
    if (balle.y <= UN || balle.y + TAILLEBALLE >= LARGECRAN)
    {
        blTemp = true;
    }
    return blTemp;
}


//Implémentation de la fonction
//BUT : Renvoie un booléen si la balle touche le goal d'un joueur
//ENTREE : La balle
//SORTIES : Un booléen
extern bool toucheBut(const SDL_Rect balle)
{
    bool blTemp = false;
    if (balle.x <= UN || balle.x + balle.w >= LONGECRAN)
    {
        blTemp = true;
    }
    return blTemp;
}
