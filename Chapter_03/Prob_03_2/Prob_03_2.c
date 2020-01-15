#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main() {
	List list;
	NameCard * pcard;

	ListInit(&list);

	pcard = MakeNameCard("wooyoung", "010-4597-4921");
	LInsert(&list, pcard);

	pcard = MakeNameCard("seoyoon", "010-1234-5678");
	LInsert(&list, pcard);

	pcard = MakeNameCard("jihoon", "010-0000-1111");
	LInsert(&list, pcard);

	if (LFirst(&list, &pcard)) {
		while (TRUE) {
			if (!NameCompare(pcard, "wooyoung"))
				ShowNameCardInfo(pcard);

			if (!LNext(&list, &pcard))
				break;
		}
	}

	if (LFirst(&list, &pcard)) {
		while (TRUE) {
			if (!NameCompare(pcard, "wooyoung"))
				ChangePhoneNum(pcard, "010-7777-1111");

			if (!LNext(&list, &pcard))
				break;
		}
	}

	if (LFirst(&list, &pcard)) {
		while (TRUE) {
			if (!NameCompare(pcard, "jihoon")) {
				LRemove(&list);
				free(pcard);
			}

			if (!LNext(&list, &pcard))
				break;
		}
	}

	if (LFirst(&list, &pcard)) {
		while (TRUE) {
			ShowNameCardInfo(pcard);

			if (!LNext(&list, &pcard))
				break;
		}
	}

	return 0;
}
