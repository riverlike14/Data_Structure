#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

int main() {
	List list;
	int nodeNum;

	ListInit(&list);

	Data data = NULL;

	data = (Data)malloc(sizeof(Employee));
	data->ID = 10773;
	data->name = "3Jason";
	LInsert(&list, data);
	data = (Data)malloc(sizeof(Employee));
	data->ID = 10774;
	data->name = "4Jason";
	LInsert(&list, data);
	data = (Data)malloc(sizeof(Employee));
	data->ID = 10775;
	data->name = "5Jason";
	LInsert(&list, data);
	data = (Data)malloc(sizeof(Employee));
	data->ID = 10771;
	data->name = "1Jason";
	LInsert(&list, data);
	data = (Data)malloc(sizeof(Employee));
	data->ID = 10772;
	data->name = "2Jason";
	LInsert(&list, data);

	LPrint(&list);

	if (NextDuty(&list, "2Jason", 36, &data)) {
		printf("ID: %d\n", data->ID);
		printf("Name: %s\n", data->name);
		printf("\n");
	}
	if (NextDuty(&list, "6Jason", 3, &data)) {
		printf("ID: %d\n", data->ID);
		printf("Name: %s\n", data->name);
		printf("\n");
	}

	return 0;
}
