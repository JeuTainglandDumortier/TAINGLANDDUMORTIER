#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "Map.h"
#include "sprite.h"
#include "Player.h"
#include "InputHandler.h"
//#include "createwindows.c"

#define LARGEUR_TILE 16 // hauteur et largeur des tiles.
#define HAUTEUR_TILE 16

//#define NOMBRE_BLOCS_LARGEUR 5 // nombre a afficher en x et y
//#define NOMBRE_BLOCS_HAUTEUR 5

int main(int argc, char *argv[])
{
    SDL_Window *ecran = NULL;
    SDL_Renderer *afficheur = NULL;

    SDL_Surface *tileset = NULL;
    SDL_Texture *textuTil = NULL;
    SDL_Event event;
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    int statut = EXIT_FAILURE;
	
	
	
	Map* map = CreateMap("gms.txt", 16, 16);   
	Map* map2 = CreateMap("gms2.txt", 16, 16);
    printf("MAP SIZE : %u, %u.\n", map->largeur, map->hauteur);

   if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    ecran = SDL_CreateWindow("Kill Monster !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                             map->largeur * map->largeur_tile, map->hauteur * map->hauteur_tile, SDL_WINDOW_SHOWN);
    if (ecran == NULL){
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
    afficheur = SDL_CreateRenderer(ecran, -1, SDL_RENDERER_ACCELERATED);
    if (afficheur == NULL){
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }
	//createwindows(map->largeur,map->largeur_tile,map->hauteur,map->hauteur_tile,afficheur,ecran);
	int posx=240;
	int posy=200;
	
	LoadMapGraphics(map2, afficheur, "bloc16t.bmp");
    LoadMapGraphics(map, afficheur, "bloc16t.bmp");
	SDL_Texture *sprite=LoadSprite(afficheur);
	spriteim(sprite,afficheur,posx,posy);
	Player* player = CreatePlayer(afficheur);
   
    while (continuer)
    {
        HandleInput(map, player, &event);
        SDL_RenderClear(afficheur);
         
        RenderMap(map2,afficheur);
        RenderMap(map,afficheur);
        
        RenderPlayer(afficheur, player);
        SDL_RenderPresent(afficheur);
    }
   

Quit:
    if (NULL != textuTil)
        SDL_DestroyTexture(textuTil);
        SDL_DestroyTexture(sprite);
    if (NULL != afficheur)
        SDL_DestroyRenderer(afficheur);
    if (NULL != ecran)
        SDL_DestroyWindow(ecran);
    SDL_Quit();

    return statut;
}
