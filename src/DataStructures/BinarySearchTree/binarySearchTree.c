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

#include <stdbool.h>
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

Node* minNode(Node* node) {
  Node* current = node;
  while (current != NULL && current->left != NULL) {
    current = current->left;
  }
  return current;
}

Node* maxNode(Node* node) {
  Node* current = node;
  while (current != NULL && current->right != NULL) {
    current = current->right;
  }
  return current;
}

bool searchNode(Node* node, int key) {
  if (node == NULL) return false;
  if (key == node->key) return true;

  if (key < node->key) {
    return searchNode(node->left, key);
  } else {
    return searchNode(node->right, key);
  }
}

Node* removeNode(Node* root, int key) {
  if (root == NULL) return NULL;

  if (key < root->key) {
    root->left = removeNode(root->left, key);
    return root;
  } else if (key > root->key) {
    root->right = removeNode(root->right, key);
    return root;
  }

  // handle 3 special conditions
  // 1 - a leaf node
  // 2 - a node with only 1 child
  // 3 - a node with 2 children
  // case 1
  if (root->left == NULL && root->right == NULL) {
    free(root);
    return NULL;
  }
  // Case 2
  if (root->left == NULL) {
    Node* temp = root->right;
    free(root);
    return temp;
  } else if (root->right == NULL) {
    Node* temp = root->left;
    free(root);
    return temp;
  }
  // Case 3
  Node* minRight = minNode(root->right);
  root->key = minRight->key;
  root->right = removeNode(root->right, minRight->key);
  return root;
}

void freeTree(Node* node) {
  if (node != NULL) {
    freeTree(node->left);
    freeTree(node->right);
    free(node);
  }
}