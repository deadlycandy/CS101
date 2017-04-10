#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

// Struct

typedef struct GraphObj{
	List* adj;
	int* color;
	int* parent;
	int* distance;
	int order;
	int size;
	int source;

} GraphObj;

//Graph Obj constructor 
Graph newGraph(int n){
	Graph G;
	G = malloc(sizeof(GraphObj));
	G->adj = malloc(sizeof(List)*n+1);
	for(int i = 1; i <= n+1; i++){
		G->adj[i] = malloc(sizeof(List));
		G->adj[i] = newList();
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

//gets the source vertex
int getSource(Graph G){
	if(G == NULL){
		printf("Graph Error: calling getSource() on NULL Graph reference\n");
		exit(1);
	}
	return(G->source);
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
	if(G->source == NIL){
		return NIL;
	}else{
		return(G->parent[u]);
	}
} 

//gets the distance of u 
int getDist(Graph G, int u){
	if(G == NULL){
		printf("Graph Error: calling getDist() on NULL Graph reference\n");
		exit(1);
	}	
	if(u < 1 || u > getOrder(G)){
		printf("Graph Error: calling getDist() u not in range 1 <= u <= getOrder(G)");
		exit(1);
	}
	if(G->source == NIL){
		return INF;
	}else{
		return(G->distance[u]);
	}
}

//gets and appends the shortest path to the list
void getPath(List L, Graph G, int u){
	if(G == NULL){
		printf("Graph Error: calling getPath() on NULL Graph reference\n");
		exit(1);
	}	
	if(getSource(G) == NIL){
		printf("Graph Error: calling getPath() on source is NIL\n");
		exit(1);
	}
	if(u < 1 || u > getOrder(G)){
		printf("Graph Error: calling getPath() u not in range 1 <= u <= getOrder(G)");
		exit(1);
	} 
	if(u == getSource(G)){
		append(L, getSource(G));	
	}else if(G->parent[u] == NIL){	
		append(L, NIL);
	}else{
		getPath(L, G, G->parent[u]);
		append(L, u); 
	}
}


//manipulation functions

//sets the graph to the null state 
void makeNull(Graph G){
	if(G == NULL){
		printf("Graph Error: calling makeNull() on NULL Graph reference\n");
		exit(1);
	}
	for(int i = 1; i <= getOrder(G); i++){
		clear(G->adj[i]);
	}	
	G->size = 0;	

}

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

//breadth first search
void BFS(Graph G, int s){
	if(G == NULL){
		printf("Graph Error: calling BFS() on NULL Graph reference\n");
		exit(1);
	}
	for(int i = 1; i <= getOrder(G); i++){
		G->color[i] = 0;
		G->distance[i] = INF;
		G->parent[i] = NIL;
	}
	G->source = s;
	G->color[s] = 1;
	G->distance[s] = 0;
	G->parent[s] = NIL;
	List L = newList();
	append(L, s);
	int u;
	while(length(L) > 0){
		moveFront(L);
		u = get(L);
		deleteFront(L);
		moveFront(G->adj[u]);
		while(index(G->adj[u]) >= 0){
			if(G->color[get(G->adj[u])] == 0){
				G->color[get(G->adj[u])] =1;
				G->distance[get(G->adj[u])] = G->distance[u] + 1;
				G->parent[get(G->adj[u])] = u;
				append(L, get(G->adj[u]));
			}
			moveNext(G->adj[u]);
		}
		G->color[u] = 2;
	}
	//free(&u);
	freeList(&L);
	L = NULL;
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











