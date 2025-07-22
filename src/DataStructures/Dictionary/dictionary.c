//-------------------------------
//         Dictionary
//-------------------------------
/*
- Dictionary is a data structure that stores key-value pairs.
- It allows for efficient retrieval, insertion, and deletion of key-value pairs.
- It is recommended to use string or char as keys, and any data type as values.
- Dictionaries are often implemented using hash tables or trees.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

typedef struct Dictionary {
  char **key;
  char **value;
  int size;
  int capacity;
} Dictionary;

Dictionary *createDictionary() {
  Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
  if (dict == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  dict->key = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
  dict->value = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
  if (dict->key == NULL || dict->value == NULL) {
    printf("Memory allocation failed.\n");
    free(dict->key);
    free(dict->value);
    free(dict);
    return NULL;
  }
  dict->size = 0;
  dict->capacity = INITIAL_CAPACITY;
  return dict;
}

bool isEmpty(Dictionary *dict) {
  if (dict == NULL) return true;
  return dict->size == 0;
}

int size(Dictionary *dict) {
  if (isEmpty(dict)) return 0;
  return dict->size;
}

bool resize(Dictionary *dict) {
  if (dict == NULL) return false;
  int newCapacity = dict->capacity * 2;
  char **newKey = (char **)malloc(newCapacity * sizeof(char *));
  char **newValue = (char **)malloc(newCapacity * sizeof(char *));
  if (newKey == NULL || newValue == NULL) {
    printf("Failed to resize dictionary.\n");
    free(newKey);
    free(newValue);
    return false;
  }
  for (int i = 0; i < dict->size; i++) {
    newKey[i] = dict->key[i];
    newValue[i] = dict->value[i];
  }
  free(dict->key);
  free(dict->value);
  dict->key = newKey;
  dict->value = newValue;
  dict->capacity = newCapacity;
  return true;
}

int hasKey(Dictionary *dict, const char *key) {
  if (dict == NULL || key == NULL) return -1;
  for (int i = 0; i < dict->size; i++) {
    if (strcmp(dict->key[i], key) == 0) {
      return i;
    }
  }
  return -1;
}

void set(Dictionary *dict, const char *key, const char *value) {
  int index = hasKey(dict, key);
  if (index != -1) {
    free(dict->value[index]);
    dict->value[index] = strdup(value);
    return;
  }
  if (dict->size >= dict->capacity) {
    if (!resize(dict)) return;
  }
  dict->key[dict->size] = strdup(key);
  dict->value[dict->size] = value;
  dict->size++;
}

void *getValue(Dictionary *dict, const char *key) {
  int index = hasKey(dict, key);
  if (index == -1) {
    printf("Key '%s' not found in dictionary.\n", key);
    return NULL;
  }
  return dict->value[index];
}

bool remove(Dictionary *dict, const char *key) {
  int index = hasKey(dict, key);
  if (index == -1) {
    printf("Key '%s' not found in dictionary.\n", key);
    return false;
  }
  free(dict->key[index]);
  free(dict->value[index]);
  for (int i = index; i < dict->size - 1; i++) {
    dict->key[i] = dict->key[i + 1];
    dict->value[i] = dict->value[i + 1];
  }
  dict->size--;
  return true;
}

void clear(Dictionary *dict) {
  if (dict == NULL) return;
  for (int i = 0; i < dict->size; i++) {
    free(dict->key[i]);
    free(dict->value[i]);
  }
  free(dict->key);
  free(dict->value);
  free(dict);
}

void keys(Dictionary *dict) {
  if (dict == NULL || isEmpty(dict)) {
    printf("Dictionary is empty.\n");
    return;
  }
  printf("keys -> [");
  for (int i = 0; i < dict->size; i++) {
    printf("\"%s\"", dict->key[i]);
    if (i != dict->size - 1) printf(", ");
  }
  printf("]\n");
}

void values(Dictionary *dict) {
  if (dict == NULL || isEmpty(dict)) {
    printf("Dictionary is empty.\n");
    return;
  }
  printf("values -> [");
  for (int i = 0; i < dict->size; i++) {
    printf("\"%s\"", dict->value[i]);
    if (i != dict->size - 1) printf(", ");
  }
  printf("]\n");
}

void keysValues(Dictionary *dict) {
  if (dict == NULL || isEmpty(dict)) {
    printf("Dictionary is empty.\n");
    return;
  }
  for (int i = 0; i < dict->size; i++) {
    printf("%s : %s\n", dict->key[i], dict->value[i]);
  }
}

void printDict(Dictionary *dict) {
  if (dict == NULL || isEmpty(dict)) {
    printf("Dictionary is empty.\n");
    return;
  }
  for (int i = 0; i < dict->size; i++) {
    printf("Key: %s, Value: %s\n", dict->key[i], dict->value[i]);
  }
}
