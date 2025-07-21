#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef struct DoublyNode {
  int data;
  struct DoublyNode *next;
  struct DoublyNode *prev;
} DoublyNode;

DoublyNode *createNode(int data);
int size(DoublyNode *head);
void insertAtBeginning(DoublyNode **head, int data);
void insertAtEnd(DoublyNode **head, int data);
void insertAtPosition(DoublyNode **head, int data, int position);
void deleteAtBeginning(DoublyNode **head);
void deleteAtEnd(DoublyNode **head);
void deleteAtPosition(DoublyNode **head, int position);
void clearList(DoublyNode **head);
void printListForward(DoublyNode *head);
void printListBackward(DoublyNode *head);
DoublyNode *getTail(DoublyNode *head);
DoublyNode *getHead(DoublyNode *head);

#endif