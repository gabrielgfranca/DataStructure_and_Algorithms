//-------------------------------
//          Min Heap
//-------------------------------
/*
A Min Heap is a complete binary tree where:
    - The value of each node is less than or equal to the values of its
children.
    - This property must be true for all nodes in the tree.
Min Heaps allow efficient access to the minimum element, as it is always located
at the root. Operations such as insertion and deletion can be performed in
logarithmic time.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct minHeap {
  int* arr;
  int capacity;
  int size;
} minHeap;

minHeap* createMinHeap(int capacity) {
  minHeap* heap = (minHeap*)malloc(sizeof(minHeap));
  if (heap == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }
  heap->size = 0;
  heap->capacity = capacity;
  heap->arr = (int*)malloc(capacity * sizeof(int));
  if (heap->arr == NULL) {
    printf("Memory allocation failed\n");
    free(heap);
    return NULL;
  }
  return heap;
}

int getLeftIndex(int index) { return 2 * index + 1; }
int getRightIndex(int index) { return 2 * index + 2; }
int getParentIndex(int index) {
  if (index == 0) return -1;
  return (index - 1) / 2;
}