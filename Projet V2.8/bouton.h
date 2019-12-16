#ifndef _BOUTON_H
#define _BOUTON_H

#include <SDL2/SDL.h>

typedef struct Bouton
{
    SDL_Texture* texture;
    SDL_Rect src;
    SDL_Rect dest;
} Bouton;

Bouton* CreateBouton(SDL_Renderer *bRenderer);


void RenderBouton(SDL_Renderer* renderer, Bouton* button);

void DestroyBouton(Bouton* button);


#endif
