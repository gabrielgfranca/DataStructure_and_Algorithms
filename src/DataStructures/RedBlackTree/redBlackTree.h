#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <stdbool.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
  int key;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
  Color color;
} Node;

Node* createNode(int key);
Node* rotationLL(Node* node);
Node* rotationRR(Node* node);
Node* rotationLR(Node* node);
Node* rotationRL(Node* node);
void fixInsert(Node** rootRef, Node* node);
Node* insertNode(Node* node, int key);
void inOrderTraversal(Node* node);
void preOrderTraversal(Node* node);
void postOrderTraversal(Node* node);
Node* minNode(Node* node);
Node* maxNode(Node* node);
bool searchNode(Node* node, int key);
Node* removeNode(Node* root, int key);
void freeTree(Node* node);

#endif