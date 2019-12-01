#include "collision.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <SDL2/SDL.h>







double distance_texture(Sprite *sprite, Postext *tabtexture)
{
	return sqrt( pow((tabtexture[i][j]->dest.x - sprite->dest.x), 2 ) + pow((tabtexture[i][j]->dest.x - sprite->dest.y), 2));
}


distance_x(Sprite *sprite, Postext *tabtexture)
{
	if (tabtexture[i][j]->dest.x>=sprite->dest.x)
	{
	return (tabtexture[i][j]->dest.x-sprite->dest.x);
	}
	else 
	{
		return (sprite->dest.x-tabtexture[i][j]->dest.x);
	}
}




distance_y(Sprite *sprite, Postext *tabtexture)
{
	if (tabtexture[i][j]->dest.y>=sprite->dest.y)
	{
	return (tabtexture[i][j]->dest.y-sprite->dest.y);
	}
	else 
	{
		return (sprite->dest.y-tabtexture[i][j]->dest.y);
	}
}

void collision(Sprite *sprite, Map* map, char* tabcar)
{
	char car;
	
	
for (int i=0;i<map->hauteur;i++)
{
	
	for(int j=0;j<map->largeur;j++)
	{
		car=map->tiles[i]{=[j];
		
		for (int f=0;f<taille_tabcar;f++)
		{
			if ((car==tabcar[f]) 
			{
				
				if(distance_x(sprite,tabpos)<=8))
				{
					sprite->dest.x=+8;
				}
				if(distance_y(sprite,tabpos)<=8))
				{
					sprite->dest.y=+8;
				}
			
			}
		}	
	}			
}				
}				

		