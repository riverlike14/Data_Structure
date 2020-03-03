#include <stdio.h>

void InsertionSort(int arr[], int n) {
	int temp, insData, j;

	for (int i = 1; i < n; i++) {
		insData = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] <= insData)
				break;
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = insData;
	}
}

int main() {
	int arr[5] = {5, 3, 2, 4, 1};

	InsertionSort(arr, 5);

	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
