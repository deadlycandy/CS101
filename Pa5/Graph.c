/*
 * Graph.c
 * Rahil Bhatnagar
 * rabhatna
 * Pa5
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

// Struct

typedef struct GraphObj{
	List* adj;
	int* color;
	int* parent;
	int* discover;
	int* finish;
	int size;
	int order;

} GraphObj;

//Graph Obj constructor 
Graph newGraph(int n){
	Graph G;
	G = malloc(sizeof(GraphObj));
	G->adj = calloc((n+1), sizeof(List));//malloc(sizeof(List)*(n+1));
	G->color = calloc((n+1),sizeof(int));
	G->parent = calloc((n+1), sizeof(int));
	G->discover = calloc((n+1), sizeof(int));
	G->finish = calloc((n+1), sizeof(int));
	for(int i = 1; i <= n; i++){
		G->adj[i] = newList();
		G->color[i] = 0;
		G->parent[i] = NIL;
		G->discover[i] = UNDEF; 
		G->finish[i] = UNDEF; 
	}
	G->order = n;
	G->size = 0;
	return G;
}

//Free allocated memory
void freeGraph(Graph* pG){
	if(pG != NULL && *pG != NULL){
		Graph x = *pG;
		for(int i = 0; i < (x->order+1); i++){
			freeList(&(x->adj[i]));
		} 
		free(x->adj);
		free(x->color);
		free(x->parent);
		free(x->discover);
		free(x->finish);
		free(*pG);
		*pG = NULL;
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


//gets the parent of u
int getParent(Graph G, int u){
	if(G == NULL){
		printf("Graph Error: calling getParent() on NULL Graph reference\n");
		exit(1);
	}
	if(u < 1 || u > getOrder(G)){
		printf("Graph Error: calling getParent() u not in range 1 <= u <= getOrder(G)");
		exit(1);
	}
	return(G->parent[u]);
} 

//gets the distance of u 
int getDiscover(Graph G, int u){
	if(G == NULL){
		printf("Graph Error: calling getDiscover() on NULL Graph reference\n");
		exit(1);
	}	
	if(u < 1 || u > getOrder(G)){
		printf("Graph Error: calling getDiscover() u not in range 1 <= u <= getOrder(G)");
		exit(1);
	}
	return(G->discover[u]);
}

//gets the distance of u 
int getFinish(Graph G, int u){
	if(G == NULL){
		printf("Graph Error: calling getFinish() on NULL Graph reference\n");
		exit(1);
	}	
	if(u < 1 || u > getOrder(G)){
		printf("Graph Error: calling getFinish() u not in range 1 <= u <= getOrder(G)");
		exit(1);
	}
	return(G->finish[u]);
}

//manipulation functions

//adding egde bi-directional u to v && v to u
void addEdge(Graph G, int u, int v){
	if(G == NULL){
		printf("Graph Error: calling addArc() on NULL Graph reference\n");
		exit(1);
	}
	if(u < 1 || u > getOrder(G)){
		printf("Graph Error: calling addEdge() u not in range 1 <= u <= getOrder(G)");
		exit(1);
	}
	if(v < 1 || v > getOrder(G)){
		printf("Graph Error: calling addEdge() v not in range 1 <= v <= getOrder(G)");
		exit(1);
	}
	
	moveFront(G->adj[u]);
	if(length(G->adj[u]) == 0){
			append(G->adj[u], v);	
			moveBack(G->adj[u]);
	}else{ 
		while(index(G->adj[u]) >= 0){	
			if(get(G->adj[u]) > v){
				insertBefore(G->adj[u], v);
				moveBack(G->adj[u]);
			}else if(index(G->adj[u]) == length(G->adj[u])-1){
				append(G->adj[u], v);
				moveBack(G->adj[u]);
			}
			moveNext(G->adj[u]);
		}
	}
	moveFront(G->adj[v]);
	if(length(G->adj[v]) == 0){
			append(G->adj[v], u);
			moveBack(G->adj[v]);
	}else{
		while(index(G->adj[v]) >= 0){
			if(get(G->adj[v]) > u){
				insertBefore(G->adj[v], u);
				moveBack(G->adj[v]);
			}else if(index(G->adj[v]) == length(G->adj[v])-1){
				append(G->adj[v], u);
				moveBack(G->adj[v]);
			}
			moveNext(G->adj[v]);
		}
	}
	G->size+=1;
}

//adding an edge one direction u to v
void addArc(Graph G, int u, int v){
	if(G == NULL){
		printf("Graph Error: calling addArc() on NULL Graph reference\n");
		exit(1);
	}
	if(u < 1 || u > getOrder(G)){
		printf("Graph Error: calling addArc() u not in range 1 <= u <= getOrder(G)");
		exit(1);
	}
	if(v < 1 || v > getOrder(G)){
		printf("Graph Error: calling addArc() v not in range 1 <= v <= getOrder(G)");
		exit(1);
	}
	moveFront(G->adj[u]);
	if(length(G->adj[u]) == 0){
		append(G->adj[u], v);
		moveBack(G->adj[u]);
	}else{ 
		while(index(G->adj[u]) >= 0){	
			if(get(G->adj[u]) > v){
				insertBefore(G->adj[u], v);
				moveBack(G->adj[u]);
			}else if(index(G->adj[u]) == length(G->adj[u])-1){
				append(G->adj[u], v);	
				moveBack(G->adj[u]);
			}

			moveNext(G->adj[u]);
		}
	}
	G->size+=1;
}

void Vist(Graph G, List L, int u, int *time){
	if(G == NULL){
		printf("Graph Error: calling Vist() on NULL Graph reference\n");
		exit(1);
	}
	if(L == NULL){
		printf("List Error: calling Vist() on NULL List reference\n");
		exit(1);	
	}	
	G->discover[u] = ++*time;
	G->color[u] = 1;
	moveFront(G->adj[u]);
	while(index(G->adj[u]) >= 0){
		if(G->color[get(G->adj[u])] == 0){
			G->parent[get(G->adj[u])] = u;
			Vist(G, L, get(G->adj[u]), time);  
		}
		moveNext(G->adj[u]);
	}
	G->color[u] = 2;
	G->finish[u] = ++*time;
	prepend(L, u);
}

//Depth first search
void DFS(Graph G, List S){
	if(G == NULL){
		printf("Graph Error: calling DFS() on NULL Graph reference\n");
		exit(1);
	}
	if(length(S) != getOrder(G)){
		printf("List error: calling DFS() with List != n\n");
		exit(1);	
	}
	for(int i = 1; i <= getOrder(G); i++){
		G->parent[i] = NIL;
		G->color[i] = 0;
		G->finish[i] = UNDEF;
		G->discover[i] = UNDEF;
	} 	
	int time = 0;
	printf("Length of S1: %d\n", length(S));
	moveFront(S);
	while(index(S) >= 0){
		if(G->color[get(S)] == 0){
			int u = get(S);
			Vist(G, S, u, &time);
		}
		moveNext(S);
	} 
	int size = length(S)/2;
	for(int i = 1; i<=size; i++){
		moveBack(S);
		delete(S);
	}
	
}


//Other functions 
Graph transpose(Graph G){		
	if(G == NULL){
		printf("Graph Error: calling transpose() on NULL Graph reference\n");
		exit(1);
	}
	Graph transpose = newGraph(getOrder(G));
	for(int i = 1; i <= getOrder(G); i++){
		moveFront(G->adj[i]);
		while(index(G->adj[i]) >= 0){
			addArc(transpose, get(G->adj[i]), i);
			moveNext(G->adj[i]); 
		}
	}
	return transpose;
}


Graph copyGraph(Graph G){		
	if(G == NULL){
		printf("Graph Error: calling copy() on NULL Graph reference\n");
		exit(1);
	}
	Graph copy = newGraph(getOrder(G));
	for(int i = 1; i <= getOrder(G); i++){
		moveFront(G->adj[i]);
		while(index(G->adj[i]) >= 0){
			addArc(copy,i, get(G->adj[i]));
			moveNext(G->adj[i]); 
		}
	}
	return copy;
}


void printGraph(FILE* out, Graph G){	
	if(G == NULL){
		printf("Graph Error: calling printGraph() on NULL Graph reference\n");
		exit(1);
	}
	for(int i = 1; i <= getOrder(G); i++){
		fprintf(out, "%d: ", i);
		printList(out, G->adj[i]);
		fprintf(out, "\n");
	}
//	fclose(out);
}











