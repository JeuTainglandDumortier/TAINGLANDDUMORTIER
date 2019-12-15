


#include "Player.h"
#include "Map.h"
#include "liste.h"
#include "collision.h"

Player* CreatePlayer(SDL_Renderer *pRenderer)
{
    Player* player = (Player*) malloc(sizeof(Player));
    SDL_Surface* pSprite = SDL_LoadBMP("spritez.bmp");
        
	if ( pSprite ){
		SDL_SetColorKey(pSprite, SDL_TRUE, SDL_MapRGB(pSprite->format, 255, 255, 0));
		player->texture = SDL_CreateTextureFromSurface(pRenderer,pSprite); // Préparation du sprite.
		SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
        player->src = (SDL_Rect) { 0,910,130,120 };
        player->dest = (SDL_Rect) { 240,200,20,20 };
	}

    return player;
}

void RenderPlayer(SDL_Renderer* renderer, Player* player)
{
    SDL_RenderCopy(renderer, player->texture, &player->src, &player->dest);
}

int HandlePlayerMovment(Map* map, Player* player, int addx, int addy, liste M)
{
    
    SDL_Rect future_pos = (SDL_Rect) { player->dest.x + addx, player->dest.y + addy, player->dest.w, player->dest.h };
    Player FuturPos = {player->texture, player->src, future_pos};
    for (int i = 0; i < map->colision_tile_count; i++){
        if ((IsInBox(&future_pos, &map->collision_boxs[i])) || (CollisionMonsterPLayer(M,&FuturPos)))
        {
            return 0;
        }
        
    }

    return 1;
}

int IsInBox(const SDL_Rect* const src, const SDL_Rect* const box)
{
    SDL_Rect junk_res;
    return SDL_IntersectRect(src, box, &junk_res);
}

void DestroyPlayer(Player* player)
{
    SDL_DestroyTexture(player->texture);
}
