#ifndef __CIRCULAR_LINKED_LIST_BASE_STACK_H__
#define __CIRCULAR_LINKED_LIST_BASE_STACK_H__

#include "CLinkedList.h"

#define TRUE 1
#define FALSE 0

typedef CList Stack;

void StackInit(Stack * pstack);
int IsEmpty(Stack * pstack);

void Push(Stack * pstack, Data data);
Data Pop(Stack * pstack);
Data Peek(Stack * pstack);

#endif
