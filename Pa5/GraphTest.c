/*
 * GraphTest.c
 * Rahil Bhatnagar
 * rabhatna
 * pa4
 *
 */
#include<stdio.h>
#include"Graph.h"
#include<stdlib.h>
#include"List.h"


int main(int argc, char* argv[]){
	
	Graph B = newGraph(11);
	List S = newList();

	addArc(B, 1, 2);
	addArc(B, 2, 5);
	addArc(B, 3, 2);
	addArc(B, 3, 5);
	addArc(B, 4, 1);
	addArc(B, 5, 4);
	addArc(B, 6, 3);
	addArc(B, 6, 5);
	addArc(B, 6, 9);
	addArc(B, 6, 10);
	addArc(B, 7, 3);
	addArc(B, 7, 6);
	addArc(B, 8, 4);
	addArc(B, 9, 4);
	addArc(B, 9, 5);
	addArc(B, 9, 8);
	addArc(B, 10, 9);
	addArc(B, 10, 11);
	addArc(B, 11, 7);

	for(int i = 1; i<=11; i++){
		append(S, i);
	}

	printf("\nLength of S: %d\n", length(S));

	printf("\nNumber of vertices: %d\n", getOrder(B)); 	

	printf("\nDiscovered time of 4: %d\n", getDiscover(B, 4));
	
	printf("\nFinished time of #: %d\n", getFinish(B, 3));

	printf("\nCalling DFS on B\n");

	DFS(B, S);

	for(int i  = 1; i<=getOrder(B); i++){
		printf("Discovered %d: %d\n", i, getDiscover(B, i));
		printf("Finished %d: %d\n", i, getFinish(B, i));
		
	}	
	printf("\nList S after DFS: ");
	printList(stdout, S);
	
	printf("\n\nOrginal B graph:\n");
	printGraph(stdout, B);

	printf("\nTranspose of B graph:\n");
	Graph C = transpose(B);
	printGraph(stdout, C);
	
	DFS(C,S);
	
	printf("\nList S after DFS transpose: ");
	printList(stdout, S);

	printf("\n\nCopying transpose of B:\n");
	Graph D = copyGraph(C);
	printGraph(stdout, D);
	
	printf("\nTranspose of C graph:\n");
	Graph E = transpose(D);
	printGraph(stdout, E);
	
	freeList(&S);	
	freeGraph(&B);
	freeGraph(&C);
	freeGraph(&D);
	freeGraph(&E);

}
