

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 





 
 
 /*char ** allouer_tab_2dim(int n, int m)
 {
	 char ** tab ; 
	 tab =malloc (n*sizeof(char*));
	 for (int i =0; i<n; i++)
	 {
	 tab[i]= malloc(m*sizeof(char*));
	 }
	 for(int i =0;i<n;i++){
		 for (int j=0;j<m;j++)
		 {
			 tab[i][j]='0';
		 }
	 }
	 return tab;
 }*/
 
 void afficher_tableau(char** tab, int nombre_blocs_largeur, int nombre_blocs_hauteur)
{
	printf("affichage tableau: \n");
    for (int i = 0; i < nombre_blocs_hauteur; i++) 
	{
        for (int j = 0; j < nombre_blocs_largeur; j++) 
		{
            //printf("%u ", tab[i][j]);//, i * nombre_blocs_largeur + j
			printf("valeur: %u indice:[%d][%d]\n",tab[i][j],i,j);
			//printf("testaft2\n");
        }
        //printf("\n");
    }
	printf("fin affichage tableau");
	printf("valeur en 0 0 :%u \n", tab[0][0]);
}