#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Graph.h"
#include"List.h"

#define MAX_LEN 10 


int main(int argc, char* argv[]){
	int size;
	int n = 0;
   	FILE *in, *out;
   	char line[MAX_LEN];
	int edgelist[MAX_LEN];
	int pathlist[MAX_LEN];
   	char* token;
	
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
	printf("Size: %d\n", size);

	Graph A = newGraph(size);

	while((fgets(line, MAX_LEN, in) != NULL) && (line[0] != '0' && line[2] != '0')){
		token = strtok(line, " \n");
		while(token!=NULL ){
			edgelist[n] = atoi(token);
        		token = strtok(NULL, " \n");
	//		printf("EdgeList %d: %d\n",n, edgelist[n]) ;
			n++;
		}	
	}

	for(int i = 0; i < n; i++){
		addEdge(A,edgelist[n], edgelist[n+1]); 	
	}
	
	printGraph(stdout, A);
	
	n = 0;
	while((fgets(line, MAX_LEN, in) != NULL) && (line[0] != '0' && line[2] != '0')){	
		token = strtok(line, " \n");
		while(token!=NULL ){
			pathlist[n] = atoi(token);
        		token = strtok(NULL, " \n");
	//		printf("PathList %d: %d\n",n, pathlist[n]) ;
			n++;
		}	
	}
	fclose(in);
	fclose(out);


}
