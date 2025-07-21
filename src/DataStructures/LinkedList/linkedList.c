//-------------------------------
//        Linked List
//-------------------------------

/*
- A linked list or singly linked list is a linear data structure that is made up
of a group of nodes in which each node has two parts: the data, and the pointer
to the next node. The last node's (also known as tail) pointers point to NULL to
indicate the end of the linked list.
- Linked lists do not store nodes in contiguous memory locations. Instead, each
node contains pointer to the next node
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *createNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  node->data = data;
  node->next = NULL;
  return node;
}

int size(Node *head) {
  int count = 0;
  Node *current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

void insertAtBeginning(Node **head, int data) {
  Node *node = createNode(data);
  if (!node) return;
  node->next = *head;
  *head = node;
}

void insertAtEnd(Node **head, int data) {
  Node *node = createNode(data);
  if (!node) return;
  if (*head == NULL) {
    *head = node;
    return;
  }
  Node *temp = *head;
  while (temp->next != NULL) temp = temp->next;
  temp->next = node;
}

void insertAtPosition(Node **head, int data, int position) {
  if (position < 1) {
    printf("Invalid position.\n");
    return;
  }
  if (position == 1) {
    insertAtBeginning(head, data);
    return;
  }
  Node *temp = *head;
  for (int i = 1; temp != NULL && i < position - 1; i++) temp = temp->next;
  if (temp == NULL) {
    printf("Position is greater than list size.\n");
    return;
  }
  Node *node = createNode(data);
  if (!node) return;
  node->next = temp->next;
  temp->next = node;
}

void deleteAtBeginning(Node **head) {
  if (*head == NULL) {
    printf("List is empty.\n");
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void deleteAtEnd(Node **head) {
  if (*head == NULL) {
    printf("List is empty.\n");
    return;
  }
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }
  Node *temp = *head;
  while (temp->next->next != NULL) temp = temp->next;
  free(temp->next);
  temp->next = NULL;
}

void deleteAtPosition(Node **head, int position) {
  if (*head == NULL || position < 1) {
    printf("Invalid operation.\n");
    return;
  }
  if (position == 1) {
    deleteAtBeginning(head);
    return;
  }
  Node *temp = *head;
  for (int i = 1; temp != NULL && i < position - 1; i++) temp = temp->next;
  if (temp == NULL || temp->next == NULL) {
    printf("Position exceeds list size.\n");
    return;
  }
  Node *toDelete = temp->next;
  temp->next = toDelete->next;
  free(toDelete);
}

void clearList(Node **head) {
  while (*head != NULL) {
    deleteAtBeginning(head);
  }
}

void printList(Node *head) {
  printf("List: ");
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

Node *getTail(Node *head) {
  if (head == NULL) return NULL;
  Node *temp = head;
  while (temp->next != NULL) temp = temp->next;
  return temp;
}

Node *getHead(Node *head) { return head; }