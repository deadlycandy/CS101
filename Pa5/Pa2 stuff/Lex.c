/*
 * Rahil Bhatnagar
 * rabhatna
 * pa2
 *
 * Lex sorts an array of text in lex order
 *
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"



#define MAX_LEN 255

//Lex sorting algorithim 
List lexSort(List L, char* A[], int size){
	
	for(int i = 0; i <= size; i++){
		int j = i -1;
		moveFront(L);
		
		//Grabbing J 
		while(j >= 0 && index(L) >= 0){
			moveNext(L);
			j--;
		}	
		int temp = get(L);
		delete(L);
		moveFront(L);
		
		//searching for spot
		j = i -1;
		while(j >= 0 && strcmp(A[get(L)],A[i]) < 0){
			moveNext(L);
			j--;
		} 
		if(length(L) < 2){
			append(L, temp);
		}
		else{
			insertBefore(L, temp);
		}
	}

	return L;
}

//print to file
void printToFile(List L, char* A[], FILE* out){
	moveFront(L);
	while(index(L) >= 0){
		fprintf(out, "%s", A[get(L)]);
		moveNext(L);
	}

}

int main(int argc, char* argv[]){

	//opening and checking files
	if( argc != 3){ 
   		printf("Usage: %s <input file> <output file>\n", argv[0]);
	      	exit(1);
   	}

   	 
	FILE* in = fopen(argv[1], "r");
        FILE* out = fopen(argv[2], "w");
     	if( in==NULL ){
   	   	printf("Unable to open file %s for reading\n", argv[1]);
                exit(1);
        }
   	if( out==NULL ){
        	printf("Unable to open file %s for writing\n", argv[2]);
		exit(1);
	}

	//find the number of lines in the file
     	char line[MAX_LEN];
	int numLines = -1;
	while(fgets(line, MAX_LEN, in) != NULL){	
		++numLines;
	}

	//reading in the lines of the file and storing in an array	
	rewind(in);
	char *A[numLines];
	int j = 0;  
	while(fgets(line, MAX_LEN, in) != NULL){
		A[j] = malloc(sizeof(line)+1);
		strcpy(A[j],line);	
		j++;
	}	
	
	//creating a list and sorting
	List L = newList();
	int size = ((sizeof(A)/sizeof(*A)));
	for(int i = 0; i <= size; i++){
		append(L, i);
	}
	L = lexSort(L, A, size);
	printToFile(L,A,out);
	

	//freeing all allocated memory
	for(int i = 0; i <= (sizeof(A) /sizeof(*A)); i++){
		free(A[i]);
	}
	freeList(&L);
	fclose(in);
	fclose(out);
	return 1;
}	
