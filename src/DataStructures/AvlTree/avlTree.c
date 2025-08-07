//-------------------------------
//          AVL Tree
//-------------------------------
/*
An AVL Tree is a self-balancing Binary Search Tree where:
    - The tree tries to maintain balance after every insertion or deletion.
    - The height of the left and right subtrees of any node differ by at most
one. AVL Trees allow efficient operations such as search, insertion, and
deletion while maintaining balance.
*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  UNBALANCED_RIGHT = 1,
  SLIGHTLY_UNBALANCED_RIGHT = 2,
  BALANCED = 3,
  SLIGHTLY_UNBALANCED_LEFT = 4,
  UNBALANCED_LEFT = 5
} BalanceFactor;

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

int getHeight(Node* node) {
  if (node == NULL) return 0;
  return fmax(getHeight(node->left), getHeight(node->right)) + 1;
}

int getBalanceFactor(Node* node) {
  if (node == NULL) return 0;
  const int heightDifference = getHeight(node->left) - getHeight(node->right);
  switch (heightDifference) {
    case -2:
      return UNBALANCED_RIGHT;
    case -1:
      return SLIGHTLY_UNBALANCED_RIGHT;
    case 1:
      return SLIGHTLY_UNBALANCED_LEFT;
    case 2:
      return UNBALANCED_LEFT;
    default:
      return BALANCED;
  }
}

Node* rotationLL(Node* node) {
  Node* tmp = node->left;
  node->left = tmp->right;
  tmp->right = node;
  return tmp;
}

Node* rotationRR(Node* node) {
  Node* tmp = node->right;
  node->right = tmp->left;
  tmp->left = node;
  return tmp;
}

Node* rotationLR(Node* node) {
  node->left = rotationRR(node->left);
  return rotationLL(node);
}

Node* rotationRL(Node* node) {
  node->right = rotationLL(node->right);
  return rotationRR(node);
}

Node* insertNode(Node* node, int key) {
  if (node == NULL)
    return createNode(key);
  else if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor == UNBALANCED_LEFT) {
    if (key < node->left->key)
      return rotationLL(node);
    else
      return rotationLR(node);
  } else if (balanceFactor == UNBALANCED_RIGHT) {
    if (key > node->right->key)
      return rotationRR(node);
    else
      return rotationRL(node);
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

  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor == UNBALANCED_LEFT) {
    if (getBalanceFactor(root->left) == BALANCED ||
        getBalanceFactor(root->left) == SLIGHTLY_UNBALANCED_LEFT) {
      return rotationLL(root);
    }
    if (getBalanceFactor(root->left) == SLIGHTLY_UNBALANCED_RIGHT)
      return rotationLR(root);
  }
  if (balanceFactor == UNBALANCED_RIGHT) {
    if (getBalanceFactor(root->right) == BALANCED ||
        getBalanceFactor(root->right) == SLIGHTLY_UNBALANCED_RIGHT)
      return rotationRR(root);
    if (getBalanceFactor(root->right) == SLIGHTLY_UNBALANCED_LEFT)
      return rotationRL(root);
  }
  return root;
}

void freeTree(Node* node) {
  if (node != NULL) {
    freeTree(node->left);
    freeTree(node->right);
    free(node);
  }
}
