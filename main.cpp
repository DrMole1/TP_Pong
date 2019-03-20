//Implémentation des bibliothèques
#include "jeu.h"
#include "collision.h"
#include "vue.h"

//Implémentation
//BUT : Reproduire le jeu du pong : Une balle se déplace sur une surface et deux raquettes se déplacent vers le haut et le bas pour que la balle
//ne passe pas dans leur camp. Une partie s'arrête quand l'un des joueurs a 3 points = il est donc vainqueur.
//ENTREE : L'environnement
//SORTIE : Une fenêtre
int main( int argc, char * argv[] )
{
    SDL_Init(SDL_INIT_VIDEO); // Démarrage de la SDL (ici : chargement du système vidéo)
    TTF_Init();


    //Partie déclarations des variables
    //====================================================================
    SDL_Window *pWindow = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;
    bool blCont=true, blJeu=false, blStart=true; //On est en cpp, pas besoin de typedef enum Bool (malinx le lynx)
    SDL_Rect raquette1;
    SDL_Rect raquette2;
    SDL_Rect balle;
    tDirection direct_Balle = droite; //La balle va partir vers la droite au début de partie
    int nCoeffY=0, nScore1=0, nScore2=0;
    //====================================================================

    pWindow = SDL_CreateWindow("Pong",SDL_WINDOWPOS_UNDEFINED,
                                                          SDL_WINDOWPOS_UNDEFINED,
                                                          LONGECRAN,
                                                          LARGECRAN,
                                                          SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(pWindow, -1, 0);
    srand(time(NULL)); //Appel de la fonction randomize

    if( pWindow ) // Dès que la fenêtre est créée
    {
        while(blCont == true)  // Tant que le jeu continue
        {
            while (SDL_PollEvent(&event)) // Stockage des événements :
            {
                switch(event.type)
                {
                    case SDL_QUIT:  // Pour fermer la fenêtre
                        blCont = false;
                        break;

                    case SDL_KEYDOWN:
                        if(event.key.keysym.sym == SDLK_SPACE) // Pour passer du menu au jeu
                        {
                            blJeu=true;
                        }
                        if(event.key.keysym.sym ==  SDLK_DOWN) // Pour déplacer la raquette du joueur vers le bas
                        {
                            if (blJeu==true)
                            {
                                if (raquette1.y + raquette1.h < LARGECRAN)
                                {
                                    setRaquette1Y(&raquette1, DOWN);
                                }
                            }
                        }
                        if(event.key.keysym.sym ==  SDLK_UP) // Pour déplacer la raquette du joueur vers le haut
                        {
                            if (blJeu==true)
                            {
                                if (raquette1.y > 0)
                                {
                                    setRaquette1Y(&raquette1, UP);
                                }
                            }
                        }
                        break;
                }
            }


            // Boucle de jeu :
            if (blJeu==false)
            {
                renduMenu(&renderer);
            }
            else
            {
                // Au début de la partie
                if (blStart==true)
                {
                    blStart=false;
                    direct_Balle = droite;
                    initJeu(&raquette1, &raquette2, &balle); //on initialise le rendu de début de partie
                    nCoeffY=(rand()%MAXRAND)-MIDRAND; //On affecte un coefficient directeur de l'axe Y pour la balle, compris entre -3 et 3
                }

                //NOTE : la liste des conditionnelles suivantes sont mis dans l'ordre de la plus produite à la moins produite pour ne pas passer à
                //chaque fois par la première et tester la méthode de condition -> OPTIMISATION
                // Si la balle touche le mur de jeu
                if (toucheMur(balle))
                {
                    nCoeffY *= -UN;
                }
                //Si la balle touche une raquette
                else if (toucheRaq2(balle,raquette2))
                {
                    direct_Balle = gauche;
                    nCoeffY=(rand()%MAXRAND)-MIDRAND;
                }
                else if (toucheRaq1(balle,raquette1))
                {
                    direct_Balle = droite;
                    nCoeffY=(rand()%MAXRAND)-MIDRAND;
                }
                // Si la balle touche un des deux camps
                else if (toucheBut(balle))
                {
                    blStart = true;  //On ré-initialise le terrain pour la prochaine balle
                    if (direct_Balle == gauche)
                        nScore2++;
                    else
                        nScore1++;
                    // Si un des joueurs a marqué 3 points
                    if (nScore1 == 3 || nScore2 == 3)
                    {
                        blCont = false;
                    }
                }



                // Set la position de la balle selon sa direction
                if (direct_Balle==droite)
                {
                    setBalleDroite(&balle, nCoeffY);
                }
                else
                {
                    setBalleGauche(&balle, nCoeffY);
                }

                setRaquette2Y(&raquette2, balle); // On set l'axe y de la raquette de l'IA
                renduJeu(&renderer, &raquette1, &raquette2, &balle, nScore1, nScore2); // On met à jour le rendu
                SDL_Delay(DELAI); // Petit délais pour éviter un jeu trop rapide
            }
        }
    }

    SDL_DestroyWindow(pWindow);// Destruction de la fenêtre
    TTF_Quit();
    SDL_Quit(); // Arrêt de la SDL (libération de la mémoire)
    printf("Score joueur 1 : %d. Score joueur 2 : %d.\n", nScore1, nScore2); //affichage du score
    return 1;
}
