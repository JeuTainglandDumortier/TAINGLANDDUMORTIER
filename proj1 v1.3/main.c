#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
//#include "SDL2_image/SDL_image.h"

//#include <SDL_image.h>
#include "allouertab.c"
#include "affichagemap.c"
#include "chargementtxt.c"

#define LARGEUR_TILE 16 // hauteur et largeur des tiles.
#define HAUTEUR_TILE 16

#define NOMBRE_BLOCS_LARGEUR 40 // nombre a afficher en x et y
#define NOMBRE_BLOCS_HAUTEUR 30




int main(int argc, char *argv[])
{
    SDL_Window *ecran = NULL;
    SDL_Renderer *afficheur = NULL;

    SDL_Surface *tileset = NULL;
    SDL_Texture *textuTil = NULL;
    SDL_Event event;
    int continuer = 1, tempsPrecedent = 0, tempsActuel = 0;
    int statut = EXIT_FAILURE;
	char** table2=ReadFile();
	printf("TEST1\n");
	
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
	printf("TEST2\n");
    ecran = SDL_CreateWindow("Kill Monster !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            LARGEUR_TILE*NOMBRE_BLOCS_LARGEUR, HAUTEUR_TILE*NOMBRE_BLOCS_HAUTEUR, SDL_WINDOW_SHOWN);
    if (ecran == NULL)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
	printf("TEST2.1\n");
    afficheur = SDL_CreateRenderer(ecran, -1, SDL_RENDERER_ACCELERATED);
    if (afficheur == NULL)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }
	printf("TEST2.2\n");
    tileset = SDL_LoadBMP("bloc16t.bmp");
	SDL_SetColorKey(tileset,SDL_TRUE,SDL_MapRGB(tileset->format,255,255,0));
	//SDL_Texture* fen =SDL_CreateTextureFromSurface(afficheur,tileset);
    if (tileset == NULL)
    {
        fprintf(stderr, "Erreur chargement image droite : %s", SDL_GetError());
        goto Quit;
    }
    printf("TEST2.3\n");
    textuTil = SDL_CreateTextureFromSurface(afficheur, tileset);
    if (textuTil == NULL)
    {
        fprintf(stderr, "Erreur SDL_CreateTexturetil : %s", SDL_GetError());
        goto Quit;
    }
	
    SDL_FreeSurface(tileset);
	
	printf("TEST4\n");
	afficher_tableau(table2,NOMBRE_BLOCS_HAUTEUR,NOMBRE_BLOCS_LARGEUR);
	Afficher(afficheur, textuTil, table2, NOMBRE_BLOCS_LARGEUR, NOMBRE_BLOCS_HAUTEUR, LARGEUR_TILE, HAUTEUR_TILE);
	
	
	int h=0;
	while(h<4)
	{
	//spriteim(afficheur,jou);
	printf("testbouclesprite");
	h++;
	}
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
					case SDLK_d:
					
					printf("avance");
                }
                break;
        }

        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > 30) /* si 30ms se sont écoulé depuis le dernier tour de la boucle
                                                  plus le temps est petit plus il se deplace vite */
        {
            tempsPrecedent = tempsActuel; // le temps actuel devient le temps présent
        }
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }

        SDL_RenderPresent(afficheur);
		
    }

Quit:
    if (NULL != textuTil)
        SDL_DestroyTexture(textuTil);
    if (NULL != afficheur)
        SDL_DestroyRenderer(afficheur);
    if (NULL != ecran)
        SDL_DestroyWindow(ecran);
    SDL_Quit();

    return statut;
}