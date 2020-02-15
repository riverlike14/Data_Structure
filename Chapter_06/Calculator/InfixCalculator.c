#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[]) {
	int len = strlen(exp);
	char * expcpy = NULL;
	expcpy = (char*)malloc(len + 1);

	int ans;
	strcpy(expcpy, exp);
	ConvToRPNExp(expcpy);
	ans = EvalRPNExp(expcpy);

	free(expcpy);

	return ans;
}
