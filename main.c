#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fractal.h"
#include <string.h>
#include <stdint.h>
#include <semaphore.h>
#include <pthread.h>
#include "buffer.h"

void* OpenFile(void *nameFile);

// %lf pour lire un double, %d pour un int, %s pour un string.

//TODO créer les sémaphores, mutex  


struct Buffer *buffer1;
struct Buffer *buffer2;
pthread_mutex_t mutex;
sem_t empty;
sem_t full;
pthread_mutex_t mutex1;
sem_t empty1;
sem_t full1;
int a = 0;
int b = 0;



int main(){

        //Initialisation des buffer, mutex et sémaphores.
	
	buffer1 = init_Buffer();
	buffer2 = init_Buffer();
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0 , 10);
	sem_init(&full, 0 , 0); 
	pthread_mutex_init(&mutex1, NULL);
	sem_init(&empty1, 0 , 10);
	sem_init(&full1, 0 , 0); 
	
	//Partie thread, et comparaison des moyennes

	int e = strcmp("-d",argv[1]);
	if(e==0){
		//il faut générer les bitmap de toutes les fractales...
	}
	else{
		//Comparer pour voir si on a un nombre max de thread de calcul ou un nom de fichier.
	}

	return 0;
}

//Ouverture de fichier, lecture des fractales et mise des fractales dans le premier buffer

void* OpenFile(void *nameFile){
	char* name = (char*)nameFile;
	FILE *fichier = NULL;
	

	int comp = strcmp("-",nameFile);

	if(comp != 0){
		
		fichier = fopen(name, "r");
		if(fichier == NULL){
			pthread_exit(NULL);
		}	
		int c = 0;
		while(c != EOF){
			a =1;
			c = fgetc(name);
			char str[63];
			int scan = 0;
			while(scan < 1){
				fscanf(fichier, "%s", str);		
			}
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
				int scan2 = 0; 
				while(scan2 < 4){
					scan2 = fscanf(fichier, "%u %u %lf %lf", &larg, &haut, &part_reel, &part_imag);
				}
				struct fractal *f = fractal_new(str, (int)larg, (int)haut, part_reel, part_imag);
			}
			sem_wait(&empty); // attente d'un slot libre
			pthread_mutex_lock(&mutex);
			// section critique
			add(buffer1, f);
			pthread_mutex_unlock(&mutex);
			sem_post(&full); // il y a un slot rempli en plus
		}
		a = 0;
	}

	else{
		printf("Veuillez entrer votre fractale en respectant la manière suivante: Nom_de_Fractale Largeur(entier de 32bits) Hauteur(entier de 32bits) Partie_Reele Partie_Imaginaire. Respectez bien les espaces et n'entrez pas un nom dépassant 64 caractères.\n\n");
		b = 1;
		char str[64] = NULL;
		uint32_t larg;
		uint32_t haut;
		double part_reel;
		double part_imag;			
		scanf("%s %u %u %lf %lf", str, &larg, &haut, &part_reel, &part_imag);
		struct fractal *f = fractal_new(str, (int)larg, (int)haut, part_reel, part_imag);
		sem_wait(&empty); // attente d'un slot libre
		pthread_mutex_lock(&mutex);
		// section critique
		add(buffer1, f);
		pthread_mutex_unlock(&mutex);
		sem_post(&full); // il y a un slot rempli en plus	
	}
	b = 0;
}

//Retire les fractales du buffer, calcul (moyenne) et remise dans le deuxième buffer.


void* calcul(){
	while(a==1 || b==1){
		sem_wait(&full);
		// attente d'un slot rempli
		pthread_mutex_lock(&mutex);
		// section critique
		struct fractal *f=remove(buffer1);
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
		// il y a un slot libre en plus

		int i;
		int j;
		int max_width = fractal_get_width(f);
		int max_height = fractal_get_height(f);
		int sum = 0;		
		for(i=0;i<max_width;i++){
			for(j=0;j<max_height;j++){
				int val = fractal_compute_value(f,i,j);
				sum = sum + val;
				fractal_set_value(f,i,j,val);
			}
		}
		fractal->moyenne = (double)(sum/(width*height));

		sem_wait(&empty1); // attente d'un slot libre
		pthread_mutex_lock(&mutex1);
		// section critique
		add(buffer2, f);
		pthread_mutex_unlock(&mutex1);
		sem_post(&full1); // il y a un slot rempli en plus
	}
}


