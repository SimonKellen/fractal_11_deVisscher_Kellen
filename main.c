#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fractal.h"
#include <string.h>
#include <stdint.h>
#define taille 64
// %lf pour lire un double, %d pour un int, %s pour un string.

struct fractal *firstBuffer = (struct fractal *) malloc(10*sizeof(struct fractal));
struct fractal *secondBuffer = (struct fractal *) malloc(10*sizeof(struct fractal));

FILE *fichier = NULL;
fichier = fopen(nameFile), "r");

int main()
{
    /* TODO */

    return 0;
}

void* OpenFile(void *nameFile){
	char* name = (char*)nameFile;
	FILE *fichier = NULL;
	fichier = fopen(name), "r");

	if(fichier == NULL){
		pthread_exit(NULL);
	}

	int comp = strcmp("-",nameFile);

	if(comp != 0){
		char *str = NULL;
		int scan = fscanf(name, "%s", str);
		
		if(str[0]=="#"){
			char *lineptr = NULL;
			size_t n = 500;
			ssize_t skip = getline(&lineptr,&n,name);
		}

		else{
			uint32_t larg;
			uint32_t haut;
			double part_reel;
			double part_imag;			
			fscanf(fichier, "%d %d %lf %lf", larg, haut, part_reel, part_imag);
		}
	}

}
