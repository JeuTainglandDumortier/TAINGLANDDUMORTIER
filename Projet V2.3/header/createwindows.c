#include "createwindows.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <SDL2/SDL.h>




void createwindows(unsigned int largeur_map, unsigned int largeur_tile, unsigned int hauteur_map,unsigned int hauteur_tile, SDL_Renderer *afficheur, SDL_Window *ecran)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
		printf("erreur  test renderer ");
        //goto Quit;
    }
    ecran = SDL_CreateWindow("Kill Monster !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                             largeur_map * largeur_tile, hauteur_map * hauteur_tile, SDL_WINDOW_SHOWN);
    if (ecran == NULL){
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
		printf("erreur  test renderer ");
        //goto Quit;
    }
    afficheur = SDL_CreateRenderer(ecran, -1, SDL_RENDERER_ACCELERATED);
    if (afficheur == NULL){
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        //goto Quit;
		printf("erreur  test renderer ");
		
		
    }
}