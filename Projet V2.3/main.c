#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "Map.h"
#include "sprite.h"
//#include "createwindows.c"

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
	int posx=240;
	int posy=200;
	
	LoadMapGraphics(map2, afficheur, "bloc16t.bmp");
    RenderMap(map2,afficheur);
    LoadMapGraphics(map, afficheur, "bloc16t.bmp");
    RenderMap(map,afficheur);
	SDL_Texture *sprite=LoadSprite(afficheur);
	spriteim(sprite,afficheur,posx,posy);
	//RenderMap(map);
	SDL_Rect src={0,910,120,120};
	SDL_Rect dest = {posx,posy,20,20};
	//DestroyMap(map);
	
   
    while (continuer)
    {
		
        SDL_PollEvent(&event);
        SDL_RenderCopy(afficheur,sprite,&src,&dest); // Copie du sprite grâce au SDL_Renderer
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
                src.y=910;
				dest.x+=2;
                src.x+=120;
                if(src.x==1200)
                    src.x=0;
                printf("avance\n");
				printf("valeur pos:%d\n",dest.x);
                break;
            //case SDL_s:
                //dest.y+=2;
                
                
            case SDLK_q:
                src.y=660;
                dest.x-=2;
                src.x-=120;
                if(src.x==0)
                    src.x=1200;
                break;
                
            case SDLK_s:
                src.y=530;
				dest.y+=2;
                src.x+=120;
                if(src.x==1200)
                    src.x=0;
                break;
                
                case SDLK_z:
                src.y=790;
				dest.y-=2;
                src.x+=120;
                if(src.x==1200)
                    src.x=0;
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
   
   
   
Quit:
    if (NULL != textuTil)
        SDL_DestroyTexture(textuTil);
        SDL_DestroyTexture(sprite);
    if (NULL != afficheur)
        SDL_DestroyRenderer(afficheur);
    if (NULL != ecran)
        SDL_DestroyWindow(ecran);
    SDL_Quit();

    return statut;
}
