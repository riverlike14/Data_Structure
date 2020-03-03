#include <stdio.h>

void SelectionSort(int arr[], int n) {
	int pidx, temp;

	for (int i = 0; i < n - 1; i++) {
		pidx = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[pidx])
				pidx = j;
		}

		temp = arr[i];
		arr[i] = arr[pidx];
		arr[pidx] = temp;
	}
}

int main() {
	int arr[4] = {3, 4, 2, 1};

	SelectionSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 4; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
