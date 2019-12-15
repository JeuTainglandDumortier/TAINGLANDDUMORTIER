#ifndef MONSTER_H_
#define MONSTER_H_

#include <SDL2/SDL.h>
#include "Map.h"
//#include "collision.h"




typedef struct Monster
{
    SDL_Texture* texture;
    SDL_Rect src;
    SDL_Rect dest;
	int pv;
	
} Monster;

int valeuralea(int min1, int max1);
int CollisionMonster(Monster *monster, Map* map, int posx, int posy);
Monster* CreateMonster(SDL_Renderer *pRenderer, Map* map);
void RenderMonster(SDL_Renderer* renderer, Monster* monster);
int movement_monster(Monster* monster,int depl, Map* map);
void deplacemonster(Monster* monster,Map* map,int addx, int addy);
int egalmonster(Monster* m1, Monster* m2);



#endif
