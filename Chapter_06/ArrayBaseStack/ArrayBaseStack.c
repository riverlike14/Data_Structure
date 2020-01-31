#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack) {
	pstack->topIndex = -1;
}

int IsEmpty(Stack * pstack) {
	return (pstack->topIndex < 0);
}

void Push(Stack * pstack, Data data) {
	(pstack->topIndex)++;
	pstack->stackArr[pstack->topIndex] = data;
}

Data Pop(Stack * pstack) {
	if (IsEmpty(pstack)) {
		printf("Stack Memory Error!\n");
		exit(-1);
	}

	Data rdata;
	rdata = pstack->stackArr[pstack->topIndex];
	(pstack->topIndex)--;

	return rdata;
}

Data Peek(Stack * pstack) {
	if (IsEmpty(pstack)) {
		printf("Stack Memory Error!\n");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
