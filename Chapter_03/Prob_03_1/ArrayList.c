#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist) {
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void LInsert(List * plist, LData data) {
	if (plist->numOfData >= LIST_LEN) {
		printf("Insertion is impossible; the array is already full.\n");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata) {
	if (plist->numOfData <= 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];

	return TRUE;
}

int LNext(List * plist, LData * pdata) {
	if (plist->curPosition > plist->numOfData - 2)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];

	return TRUE;
}

LData LRemove(List * plist) {
	if (plist->numOfData == 0) {
		printf("There is no data to remove; the array is already empty.\n");
		return 0;
	}

	LData rdata = plist->arr[plist->curPosition];

	for (int i = plist->curPosition; i < plist->numOfData - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;

	return rdata;
}

int LCount(List * plist) {
	return plist->numOfData;
}
