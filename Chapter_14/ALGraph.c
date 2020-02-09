#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph * pg, int nv) {
	pg->numV = nv;
	pg->numE = 0;
	pg->adjList = (List*)malloc(sizeof(List) * nv);

	for (int i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

void GraphDestroy(ALGraph * pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);
}

void AddEdge(ALGraph * pg, int fromV, int toV) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

void ShowGraphEdgeInfo(ALGraph * pg) {
	int vx;

	for (int i = 0; i < pg->numV; i++) {
		printf("Vertices connected with %c: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx)) {
			while (TRUE) {
				printf("%c ", vx + 65);
				if (!LNext(&(pg->adjList[i]), &vx))
					break;
			}
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2) {
	if (data1 < data2)
		return 0;
	else
		return 1;
}
