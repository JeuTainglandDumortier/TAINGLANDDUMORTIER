
#include <SDL2/SDL.h>

#ifndef SPRITE_H_
#define SPRITE_H_



typedef struct Face
{
	
	SDL_Rect src;
	SDL_Rect dest;

}Face;


typedef struct Sprite
{
	 Face tabfacefront[15];
	 Face tabfaceback[15];
}	Sprite;
	
	
    
    



SDL_Texture* LoadSprite(SDL_Renderer *pRenderer);
void spriteim(/*Sprite* sprite* ,*/ SDL_Texture* pTexture, SDL_Renderer *pRenderer, int posx,int posy);


#endif
