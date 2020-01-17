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

	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	tail = head;

	while (1) {
		printf("Enter a number: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");

	printf("Print the whole data! \n");
	cur = head->next;
	if (cur == NULL) 
		printf("There are no saved numbers. \n");
	else {
		while (cur != NULL) {
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}
	printf("\n\n");

	Node * delNextNode = NULL;
	while (head != NULL) {
		delNextNode = head->next;
		free(head);
		head = delNextNode;
	}

	return 0;
}
