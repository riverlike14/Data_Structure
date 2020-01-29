#include <stdio.h>
#include "CLinkedList.h"

int main() {
	List list;
	int nodeNum;
	Data data;

	ListInit(&list);

	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);
	LInsertFront(&list, 10);
	LInsertFront(&list, 9);

	if (LFirst(&list, &data)) {
		printf("%d ", data);
	}
	for (int i = 0; i < LCount(&list) * 3 - 1; i++) {
		LNext(&list, &data);
		printf("%d ", data);
	}
	printf("\n");

	nodeNum = LCount(&list);
	if (nodeNum) {
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);
	}
	for (int i = 0; i < nodeNum - 1; i++) {
		LNext(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);
	}

	LPrint(&list);

	nodeNum = LCount(&list);
	if (LFirst(&list, &data)) {
		printf("%d ", data);
	}
	for (int i = 0; i < nodeNum - 1; i++) {
		LNext(&list, &data);
		printf("%d ", data);
	}
	printf("\n");

	return 0;
}
