#include <stdio.h>
#include "ArrayList/ArrayList.h"

int main() {
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	printf("Current number of data: %d \n", LCount(&list));

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

	printf("Current number of data: %d \n", LCount(&list));

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
