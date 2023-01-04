#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

typedef struct Node {
  int data;
  char color;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
} Node;

Node* newNode(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->color = RED;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  return node;
}

Node* insert(Node* root, int data) {
  if (root == NULL) {
    return newNode(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
    root->left->parent = root;
  } else if (data > root->data) {
    root->right = insert(root->right, data);
    root->right->parent = root;
  }

  return root;
}

Node* search(Node* root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  }

  if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

void inorder(Node* root) {
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void preorder(Node* root) {
  if (root == NULL) {
    return;
  }

  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node* root) {
  if (root == NULL) {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

int main() {
  Node* root = NULL;
  root = insert(root, 7);
  root = insert(root, 3);
  root = insert(root, 18);
  root = insert(root, 10);
  root = insert(root, 22);
  root = insert(root, 8);
  root = insert(root, 11);
  root = insert(root, 26);

  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");

  printf("Preorder traversal: ");
  preorder(root);
  printf("\n");

  printf("Postorder traversal: ");
  postorder(root);
  printf("\n");

  int data ;
  printf("Enter the element:");
  scanf("%d",&data);
  Node* result = search(root, data);
  if (result == NULL) {
    printf("Element %d not found in the tree\n", data);
  } else {
    printf("Element %d found in the tree\n", data);
  }

  return 0;
}