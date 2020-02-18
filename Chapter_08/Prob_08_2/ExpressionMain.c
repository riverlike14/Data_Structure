#include <stdio.h>
#include "ExpressionTree.h"

int main() {
	char exp[] = "12+7*";
	BTreeNode * eTree = MakeExpTree(exp);
	
	printf("Preorder Expression: ");
	ShowPrefixTypeExp(eTree);
	printf("\n");

	printf("Inorder Expression: ");
	ShowInfixTypeExp(eTree);
	printf("\n");

	printf("Postorder Expression: ");
	ShowPostfixTypeExp(eTree);
	printf("\n");

	return 0;
}
