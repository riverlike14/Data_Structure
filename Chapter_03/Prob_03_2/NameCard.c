#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone) {
	NameCard * pcard;
	pcard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(pcard->name, name);
	strcpy(pcard->phone, phone);

	return pcard;
}

void ShowNameCardInfo(NameCard * pcard) {
	printf("Name: %s\n", pcard->name);
	printf("Phone: %s\n", pcard->phone);
	printf("\n");
}

int NameCompare(NameCard * pcard, char * name) {
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, char * phone) {
	strcpy(pcard->phone, phone);
}
