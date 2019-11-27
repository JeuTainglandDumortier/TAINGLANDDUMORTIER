#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "Map.c"
#include "sprite.c"
#include "menu.c"
#include "bouton.c"
#include "initialisation.c"
//#include "createwindows.c"
#include "bouclejeu.c"

#define LARGEUR_TILE 16 // hauteur et largeur des tiles.
#define HAUTEUR_TILE 16

//#define NOMBRE_BLOCS_LARGEUR 5 // nombre a afficher en x et y
//#define NOMBRE_BLOCS_HAUTEUR 5

int main(int argc, char *argv[])
{
    SDL_Window *ecran = NULL;
    SDL_Renderer *afficheur = NULL;

    SDL_Surface *tileset = NULL;
    SDL_Texture *textuTil = NULL;
    SDL_Event event;
    int continuer = 1;
    int start = 0;
    int tempsPrecedent = 0, tempsActuel = 0;
    int statut = EXIT_FAILURE;
	
	
	
	Map *map = CreateMap("gms.txt", 16, 16);   
	Map *map2 = CreateMap("gms2.txt", 16, 16);
    printf("MAP SIZE : %u, %u.\n", map->largeur, map->hauteur);

   if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    ecran = SDL_CreateWindow("Kill Monster !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                             map->largeur * map->largeur_tile, map->hauteur * map->hauteur_tile, SDL_WINDOW_SHOWN);
    if (ecran == NULL){
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
    afficheur = SDL_CreateRenderer(ecran, -1, SDL_RENDERER_ACCELERATED);
    if (afficheur == NULL){
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }
	//createwindows(map->largeur,map->largeur_tile,map->hauteur,map->hauteur_tile,afficheur,ecran);
	Sprite*spray;

	initialisation_affichage(map,map2, afficheur, spray);

   
    while (continuer)
    {
    	if (start==0)
        {
            SDL_PollEvent(&event);
            
   			 
  			switch (event.type)
  			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_g:
					start=1;
					break;
					
					case SDLK_ESCAPE:
                	continuer = 0;
                	break;
                break;
				}
			break;
			}
        }
		else
		{

        SDL_PollEvent(&event);
        SDL_RenderCopy(afficheur,spray->texture,&(spray->src) , &(spray->dest)); // Copie du sprite grâce au SDL_Renderer
        SDL_RenderPresent(afficheur);
        RenderMap(map2,afficheur);
        RenderMap(map,afficheur);
        //SDL_RenderCopy(afficheur,sprite,&src,&dest); // Copie du sprite grâce au SDL_Renderer

        //SDL_RenderClear(afficheur);

        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer = 0;
                break;
            case SDLK_d:
                deplacementd(spray);
                break;

                
            case SDLK_q:
                deplacementq(spray);
                break;
                
            case SDLK_s:
                deplacements(spray);
                break;
                
                case SDLK_z:
                deplacementz(spray);
                break;
                
                
            }
            break;
        }
		//spriteim(sprite,afficheur,posx,posy);
        //tempsActuel = SDL_GetTicks();
        /*if (tempsActuel - tempsPrecedent > 30) // si 30ms se sont écoulé depuis le dernier tour de la boucle
                                                  plus le temps est petit plus il se deplace vite 
        {
            tempsPrecedent = tempsActuel; // le temps actuel devient le temps présent
        }
        else
        {
            SDL_Delay(30 - (tempsActuel - tempsPrecedent));
        }*/
		
		
		
		//SDL_Texture *sprite=LoadSprite(afficheur);
   		 }
		
    	
	}

   
   
   
Quit:
    if (NULL != textuTil)
        SDL_DestroyTexture(textuTil);
        SDL_DestroyTexture(spray->texture);
    if (NULL != afficheur)
        SDL_DestroyRenderer(afficheur);
    if (NULL != ecran)
        SDL_DestroyWindow(ecran);
    SDL_Quit();

    return statut;
}
