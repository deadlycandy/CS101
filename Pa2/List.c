/*
	List.c 
	Implementation for List ADT

*/

#include<stdio.h>
#include<stdlib.h>

// structs

typedef struct NodeObj{
	int data;
	struct NodeObj* next;
	struct NodeObj* prev;
} NodeObj;

typedef NodeObj* Node;

typedef struct ListObj{
	Node front;
	Node back;
	Node curr;
	int length;
	int index;
} ListObj;

// Constructors and Destructors 

Node newNode(int data){
	Node n = malloc(sizeof(NodeObj));
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	return(n);
}

void freeNode(Node* pN){
	if(pN != NULL && *pN != NULL){
		free(*pN);
		*pN = NULL;
	}
}

List newList(void){
	List L;
	L = malloc(sizeof(ListObj);
	L->front = NULL;
	L->back = NULL;
	L->curr = NULL;
	L->length = 0;
	L->index = -1;
	return(L);
}

void freeList(List* pL){
	if(pL != NULL && *pL != NULL){
		moveFront(*pL);
		while( length(*pL) != 0){
			delete(*pL);
			moveNext(*pL);	
		}
		free(*pL);
		*pL = NULL;
	}
}

//Access functions

int length(List L){
	if(L == NULL){
		printf("List Error: calling length() NULL List refference\n");
		exit(1);
	}
	return(L->length);
}

int index(List L){
	if(L == NULL){
		printf("List Error: calling index() NULL List refference\n");
		exit(1);
	}
	if(L->curr == NULL){
		return -1;
	}	
	return (L->index);
}

int front(List L){
	if(L == NULL){
		printf("List Error: calling front() NULL List refference\n");
		exit(1);
	}
	if(L->length <= 0){
		printf("List Error: calling front() failed precondition length <= 0\n");
		exit(1);
	}
	return(L->front->data);
}

int back(List L){
	if(L == NULL){
		printf("List Error: calling back() NULL List refference\n");
		exit(1);
	}
	if(L->length <= 0){
		printf("List Error: calling back() failed precondition length <= 0\n");
		exit(1);
	}
	return(L->back->data);
}

int get(List L){
	if(L == NULL){
		printf("List Error: calling get() NULL List refference\n");
		exit(1);
	}
	if(L->length <= 0){
		printf("List Error: calling get() failed precondition length <= 0\n");
		exit(1);
	}
	return(L->curr->data);
}

int equals(List A, List B){
	if(A == NULL){
		printf("List Error: calling equals() NULL List refference\n");
		exit(1);
	}
	if(B == NULL){
		printf("List Error: calling equals() NULL List refference\n");
		exit(1);
	}
	if(A->length == B->length){
		Node curr1 = A->front;
		Node curr2 = B->front;
		while(curr1 != NULL && curr2 != NULL){
			if(curr1->data != curr2->data){
				return(false);
			}
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
		free(curr1);
		free(curr2);
		return(true);
	}
	else{
		return(false);
	}
}

// Manipulation procedures
void clear(List L){
	if(L == NULL){
		printf("List Error: calling clear() NULL List refference\n");
		exit(1);
	}
	Node curr1 = L->front;
	Node temp = NULL;
	while(curr1 != NULL){
		temp = curr1;
		curr1 = curr1->next;
		free(temp);
		temp = NULL;
	}
	L->front = L->back = L->curr = NULL;
	L->length = 0;
	L->index = -1;
}

void moveFront(List L){
	if(L == NULL{
		printf("List Error: calling moveFront() NULL List refference\n");
		exit(1);
	}
	if(L->length <= 0){
		printf("List Error: calling moveFront() failed precondition length <= 0\n");
	}
}













