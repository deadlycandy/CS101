#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

// Struct

typedef struct GraphObj{
	List* neighbors;
	int* color;
	int* parent;
	int* distance;
	int order;
	int size;
	int soruce;

} GraphObj;

//Graph Obj constructor 
Graph newGraph(int n){
	Graph G;
	G = malloc(sizeof(GraphObj));
	G->neighbors = malloc(sizeof(List)*n+1);
	for(int i = 1; i <= n+1; i++){
		G->neighbors[i] = malloc(sizeof(List));
	}
	G->color = malloc(sizeof(int)*n+1);
	G->parent = malloc(sizeof(int)*n+1);
	G->distance = malloc(sizeof(int)*n+1);
	G->order = n;
	G->size = 0;
	G->source = NIL;
	return G;
}

//Free allocated memory
void freeGraph(Graph* pG){
	if(pG != NULL && *pG != NULL){
		free(*pG);

		/*for(int i = 1;  i <= *pG->order+1; i++){
			freeList(*pG->neighbors[i]);			
		}
		free(*pG->neighbors);
		free(*pG->color);
		free(*pG->parent);
		free(*pG->distance);
		free(*pG->order);
		free(*pG->size);
		free(*pG->vertex);*/
	}

}

//access functions 

//gets number of vertices 
int getOrder(Graph G){
	if(G == NULL){
		printf("Graph Error: calling getOrder() on NULL Graph reference\n");
		exit(1);	
	}
	return(G->order);
}

//gets number of egdes 
int getSize(Graph G){
	if(G == NULL){
		printf("Graph Error: calling getSize() on NULL Graph reference\n");
		exit(1);
	}
	return(G->size);
}

//gets the source vertex
int getSource(Graph G){
	if(G == NULL){
		printf("Graph Error: calling getSource() on NULL Graph reference\n");
		exit(1);
	}
	return(G->source);
}

//























