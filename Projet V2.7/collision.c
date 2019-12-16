#include <SDL2/SDL.h>
#include "liste.h"
#include "monster.h"
#include "Player.h"






















int CollisionentreMonster(liste M, Monster* monster )
{
   
    while (!est_vide(M))
    {
		//if (!egalmonster(prem(M),monster))
		//{
			
			if(IsInBox(&(monster->dest), &(M->premier->dest))) 
			{
				printf("collision entre monstres\n");
				return 1;
				
			}
		//}
        M=reste(M);
    }
    return 0;
}


int CollisonCombat(Monster* monster, Player *player)
{
    if((IsInBox(&(monster->dest), &(player->dest))) && (monster->pv>0))
        {
           
			
            return 1;
        }

        return 0;
}





int CollisionMonsterPLayer(liste M, Player* player,SDL_Event* event)
{
    
    while (!est_vide(M))
    {
		if (CollisonCombat(prem(M),player))
		{
				SDL_PollEvent(event);
				switch (event->type)
				{
					case SDL_KEYDOWN:
					switch (event->key.keysym.sym)
					{
						case SDLK_t:
                   
						
							   M->premier->pv-=5;
							   printf("combatc\n");
							   printf("pv monstres:%d\n",M->premier->pv);
							
							break;
							
					}
				}
                   return 1;     
         }
                    
			
		
        M=reste(M);
    }
    return 0;
    
}






        
        
        
        
        
        
        
        
        
        
        
        
        
        

            
      
            
            
            
            
            
            
            
