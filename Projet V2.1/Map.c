#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>

Map* CreateMap(const char* path, unsigned largeur_tile, unsigned hauteur_tile)
{
    Map* map = (Map*) malloc(sizeof(Map));
    map->largeur_tile = largeur_tile;
    map->hauteur_tile = hauteur_tile;

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
        l++;
    }

    fclose(map_file);
    return map;
}

void LoadMapGraphics(Map* map, struct SDL_Renderer* renderer, const char* tileset_path)
{
    map->afficheur = renderer;
    SDL_Surface* tileset = SDL_LoadBMP(tileset_path);
    if (!tileset){
        printf("Can't open the image file '%s'.", tileset_path);
        return;
    }
    SDL_SetColorKey(tileset, SDL_TRUE, SDL_MapRGB(tileset->format, 255, 255, 0));
    map->texture = SDL_CreateTextureFromSurface(renderer, tileset);
    if (!map->texture){
        printf("Can't convert the surface to texture.");
    }
    SDL_FreeSurface(tileset);
}

void RenderMap(Map* map)
{
    SDL_Rect Rect_source = {0};
    SDL_Rect Rect_dest = {0};
    Rect_source.w = map->largeur_tile;
    Rect_source.h = map->hauteur_tile;
    Rect_dest.w = map->largeur_tile;
    Rect_dest.h = map->hauteur_tile;

    for (int i = 0; i < map->hauteur; i++)
    {
        for (int j = 0; j < map->largeur; j++)
        {
            if (map->tiles[i][j] == EMPTY_TILE)
               continue;
    
            Rect_source.x = (int)(map->tiles[i][j] - 33) * map->largeur_tile;
            Rect_dest.x = j * map->hauteur_tile;
            Rect_dest.y = i * map->largeur_tile;
            SDL_RenderCopy(map->afficheur, map->texture, &Rect_source, &Rect_dest);
        }
    }
}

void DestroyMap(Map* map)
{
    if (!map){
        SDL_DestroyTexture(map->texture);

        for (int i = 0; i < map->hauteur; i++){
            free(map->tiles[i]);
        }
        free(map->tiles);
    }
}