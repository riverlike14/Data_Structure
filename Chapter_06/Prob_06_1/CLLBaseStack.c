#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "CLLBaseStack.h"

void StackInit(Stack * pstack) {
	ListInit(pstack);
}

int IsEmpty(Stack * pstack) {
	return (pstack->numOfData == 0);
}

void Push(Stack * pstack, Data data) {
	LInsertFront(pstack, data);
}

Data Pop(Stack * pstack) {
	Data data;
	LFirst(pstack, &data);
	return LRemove(pstack);
}

Data Peek(Stack * pstack) {
	if (IsEmpty(pstack)) {
		printf("Stack Memory Error!\n");
		exit(-1);
	}

	Data data;
	LFirst(pstack, &data);
	return data;
}
