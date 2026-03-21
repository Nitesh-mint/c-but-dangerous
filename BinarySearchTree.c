#include <stdio.h>
#include <stdlib.h>

struct Node {
  int number;
  struct Node *left;
  struct Node *right;
};

struct Node *getSuccessor(struct Node *node) {
  struct Node *currentNode = node->right;

  if (node == NULL) {
    return NULL;
  }
  while (currentNode != NULL && currentNode->left != NULL) {
    currentNode = currentNode->left;
  }
  return currentNode;
};

struct Node *createNode(int number) {
  struct Node *node = malloc(sizeof(struct Node));
  node->number = number;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void BST_INIT(struct Node *node, int number) {
  if (node == NULL) {
    printf("Can't initialize the tree. The nod is null");
    return;
  }

  node->number = number;
  node->left = NULL;
  node->right = NULL;

  printf("Struct initialized succesfully\n");
}

int BST_SEARCH(struct Node *node, int number) {
  if (node == NULL) {
    printf("The node is null\n");
    return 0;
  }
  if (number == node->number) {
    return number;
  }
  if (number > node->number) {
    return BST_SEARCH(node->right, number);
  } else {
    return BST_SEARCH(node->left, number);
  }
  return 0;
}

void BST_INSERT(struct Node *node, int number) {

  if (node == NULL) {
    printf("The node is null\n");
    return;
  }

  if (number == node->number) {
    printf("The number is already present in the tree");
    return; // number already exists
  }

  if (number > node->number) {
    if (node->right != NULL) {
      BST_INSERT(node->right, number);
    } else {
      node->right = malloc(sizeof(struct Node));
      node->right->number = number;
      node->right->left = node->right->right = NULL;
      printf("%d is succesfully inserted in the tree\n", number);
    }
  } else {
    if (node->left != NULL) {
      BST_INSERT(node->left, number);
    } else {
      node->left = malloc(sizeof(struct Node));
      node->left->number = number;
      node->left->left = node->left->right = NULL;
      printf("%d is succesfully inserted in the tree\n", number);
    }
  }
  return;
};

// need to rewrite this completely
void BST_DELETE(struct Node *node, int number) {
  if (node == NULL) {
    return;
  }
  if (node->number == number) {
    struct Node *successor = getSuccessor(node);
    node->number = successor->number;
    free(successor);
    return;
  }
  if (number > node->number) {
    BST_DELETE(node->right, number);
  }
  if (number < node->number) {
    BST_DELETE(node->left, number);
  }
};

void BST_PRINT(struct Node *node) {
  if (node == NULL) {
    printf("There is no node in the tree\n");
    return;
  }
  // struct Node *currentNode = node;
  // while ()
}

int main(void) {
  struct Node *node = malloc(sizeof(struct Node));
  BST_INIT(node, 44);
  BST_INSERT(node, 50);
  BST_INSERT(node, 20);
  BST_INSERT(node, 1);
  printf("The number %d is in the list \n", BST_SEARCH(node, 1));
  BST_DELETE(node, 44);
  printf("The number %d is in the list \n", BST_SEARCH(node, 44));
  return 0;
}
