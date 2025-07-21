//-------------------------------
//          Stack
//-------------------------------

/*
- Stack is the linear data structure that follows the Last in, First Out(LIFO)
principle of data insertion and deletion.
- The element that is inserted last will be the first one to be removed and the
element that is inserted first will be removed at last.
- Stack is a linear data structure that can be implemented using arrays or
linked lists.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct Stack {
  int *data;
  int top;
  int capacity;
} Stack;

Stack *createStack() {
  Stack *stack = (int *)malloc(sizeof(Stack));
  if (stack == NULL) return NULL;

  stack->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
  if (stack->data == NULL) {
    free(stack);
    return NULL;
  }

  stack->top = -1;
  stack->capacity = INITIAL_CAPACITY;
  return stack;
}

bool isEmpty(Stack *stack) { return stack->top == -1; }

int size(Stack *stack) { return stack->top + 1; }

bool resize(Stack *stack) {
  int newCapacity = stack->capacity * 2;
  int *newData = (int *)realloc(stack->data, newCapacity * sizeof(int));
  if (newData == NULL) return 1;
  stack->data = newData;
  stack->capacity = newCapacity;
  return true;
}

bool push(Stack *stack, int value) {
  if (stack->top + 1 == stack->capacity) {
    if (!resize(stack)) return false;
  }
  stack->data[++stack->top] = value;
  return true;
}

int pop(Stack *stack) {
  if (isEmpty(stack)) return -1;
  return stack->data[stack->top--];
}

int peek(Stack *stack) {
  if (isEmpty(stack)) return -1;
  return stack->data[stack->top];
}

void clear(Stack *stack) {
  if (stack != NULL) {
    free(stack->data);
    free(stack);
  }
}

void printStack(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack elements (bottom -> top): ");
  for (int i = 0; i <= stack->top; i++) {
    printf("%d ", stack->data[i]);
  }
  printf("\n");
}
