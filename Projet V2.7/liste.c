
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "monster.h"
#include "liste.h"
#include "Map.h"
#include "Player.h"
#include "collision.h"


liste l_vide ()
{
  return NULL ;
}

liste cons (Monster* x, liste L)
{
  liste M ;
 
  M = malloc (sizeof (*M)) ;
  M->premier = x ; // On peut aussi écrire " M->premier = x ; "
  M->suivant = L ;
  return M ;
}

/* Accès */
bool est_vide (liste L)
{
  return L== NULL ;
}

Monster* prem (liste L)
{
  if (est_vide (L))
    {
      printf ("Calcul de prem sur liste vide !\n") ;
      exit (0) ;
    }
  return L->premier ;
}

liste reste (liste L)
{
  if (est_vide(L))
    {
        return L;
    }

    return L->suivant ;
}

/* Autres opérations primitives (hors type-abstrait) */
void liberer_liste (liste L)
{
  if (est_vide (L))
    {
      return ;
    }
  liberer_liste (reste (L)) ;
  free(L) ;
}



void ecrire_reste (liste R, liste L)
{
  L->suivant = R ;
}

/* OPERATIONS NON PRIMITIVES */
unsigned int longueurR (liste L)
{
  if (est_vide (L))
    return 0 ;
  return 1 + longueurR (reste (L)) ;
}

unsigned int longueurI (liste L)
{
  unsigned int lg ;
  lg = 0 ;
  while (!est_vide (L))
    {
      lg = lg + 1 ;
      L = reste (L) ;
    }
  return lg ;
}




liste inserer_liste_D (unsigned int n, Monster* x, liste L)
{
  unsigned int i ;
  liste M ;
  if (n == 0 || est_vide(L))
    {
      printf ("Utilisation d'inserer_liste_D incorrecte\n") ;
      exit(EXIT_FAILURE) ;
    }
  if (n == 1)
    {
      return cons (x, L) ;
    }
  M = L ;
  i = 1 ;
  while (!est_vide(reste(M)) && i < n - 1) {
      M = reste(M) ;
      i = i + 1 ;
  }
  ecrire_reste (cons(x, reste(M)), M) ;
  return L ;
}






bool appartient_I(Monster* monster, liste M)
{
	liste L;
	L=M;
	while (!est_vide(L) && egalmonster(prem(L),monster))
	{
		L=reste(L);
	}
	return !est_vide(L);
}





liste removeMonsterR( Monster* monster,liste M)
{
	if (est_vide(reste(M)) && !egalmonster(monster,prem(M)))
	{
		ecrire_reste(cons(prem(M),l_vide()),M);
	}
	if (egalmonster(monster,prem(M)))
	{
		removeMonsterI(monster,reste(M));
	}
	return cons(prem(M),removeMonsterI(monster,reste(M)));
	
   
}


liste removeMonsterI(Monster* monster, liste M)
{
	//Monster* m=monster;
	liste L,C;
	C=l_vide();
	
	L=M;
	while (!appartient_I(monster,L))
	{
		if(egalmonster(prem(L),monster))
		{
			L=reste(L);
		}
		C=cons(prem(L),C);
		L=reste(L);
	}
	return C;
}











void affichermonstersliste(liste M)
{
	int i=1;
	while (!est_vide(M))
	{
		
	printf("monstres:%d posx:%d, posy:%d\n",i,prem(M)->dest.x,prem(M)->dest.y);
	M=reste(M);
	i=i+1;
	}
	
}




liste CreateListeMonster(int nbmonster,SDL_Renderer *pRenderer, Map *map)
{
    
	liste M= cons(CreateMonster(pRenderer,map),l_vide());
    
	int i;
	for (i=0; i<nbmonster-1;i++)
	{
        
        Monster* monstermem=CreateMonster(pRenderer,map);
        while (CollisionentreMonster(M, monstermem))
        {
            monstermem=CreateMonster(pRenderer,map);
        }
		M=cons(monstermem,M);
	}
	
	return M;
}




void RenderListeMonster(SDL_Renderer* renderer,liste M)
{
	
    
	while (!est_vide(M))
	{
        
    
       
		RenderMonster(renderer, prem(M));
       
		M=reste(M);
		
		
	}
   
}




        
    
    

    
    
    
    
    
    
    



