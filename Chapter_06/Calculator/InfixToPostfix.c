#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "InfixToPostfix.h"

void ConvToRPNExp(char exp[]) {
	Stack stack;
	StackInit(&stack);
	int len = strlen(exp);

	char * convExp = NULL;
	convExp = (char*)malloc(len + 1);
	memset(convExp, 0, len + 1);
	
	char op, idx = 0;;

	for (int i = 0; i < len; i++) {
		op = exp[i];
		if (isdigit(op))
			convExp[idx++] = op;
		else if (op == '(')
			Push(&stack, op);
		else {
			while (!IsEmpty(&stack)) {
				if (WhoPrecOp(Peek(&stack), op))
					break;
				convExp[idx++] = Pop(&stack);
			}
			if (op == ')')
				Pop(&stack);
			else
				Push(&stack, op);
		}
	}

	while (!IsEmpty(&stack))
		convExp[idx++] = Pop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}

int GetOpPrec(char op) {
	switch(op) {
		case '*':
		case '/':
			return 3;
		case '+':
		case '-':
			return 2;
		case ')':
			return 1;
		case '(':
			return 0;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2) {
	return (GetOpPrec(op2) > GetOpPrec(op1));
}
