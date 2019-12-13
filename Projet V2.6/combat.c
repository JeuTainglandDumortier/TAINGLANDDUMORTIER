#include <SDL2/SDL.h>
#include "monster.h"
#include "Map.h"
#include "Player.h"
#include<stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>




void combat (Player* player, liste M, SDL_Event* event)
{
    
    printf("dans combat\n");
    SDL_PollEvent(event);
    switch (event->type)
    {    
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym)
            {
                case SDLK_t:
                    while (!est_vide(M))
                    {
                        if (CollisonCombat(M->premier,player))
                        {
                           M->premier->pv-=5;
                           printf("pv du monstre:%d\n",M->premier->pv);
                        }
                        M=reste(M);
                        
                    }
                    
            }
            break;
                    
                
    }       
}
