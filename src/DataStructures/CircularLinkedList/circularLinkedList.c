//-------------------------------
//     Circular Linked List
//-------------------------------

/*
- A circular linked list is a variation of a linked list where the last node
points back to the first node, forming a circle.
- This structure allows for continuous traversal of the list without reaching a
null pointer, making it useful for applications that require a circular
iteration over the elements.
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
  if (head == NULL) return 0;
  int count = 1;
  Node *current = head->next;
  while (current != head) {
    count++;
    current = current->next;
  }
  return count;
}

void insertAtBeginning(Node **head, int data) {
  Node *node = createNode(data);
  if (!node) return;
  if (*head == NULL) {
    node->next = node;
    *head = node;
  } else {
    Node *tail = *head;
    while (tail->next != *head) tail = tail->next;
    node->next = *head;
    tail->next = node;
    *head = node;
  }
}

void insertAtEnd(Node **head, int data) {
  Node *node = createNode(data);
  if (!node) return;
  if (*head == NULL) {
    node->next = node;
    *head = node;
  } else {
    Node *tail = *head;
    while (tail->next != *head) tail = tail->next;
    tail->next = node;
    node->next = *head;
  }
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
  if (temp->next == *head) {
    free(temp);
    *head = NULL;
    return;
  }
  Node *tail = *head;
  while (tail->next != *head) tail = tail->next;
  tail->next = (*head)->next;
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
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }
  printf("Circular Linked List: ");
  Node *temp = head;
  do {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("\n");
}

Node *getTail(Node *head) {
  if (head == NULL) return NULL;
  Node *temp = head;
  while (temp->next != head) temp = temp->next;
  return temp;
}

Node *getHead(Node *head) { return head; }