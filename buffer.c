// On crée la classe buffer qui est en fait une pile de node.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "buffer.h"
#include "fractal.h"

struct Node *init_Node(struct fractal* fractal){ 

	struct Node *node = malloc(sizeof(struct Node));
	if(node == NULL){
        	return -1;
	}
	node->fractal = fractal;
	node->next = NULL;
	return node;
}

struct Buffer *init_Buffer(){

	stuct Buffer* buffer = (struct Buffer*)malloc(sizeof(struct Buffer));
	if(buffer == NULL){
		return -1;
	}
	buffer->top = NULL;
	(buffer->size) = 0;
	return buffer;
}

int isEmpty(struct Buffer *buffer){
	return ((buffer->size )==0);
}

int isFull(struct Buffer *buffer){
	return ((buffer->size) == 10);
}


int add(struct Buffer *buffer ,struct fractal* fractal){
	if(buffer==NULL){
		return -1;
	}
	struct Node *node = *init_Node(fractal);
	if(isEmpty(buffer)){
		buffer->top = node;
		(buffer->size)++;
		return 0;	
	}
	else{
		node->next = buffer->top;
		buffer->top = node;
		buffer->size++;
		return 0;	
	}	
}

struct fractal *remove(struct Buffer *buffer){
	if(buffer==NULL){
		return -1;
	}
	struct Node *node = buffer->top;
	buffer->top = node->next;
	(buffer->size)--;
	struct fractal *f = node->fractal;
	free(node);
	return f;
}

void *free_buffer(struct Buffer *buffer){
	if(buffer==NULL){
		return -1;	
	}
	if(isEmpty(buffer){
		free(buffer);
	}
	else{
		while(!isEmpty(buffer)){
			remove(buffer);		
		}	
	}
}


