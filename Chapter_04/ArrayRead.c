#include <stdio.h>

int main() {
	int arr[10];
	int readCount = 0;
	int readData;

	while (1) {
		printf("Enter a number: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		arr[readCount++] = readData;
	}

	for (int i = 0; i < readCount; i++)
		printf("%d ", arr[i]);

	return 0;
}
