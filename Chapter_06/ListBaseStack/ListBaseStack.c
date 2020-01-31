#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack) {
	pstack->head = NULL;
}

int IsEmpty(Stack * pstack) {
	return (pstack->head == NULL);
}

void Push(Stack * pstack, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data Pop(Stack * pstack) {
	if (IsEmpty(pstack)) {
		printf("Stack Memory Error!\n");
		exit(-1);
	}

	Data rdata = pstack->head->data;

	Node * delNode = pstack->head;
	pstack->head = pstack->head->next;
	free(delNode);

	return rdata;
}

Data Peek(Stack * pstack) {
	if (IsEmpty(pstack)) {
		printf("Stack Memory Error!\n");
		exit(-1);
	}

	return pstack->head->data;
}
