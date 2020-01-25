#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq) {
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue * pq) {
	return (pq->front == pq->rear);
}

void Enqueue(Queue * pq, Data data) {
	if ((pq->rear - pq->front + QUEUE_LEN + 1) % QUEUE_LEN == 0) {
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	pq->rear = (pq->rear + 1) % QUEUE_LEN;
	pq->queueArr[pq->rear] = data;
}

Data Dequeue(Queue * pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	pq->front = (pq->front + 1) % QUEUE_LEN;
	return pq->queueArr[pq->front];
}

Data QPeek(Queue * pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	int nextPos = (pq->front + 1) % QUEUE_LEN;
	return pq->queueArr[nextPos];
}
