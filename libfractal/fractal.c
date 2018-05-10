#include <stdlib.h>
#include "fractal.h"
#include <string.h>

struct fractal *fractal_new(const char *name, int width, int height, double a, double b)
{
    struct fractal* f = (struct fractal*)malloc(sizeof(struct fractal));
    if(f == NULL){
        return -1;
    }
    f->nom = (char*)malloc(sizeof(name)+1);
    if(f->nom == NULL){
        free(f);
        return NULL;
    }
    f->nom = strcpy(f->nom, name);
    f->largeur = width;
    f->hauteur = height;
    f->reel = a;
    f->imaginaire = b;
    f->valeur = (int**)malloc(sizeof(int));

    if(f->valeur == NULL){
        free(f->nom);
        free(f);
        return NULL;
    }

    int i =0;
    for(int i; i<height; i++){
        f->valeur[i] = (int*)malloc(sizeof(int));

        if(f->valeur[i] == NULL){

            for(int i=i-1; i>=0;i--){
                free(f->valeur[i]);
            } //fin du for

            free(f->valeur);
            free(f->nom);
            free(f);
            return NULL;

        }//fin du if

    } //fin du for
    return f;
}

void fractal_free(struct fractal *f)
{
    for(int i=0; i<f->hauteur; i++){
        free(f->valeur[i]);
    }
    free(f->valeur);
    free(f->nom);
    free(f);
}

const char *fractal_get_name(const struct fractal *f)
{
    return (const char*) f->nom;
}

int fractal_get_value(const struct fractal *f, int x, int y)
{
    return f->valeur[y][x];
}

void fractal_set_value(struct fractal *f, int x, int y, int val)
{
    f->valeur[y][x] = val;
}

int fractal_get_width(const struct fractal *f)
{
    return f->largeur;
}

int fractal_get_height(const struct fractal *f)
{
    return f->hauteur;
}

double fractal_get_a(const struct fractal *f)
{
    return f->reel;
}

double fractal_get_b(const struct fractal *f)
{
    return f->imaginaire;
}

double fractal_get_moyenne(const struct fractal *f){
	return f->moyenne;
}
