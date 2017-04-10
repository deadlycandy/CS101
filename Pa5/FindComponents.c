/*
 * FindPath.c
 * Rahil Bhatnagar
 * rabhatna
 * Pa4
 *
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Graph.h"
#include"List.h"

#define MAX_LEN 10 


int main(int argc, char* argv[]){
	int size;
   	FILE *in, *out;
   	char line[MAX_LEN];
	
	   // check command line for correct number of arguments
	if( argc != 3 ){
	      printf("Usage: %s <input file> <output file>\n", argv[0]);
	      exit(1);
	}
	// open files for reading and writing 
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	if( in==NULL ){
		printf("Unable to open file %s for reading\n", argv[1]);
		exit(1);
	}
	if( out==NULL ){
		printf("Unable to open file %s for writing\n", argv[2]);
		exit(1);
  	}


	fgets(line, MAX_LEN, in);
	size = atoi(line);
	printf("Size %d" , size);	
	Graph A = newGraph(size);
	int edge1, edge2;

	fgets(line, MAX_LEN, in);
	sscanf(line, "%d %d", &edge1, &edge2);
	
	while((fgets(line, MAX_LEN, in) != NULL) && (edge1 != 0 && edge2 != 0)){
		addArc(A, edge1, edge2);
		sscanf(line, "%d %d", &edge1, &edge2);
		printf("Edge1: %d\n", edge1);
		printf("Edge2: %d\n", edge2);
	}


	printGraph(stdout,A);
/*	fprintf(out,"\n");

	int source, dest;	
	List L = newList();
	
	sscanf(line, "%d %d", &source, &dest);
	while((fgets(line, MAX_LEN, in) != NULL) && (source != 0 && dest != 0)){	
		BFS(A, source);
		if(getDist(A, dest) == INF){	
			fprintf(out,"The distance from %d to %d is infinity\n", source, dest);
		}else{
			fprintf(out,"The distance from %d to %d is %d\n", source, dest, getDist(A, dest));
		}
		getPath(L, A, dest);
		moveFront(L);
		if(get(L) == NIL){
			fprintf(out,"No %d-%d path exists", source, dest);
		}else{
			fprintf(out,"A shortest %d-%d path is: ", source, dest);
			printList(out,L);
		}
		clear(L);
		fprintf(out,"\n");
		fprintf(out,"\n");
		sscanf(line, "%d %d", &source, &dest);
	//	printf("Source: %d", source);
	//	printf("Source: %d", dest);
	}
*/
	freeGraph(&A);
//	freeList(&L);
	fclose(in);
	fclose(out);


}
