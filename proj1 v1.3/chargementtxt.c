#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "chargementtxt.h"
#include "allouertab.c"
 
char** ReadFile()
{
	printf("testx\n");
    char *FileHeight = NULL;
    char *FileWidth = NULL;
 
    int Height = 0;
    int Width = 0;
 
    FileHeight = calloc(5,sizeof(char));
    FileWidth = calloc(5,sizeof(char));
 
    FILE* Fichier = fopen("fichiermap.txt","r");
    fgets(FileHeight,5,Fichier);
    fgets(FileWidth,5,Fichier);
 
    Height = atoi(FileHeight);
    Width = atoi(FileWidth);
	printf("testhw\n");
    printf("hauteur:%d\n",Height);
	printf ("largeur:%d\n",Width);
   
    char **Map = calloc(Height+1,sizeof(char*));
    for(int h = 0; h < Height; h++)
    {
        Map[h] = calloc(Width+1,sizeof(char));   
    }
    for(int Y = 0; Y < Height; Y++)
    {
        for(int X = 0; X < Width; X++)
        {
       
            char Character = fgetc(Fichier);
            if (Character == EOF)
            {
                break;
            }
            if (Character == '\n')
            {
                Y--;
                break;
            }
            else
            {
                Map[Y][X] = Character;
            }
        }
    }
   
    for(int Y = 0; Y < Height; Y++)
    {
		printf("ligne %d:\n",Y);
        for(int X = 0; X < Width; X++)
        {
			
            printf("%c", Map[Y][X]);
        }
        printf("\n");
       
    }
   
 
    fclose(Fichier);
    free(FileHeight);
    free(FileWidth);
    return Map;
}
 
 
 
int main(int argc, char **argv)
{
	
    char ** tab1=ReadFile();
	afficher_tableau(tab1,Width,Height);
    return EXIT_SUCCESS;
}
