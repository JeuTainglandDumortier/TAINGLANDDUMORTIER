#ifndef MONSTER_H_
#define MONSTER_H_

#include <SDL2/SDL.h>



typedef struct Monster
{
    SDL_Texture* texture;
    SDL_Rect src;
    SDL_Rect dest;
	int pv;
	
} Monster;

int valeuralea(int min1, int max1);
Monster* CreateMonster(SDL_Renderer *pRenderer);
void RenderMonster(SDL_Renderer* renderer, Monster* monster);



#endif