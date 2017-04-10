
#include<stdio.h>
#include"Graph.h"
#include<stdlib.h>
#include"List.h"


int main(int argc, char* argv[]){
	
	Graph A = newGraph(8);
	Graph B = newGraph(5);
		
	addEdge(A, 1, 2);
	addEdge(A, 2, 3);
	addEdge(A, 3, 4);
	addEdge(A, 4, 5);
	addEdge(A, 5, 6);
	addEdge(A, 6, 7);
	addEdge(A, 7, 8);
	addEdge(A, 8, 4);
	addEdge(A, 8, 6);
	addEdge(A, 5, 8);
 
	printf("Graph A\n");
	printf("A #Vertices: %d\n", getOrder(A));
	printf("A #Edges: %d\n", getSize(A));
	
	printf("Adj of graph A\n");
	printGraph(stdout, A);
	printf("\n");	

	BFS(A, 4);
	printf("A source: %d\n", getSource(A));
	
	printf("Distances from source\n");	
	for(int i = 1; i <= getOrder(A); i++){
		printf("%d: %d\n", i, getDist(A, i));
	}

	printf("\n");
	printf("Parents\n");
	for(int i = 1; i <= getOrder(A); i++){
		printf("%d: %d\n", i, getParent(A, i));
	}
	
	printf("\n");
	List L = newList();
	getPath(L, A, 1);
	printf("Path from 1-4: ");
	printList(stdout,L);
	
	printf("\n");
	printf("\n");

	addArc(B, 1, 2);
	addArc(B, 1, 3);
	addArc(B, 1, 5);
	addArc(B, 2, 3);
	addArc(B, 3, 5);
	addArc(B, 4, 3);
	addArc(B, 4, 5);
	
	printf("Graph B\n");
	printf("B #Vertices: %d\n", getOrder(B));
	printf("B #Edges: %d\n", getSize(B));
	printGraph(stdout, B);
	printf("\n");

	BFS(B, 1);
	printf("B source: %d\n", getSource(B));
		
	for(int i = 1; i<= getOrder(B); i++){
		printf("%d: %d\n",i, getDist(B, i));
	}
	
	printf("\n");
	printf("Parents\n");
	for(int i = 1; i <= getOrder(B); i++){
		printf("%d: %d\n", i, getParent(B, i));
	}

	printf("\n");
	List L1 = newList();
	getPath(L1, B, 4);
	printf("Path from 1-4: ");
	printList(stdout,L1);	
	printf("\n");

	printf("\n");
	printf("Make B NULL\n");
	makeNull(B);
		
	printf("B #Vertices: %d\n", getOrder(B));
	printf("B #Edges: %d\n", getSize(B));
	printf("B source: %d\n", getSource(B));

	freeList(&L);
	freeList(&L1);
	freeGraph(&A);
	freeGraph(&B);

}
