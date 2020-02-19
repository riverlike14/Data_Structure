#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq) {
	Node * newNode = NULL;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	pdeq->head = newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	pdeq->tail = newNode;

	pdeq->head->next = pdeq->tail;
	pdeq->tail->prev = pdeq->head;
}

int DQIsEmpty(Deque * pdeq) {
	return (pdeq->head->next == pdeq->tail);
}

void DQAddFirst(Deque * pdeq, Data data) {
	Node * newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pdeq->head->next;
	newNode->prev = pdeq->head;

	newNode->next->prev = newNode;
	newNode->prev->next = newNode;
}

void DQAddLast(Deque * pdeq, Data data) {
	Node * newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pdeq->tail;
	newNode->prev = pdeq->tail->prev;

	newNode->next->prev = newNode;
	newNode->prev->next = newNode;
}

Data DQRemoveFirst(Deque * pdeq) {
	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!\n");
		exit(-1);
	}

	Node * rnode = pdeq->head->next;
	Data ret = rnode->data;

	rnode->next->prev = rnode->prev;
	rnode->prev->next = rnode->next;
	free(rnode);

	return ret;
}

Data DQRemoveLast(Deque * pdeq) {
	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!\n");
		exit(-1);
	}

	Node * rnode = pdeq->tail->prev;
	Data ret = rnode->data;

	rnode->next->prev = rnode->prev;
	rnode->prev->next = rnode->next;
	free(rnode);

	return ret;
}

Data DQGetFirst(Deque * pdeq) {
	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!\n");
		exit(-1);
	}

	return pdeq->head->next->data;
}

Data DQGetLast(Deque * pdeq) {
	if (DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!\n");
		exit(-1);
	}

	return pdeq->tail->prev->data;
}
