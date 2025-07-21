//-------------------------------
//          Deque
//-------------------------------

/*
- It is exactly like a queue except that it does not follow the FIFO rule (First
in first out)
- the elements can be added to or removed from either the front(head) or
tail(tail) of the deque.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct Deque {
  int *data;
  int front;
  int tail;
  int capacity;
  int size;
} Deque;

Deque *createDeque() {
  Deque *deque = (Deque *)malloc(sizeof(Deque));
  if (deque == NULL) return NULL;

  deque->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
  if (deque->data == NULL) {
    free(deque);
    return NULL;
  }
  deque->front = 0;
  deque->tail = -1;
  deque->size = 0;
  deque->capacity = INITIAL_CAPACITY;
  return deque;
}

bool isEmpty(Deque *deque) { return deque->size == 0; }

int size(Deque *deque) { return deque->size; }

bool resize(Deque *deque) {
  int newCapacity = deque->capacity * 2;
  int *newData = (int *)malloc(newCapacity * sizeof(int));
  if (newData == NULL) return false;
  for (int i = 0; i < deque->size; i++) {
    newData[i] = deque->data[(deque->front + i) % deque->capacity];
  }
  free(deque->data);
  deque->data = newData;
  deque->capacity = newCapacity;
  deque->front = 0;
  deque->tail = deque->size - 1;
  return true;
}

bool addFront(Deque *deque, int value) {
  if (deque->size == deque->capacity) {
    if (!resize(deque)) return false;
  }
  deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
  deque->data[deque->front] = value;
  deque->size++;
  if (deque->tail == 1) deque->tail = deque->front;
  return true;
}

bool addTail(Deque *deque, int value) {
  if (deque->size == deque->capacity) {
    if (!resize(deque)) return false;
  }
  deque->tail = (deque->tail + 1) % deque->capacity;
  deque->data[deque->tail] = value;
  deque->size++;
  return true;
}

bool removeFront(Deque *deque, int *value) {
  if (isEmpty(deque)) return false;
  *value = deque->data[deque->front];
  deque->front = (deque->front + 1) % deque->capacity;
  deque->size--;
  return true;
}

bool removeTail(Deque *deque, int *value) {
  if (isEmpty(deque)) return false;
  *value = deque->data[deque->tail];
  deque->tail = (deque->tail - 1 + deque->capacity) % deque->capacity;
  deque->size--;
  return true;
}

bool peekFront(Deque *deque, int *value) {
  if (isEmpty(deque)) return false;
  *value = deque->data[deque->front];
  return true;
}

bool peekTail(Deque *deque, int *value) {
  if (isEmpty(deque)) return false;
  *value = deque->data[deque->tail];
  return true;
}

void clearDeque(Deque *deque) {
  if (deque != NULL) {
    free(deque->data);
    free(deque);
  }
}

void display(Deque *deque) {
  if (isEmpty(deque)) {
    printf("Deque is empty\n");
    return;
  }
  printf("Deque elements (front -> tail): ");
  for (int i = 0; i < deque->size; i++) {
    printf("%d ", deque->data[(deque->front + i) % deque->capacity]);
  }
  printf("\n");
}
