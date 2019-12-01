#ifndef MAP_H_
#define MAP_H_
#include <SDL2/SDL.h>
#define EMPTY_TILE ' '





typedef struct Postext
{
	SDL_Rect dest;
	
	
	
}Postext;


typedef struct Map
{

    unsigned int largeur, hauteur;
    unsigned int largeur_tile, hauteur_tile;
    char** tiles;
	Postext **tabtexture;
    struct SDL_Texture* texture;
    //struct SDL_Renderer* afficheur;
} Map;






Map* CreateMap(const char* path, unsigned largeur_tile, unsigned hauteur_tile);

void LoadMapGraphics(Map* map, SDL_Renderer* renderer, const char* tileset_path);

void RenderMap(Map* map,SDL_Renderer* mapRend);

char* tabcar (const char* tileset_path);

void DestroyMap(Map* map);

#endif
