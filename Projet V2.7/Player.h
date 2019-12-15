#ifndef _PLAYER_H
#define _PLAYER_H

#include <SDL2/SDL.h>
#include "Map.h"
#include "liste.h"


typedef struct Player
{
    SDL_Texture* texture;
    SDL_Rect src;
    SDL_Rect dest;
} Player;

Player* CreatePlayer(SDL_Renderer *pRenderer);

int HandlePlayerMovment(Map* map, Player* player, int addx, int addy, liste M);

void RenderPlayer(SDL_Renderer* renderer, Player* player);

void DestroyPlayer(Player* player);

int IsInBox(const SDL_Rect* const src, const SDL_Rect* const box);

#endif




