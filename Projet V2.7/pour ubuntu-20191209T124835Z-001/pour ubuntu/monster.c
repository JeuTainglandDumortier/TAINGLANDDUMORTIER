#include <SDL2/SDL.h>
#include "monster.h"
#include "Map.h"
#include<stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>




int valeuralea(int min1, int max1)
{


    

	/*srand(time(NULL));*/
	return (rand()%(max1-min1+1)+min1);
      
}


Monster* CreateMonster(SDL_Renderer *pRenderer)
{
    Monster* monster = (Monster*) malloc(sizeof(Monster));
    SDL_Surface* pSprite = SDL_LoadBMP("monstres.bmp");
        
	if ( pSprite ){
		SDL_SetColorKey(pSprite, SDL_TRUE, SDL_MapRGB(pSprite->format, 255, 255, 0));
		monster->texture = SDL_CreateTextureFromSurface(pRenderer,pSprite); // Préparation du sprite.
		SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
        monster->src = (SDL_Rect) { 0,0,60,54 };
		int valeura=valeuralea(50,100);
		printf("valeura:%d\n",valeura);
		
		int valeurb=valeuralea(100,150);
		printf("valeurb:%d\n",valeurb);
        monster->dest = (SDL_Rect) { valeura,valeurb,20,20 };;
	}

    return monster;
}



void RenderMonster(SDL_Renderer* renderer, Monster* monster)
{
    SDL_RenderCopy(renderer, monster->texture, &monster->src, &monster->dest);
}