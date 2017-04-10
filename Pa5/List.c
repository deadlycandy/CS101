/*
 * 	Rahil Bhatnagar
 * 	rabhatna
 * 	pa4
 *
 * 	List.c 
 * 	Implementation for List ADT, with access and manipluation functions
*/

#include<stdio.h>
#include<stdlib.h>
#include "List.h"

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

//constructor for new node
Node newNode(int data){
	Node n = malloc(sizeof(NodeObj));
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	return(n);
}

//destructor for nodes (frees memory)
void freeNode(Node* pN){
	if(pN != NULL && *pN != NULL){
		free(*pN);
		*pN = NULL;
	}
}

//constructor for list
List newList(void){
	List L;
	L = malloc(sizeof(ListObj));
	L->front = NULL;
	L->back = NULL;
	L->curr = NULL;
	L->length = 0;
	L->index = -1;
	return(L);
}

//destructor for list
void freeList(List* pL){
	if(pL != NULL && *pL != NULL){
		Node curr1 = (*pL)->front;
		Node temp  = NULL;
		while(curr1 != NULL){
			temp = curr1;
			curr1 = curr1->next;
			freeNode(&temp);
		}
		free(*pL);
		*pL = NULL;
	}
}

//Access functions

//returns size of list
int length(List L){
	if(L == NULL){
		printf("List Error: calling length() NULL List refference\n");
		exit(1);
	}
	return(L->length);
}

//returns index of currsor if defined
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

//returns front value of the list if length > 0
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

//returns back value of the list if length >0
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

//returns cursor value if length > 0 and index > 0
int get(List L){
	if(L == NULL){
		printf("List Error: calling get() NULL List refference\n");
		exit(1);
	}
	if(L->length <= 0){
		printf("List Error: calling get() failed precondition length <= 0\n");
		exit(1);
	}
	if(L->index < 0){
		printf("List Error: calling get() failed precondition index < 0\n");
		exit(1);
	}
	return(L->curr->data);
}

//Checks if two lists are equal
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
				return(0);
			}
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
		free(curr1);
		free(curr2);
		return(1);
	}
	else{
		return(0);
	}
}

// Manipulation procedures

//clears the list reverting it to empty list 
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

//moves the currsor to the front of the list if length > 0
void moveFront(List L){
	if(L == NULL){
		printf("List Error: calling moveFront() NULL List refference\n");
		exit(1);
	}
	if(L->length > 0){
		L->curr = L->front;
		L->index = 0;
	}
}

//moves the cursor to the back of the list if length > 0
void moveBack(List L){
	if(L == NULL){
		printf("List Error: calling moveBack() NULL List refference\n");
		exit(1);
	}
	if(L->length > 0){
		L->curr = L->back;
		L->index = L->length - 1;
	}
}

//moves the cursor one step closer to the front
void movePrev(List L){
	if(L == NULL){
		printf("List Error: calling movePrev() NULL List refference\n");
		exit(1);
	}
	if(L->curr != NULL && L->curr != L->front){
		L->curr = L->curr->prev;
		L->index = L->index - 1;
	} 
	else if(L->curr == L->front){
		L->index = -1;
		L->curr = NULL;
	}
}

//moves the cursor one step closer to the back
void moveNext(List L){
	if(L == NULL){
		printf("List Error: calling moveNext() NULL List refference\n");
		exit(1);
	}
	if(L->curr != NULL && L->curr != L->back){
		L->curr = L->curr->next;
		L->index = L->index + 1;
	}
	else if(L->curr == L->back){
		L->curr = NULL;
		L->index = -1;
	}
}

//addds a new node to the front of the list
void prepend(List L, int data){
	if(L == NULL){
		printf("List Error: calling prepend() NULL List refference\n");
		exit(1);
	}
	Node n = newNode(data);	
	if(L->length == 0){
		L->front = n;
		L->back = n;
		L->length = 1;
	}
	else{
		n->next =  L->front;
		L->front->prev = n;
		n->prev = NULL;
		L->front = n;
		L->index += 1;
		L->length +=1;		
	}


}

//adds a new node to the back of the list
void append(List L, int data){
	if(L == NULL){
		printf("List Error: calling append() NULL List refference\n");
		exit(1);
	}
	Node n = newNode(data);	
	if(L->length == 0){
		L->front = n;
		L->back = n;
		L->length = 1;
	}
	else{
		n->prev = L->back;
		L->back->next = n;
		n->next = NULL;
		L->back = n;
		L->length +=1;		
	}


}

//inserts a new node before the cursor if index > 0 and length > 0 
void insertBefore(List L, int data){
	if(L == NULL){
		printf("List Error: calling insertBefore() NULL List refference\n");
		exit(1);
	}
	if(L->index < 0){
		printf("List Error: calling insertBefore() failed precondition index < 0\n");
		exit(1); 
	}
	if(L->length <= 0){
		printf("List Error: calling insertBefore() failed precondition length <= 0\n");
		exit(1);
	}
	if(L->curr->prev == NULL){
		prepend(L, data);
	}
	else{
		Node n = newNode(data);
		L->curr->prev->next = n;
		n->prev = L->curr->prev;
		n->next = L->curr;
		L->curr->prev = n;
		L->index += 1;
		L->length += 1;

	
	}
	
}

//inserts a new node after the cursor if index > 0 and length > 0
void insertAfter(List L, int data){
	if(L == NULL){
		printf("List Error: calling insertAfter() NULL List refference\n");
		exit(1);
	}
	if(L->index < 0){
		printf("List Error: calling insertAfter() failed precondition index < 0\n");
		exit(1); 
	}
	if(L->length <= 0){
		printf("List Error: calling insertAfter() failed precondition length <= 0\n");
		exit(1);
	}
	if(L->curr->next == NULL){
		append(L, data);
	}
	else{
		Node n = newNode(data);
		n->next = L->curr->next;
		L->curr->next = n;
		n->next->prev = n;
		n->prev = L->curr;
		L->length += 1;
	
	
	}
}

//deletes the front element of the list if length > 0
void deleteFront(List L){
	if(L == NULL){
		printf("List Error: calling deleteFront() NULL List refference\n");
		exit(1);
	}
	if(L->length <= 0){
		printf("List Error: calling deleteFront() failed precondition length <= 0\n");
		exit(1);
	}

        if(L->length==1)
	{
		freeNode(&L->front);
		L->front=L->back=NULL;
		L->index=-1;
		L->length=0;
	}else{
		L->front = L->front->next;
		freeNode(&L->front->prev);
	//	L->front->prev = NULL;
		L->index -= 1;
		L->length -= 1;
	}
}

//deletes the back element of the list if length > 0
void deleteBack(List L){
	if(L == NULL){
		printf("List Error: calling deleteBack() NULL List refference\n");
		exit(1);
	}
	if(L->length <= 0){
		printf("List Error: calling deleteBack() failed precondition length <= 0\n");
		exit(1);
	}
        if(L->length==1)
	{
		freeNode(&L->front);
		L->front=L->back=NULL;
		L->index=-1;
		L->length=0;
	}else{
		L->back = L->back->prev;
		free(L->back->next);
		L->back->next = NULL;
		L->length -= 1;
	}
}

//deletes the element the cursor is on if length > 0 and index > 0 
void delete(List L){
	if(L == NULL){
		printf("List Error: calling delete() NULL List refference\n");
		exit(1);
	}
	if(L->length <= 0){
		printf("List Error: calling delete() failed precondition length <= 0\n");
		exit(1);
	}
	
	if(L->index < 0){
		printf("List Error: calling delete() failed precondition index < 0\n");
		exit(1);
	}
	if(L->curr->next == NULL){
		L->back = L->back->prev;
		free(L->back->next);
		L->back->next = NULL;
		L->curr = NULL;
		L->index = -1;
		L->length -= 1;
	}
	else if(L->curr->prev == NULL){
		L->front = L->front->next;
		free(L->front->prev);
		L->front->prev = NULL;
		L->curr = NULL;
		L->index = -1;
		L->length -=1;
	}else if(L->length == 1){
		L->front=L->back=L->curr=NULL;
		L->index=-1;
		L->length=0;
	}else{
		L->curr->prev->next = L->curr->next;
		L->curr->next->prev = L->curr->prev;
		free(L->curr);
		L->curr = NULL;
		L->index = -1;
		L->length -= 1;
	}
}

//prints the content of the list to the file 
void printList(FILE* out, List L){
	if(L == NULL){
		printf("List Error: calling printList() NULL List refference\n");
		exit(1);
	}
	Node n;
	n = L->front;
	while(n != NULL){
		fprintf(out, "%d ", n->data);
  		n = n->next;
	}
	free(n);
	n = NULL;
}

//creates a copy of the list 
List copyList(List L){
	if(L == NULL){
		printf("List Error: calling copyList() NULL List refference\n");
		exit(1);
	}
	Node n = L->front;
	List L2 = newList();
	while(n != NULL){
		append(L2, n->data);
		n = n->next;
	}
	free(n);
	n = NULL;
	return(L2);
}

















