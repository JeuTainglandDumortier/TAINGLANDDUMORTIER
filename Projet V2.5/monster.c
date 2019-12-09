#include <SDL2/SDL.h>
#include "monster.h"
#include "Map.h"
#include "PLayer.h"
#include<stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>




int valeuralea(int min1, int max1)
{

	return (rand()%(max1-min1+1)+min1);
      
}


void CollisionMonster(Monster *monster, Map* map)
{
    for (int i = 0; i < map->colision_tile_count; i++)
    {
        while (IsInBox(&(monster->dest), &map->collision_boxs[i]))
        
        {
            printf("dans boucle\n");
            monster->dest=(SDL_Rect){valeuralea(0, map->largeur*map->largeur_tile),valeuralea(0, map->hauteur*map->hauteur_tile),20,20};
        }
    }      
}





Monster* CreateMonster(SDL_Renderer *pRenderer, Map* map)
{
    Monster* monster = (Monster*) malloc(sizeof(Monster));
    SDL_Surface* pSprite = SDL_LoadBMP("monstres.bmp");
        
	if ( pSprite ){
		SDL_SetColorKey(pSprite, SDL_TRUE, SDL_MapRGB(pSprite->format, 255, 255, 0));
		monster->texture = SDL_CreateTextureFromSurface(pRenderer,pSprite); // Préparation du sprite.
		SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
        monster->src = (SDL_Rect) { 0,0,60,54 };
		monster->dest=(SDL_Rect){valeuralea(0, map->largeur*map->largeur_tile),valeuralea(0, map->hauteur*map->hauteur_tile),20,20};
        CollisionMonster(monster,map);
        
	}

    return monster;
}



void RenderMonster(SDL_Renderer* renderer, Monster* monster)
{
    SDL_RenderCopy(renderer, monster->texture, &monster->src, &monster->dest);
}
