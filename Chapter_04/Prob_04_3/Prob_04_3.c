#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int main() {
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	printf("Current number of data: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		while (TRUE) {
			ShowPointPos(ppos);

			if (!LNext(&list, &ppos))
				break;
		}
	}
	printf("\n\n");

	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos)) {
		while (TRUE) {
			if (PointComp(ppos, &compPos) == 1) {
				ppos = LRemove(&list);
				free(ppos);
			}

			if (!LNext(&list, &ppos))
				break;
		}
	}

	printf("Current number of data: %d \n", LCount(&list));

	if (LFirst(&list, &ppos)) {
		while (TRUE) {
			ShowPointPos(ppos);

			if (!LNext(&list, &ppos))
				break;
		}
	}
	printf("\n\n");

	return 0;
}
