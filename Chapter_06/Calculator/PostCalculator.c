#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ListBaseStack.h"
#include "PostCalculator.h"

int EvalRPNExp(char exp[]) {
	Stack stack;
	StackInit(&stack);

	int len = strlen(exp);
	int num1, num2;
	
	for (int i = 0; i < len; i++) {
		if (isdigit(exp[i]))
			Push(&stack, exp[i] - '0');
		else {
			num2 = Pop(&stack);
			num1 = Pop(&stack);
			switch(exp[i]) {
				case '+':
					Push(&stack, num1 + num2);
					break;
				case '-':
					Push(&stack, num1 - num2);
					break;
				case '*':
					Push(&stack, num1 * num2);
					break;
				case '/':
					Push(&stack, num1 / num2);
					break;
			}
		}
	}

	return Pop(&stack);
}
