//-------------------------------
//          queue
//-------------------------------

/*
- A queue is a linear data structure that follows the First In First Out (FIFO)
order of insertion and deletion.
- The element that is inserted first will be the first one to be removed and the
element that is inserted last will be removed at last.
- We can implement a queue in C using either an array or a linked list.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5

typedef struct Queue {
  int *data;
  int front;
  int tail;
  int capacity;
} Queue;

Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (queue == NULL) return NULL;

  queue->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
  if (queue->data == NULL) {
    free(queue);
    return NULL;
  }
  queue->front = 0;
  queue->tail = 0;
  queue->capacity = INITIAL_CAPACITY;
  return queue;
}

bool isEmpty(Queue *queue) { return queue->front == queue->tail; }

int size(Queue *queue) { return queue->tail - queue->front; }

bool resize(Queue *queue) {
  int currentSize = size(queue);
  int newCapacity = queue->capacity * 2;
  int *newData = (int *)malloc(newCapacity * sizeof(int));
  if (newData == NULL) return false;
  for (int i = 0; i < currentSize; i++) {
    newData[i] = queue->data[queue->front + i];
  }
  free(queue->data);
  queue->data = newData;
  queue->front = 0;
  queue->tail = currentSize;
  queue->capacity = newCapacity;
  return true;
}

bool enqueue(Queue *queue, int value) {
  if (queue->tail == queue->capacity) {
    if (!resize(queue)) return false;
  }
  queue->data[queue->tail++] = value;
  return true;
}

int dequeue(Queue *queue) {
  if (isEmpty(queue)) return -1;
  return queue->data[queue->front++];
}

int peek(Queue *queue) {
  if (isEmpty(queue)) return -1;
  return queue->data[queue->front];
}

void clear(Queue *queue) {
  if (queue != NULL) {
    free(queue->data);
    free(queue);
  }
}

void printQueue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements (front -> tail): ");
  for (int i = queue->front; i < queue->tail; i++) {
    printf("%d ", queue->data[i]);
  }
  printf("\n");
}