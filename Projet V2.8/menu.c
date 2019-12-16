#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


int MenuInput(SDL_Event* ev, SDL_Renderer* rend)
{
    
    SDL_Surface *fond = SDL_LoadBMP("menu/background.bmp");
    SDL_Texture* bg = SDL_CreateTextureFromSurface(rend,fond);
    
    SDL_Rect position_bg;
    position_bg.x=0;
    position_bg.y=0;
    position_bg.w=800;
    position_bg.h=480;
    
    SDL_RenderCopy(rend,bg, NULL, &position_bg);
    
    int curseurx;
    int curseury;
    
    SDL_PollEvent(ev);    
    switch (ev->type){
        case SDL_QUIT:
            exit(0);
            break;
            
        case SDL_MOUSEBUTTONDOWN:
            curseurx= ev->button.x;
            curseury= ev->button.y;
          
            if (( curseurx > 325 && curseurx < 475) && (curseury > 170 && curseury < 320))
            { 
                return 0;
            }
           
        case SDL_KEYDOWN:
            switch (ev->key.keysym.sym){
            case SDLK_ESCAPE:
                exit(0);
                break;
            case SDLK_d:
                return 0;
                break;
            }
    }
return 1;
}
                


