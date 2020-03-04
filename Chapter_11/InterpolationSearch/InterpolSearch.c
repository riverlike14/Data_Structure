#include <stdio.h>

int ISearch(int arr[], int first, int last, int target) {
	if (last - first < 1)
		return -1;
	if (target < arr[first] || target > arr[last - 1])
		return -1;

	int mid = (first * arr[last - 1] + last * target - last * arr[first] - first * target) / (arr[last - 1] - arr[first]);

	if (arr[mid] == target)
		return mid;
	if (arr[mid] > target)
		return ISearch(arr, first, mid, target);
	if (arr[mid] < target)
		return ISearch(arr, mid + 1, last, target);
}

int main() {
	int arr[] = {1, 3, 5, 7, 9};
	int index;

	index = ISearch(arr, 0, 5, 7);
	if (index == -1)
		printf("Search failed...\n");
	else
		printf("Target index: %d\n", index);

	index = ISearch(arr, 0, 5, 2);
	if (index == -1)
		printf("Search failed...\n");
	else
		printf("Target index: %d\n", index);

	return 0;
}
