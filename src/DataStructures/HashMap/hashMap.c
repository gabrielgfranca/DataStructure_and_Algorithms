//-------------------------------
//           HashMap
//-------------------------------

/*
- HashMaping consists of finding a value in a data structure as quickly as
possible
- When we use a hash function, we already know where the value is, so we can
simply access it.
- A hash function is a function that, given a key, returns the address where the
value is in the table.


This implementation is the most basic form of a dictionary (hash map) using
arrays of keys and values. It was created for educational purposes to illustrate
the basic functionality of insertion, search, and removal.

⚠️ However, this structure has a significant issue: **hash collisions**.
Since it does not use a proper hash function nor implements collision
handling, if two keys are equal or different but result in the same array index,
they may overwrite values or cause inconsistencies.

There are two common approaches to handle collisions:
  1. Separate Chaining:
     - Each position in the hash table holds a structure (usually a linked list)
that stores all key-value pairs that hash to that index.
     - This allows storing multiple items with the same hash without overwriting
each other.

  2. Linear Probing:
     - If a position is already occupied, the insertion function searches for
the next available slot in the array linearly until it finds a free space.
     - Lookup and removal follow the same probing logic until the key is found
or a null position is reached.

Both strategies require adjustments to the hash function, collision checking,
and resizing of the array with rehashing (recomputing the position of all items)
when necessary.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 100

typedef struct hashNode {
  char *key;
  char *value;
  struct hashNode *next;
} hashNode;

typedef struct HashMap {
  hashNode **table;
  int size;
  int capacity;
} HashMap;

unsigned long djb2HashCode(const char *str) {
  unsigned long hash = 5381;
  int c;
  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;  // hash * 33 + c
  }
  return hash;
}

int getHashIndex(const char *key, int capacity) {
  return djb2HashCode(key) % capacity;
}

HashMap *createHashMap() {
  HashMap *map = (HashMap *)malloc(sizeof(HashMap));
  if (map == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  map->capacity = INITIAL_CAPACITY;
  map->size = 0;
  map->table = (hashNode **)calloc(map->capacity, sizeof(hashNode *));
  if (map->table == NULL) {
    printf("Memory allocation failed.\n");
    free(map);
    return NULL;
  }
  return map;
}

bool resizeHashMap(HashMap *map) {
  if (map == NULL) return false;
  int newCapacity = map->capacity * 2;
  hashNode **newTable = (hashNode **)calloc(newCapacity, sizeof(hashNode *));
  if (newTable == NULL) {
    printf("Memory allocation failed during resize.\n");
    return false;
  }

  for (int i = 0; i < map->capacity; i++) {
    hashNode *current = map->table[i];
    while (current != NULL) {
      int newIndex = getHashIndex(current->key, newCapacity);
      hashNode *nextNode = current->next;
      current->next = newTable[newIndex];
      newTable[newIndex] = current;
      current = nextNode;
    }
  }

  free(map->table);
  map->table = newTable;
  map->capacity = newCapacity;
  return true;
}

bool isEmpty(HashMap *map) { return (map == NULL) ? true : map->size == 0; }

int size(HashMap *map) { return (map == NULL) ? 0 : map->size; }

void setHash(HashMap *map, const char *key, const char *value) {
  if (map == NULL || key == NULL || value == NULL) return;
  int index = getHashIndex(key, map->capacity);
  hashNode *current = map->table[index];
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      free(current->value);
      current->value = strdup(value);
      return;
    }
    current = current->next;
  }
  hashNode *newNode = (hashNode *)malloc(sizeof(hashNode));
  if (newNode == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }
  newNode->key = strdup(key);
  newNode->value = strdup(value);
  newNode->next = map->table[index];
  map->table[index] = newNode;
  map->size++;
  if ((float)map->size / map->capacity > 0.75f) {
    resizeHashMap(map);
  }
}

char *getHash(HashMap *map, const char *key) {
  if (map == NULL || key == NULL) return NULL;
  int index = getHashIndex(key, map->capacity);
  hashNode *current = map->table[index];
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      return current->value;
    }
    current = current->next;
  }
  return NULL;
}

bool deleteHash(HashMap *map, const char *key) {
  if (map == NULL || key == NULL) return false;
  int index = getHashIndex(key, map->capacity);
  hashNode *current = map->table[index];
  hashNode *prev = NULL;
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      if (prev == NULL) {
        map->table[index] = current->next;
      } else {
        prev->next = current->next;
      }
      free(current->key);
      free(current->value);
      free(current);
      map->size--;
      return true;
    }
    prev = current;
    current = current->next;
  }
  return false;
}

void clearHashMap(HashMap *map) {
  if (map == NULL) return;
  for (int i = 0; i < map->capacity; i++) {
    hashNode *current = map->table[i];
    while (current != NULL) {
      hashNode *temp = current;
      current = current->next;
      free(temp->key);
      free(temp->value);
      free(temp);
    }
  }
  free(map->table);
  free(map);
}

void printHashMap(HashMap *map) {
  if (map == NULL) {
    printf("HashMap is NULL.\n");
    return;
  }
  for (int i = 0; i < map->capacity; i++) {
    hashNode *current = map->table[i];
    if (current != NULL) {
      printf("Index %d: ", i);
      while (current != NULL) {
        printf("(%s: %s) -> ", current->key, current->value);
        current = current->next;
      }
      printf("NULL\n");
    }
  }
}
