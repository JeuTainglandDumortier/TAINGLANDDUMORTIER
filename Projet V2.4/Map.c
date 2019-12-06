#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>

static const char* COLLISION_TILE_ID = "0/12IJKLMNOPQRSTUVWXYZ[\\]^_`a@ABCDEF";

Map* CreateMap(const char* path, unsigned largeur_tile, unsigned hauteur_tile)
{
    Map* map = (Map*) malloc(sizeof(Map));
    map->largeur_tile = largeur_tile;
    map->hauteur_tile = hauteur_tile;
    map->colision_tile_count = 0;

    FILE* map_file = fopen(path, "r");

    if (!map_file) {// en cas d'error (failed to open file or file doesnt exist)
        printf("Can't open file '%s', check if the file exist or you have the permissions to access it.", path);
        return NULL; 
    }

    fscanf(map_file, "%u", &map->hauteur);
    fscanf(map_file, "%u", &map->largeur);

    map->tiles = (char**) malloc(sizeof(char*) * map->hauteur);
    for (int i = 0; i < map->hauteur; i++){
        map->tiles[i] = (char*) malloc(sizeof(char) * map->largeur);
        memset(map->tiles[i], (int) EMPTY_TILE, sizeof(char) * map->largeur); // au lieu d'une autre boucle bla bla bla
    }

    unsigned h = 0; unsigned l = 0;
    bool first_nl = true;
    int tile;

    while ((tile = fgetc(map_file)) != EOF){
        if (tile <= 31 && tile != '\n') continue;

        if (tile == '\n'){
            if (!first_nl){
                h++;
                l = 0;
                if (h >= map->hauteur)
                    break;
            }
            continue;
        }else {
            first_nl = false;
        }

        map->tiles[h][l] = (char) tile;
        if (strchr(COLLISION_TILE_ID, tile) != NULL){
            map->colision_tile_count++;
        }
        l++;
    }

    fclose(map_file);
    return map;
}

SDL_Texture* LoadMapGraphics(Map* map,SDL_Renderer* renderer, const char* tileset_path)
{
	if (renderer)
	{
    //map->afficheur = renderer;
    SDL_Surface* tileset = SDL_LoadBMP(tileset_path);
    if (!tileset){
        printf("Can't open the image file '%s'.", tileset_path);
        return NULL;
    }
    SDL_SetColorKey(tileset, SDL_TRUE, SDL_MapRGB(tileset->format, 255, 255, 0));
    map->tile_texture = SDL_CreateTextureFromSurface(renderer, tileset);
    if (!map->tile_texture){
        printf("Can't convert the surface to texture.");
    }
    SDL_FreeSurface(tileset);
	}
	else
	{
		printf("erreur creation renderer\n");
	}

    map->map_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, map->largeur * map->largeur_tile, map->hauteur * map->hauteur_tile);
    LoadMapTileGraphics(map, renderer);
    return map->tile_texture;
}

void LoadMapTileGraphics(Map* map,SDL_Renderer* mapRend)
{
   
    SDL_Rect Rect_source = {0};
    SDL_Rect Rect_dest = {0};
    Rect_source.w = map->largeur_tile;
    Rect_source.h = map->hauteur_tile;
    Rect_dest.w = map->largeur_tile;
    Rect_dest.h = map->hauteur_tile;

    map->collision_boxs = (SDL_Rect*) malloc(sizeof(SDL_Rect) * map->colision_tile_count);
    unsigned int col_counter = 0;

    SDL_SetRenderTarget(mapRend, map->map_texture);
    for (int i = 0; i < map->hauteur; i++)
    {
        for (int j = 0; j < map->largeur; j++)
        {
            if (map->tiles[i][j] == EMPTY_TILE)
               continue;
    
            Rect_source.x = (int)(map->tiles[i][j] - 33) * map->largeur_tile;
            Rect_dest.x = j * map->hauteur_tile;
            Rect_dest.y = i * map->largeur_tile;
            SDL_RenderCopy(mapRend, map->tile_texture, &Rect_source, &Rect_dest);

            if (strchr(COLLISION_TILE_ID, map->tiles[i][j]) != NULL){
                map->collision_boxs[col_counter] = Rect_dest;
                col_counter++;
            }
            
        }
    }
    SDL_SetRenderTarget(mapRend, NULL);
}

void RenderMap(Map* map,SDL_Renderer* mapRend)
{	
	SDL_SetTextureBlendMode (map->map_texture, SDL_BLENDMODE_BLEND); 
    SDL_RenderCopy(mapRend, map->map_texture, NULL, NULL);
}

void DestroyMap(Map* map)
{
    if (!map){
        SDL_DestroyTexture(map->tile_texture);
        SDL_DestroyTexture(map->map_texture);

        for (int i = 0; i < map->hauteur; i++){
            free(map->tiles[i]);
        }
        free(map->tiles);
        free(map->collision_boxs);
    }
}
