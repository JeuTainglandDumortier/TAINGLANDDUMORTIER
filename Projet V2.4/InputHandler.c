

#include <SDL2/SDL.h>
#include "InputHandler.h"
#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Map.h"

void HandleInput(Map* map, Player* player, SDL_Event* event)
{
    SDL_PollEvent(event);
    switch (event->type){
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym){
            case SDLK_ESCAPE:
                exit(0);
                break;
            case SDLK_d:
                if (HandlePlayerMovment(map, player, 20, 0)){
                    player->src.y=910;
				    player->dest.x+=2;
                    player->src.x+=120;
                    if(player->src.x==1200)
                        player->src.x=0;
                    printf("posx:%d , posy:%d\n",player->dest.x,player->dest.y);
                    printf("srcx:%d , srcy:%d\n",player->src.x,player->src.y);
                    
                }

                break;
            case SDLK_q:
                if (HandlePlayerMovment(map, player, -20, 0)){
                    player->src.y=660;
                    player->dest.x-=2;
                    player->src.x+=120;
                    if(player->src.x==1200)
                        player->src.x=0;
                    printf("posx:%d , posy:%d\n",player->dest.x,player->dest.y);
                    printf("srcx:%d , srcy:%d\n",player->src.x,player->src.y);
                }
                break;
            case SDLK_s:
                if (HandlePlayerMovment(map, player, 0, 20)){
                    player->src.y=530;
                    player->dest.y+=2;
                    player->src.x+=120;
                    if(player->src.x==1200)
                        player->src.x=0;
                    printf("posx:%d , posy:%d\n",player->dest.x,player->dest.y);
                    printf("srcx:%d , srcy:%d\n",player->src.x,player->src.y);
                }
                break;
            case SDLK_z:
                if (HandlePlayerMovment(map, player, 0, -20)){
                    player->src.y=790;
				    player->dest.y-=2;
                    player->src.x+=120;
                    if(player->src.x==1200)
                        player->src.x=0;
                    printf("posx:%d , posy:%d\n",player->dest.x,player->dest.y);
                    printf("srcx:%d , srcy:%d\n",player->src.x,player->src.y);
                }
                break;
            }
    }
}
