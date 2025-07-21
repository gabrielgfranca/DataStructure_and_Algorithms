#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct {
  int *items;
  int size;
  int capacity;
} Set;

Set *createSet();
void clearSet(Set *set);
bool add(Set *set, int element);
bool delete(Set *set, int element);
bool has(Set *set, int element);
Set *unionSet(Set *set1, Set *set2);
Set *intersectionSet(Set *set1, Set *set2);
Set *differenceSet(Set *set1, Set *set2);
bool isSubset(Set *subset, Set *superset);
bool isEmpty(Set *set);
int size(Set *set);
void printSet(Set *set);
void freeSet(Set *set);

#endif
