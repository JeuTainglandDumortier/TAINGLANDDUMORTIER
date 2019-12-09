#ifndef MONSTER_H_
#define MONSTER_H_

#include <SDL2/SDL.h>
#include "Map.h"




typedef struct Monster
{
    SDL_Texture* texture;
    SDL_Rect src;
    SDL_Rect dest;
	int pv;
	
} Monster;

int valeuralea(int min1, int max1);
void CollisionMonster(Monster *monster, Map* map);
Monster* CreateMonster(SDL_Renderer *pRenderer, Map* map);
void RenderMonster(SDL_Renderer* renderer, Monster* monster);



#endif
