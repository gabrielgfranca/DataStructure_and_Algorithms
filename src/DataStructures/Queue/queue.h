#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Queue {
  int *data;
  int front;
  int tail;
  int capacity;
} Queue;

Queue *createQueue();
bool isEmpty(Queue *queue);
int size(Queue *queue);
bool resize(Queue *queue);
bool enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
int peek(Queue *queue);
void clear(Queue *queue);
void printQueue(Queue *queue);

#endif