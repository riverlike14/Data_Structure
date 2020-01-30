#include <stdio.h>
#include "DLinkedList.h"

int main() {
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);

	if (LFirst(&list, &data)) {
		printf("From left to right: ");
		while (TRUE) {
			printf("%d ", data);
			if (!LNext(&list, &data)) {
				printf("\n");
				break;
			}
		}

		printf("From right to left: ");
		while (TRUE) {
			printf("%d ", data);
			if (!LPrevious(&list, &data)) {
				printf("\n");
				break;
			}
		}

		printf("\n");
	}

	return 0;
}
