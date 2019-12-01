#include "bouclejeu.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>




void deplacementq(Sprite *spray)
{
    spray->src.y=660;
	spray->dest.x-=8;
	spray->src.x+=120;
	if(spray->src.x==1200)
		spray->src.x=0;
	printf("srcx:%d\n",(spray->src.x));
}


void deplacementd(Sprite *spray)
{

	spray->src.y=915;
	spray->dest.x+=8;
    spray->src.x+=120;
    if(spray->src.x==1200)
    	spray->src.x=0;
	
}


void deplacements(Sprite *spray)
{

	spray->src.y=530;
	spray->dest.y+=8;
	spray->src.x+=120;
	if(spray->src.x==1200)
			spray->src.x=0;
}


void deplacementz(Sprite *spray)
{
                
	spray->src.y=790;
	spray->dest.y-=8;
	spray->src.x+=120;
	if(spray->src.x==1200)
		spray->src.x=0;
}
                
                

