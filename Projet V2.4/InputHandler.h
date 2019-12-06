#ifndef _INPUT_HANDLER_H
#define _INPUT_HANDLER_H

#include <SDL2/SDL.h>
#include "Player.h"
#include "Map.h"
#include <stdio.h>
#include <stdlib.h>


void HandleInput(Map* map, Player* player, SDL_Event* event);

#endif
