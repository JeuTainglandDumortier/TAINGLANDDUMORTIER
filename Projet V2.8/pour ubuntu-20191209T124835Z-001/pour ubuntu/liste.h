#ifndef LISTE_H_
#define LISTE_H_
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "monster.h";




typedef struct Liste *liste ;

struct Liste
{
  Monster* premier ;
  liste suivant ;
} ;

/* SIGNATURES DES OPERATIONS PRIMITIVES */
/* issues du type abstrait */
liste l_vide () ;
liste cons (Monster* x, liste L) ;
bool est_vide (liste L) ;
Monster* prem (liste L) ;
liste reste (liste L) ;
/* autres opérations primitives */
void liberer_liste (liste L) ;
liste CreateListeMonster(int nbmonster,SDL_Renderer *pRenderer);
//void ecrire_prem (Monster* x, liste L) ;
void ecrire_reste (liste R, liste L) ;
void RenderListeMonster(SDL_Renderer* renderer,liste M);

/* IMPLANTATION DES OPERATIONS PRIMITIVES */
/* Constructeurs */


#endif