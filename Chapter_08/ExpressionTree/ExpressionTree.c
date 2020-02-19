#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree.h"
#include "ExpressionTree.h"

BTreeNode * MakeExpTree(char exp[]) {
	Stack stack;
	BTreeNode * pnode;

	int len = strlen(exp);

	StackInit(&stack);

	for (int i = 0; i < len; i++) {
		pnode = MakeBTreeNode();

		if (isdigit(exp[i])) {
			SetData(pnode, exp[i] - '0');
		}
		else {
			MakeRightSubTree(pnode, Pop(&stack));
			MakeLeftSubTree(pnode, Pop(&stack));
			SetData(pnode, exp[i]);
		}

		Push(&stack, pnode);
	}

	return Pop(&stack);
}

int EvaluateExpTree(BTreeNode * bt) {
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	int op1, op2;
	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt)) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
	}

	return 0;
}

void ShowPrefixTypeExp(BTreeNode * bt) {
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt) {
	InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode * bt) {
	PostorderTraverse(bt, ShowNodeData);
}

void ShowNodeData(int data) {
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}
