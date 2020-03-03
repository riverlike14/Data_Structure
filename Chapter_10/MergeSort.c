#include <stdio.h>
#include <stdlib.h>

void Merge(int arr[], int left, int right) {
	int mid = (left + right) / 2;
	int lidx = left, ridx = mid;
	int sidx = 0;

	int * sortArr = (int*)malloc(sizeof(int) * (right - left));

	while (lidx < mid && ridx < right) {
		if (arr[lidx] > arr[ridx])
			sortArr[sidx] = arr[ridx++];
		else
			sortArr[sidx] = arr[lidx++];
		sidx++;
	}

	if (lidx < mid) {
		for (int i = lidx; i < mid; i++)
			sortArr[sidx++] = arr[i];
	}
	if (ridx < right) {
		for (int i = ridx; i < right; i++)
			sortArr[sidx++] = arr[i];
	}

	for (int i = left; i < right; i++)
		arr[i] = sortArr[i - left];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
	if (right - left > 1) {
		int mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid, right);
		Merge(arr, left, right);
	}
}

int main() {
	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	
	MergeSort(arr, 0, 7);

	for (int i = 0; i < 7; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}
