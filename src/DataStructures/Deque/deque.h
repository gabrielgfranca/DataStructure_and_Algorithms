#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

typedef struct Deque {
  int *data;
  int front;
  int tail;
  int capacity;
  int size;
} Deque;

Deque *createDeque();
bool isEmpty(Deque *deque);
int size(Deque *deque);
bool resize(Deque *deque);
bool addFront(Deque *deque, int value);
bool addTail(Deque *deque, int value);
bool removeFront(Deque *deque, int *value);
bool removeTail(Deque *deque, int *value);
bool peekFront(Deque *deque, int *value);
bool peekTail(Deque *deque, int *value);
void clearDeque(Deque *deque);
void display(Deque *deque);

#endif