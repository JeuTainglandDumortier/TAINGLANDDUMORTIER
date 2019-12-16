#ifndef _COLLISION_H
#define _COLLISION_H



#include <SDL2/SDL.h>

#include "monster.h"
#include "Player.h"
#include "liste.h"
//#include "Map.h"



int CollisionentreMonster(liste M, Monster* monster );
int CollisionMonsterPLayer(liste M, Player* player,SDL_Event* event);
int CollisonCombat(Monster* monster, Player *player);
//void CollisionMonster(Monster *monster, Map* map);

















#endif

