#include "sprite.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>






SDL_Texture* LoadSprite(SDL_Renderer *pRenderer)
{
		if ( pRenderer )
	{
		SDL_Surface* pSprite = SDL_LoadBMP("spritez.bmp");
        
		if ( pSprite )
		{
			SDL_SetColorKey(pSprite, SDL_TRUE, SDL_MapRGB(pSprite->format, 255, 255, 0));
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
			
			
			
			
			
			
			
			
void spriteim(/*Sprite* sprite, */SDL_Texture* pTexture, SDL_Renderer *pRenderer,int posx, int posy)
{
	
			if ( pTexture )
			{
				
				SDL_Rect src={0,530,130,120};
				SDL_Rect dest = {posx,posy,50,50};
				printf("danssprite\n");
				printf("valeur x dans sprite:%d\n",posx);
				SDL_RenderCopy(pRenderer,pTexture,&src,&dest); // Copie du sprite grâce au SDL_Renderer
				
				//SDL_RenderPresent(pRenderer); // Affichage
				//SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */
				
				//SDL_DestroyTexture(pTexture); // Libération de la mémoire associée à la texture
			}
			else
			{
				fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
			}
			
			
		
		
		
		//SDL_DestroyRenderer(pRenderer); // Libération de la mémoire du SDL_Renderer
}
	
