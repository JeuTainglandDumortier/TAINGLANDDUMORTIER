#include "limit.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>




/*int limit_right(Map *map, Sprite *perso)
{
	if(perso->scr.x==map->largeur) return 0;
}


int limit_left(Map *map, Sprite *perso)
{
	if(perso->scr.x==0) return 0;
}

int limit_top(Map *map, Sprite *perso)
{
	if(perso->scr.y==0) return 0;
}


int limit_bottom(Map *map, Sprite *perso)
{
	if(perso->scr.y==map->hauteur) return 0;
}*/



void replacement(Map *map, Sprite *perso)
{
	if(perso->dest.x>map->largeur*map->largeur_tile-perso->dest.w)
	{
		perso->dest.x-=8;
	}
	
	if(perso->dest.x<0)
	{
		perso->dest.x=0;
	}
	
	if(perso->dest.y<0)
	{
		perso->dest.y=0;
	}
	if(perso->dest.y>map->hauteur*map->hauteur_tile-perso->dest.h)
	{
		perso->dest.y-=8;
		
	}
	
}
	
		
	
	
	
	
	
		
	
	
	
	
	
	
	
	
	
	
	
	