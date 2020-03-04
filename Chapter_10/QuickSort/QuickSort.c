#include <stdio.h>

void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int lidx = left, ridx = right - 1;

	while (ridx >= lidx) {
		if (arr[lidx] <= pivot)
			lidx++;
		else if (arr[ridx] >= pivot)
			ridx--;
		else {
			Swap(arr, lidx, ridx);
			lidx++;
			ridx--;
		}
	}

	Swap(arr, left, ridx);

	return ridx;
}

void QuickSort(int arr[], int left, int right) {
	if (right - left > 1) {
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot);
		QuickSort(arr, pivot + 1, right);
	}
}

int main() {
	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	int len = sizeof(arr) / sizeof(int);

	QuickSort(arr, 0, len);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
