#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

int dlen(int num) {
	int n = 0;
	while (num) {
		num /= 10;
		n++;
	}

	return n;
}

void RadixSort(int arr[], int num) {
	int len, N = 0;
	for (int i = 0; i < num; i++) {
		len = dlen(arr[i]);
		N = (N > len) ? N : len;
	}

	Queue buckets[BUCKET_NUM];
	for (int i = 0; i < BUCKET_NUM; i++)
		QueueInit(buckets + i);

	int radix, div = 1;

	while (N--) {
		for (int i = 0; i < num; i++) {
			radix = (arr[i] / div) % 10;
			Enqueue(buckets + radix, arr[i]);
		}

		int n = 0;
		for (int i = 0; i < BUCKET_NUM; i++) {
			while (!QIsEmpty(buckets + i))
				arr[n++] = Dequeue(buckets + i);
		}

		div *= 10;
	}
}

int main() {
	int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};
	int len = sizeof(arr) / sizeof(int);

	RadixSort(arr, len);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
