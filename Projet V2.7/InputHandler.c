


#include "InputHandler.h"
#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Map.h"
#include "collision.h"
#include "monster.h"



void Handmonster(liste M,Map* map)
{
    int i=1;
	int addx=valeuraleaposm(-2,2);
   int addy=valeuraleaposm(-2,2);
	M=reste(M);
    while (!est_vide(M->suivant))
    {
		//affichermonstersliste(M);
	//SDL_Delay(100);
    	//if(movement_monster(M->premier,2,map)){}
		printf("addx:%d\n",addx);
		printf("addy:%d\n",addy);
		//printf("testcpt:%d\n",i);
			
		while (!CollisionMonster(M->premier,map,addx,addy)) 
        {
            
            //printf("test2:%d\n",i);
            addx=valeuraleaposm(-2,2);
            addy=valeuraleaposm(3,4);
			i+=1;
             
        }
        	deplacemonster(M->premier,map, addx,addy);
        	M=M->suivant;
			//}
				
        
        
    }
    //liberer_liste(copieM);
    
    
}



void evenement(liste M)
{
    while (!est_vide(M))
    {
        if (prem(M)->pv<=0)
        {	
		printf("testeve\n");
            M=removeMonsterI(M,prem(M));
        }
        M=reste(M);
    }
    
}



void HandleInput(Map* map, Player* player, SDL_Event* event, liste M)
{
    SDL_PollEvent(event);
    switch (event->type){
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym){
                
            case SDLK_ESCAPE:
                exit(0);
            
            case SDLK_d:
                if (HandlePlayerMovment(map, player, 2, 0, M))// && CollisionMonsterPLayer(M,player))
                {
                    player->src.y=910;
				    player->dest.x+=2;
                    player->src.x+=120;
                    if(player->src.x==1200)
                        player->src.x=0;
                Handmonster(M,map);
                    //printf("posx:%d , posy:%d\n",player->dest.x,player->dest.y);
                   // printf("srcx:%d , srcy:%d\n",player->src.x,player->src.y);
                    
                }

                break;
            case SDLK_q:
                if (HandlePlayerMovment(map, player, -2, 0, M)) //&& CollisionMonsterPLayer(M,player))
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
                if (HandlePlayerMovment(map, player, 0, 2, M))// && CollisionMonsterPLayer(M,player))
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
                if (HandlePlayerMovment(map, player, 0, -2, M)) //&& CollisionMonsterPLayer(M,player))
                {
                    player->src.y=790;
				    player->dest.y-=2;
                    player->src.x+=120;
                    if(player->src.x==1200)
                        player->src.x=0;
                    
                   Handmonster(M,map);
                   // printf("posx:%d , posy:%d\n",player->dest.x,player->dest.y);
                   // printf("srcx:%d , srcy:%d\n",player->src.x,player->src.y);
                }
                break;
                
                case SDLK_t:
                    //liste copieM=M;
                    while (!est_vide(M))
                    {
                        if (CollisonCombat(M->premier,player))
                        {
                           M->premier->pv-=5;
                           printf("pv du monstre:%d\n",M->premier->pv);
                           
                        }
                        M=reste(M);
                        
                    }
                    break;
                    
            }
    }
    //evenement(M);
    //Handmonster(M);
}










	

	












