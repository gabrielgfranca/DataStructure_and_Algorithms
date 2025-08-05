#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <stdbool.h>

typedef struct Node {
  int key;
  struct Node* left;
  struct Node* right;
} Node;

Node* createNode(int key);
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