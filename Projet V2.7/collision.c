#include <SDL2/SDL.h>
#include "liste.h"
#include "monster.h"
#include "Player.h"






















int CollisionentreMonster(liste M, Monster* monster, Player* player )
{
   
    while (!est_vide(M))
    {
        if((IsInBox(&(monster->dest), &(M->premier->dest))) || (IsInBox(&(M->premier->dest), &(player->dest))))
        {
            return 1;
        }
        M=reste(M);
    }
    return 0;
}



int CollisionMonsterPLayer(liste M, Player* player)
{
    
    while (!est_vide(M))
    {
        if((IsInBox(&(M->premier->dest), &(player->dest))) && (M->premier->pv>0))
        {
            printf("test collision joueur monstres\n");
            return 1;
        }
        M=reste(M);
    }
    return 0;
    
}

int CollisonCombat(Monster* monster, Player *player)
{
    if((IsInBox(&(monster->dest), &(player->dest))) && (monster->pv>0))
        {
            printf("test collision joueur monstres\n");
            return 1;
        }

        return 0;
}



/*int all_collision (liste M, PLayer* player ,Map* map)
{
    liste M=copieM;
    
    while (!est_vide(copieM)
    {
        if (CollisionentreMonster(*/
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        

            
      
            
            
            
            
            
            
            
