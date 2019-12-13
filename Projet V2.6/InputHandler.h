#ifndef _INPUT_HANDLER_H
#define _INPUT_HANDLER_H

#include <SDL2/SDL.h>
#include "Player.h"
#include "Map.h"
#include "liste.h"
#include "monster.h"
#include <stdio.h>
#include <stdlib.h>


void HandleInput(Map* map, Player* player, SDL_Event* event, liste M);
void Handmonster(liste M,Map* map);
void evenement(liste M);
#endif
