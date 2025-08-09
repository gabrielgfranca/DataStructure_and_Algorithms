//-------------------------------
//       Red-Black Tree
//-------------------------------
/*
Like the AVL Tree, the red-black tree is also a self-balancing binary search
tree. It maintains balance through a set of properties that ensure the tree
remains approximately balanced after insertions and deletions. The red-black
tree allows for efficient search, insertion, and deletion operations while
ensuring that the longest path from the root to a leaf is no more than twice as
long as the shortest path. The properties of a red-black tree include:
1. Each node is either red or black.
2. The root is always black.
3. All the leaves are black (NULL nodes).
4. If a node is red, its children must be black.
5. Cannot have two red nodes that are adjacent.
6. Every path from a node to its descendant NULL nodes must have the same number
of black nodes.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
  int key;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
  Color color;
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
  newNode->parent = NULL;
  newNode->color = RED;
  return newNode;
}

Node* rotationLL(Node* node) {
  Node* tmp = node->left;
  node->left = tmp->right;
  if (tmp->right) tmp->right->parent = node;

  tmp->parent = node->parent;
  if (!node->parent)
    node = tmp;
  else {
    if (node == node->parent->left)
      node->parent->left = tmp;
    else
      node->parent->right = tmp;
  }
  tmp->right = node;
  node->parent = tmp;
  return tmp;
}

Node* rotationRR(Node* node) {
  Node* tmp = node->right;
  node->right = tmp->left;
  if (tmp->left) tmp->left->parent = node;

  tmp->parent = node->parent;
  if (!node->parent)
    node = tmp;
  else {
    if (node == node->parent->left)
      node->parent->left = tmp;
    else
      node->parent->right = tmp;
  }
  tmp->left = node;
  node->parent = tmp;
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

void fixInsert(Node** rootRef, Node* node) {
  while (node != NULL && node->parent != NULL && node->parent->color == RED) {
    Node* parent = node->parent;
    Node* grandParent = parent->parent;

    if (grandParent == NULL) break;  // root

    if (parent == grandParent->left) {
      Node* uncle = grandParent->right;
      if (uncle && uncle->color == RED) {
        // Case 1: uncle is red
        grandParent->color = RED;
        parent->color = BLACK;
        uncle->color = BLACK;
        node = grandParent;
      } else {
        // Case 2: node is right child
        if (node == parent->right) {
          node = parent;
          rotationRR(node);
          parent = node->parent;
        }
        // Case 3: node is left child
        rotationLL(grandParent);
        parent->color = BLACK;
        grandParent->color = RED;
        node = parent;
      }
    } else {
      // Parent is right child
      Node* uncle = grandParent->left;

      if (uncle && uncle->color == RED) {
        // Case 1 mirrored: uncle is red
        grandParent->color = RED;
        parent->color = BLACK;
        uncle->color = BLACK;
        node = grandParent;
      } else {
        // Case 2 mirrored: node is left child
        if (node == parent->left) {
          node = parent;
          rotationLL(node);
          parent = node->parent;
        }
        // Case 3 mirrored: node is right child
        rotationRR(grandParent);
        parent->color = BLACK;
        grandParent->color = RED;
        node = parent;
      }
    }
  }
  // Fix the root and ensure it's black
  while ((*rootRef)->parent != NULL) *rootRef = (*rootRef)->parent;
  (*rootRef)->color = BLACK;
}

Node* insertNode(Node* root, int key) {
  if (root == NULL) {
    Node* newNode = createNode(key);
    newNode->color = BLACK;  // root is always black
    return newNode;
  }

  Node* inserted = NULL;
  if (key < root->key) {
    root->left = insertNode(root->left, key);
    root->left->parent = root;
    inserted = root->left;
  } else if (key > root->key) {
    root->right = insertNode(root->right, key);
    root->right->parent = root;
    inserted = root->right;
  } else {
    return root;
  }
  fixInsert(&root, inserted);
  return root;
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
  } else if (key > root->key) {
    root->right = removeNode(root->right, key);
  } else {
    // Case 1: Leaf
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    }
    // Case 2: One child
    else if (root->left == NULL) {
      Node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node* temp = root->left;
      free(root);
      return temp;
    }
    // Case 3: Two children
    else {
      Node* minRight = minNode(root->right);
      root->key = minRight->key;
      root->right = removeNode(root->right, minRight->key);
    }
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
