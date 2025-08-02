//-------------------------------
//      Binary Search Tree
//-------------------------------
/*
- A tree is a hierarchical data structure composed of nodes.
- Each node contains a key and references to its left and right children.
- A Binary Search Tree (BST) is a tree where:
  - The key of the left child is less than the parent node's key.
  - The key of the right child is greater than the parent node's key.
- A BST allows efficient operations such as search, insertion, and deletion.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node* left;
  struct Node* right;
} Node;

Node* createNode(int key) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* insertNode(Node* node, int key) {
  if (node == NULL) return createNode(key);
  if (key < node->key) {
    node->left = insertNode(node->left, key);
  } else {
    node->right = insertNode(node->right, key);
  }
  return node;
}

Node* getRoot(Node* root) { return root; }

void inOrderTraversal(Node* node) {
  if (node != NULL) {
    inOrderTraversal(node->left);
    printf("%d ", node->key);
    inOrderTraversal(node->right);
  }
}

void preOrderTraversal(Node* node) {
  if (node != NULL) {
    printf("%d ", node->key);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
  }
}

void postOrderTraversal(Node* node) {
  if (node != NULL) {
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%d ", node->key);
  }
}
