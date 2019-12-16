


#include "InputHandler.h"
#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Map.h"
#include "collision.h"
#include "monster.h"






void Handmonster(liste M,Map* map)
{
    int i=0,j=0;
	int addx, addy,posx,posy;
	//liste copieM=M;

	
    while (!est_vide(M))
    {
	
		
		addx=valeuraleaposm(0,10);
	if (addx!=0)
	{
		if (valeuralea(0,1)==0)
		{
			addx=-valeuraleaposm(0,10);
		}
		else 
		{
			addx=valeuraleaposm(0,10);
		}
		addy=0;
	}
	else
	{
		if (valeuralea(0,1)==0)
		{
			addy=-valeuraleaposm(0,10);
		}
		else 
		{
			addy=valeuraleaposm(0,10);
		
		}
	}
		
	
		posx=prem(M)->dest.x+addx;
		posy=prem(M)->dest.y+addy;
			
		if ((!CollisionMonster(M->premier,map,posx,posy))) //&& (!CollisionentreMonster(copieM,prem(M))))
        {
            
           deplacemonster(M->premier,map, addx,addy);
		   M=reste(M);
			i=i+1;
			
        }
		j=j+1;
		
    }
   
  }




void evement(liste M)
{
	liste copieM;
	copieM=M;
	while (!est_vide(M))
	{
		if (prem(M)->pv<=0)
		{
			removeMonsterR(prem(M),copieM);
		}
	M=reste(M);
	}
	M=copieM;
}
	
	
	
	
	
	
	



void HandleInput(Map* map, Player* player, SDL_Event *event, liste M)
{
    SDL_PollEvent(event);
    switch (event->type)
	{
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym){
                
            case SDLK_ESCAPE:
                exit(0);
            
            case SDLK_d:
                if (HandlePlayerMovment(map, player, 2, 0, M,event))// && CollisionMonsterPLayer(M,player))
                {
                    player->src.y=910;
				    player->dest.x+=2;
                    player->src.x+=120;
                    if(player->src.x==1200)
                        player->src.x=0;
               Handmonster(M,map);
			   //affichermonstersliste(M);
                    //printf("posx:%d , posy:%d\n",player->dest.x,player->dest.y);
                   // printf("srcx:%d , srcy:%d\n",player->src.x,player->src.y);
                    
                }

                break;
            case SDLK_q:
                if (HandlePlayerMovment(map, player, -2, 0, M,event)) //&& CollisionMonsterPLayer(M,player))
                {
                    player->src.y=660;
                    player->dest.x-=2;
                    player->src.x+=120;
                    if(player->src.x==1200)
                        player->src.x=0;
                    Handmonster(M,map);
                    //printf("posx:%d , posy:%d\n",player->dest.x,player->dest.y);
                   // printf("srcx:%d , srcy:%d\n",player->src.x,player->src.y);
                }
                break;
            case SDLK_s:
                if (HandlePlayerMovment(map, player, 0, 2, M,event))// && CollisionMonsterPLayer(M,player))
                {
                    player->src.y=530;
                    player->dest.y+=2;
                    player->src.x+=120;
                    if(player->src.x==1200)
                        player->src.x=0;
                   Handmonster(M,map);
                    //printf("posx:%d , posy:%d\n",player->dest.x,player->dest.y);
                    //printf("srcx:%d , srcy:%d\n",player->src.x,player->src.y);
                }
                break;
            case SDLK_z:
                if (HandlePlayerMovment(map, player, 0, -2, M,event)) //&& CollisionMonsterPLayer(M,player))
                {
                    player->src.y=790;
				    player->dest.y-=2;
                    player->src.x+=120;
                    if(player->src.x==1200)
                        player->src.x=0;
                    
                   Handmonster(M,map);
                   
                }
                break;
                
                case SDLK_t:
                   
                    while (!est_vide(M))
                    {
                        if (CollisonCombat(M->premier,player))
                        {
                           M->premier->pv-=5;
                           printf("combat");
						   
                        }
                        M=reste(M);
                        
                    }
                    break;
                    
            }
    }
	evement(M);
	
	
  
	
}










	

	












