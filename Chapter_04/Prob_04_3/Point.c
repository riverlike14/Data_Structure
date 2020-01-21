#include <stdio.h>
#include "Point.h"

void SetPointPos(Point * ppos, int xpos, int ypos) {
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void ShowPointPos(Point * ppos) {
	printf("(%d, %d) \n", ppos->xpos, ppos->ypos);
}

int PointComp(Point * pos1, Point * pos2) {
	int xpos1 = pos1->xpos, xpos2 = pos2->xpos;
	int ypos1 = pos1->ypos, ypos2 = pos2->ypos;

	if (xpos1 == xpos2 && ypos1 == ypos2)
		return 0;
	else if (xpos1 == xpos2)
		return 1;
	else if (ypos1 == ypos2)
		return 2;
	else
		return - 1;
}
