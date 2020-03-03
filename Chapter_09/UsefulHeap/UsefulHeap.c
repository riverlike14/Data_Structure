#include "UsefulHeap.h"

void HeapInit(Heap * ph, PriorityComp pc) {
	ph->comp = pc;
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

	if (ph->comp(ph->heapArr[lcidx], ph->heapArr[rcidx]) < 0)
		return rcidx;
	else
		return lcidx;
}

void HInsert(Heap * ph, HData data) {
	int index = ph->numOfData + 1;
	int pidx;

	while (index > 1) {
		pidx = GetParentIdx(index);

		if (ph->comp(data, ph->heapArr[pidx]) <= 0)
			break;
		
		ph->heapArr[index] = ph->heapArr[pidx];
		index = pidx;
	}

	ph->heapArr[index] = data;
	ph->numOfData++;
}

HData HDelete(Heap * ph) {
	HData retData = ph->heapArr[1];
	HData lastData = ph->heapArr[ph->numOfData];

	int index = 1;
	int cidx;

	while (TRUE) {
		cidx = GetHighChildIdx(ph, index);
		if (cidx == 0)
			break;
		if (ph->comp(lastData, ph->heapArr[cidx]) >= 0)
			break;

		ph->heapArr[index] = ph->heapArr[cidx];
		index = cidx;
	}

	ph->heapArr[index] = lastData;
	ph->numOfData--;

	return retData;
}
