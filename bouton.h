
#include <SDL2/SDL.h>

#ifndef BOUTON_H_
#define BOUTON_H_


typedef struct Bouton
{
	
	int posx;
	int posy;
	int largeur;
	int hauteur;

}Bouton;



SDL_Texture* LoadBouton(SDL_Renderer *pRenderer);


void bouton_sprite(SDL_Texture* pTexture, SDL_Renderer *pRenderer);


#endif
