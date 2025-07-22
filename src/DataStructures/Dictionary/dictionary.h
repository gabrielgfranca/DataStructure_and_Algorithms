#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

typedef struct Dictionary {
  char **key;
  char **value;
  int size;
  int capacity;
} Dictionary;

Dictionary *createDictionary();
bool isEmpty(Dictionary *dict);
int size(Dictionary *dict);
bool resize(Dictionary *dict);
int hasKey(Dictionary *dict, const char *key);
void set(Dictionary *dict, const char *key, const char *value);
void *getValue(Dictionary *dict, const char *key);
bool remove(Dictionary *dict, const char *key);
void clear(Dictionary *dict);
void keys(Dictionary *dict);
void values(Dictionary *dict);
void keysValues(Dictionary *dict);
void printDict(Dictionary *dict);

#endif