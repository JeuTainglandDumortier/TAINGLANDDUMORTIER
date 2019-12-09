#ifndef MAP_H_
#define MAP_H_
#include <SDL2/SDL.h>
#define EMPTY_TILE ' '

static const char* COLLISION_TILE_ID;

typedef struct Map
{

    unsigned int largeur, hauteur;
    unsigned int largeur_tile, hauteur_tile;
    char** tiles;
    SDL_Texture* tile_texture;
    SDL_Texture* map_texture;
    unsigned int colision_tile_count;
    SDL_Rect* collision_boxs;
} Map;

Map* CreateMap(const char* path, unsigned largeur_tile, unsigned hauteur_tile);

SDL_Texture* LoadMapGraphics(Map* map, SDL_Renderer* renderer, const char* tileset_path);

void LoadMapTileGraphics(Map* map, SDL_Renderer* mapRend);

void RenderMap(Map* map,SDL_Renderer* mapRend);

void DestroyMap(Map* map);

#endif
