#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>

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

unsigned long djb2HashCode(const char *str);
int getHashIndex(const char *key, int capacity);
HashMap *createHashMap();
bool resizeHashMap(HashMap *map);
bool isEmpty(HashMap *map);
int size(HashMap *map);
void setHash(HashMap *map, const char *key, const char *value);
char *getHash(HashMap *map, const char *key);
bool deleteHash(HashMap *map, const char *key);
void clearHashMap(HashMap *map);
void printHashMap(HashMap *map);

#endif