#ifndef __INFIX_TO_POSTFIX_H__
#define __INFIX_TO_POSTFIX_H__

void ConvToRPNExp(char exp[]);
int GetOpPrec(char op);
int WhoPrecOp(char op1, char op2);

#endif
