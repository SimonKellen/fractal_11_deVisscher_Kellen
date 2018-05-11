/**
* Structure node
*
* @next: pointer vers la prochaine node dans le buffer, NULL si c'est la node au top.
* @fractal: fractale stockée dans la node
*/
struct Node {
	struct Node *next;
	struct fractal *fractal;
};

/**
* Structure Buffer, prend la forme d'une pile de node.
*
* @top: top node du Buffer, NULL si le buffer est vide
* @size: nombre de nodes dans le buffer
* @name: nom du buffer
*/
struct Buffer {
	struct Node *top;
	int size;
};

/**
* Initialise une node contenant une fractale fractal.
*/
struct Node *init_Node(struct fractal* fractal);


/**
* Initialise un buffer de nom name et de taille size.
*/
struct Buffer *init_Buffer();

/**
* Crée une node contenant la fractale fractal et l'ajoute à la pile buffer. Retourne -1 si il y a * eu une erreur d'allocation de mémoire, 1 si la pile est complète et 0 si tout s'est bien passé.
*/
int add(struct Buffer *buffer, struct fractal *fractal);

/**
* Retire la node qui est au top du buffer et retourne sa fractale.
*/
struct fractal *retirer(struct Buffer *buffer);

/**
* Vérifie si la liste est vide à l'aide d'une variable globale count qui est incrémentée/
* décrémentée si on ajoute/retire une node du Buffer buffer. Retourne -1 si il y a eu un problème et 0 sinon.
*/
int isEmpty(struct Buffer *buffer);

/**
* Pareil que isEmpty mais pour vérifier si le Buffer buffer est rempli.
*/
int isFull(struct Buffer *buffer);

/**
* Libère le pointeur vers l'espace mémoire d'un buffer. Vide le buffer si celui-ci ne l'est pas.
*/
void *free_buffer(struct Buffer *buffer);

