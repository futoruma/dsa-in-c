#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} Node;

Node * node_init(int key)
{
  Node *new_node = (Node *) malloc(sizeof(Node));
  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

Node * node_search(Node *root, int key)
{
  if (root == NULL) {
    return NULL;
  }

  if (root->key > key) {
    return node_search(root->left, key);
  }
  else if (root->key < key) {
    return node_search(root->right, key);
  }
  else {
    return root;
  }
}

Node * node_insert(Node *root, int key)
{
  if (root == NULL) {
    root = node_init(key);
  }
  else if (root->key > key) {
    root->left = node_insert(root->left, key);
  }
  else if (root->key < key) {
    root->right = node_insert(root->right, key);
  }

  return root;
}

Node * tree_rotate_right(Node *root)
{
  Node *a = root->left;
  Node *b = a->right;
  
  a->right = root;
  root->left = b;

  return a;
}

Node * tree_rotate_left(Node *root)
{
  Node *a = root->right;
  Node *b = a->left;

  a->left = root;
  root->right = b;

  return a;
}

size_t tree_get_height(Node *root)
{
  Node * queue[256];
  size_t l = 0;
  size_t r = 0;

  queue[r] = root;
  r++;

  size_t height = -1;
  
  size_t queue_len;
  while (l < r) {
    queue_len = r - l;

    for (size_t i = 0; i < queue_len; ++i) {
      if (queue[l] != NULL) {
        queue[r] = queue[l]->left;
        r++;
        queue[r] = queue[l]->right;
        r++;
      }

      l++;
    }

    height++;
  }

  return height;
}

void tree_print(Node *root)
{
  Node * queue[256];
  size_t l = 0;
  size_t r = 0;

  queue[r] = root;
  r++;

  size_t queue_len;
  while (l < r) {
    queue_len = r - l;

    for (size_t i = 0; i < queue_len; ++i) {
      if (queue[l] == NULL) {
        printf("N ");
      }
      else {
        printf("%d ", queue[l]->key);
        
        queue[r] = queue[l]->left;
        r++;
        queue[r] = queue[l]->right;
        r++;
      }

      l++;
    }

    printf("\n");
  }
}

Node * tree_balance(Node *root)
{
  size_t h1 = tree_get_height(root->left) - tree_get_height(root->right);

  if (h1 == 2) {
    size_t h2 = tree_get_height(root->left->right) - tree_get_height(root->left->left);
    if (h2 > 0) {
      root->left = tree_rotate_left(root->left);
    }

    root = tree_rotate_right(root);
  }

  else if (h1 == -2) {
    size_t h3 = tree_get_height(root->right->left) - tree_get_height(root->right->right);
    if (h3 > 0) {
      root->right = tree_rotate_right(root->right);
    }

    root = tree_rotate_left(root);
  }

  return root;
}

Node * node_insert_and_balance(Node *root, int key)
{
  if (root == NULL) {
    root = node_init(key);
  }
  else if (root->key > key) {
    root->left = node_insert_and_balance(root->left, key);
  }
  else if (root->key < key) {
    root->right = node_insert_and_balance(root->right, key);
  }

  root = tree_balance(root);

  return root;
}

int main()
{
  Node *root = node_init(6);
  root->left = node_init(3);
  root->right = node_init(9);
  root->left->left = node_init(1);
  root->left->right = node_init(5);

  root = node_insert_and_balance(root, 4);
  root = node_insert_and_balance(root, 8);

  tree_print(root);
  
  return 0;
}

