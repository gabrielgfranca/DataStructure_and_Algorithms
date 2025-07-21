#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Stack {
  int *data;
  int top;
  int capacity;
} Stack;

Stack *createStack();
bool isEmpty(Stack *stack);
int size(Stack *stack);
bool resize(Stack *stack);
bool push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void clear(Stack *stack);
void printStack(Stack *stack);

#endif
