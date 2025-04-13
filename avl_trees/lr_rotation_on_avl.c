#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
  struct Node * lchild;
  int data;
  int bf;
  struct Node * rchild;
} Node;

Node * root = NULL;

int height(Node * p)
{
  int x = 0, y = 0;

  if (!p) return 0;

  x = height(p -> lchild);
  y = height(p -> rchild);
  
  return x > y ? x + 1 : y + 1;
}

void insert(int key)
{
  Node *t = root;
  Node *r = NULL, *p;

  if (root == NULL) {
    p = (Node * ) malloc(sizeof(Node));
    p -> data = key;
    p -> bf = 0;
    p -> lchild = p -> rchild = NULL;
    root = p;
    return;
  }

  while (t != NULL) {
    r = t;
    if (key < t -> data)
      t = t -> lchild;
    else if (key > t -> data)
      t = t -> rchild;
    else
      return;
  }

  p = (Node * ) malloc(sizeof(Node));
  p -> data = key;
  p -> lchild = p -> rchild = NULL;

  if (key < r -> data) r -> lchild = p;
  else r -> rchild = p;
}

Node * ll_rotation(Node * p)
{
  int lbf, rbf;

  Node * pl = p -> lchild;
  pl -> bf = 0;
  p -> lchild = pl -> rchild;
  pl -> rchild = p;
  lbf = height(p -> lchild) + 1;
  rbf = height(p -> rchild) + 1;
  p -> bf = lbf - rbf;

  if (p == root) root = pl;
  
  return pl;
}

Node * lr_rotation(Node * p)
{
  int lbf, rbf;

  Node * pl = p -> lchild;
  Node * plr = pl -> rchild;
  plr -> bf = 0;

  p -> lchild = plr -> rchild;
  pl -> rchild = plr -> lchild;
  plr -> lchild = pl;
  plr -> rchild = p;
  lbf = height(p -> lchild) + 1;
  rbf = height(p -> rchild) + 1;
  p -> bf = lbf - rbf;

  lbf = height(pl -> lchild) + 1;
  rbf = height(pl -> rchild) + 1;
  pl -> bf = lbf - rbf;
  
  if (p == root) root = plr;
  
  return plr;
}

Node * rr_rotation(Node * p)
{
  int lbf, rbf;
  
  Node * pr = p -> rchild;
  pr -> bf = 0;
  p -> rchild = pr -> lchild;
  pr -> lchild = p;
  lbf = height(p -> lchild) + 1;
  rbf = height(p -> rchild) + 1;
  p -> bf = lbf - rbf;
  
  if (p == root) root = pr;
  
  return pr;
}

Node * rl_rotation(Node * p)
{
  int lbf, rbf;
  
  Node * pr = p -> rchild;
  Node * prl = pr -> lchild;
  prl -> bf = 0;

  p -> rchild = prl -> lchild;
  pr -> lchild = prl -> rchild;
  prl -> rchild = pr;
  prl -> lchild = p;
  lbf = height(p -> lchild) + 1;
  rbf = height(p -> rchild) + 1;
  p -> bf = lbf - rbf;

  lbf = height(pr -> lchild) + 1;
  rbf = height(pr -> rchild) + 1;
  pr -> bf = lbf - rbf;
  
  if (p == root) root = prl;
  
  return prl;
}

Node * r_insert(Node * p, int key)
{
  Node * t;
  int lbf, rbf;
  
  if (p == NULL) {
    t = (Node * ) malloc(sizeof(Node));
    t -> data = key;
    t -> bf = 0;
    t -> lchild = t -> rchild = NULL;
    
    return t;
  }

  if (key < p -> data)
    p -> lchild = r_insert(p -> lchild, key);
  else if (key > p -> data)
    p -> rchild = r_insert(p -> rchild, key);

  lbf = height(p -> lchild) + 1;
  rbf = height(p -> rchild) + 1;
  p -> bf = lbf - rbf;
  
  if (p -> bf == 2 && p -> lchild -> bf == 1)
    return ll_rotation(p);

  if (p -> bf == 2 && p -> lchild -> bf == -1)
    return lr_rotation(p);

  if (p -> bf == -2 && p -> rchild -> bf == -1)
    return rr_rotation(p);

  if (p -> bf == -2 && p -> rchild -> bf == 1)
    return rl_rotation(p);

  return p;
}

void inorder(Node * p)
{
  if (p) {
    inorder(p -> lchild);
    printf("%d ", p -> data);
    inorder(p -> rchild);
  }
}

Node * search(int key)
{
  Node * t = root;

  while (t != NULL) {
    if (key == t -> data)
      return t;
    else if (key < t -> data)
      t = t -> lchild;
    else
      t = t -> rchild;
  }

  return NULL;
}

int main(int argc, char **argv)
{
  Node *tmp;

  insert(30);
  r_insert(root, 55);
  r_insert(root, 4);
  r_insert(root, 204);
  r_insert(root, 105);
  r_insert(root, 462);
  r_insert(root, 2);

  inorder(root);
  printf("\n");

  tmp = search(2);
  if (tmp != NULL)
    printf("Element %d is found.\n", tmp -> data);
  else
    printf("Element is not found.\n");

  return 0;
}
