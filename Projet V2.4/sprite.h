
#include <SDL2/SDL.h>

#ifndef SPRITE_H_
#define SPRITE_H_




	
    
    



SDL_Texture* LoadSprite(SDL_Renderer *pRenderer);
void spriteim(/*Sprite* sprite* ,*/ SDL_Texture* pTexture, SDL_Renderer *pRenderer, int posx,int posy);


#endif
