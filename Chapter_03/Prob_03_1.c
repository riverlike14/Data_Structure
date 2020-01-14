#include <stdio.h>
#include "ArrayList/ArrayList.h"

int main() {
	List list;
	ListInit(&list);

	for (int i = 1; i < 10; i++)
		LInsert(&list, i);

	int data;
	int total = 0;

	if (LFirst(&list, &data)) {
		while (TRUE) {
			total += data;

			if (!LNext(&list, &data))
				break;
		}
	}
	printf("Total sum: %d\n\n", total);

	if (LFirst(&list, &data)) {
		while (TRUE) {
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);

			if (!LNext(&list, &data))
				break;
		}
	}

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
