
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>

SDL_Texture* LoadBackground(SDL_Renderer *pRenderer)
{
		if ( pRenderer )
	{
		SDL_Surface* pSprite = SDL_LoadBMP("background/starting_screen.bmp");
        
		if ( pSprite )
		{
			SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer,pSprite); // Préparation du sprite.
			SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
			return pTexture;
		}
		
		else
		{
			fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
            return 0;
		}
		
	}
	else
	{
		fprintf(stdout,"Échec de création du renderer (%s)\n",SDL_GetError());
        return 0;
	}
    
	
}
			

void starting_sprite(SDL_Texture* pTexture, SDL_Renderer *pRenderer, Map *map)
{

	if (pTexture)
	{

		SDL_Rect src_bg={0,0,1920,1080};
		SDL_Rect dest_bg = {0,0, map->largeur*map->largeur_tile, map->hauteur*map->hauteur_tile};
		SDL_RenderCopy(pRenderer,pTexture,&src_bg,&dest_bg);
		
	}
	else
	{
		fprintf(stdout,"Échec de création de la texture (background) (%s)\n",SDL_GetError());
	}

}