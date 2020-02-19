#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

#include "BinaryTree.h"

#define TRUE 1
#define FALSE 0

typedef BTreeNode * Data;

typedef struct _node {
	Data data;
	struct _node * next;
} Node;

typedef struct _listStack {
	Node * head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack);
int IsEmpty(Stack * pstack);

void Push(Stack * pstack, Data data);
Data Pop(Stack * pstack);
Data Peek(Stack * pstack);

#endif
