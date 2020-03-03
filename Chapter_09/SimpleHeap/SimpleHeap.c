#include "SimpleHeap.h"

void HeapInit(Heap * ph) {
	ph->numOfData = 0;
}

int HIsEmpty(Heap * ph) {
	return ph->numOfData == 0;
}

int GetParentIdx(int index) {
	return index / 2;
}

int GetLChildIdx(int index) {
	return index * 2;
}

int GetRChildIdx(int index) {
	return index * 2 + 1;
}

int GetHighChildIdx(Heap * ph, int index) {
	if (GetLChildIdx(index) > ph->numOfData)
		return 0;
	if (GetLChildIdx(index) == ph->numOfData)
		return GetLChildIdx(index);

	int lcidx = GetLChildIdx(index);
	int rcidx = GetRChildIdx(index);

	if (ph->heapArr[lcidx].pr > ph->heapArr[rcidx].pr)
		return rcidx;
	else
		return lcidx;
}

void HInsert(Heap * ph, HData data, Priority pr) {
	HeapElem nelem = {pr, data};

	ph->numOfData++;
	int index = ph->numOfData;
	int pidx;

	while (index > 1) {
		pidx = GetParentIdx(index);

		if (pr >= ph->heapArr[pidx].pr)
			break;
		
		ph->heapArr[index] = ph->heapArr[pidx];
		index = pidx;
	}

	ph->heapArr[index] = nelem;
}

HData HDelete(Heap * ph) {
	HData retData = (ph->heapArr[1]).data;
	HeapElem lastelem = ph->heapArr[ph->numOfData];

	ph->numOfData--;
	int index = 1;
	int cidx;

	while (TRUE) {
		cidx = GetHighChildIdx(ph, index);
		if (cidx == 0)
			break;
		if (lastelem.pr <= ph->heapArr[cidx].pr)
			break;

		ph->heapArr[index] = ph->heapArr[cidx];
		index = cidx;
	}

	ph->heapArr[index] = lastelem;

	return retData;
}
