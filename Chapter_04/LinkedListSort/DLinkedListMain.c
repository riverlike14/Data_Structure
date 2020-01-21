#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2) {
	return (d1 < d2);
}

int main() {
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list, 11);
	LInsert(&list, 22);

	printf("Current number of data: %d\n", LCount(&list));

	if (LFirst(&list, &data)) {
		while (TRUE) {
			printf("%d ", data);
			if (!LNext(&list, &data))
				break;
		}
	}
	printf("\n\n");

	if (LFirst(&list, &data)) {
		while (TRUE) {
			if (data == 22)
				LRemove(&list);
			
			if (!LNext(&list, &data))
				break;
		}
	}
	printf("Currently remaining number of data: %d\n", LCount(&list));

	if (LFirst(&list, &data)) {
		while (TRUE) {
			printf("%d ", data);
			if (!LNext(&list, &data))
				break;
		}
	}
	printf("\n\n");

	return 0;
}
