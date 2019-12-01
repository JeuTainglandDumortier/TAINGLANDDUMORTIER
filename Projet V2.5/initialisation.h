#include <SDL2/SDL.h>

#ifndef INITIALISATION_H_
#define INITIALISATION_H_


typedef struct Sprite
{

   SDL_Texture* texture;
   int posx;
   int posy;
   SDL_Rect src;
   SDL_Rect dest;

} Sprite;



void initialisation_affichage(Map *map, Map *map2, SDL_Renderer *pRenderer, Sprite *spray);



#endif