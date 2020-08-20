#ifndef _PILHA_H
#define _PILHA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct stack Stack;

int menu();

Stack* createStack();

int push(Stack* myStack, int val);
int pop(Stack* myStack);
int top(Stack* myStack);
int isEmpty(Stack* myStack);
int removeStack(Stack* myStack);
void print(Stack* myStack);

#endif // !_PILHA_H