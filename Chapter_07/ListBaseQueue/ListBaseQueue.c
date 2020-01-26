#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue * pq) {
	Node * initNode = (Node*)malloc(sizeof(Node));
	initNode->next = NULL;

	pq->front = initNode;
	pq->rear = initNode;
}

int QIsEmpty(Queue * pq) {
	return (pq->front->next == NULL);
}

void Enqueue(Queue * pq, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	pq->rear->next = newNode;
	pq->rear = newNode;
}

Data Dequeue(Queue * pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	Node * delNode = pq->front;
	Data retData = delNode->next->data;
	pq->front = pq->front->next;

	free(delNode);

	return retData;
}

Data QPeek(Queue * pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	return pq->front->next->data;
}
