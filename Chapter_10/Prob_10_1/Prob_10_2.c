#include <stdio.h>

void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right) {
	int mid = (left + right) / 2;
	int pidx;
	if ((arr[left] - arr[mid]) * (arr[mid] - arr[right - 1]) >= 0)
		pidx = mid;
	else if ((arr[mid] - arr[left]) * (arr[left] - arr[right - 1]) >= 0)
		pidx = left;
	else
		pidx = right - 1;
	Swap(arr, left, pidx);

	int pivot = arr[left];
	printf("Pivot: %d\n", pivot);

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
	int arr[15];
	for (int i = 0; i < 15; i++)
		arr[i] = 15 - i;
	int len = sizeof(arr) / sizeof(int);

	QuickSort(arr, 0, len);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
