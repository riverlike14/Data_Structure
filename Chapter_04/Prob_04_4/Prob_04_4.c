#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int WhoIsPrecede(Point * p1, Point * p2) {
	if (p1->xpos > p2->xpos)
		return FALSE;
	else if (p1->xpos < p2->xpos)
		return TRUE;
	else
		return (p1->ypos <= p2->ypos);
}

int main() {
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

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
