#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;

	plist->numOfData = 0;
}

void LInsert(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if (plist->numOfData == 0) {
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

void LInsertFront(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->numOfData == 0) {
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata) {
	if (plist->numOfData == 0)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->before->next;

	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, Data * pdata) {
	if (plist->numOfData == 0)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List * plist) {
	if (plist->numOfData == 0) {
		printf("Circular Linked List Memory Error!\n");
		exit(-1);
	}

	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	if (rpos == plist->tail) {
		if (plist->numOfData == 1)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;

	return rdata;
}

int LCount(List * plist) {
	return plist->numOfData;
}
