#include <SDL2/SDL.h>
#include "monster.h"
#include "Map.h"
#include "Player.h"
#include<stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>




int valeuralea(int min1, int max1)
{

	return (rand()%(max1-min1+1)+min1);
      
}


int valeuraleaposm(int min1 , int max1)
{
    int val=(rand()%(max1-min1+1)+min1);
    if (!(val==min1) && !(val==max1))
    {
        return valeuraleaposm(min1 ,max1);
    }
    return val;
}
    
    
int egalmonster(Monster* m1, Monster* m2)
{
    if ((m1->dest.x==m2->dest.x) &&(m2->dest.y==m2->dest.y))
    {
        return 1;
    }
    return 0;
}
    
    
    
    
    

int CollisionMonster(Monster *monster, Map* map, int posx , int posy)
{
    SDL_Rect future_pos = (SDL_Rect) { posx, posy, monster->dest.w, monster->dest.h };
     //printf("seg fault fcoli1\n");
    for (int i = 0; i < map->colision_tile_count; i++)
    {
        if ((IsInBox(&(future_pos), &map->collision_boxs[i])) && (monster->pv>0))
        
        {
            //printf("seg fault fcoli2\n");
           return 1;
        }
    }
    //printf("seg fault fcoli3\n");
    return 0;
}








Monster* CreateMonster(SDL_Renderer *pRenderer, Map* map)
{
    Monster* monster = (Monster*) malloc(sizeof(Monster));
    SDL_Surface* pSprite = SDL_LoadBMP("monstres.bmp");
        
	if ( pSprite ){
		SDL_SetColorKey(pSprite, SDL_TRUE, SDL_MapRGB(pSprite->format, 255, 255, 0));
		monster->texture = SDL_CreateTextureFromSurface(pRenderer,pSprite); // Préparation du sprite.
		SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
        monster->src = (SDL_Rect) { 11,2,54,54 };
		//monster->dest=(SDL_Rect){valeuralea(0, map->largeur*map->largeur_tile),valeuralea(0, map->hauteur*map->hauteur_tile),20,20};
        int posx=valeuralea(0, map->largeur*map->largeur_tile);
        int posy=valeuralea(0, map->hauteur*map->hauteur_tile);
        monster->dest=(SDL_Rect){posx,posy,20,20};
		monster->pv=valeuralea(10,20);
        //printf("test\n");
        while (CollisionMonster(monster,map,posx,posy))
        {
            //printf("test2\n");
            posx=valeuralea(0, map->largeur*map->largeur_tile);
            posy=valeuralea(0, map->hauteur*map->hauteur_tile);
             
        }
        monster->dest=(SDL_Rect){posx,posy,20,20};
        monster->pv=valeuralea(10,20);
	}

    return monster;
}



void RenderMonster(SDL_Renderer* renderer, Monster* monster)
{
	if (monster->pv>0)
	{
    SDL_RenderCopy(renderer, monster->texture, &monster->src, &monster->dest);
	}
}



void free_monster(Monster* monster)
{
    
    
    SDL_DestroyTexture(monster->texture);
    
}



void deplacemonster(Monster* monster, Map *map,int addx, int addy)
{
   //int addx=valeuraleaposm(-2,2);
   //int addy=valeuraleaposm(-2,2);
   /*if (CollisionMonster(monster,map,addx,addy))
   {
       deplacemonster(monster,map);
   }*/
       
    monster->dest.x+=addx;
    
    monster->dest.y+=addy;
    
}





int movement_monster(Monster* monster,int depl, Map* map)
{
    
    int movepos=valeuralea(0,3);
    //printf("valeur alea%d\n",movepos);
    //0:top 1:bottom  2:right  3:left
    
    int deplmem;
    if (movepos==0)
    {
        deplmem=monster->dest.y-depl;
            if (!CollisionMonster(monster,map,0,deplmem))
            {
                //deplacemonster(monster,0,-depl);
                return 1;
            }
       return 0;
    }
    
    
    if (movepos==1)
    {
        
        deplmem=monster->dest.y+depl;
            if (!CollisionMonster(monster,map,0,deplmem))
            {
                //deplacemonster(monster,0,depl);
                return 1;
            }
            return 0;
    }
    
    
    if (movepos==2)
    {
          deplmem=monster->dest.x+depl;
            if (!CollisionMonster(monster,map,deplmem,0))
            {
                //deplacemonster(monster,depl,0);
                return 1;
            }
            return 0;
    }
    
    
    if (movepos==3)
    {
      deplmem=monster->dest.x-depl;
            if (!CollisionMonster(monster,map,deplmem,0))
            {
                //deplacemonster(monster,-depl,0);
                return 1;
            }
       return 0;
        
    }
    free(deplmem);
    free(movepos);
}
