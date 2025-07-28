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

typedef struct BinarySearchTree {
  Node* root;
} BinarySearchTree;

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

void initTree(BinarySearchTree* tree) { tree->root = NULL; }

void insertNode(Node* current, int key) {
  if (key < current->key) {
    if (current->left == NULL) {
      current->left = createNode(key);
    } else {
      insertNode(current->left, key);
    }
  } else {
    if (current->right == NULL) {
      current->right = createNode(key);
    } else {
      insertNode(current->right, key);
    }
  }
}

void insert(BinarySearchTree* tree, int key) {
  if (tree->root == NULL) {
    tree->root = createNode(key);
  } else {
    insertNode(tree->root, key);
  }
}

Node* getRoot(BinarySearchTree* tree) { return tree->root; }