#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist) {
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->data = data;

	if (plist->numOfData)
		plist->head->prev = newNode;
	newNode->next = plist->head;

	plist->head = newNode;

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata) {
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, Data * pdata) {
	if (plist->cur == NULL)
		return FALSE;
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List * plist, Data * pdata) {
	if (plist->cur == NULL)
		return FALSE;
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

int LCount(List * plist) {
	return (plist->numOfData);
}
