//-------------------------------
//      Doubly Linked List
//-------------------------------

/*
- A doubly linked list is a bit more complex than singly linked list. In it,
each node contains three parts: the data, a pointer to the next node, and one
extra pointer which points to the previous node. This allows for traversal in
both directions, making it more versatile than a singly linked list.
- Doubly Linked lists do not store nodes in contiguous memory locations.
Instead, each node contains pointer to the next node and previous one.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyNode {
  int data;
  struct DoublyNode *next;
  struct DoublyNode *prev;
} DoublyNode;

DoublyNode *createNode(int data) {
  DoublyNode *node = (DoublyNode *)malloc(sizeof(DoublyNode));
  if (node == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

int size(DoublyNode *head) {
  int count = 0;
  DoublyNode *current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

void insertAtBeginning(DoublyNode **head, int data) {
  DoublyNode *node = createNode(data);
  if (!node) return;
  if (*head == NULL) {
    *head = node;
  } else {
    node->next = *head;
    (*head)->prev = node;
    *head = node;
  }
}

void insertAtEnd(DoublyNode **head, int data) {
  DoublyNode *node = createNode(data);
  if (!node) return;
  if (*head == NULL) {
    *head = node;
    return;
  }
  DoublyNode *temp = *head;
  while (temp->next != NULL) temp = temp->next;
  temp->next = node;
  node->prev = temp;
}

void insertAtPosition(DoublyNode **head, int data, int position) {
  if (position < 1) {
    printf("Position should be >= 1\n");
    return;
  }
  if (position == 1) {
    insertAtBeginning(head, data);
    return;
  }
  DoublyNode *node = createNode(data);
  if (!node) return;
  DoublyNode *temp = *head;
  for (int i = 1; temp != NULL && i < position - 1; i++) temp = temp->next;
  if (temp == NULL) {
    printf("Position greater than the number of nodes.\n");
    free(node);
    return;
  }
  node->next = temp->next;
  node->prev = temp;
  if (temp->next != NULL) temp->next->prev = node;
  temp->next = node;
}

void deleteAtBeginning(DoublyNode **head) {
  if (*head == NULL) {
    printf("The list is already empty.\n");
    return;
  }
  DoublyNode *temp = *head;
  *head = (*head)->next;
  if (*head) (*head)->prev = NULL;
  free(temp);
}

void deleteAtEnd(DoublyNode **head) {
  if (*head == NULL) {
    printf("The list is already empty.\n");
    return;
  }
  DoublyNode *temp = *head;
  if (temp->next == NULL) {
    *head = NULL;
    free(temp);
    return;
  }
  while (temp->next != NULL) temp = temp->next;
  temp->prev->next = NULL;
  free(temp);
}

void deleteAtPosition(DoublyNode **head, int position) {
  if (*head == NULL) {
    printf("The list is already empty.\n");
    return;
  }
  if (position == 1) {
    deleteAtBeginning(head);
    return;
  }
  DoublyNode *temp = *head;
  for (int i = 1; temp != NULL && i < position; i++) temp = temp->next;
  if (temp == NULL) {
    printf("Position greater than the number of nodes.\n");
    return;
  }
  if (temp == *head) {
    *head = temp->next;
    if (*head) (*head)->prev = NULL;
  } else {
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;
  }
  free(temp);
}

void clearList(DoublyNode **head) {
  while (*head != NULL) {
    deleteAtBeginning(head);
  }
}

void printListForward(DoublyNode *head) {
  DoublyNode *temp = head;
  printf("List forward: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void printListBackward(DoublyNode *head) {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }
  DoublyNode *temp = head;
  while (temp->next != NULL) temp = temp->next;
  printf("List backward: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}

DoublyNode *getTail(DoublyNode *head) {
  if (head == NULL) return NULL;
  DoublyNode *temp = head;
  while (temp->next != NULL) temp = temp->next;
  return temp;
}

DoublyNode *getHead(DoublyNode *head) { return head; }
