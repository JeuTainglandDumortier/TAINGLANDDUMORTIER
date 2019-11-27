#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>










void Afficher(SDL_Renderer* afficheur, SDL_Texture* textuTil,
     char** table, int nombre_blocs_largeur, int nombre_blocs_hauteur, int largeur_tile, int hauteur_tile)
{
	printf("chargement du renderer\n");
    int i, j,stock;
    SDL_Rect Rect_dest;
    SDL_Rect Rect_source;
    Rect_source.w = largeur_tile;
    Rect_dest.w   = largeur_tile;
    Rect_source.h = hauteur_tile;
    Rect_dest.h   = hauteur_tile;
	//init
	Rect_source.y=0;
	Rect_dest.x=0;
	Rect_dest.y=0;
    for(i = 0 ; i < nombre_blocs_hauteur; i++)
    {
        for(j = 0 ; j < nombre_blocs_largeur; j++)
        {
            stock=(int)(table[i][j]-33)*largeur_tile;
			
			printf("valeur de stock:%d\n",stock);
			
            Rect_source.x = stock;//(table[i*NOMBRE_BLOCS_HAUTEUR+j] )* LARGEUR_TILE;//- '0'
            /*Rect_source.y = 0;
			Rect_dest.x = i * LARGEUR_TILE;
            Rect_dest.y = j * HAUTEUR_TILE;*/
            SDL_RenderCopy(afficheur, textuTil, &Rect_source, &Rect_dest);
			Rect_source.x=0;
			Rect_dest.x+=largeur_tile;
        }
		Rect_source.y=0;
		Rect_dest.x=0;
		Rect_dest.y+=largeur_tile;
		
		
    }
	free(table);
}