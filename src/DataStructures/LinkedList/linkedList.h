#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *createNode(int data);
int size(Node *head);
void insertAtBeginning(Node **head, int data);
void insertAtEnd(Node **head, int data);
void insertAtPosition(Node **head, int data, int position);
void deleteAtBeginning(Node **head);
void deleteAtEnd(Node **head);
void deleteAtPosition(Node **head, int position);
void clearList(Node **head);
void printList(Node *head);
Node *getTail(Node *head);
Node *getHead(Node *head);

#endif