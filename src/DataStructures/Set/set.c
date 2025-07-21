//-------------------------------
//          SET
//-------------------------------
/*
- A set is a collection of distinct elements.
- Sets are typically implemented using hash tables or balanced trees.
- Basic operations include add, remove, and contains.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct Set {
  int *data;
  int size;
  int capacity;
} Set;

Set *createSet() {
  Set *set = (Set *)malloc(sizeof(Set));
  if (!set) {
    printf("Memory allocation failed\n");
    return NULL;
  }
  set->size = 0;
  set->capacity = INITIAL_CAPACITY;
  set->data = (int *)malloc(set->capacity * sizeof(int));
  if (!set->data) {
    printf("Memory allocation failed\n");
    free(set);
    return NULL;
  }
  return set;
}

void clearSet(Set *set) { set->size = 0; }

bool has(Set *set, int value) {
  for (int i = 0; i < set->size; i++) {
    if (set->data[i] == value) return true;
  }
  return false;
}

bool add(Set *set, int value) {
  if (has(set, value)) return false;
  if (set->size == set->capacity) {
    set->capacity *= 2;
    set->data = (int *)realloc(set->data, set->capacity * sizeof(int));
    if (!set->data) {
      printf("Memory allocation failed\n");
      return false;
    }
  }
  set->data[set->size++] = value;
  return true;
}

bool remove(Set *set, int value) {
  for (int i = 0; i < set->size; i++) {
    if (set->data[i] == value) {
      set->data[i] = set->data[--set->size];
      return true;
    }
  }
  return false;
}

Set *unionSet(Set *set1, Set *set2) {
  Set *result = createSet();
  if (!result) return NULL;
  for (int i = 0; i < set1->size; i++) add(result, set1->data[i]);
  for (int i = 0; i < set2->size; i++) add(result, set2->data[i]);
  return result;
}

Set *intersectionSet(Set *set1, Set *set2) {
  Set *result = createSet();
  if (!result) return NULL;
  for (int i = 0; i < set1->size; i++) {
    if (!has(set2, set1->data[i])) add(result, set1->data[i]);
  }
  return result;
}

Set *differenceSet(Set *set1, Set *set2) {
  Set *result = createSet();
  if (!result) return NULL;
  for (int i = 0; i < set1->size; i++) {
    if (!has(set2, set1->data[i])) add(result, set1->data[i]);
  }
  return result;
}

bool isSubset(Set *subset, Set *superset) {
  for (int i = 0; i < subset->size; i++) {
    if (!has(superset, subset->data[i])) return false;
  }
  return true;
}

bool isEmpty(Set *set) { return set->size == 0; }

int size(Set *set) { return set->size; }

void printSet(Set *set) {
  printf("{ ");
  for (int i = 0; i < set->size; i++) {
    printf("%d ", set->data[i]);
  }
  printf("}\n");
}

void freeSet(Set *set) {
  if (set) {
    free(set->data);
    free(set);
  }
}
