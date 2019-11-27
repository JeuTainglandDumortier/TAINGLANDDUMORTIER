#include "initialisation.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>




void initialisation_affichage(Map *map, Map *map2, SDL_Renderer *pRenderer, Sprite *spray){

	spray->posx=240;
	spray->posy=200;

	LoadMapGraphics(map2, pRenderer, "bloc16t.bmp");
    RenderMap(map2,pRenderer);
    LoadMapGraphics(map, pRenderer, "bloc16t.bmp");
    RenderMap(map,pRenderer);
	spray->texture=LoadSprite(pRenderer);
	spriteim(spray->texture, pRenderer, spray->posx, spray->posy);
	//RenderMap(map);
	spray->src.x = 0;
	spray->src.y = 910;
	spray->src.w = 120;
	spray->src.h = 120;
	spray->dest.x=spray->posx;
	spray->dest.y=spray->posy;
	spray->dest.w=60;
	spray->dest.h=60;

	//DestroyMap(map);
	SDL_Texture *bouton1 =LoadBouton(pRenderer);
   	SDL_Texture *background=LoadBackground(pRenderer);
	
    starting_sprite(background, pRenderer,map);
    bouton_sprite(bouton1, pRenderer);
    SDL_RenderPresent(pRenderer);

}
