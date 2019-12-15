#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "bouton.h"

Bouton* CreateBouton(SDL_Renderer *bRenderer)
{
    Bouton* button = (Bouton*) malloc(sizeof(Bouton));
    SDL_Surface* pbouton = SDL_LoadBMP("menu/play.bmp");
        
	if ( pbouton ){
		//SDL_SetColorKey(pbouton, SDL_TRUE, SDL_MapRGB(pbouton->format, 255, 255, 0));
		button->texture = SDL_CreateTextureFromSurface(bRenderer,pbouton); // Préparation du sprite.
		SDL_FreeSurface(pbouton); // Libération de la ressource occupée par le sprite
        button->src = (SDL_Rect) { 0,0,128,128 };
        button->dest = (SDL_Rect) { 325,170,150,150 };;
	}

    return button;
}


void RenderBouton(SDL_Renderer* renderer, Bouton* button)
{
    SDL_RenderCopy(renderer, button->texture, &button->src, &button->dest);
}



void DestroyBouton(Bouton* button)
{
    SDL_DestroyTexture(button->texture);
}
