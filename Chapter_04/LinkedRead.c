#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node * next;
} Node;

int main() {
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	while (1) {
		printf("Enter a number: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	printf("Print the whole data! \n");
	if (head == NULL) 
		printf("There are no saved numbers. \n");
	else {
		cur = head;
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}
	printf("\n\n");

	Node * delNextNode;
	while (head != NULL) {
		delNextNode = head->next;
		free(head);
		head = delNextNode;
	}

	return 0;
}
