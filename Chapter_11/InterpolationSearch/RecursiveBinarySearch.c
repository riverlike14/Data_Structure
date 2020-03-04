#include <stdio.h>

int BSearchRecur(int arr[], int first, int last, int target) {
	if (last - first < 1)
		return -1;

	int mid = (first + last) / 2;

	if (arr[mid] == target)
		return mid;
	if (arr[mid] > target)
		return BSearchRecur(arr, first, mid, target);
	if (arr[mid] < target)
		return BSearchRecur(arr, mid + 1, last, target);
}
