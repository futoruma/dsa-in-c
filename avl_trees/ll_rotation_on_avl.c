#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node * lchild;
  int data;
  int height;
  struct Node * rchild;
} Node;

Node * root = NULL;

int node_height(Node * p)
{
  int hl, hr;
  hl = p && p -> lchild ? p -> lchild -> height : 0;
  hr = p && p -> rchild ? p -> rchild -> height : 0;

  return hl > hr ? hl + 1 : hr + 1;
}

int balance_factor(Node * p)
{
  int hl, hr;
  hl = p && p -> lchild ? p -> lchild -> height : 0;
  hr = p && p -> rchild ? p -> rchild -> height : 0;

  return hl - hr;
}

Node * ll_rotation(Node * p)
{
  Node * pl = p -> lchild;
  Node * plr = pl -> rchild;

  pl -> rchild = p;
  p -> lchild = plr;
  p -> height = node_height(p);
  pl -> height = node_height(pl);

  if (root == p)
    root = pl;

  return pl;
}

Node * lr_rotation(Node * p)
{
  Node * pl = p -> lchild;
  Node * plr = pl -> rchild;

  pl -> rchild = plr -> lchild;
  p -> lchild = plr -> rchild;

  plr -> lchild = pl;
  plr -> rchild = p;

  pl -> height = node_height(pl);
  p -> height = node_height(p);
  plr -> height = node_height(plr);

  if (root == p)
    root = plr;
  
  return plr;
}

Node * rr_rotation(Node * p)
{
  return NULL;
}

Node * rl_rotation(Node * p)
{
  return NULL;
}

Node * r_insert(Node * p, int key)
{
  Node * t = NULL;

  if (p == NULL) {
    t = (Node * ) malloc(sizeof(Node));
    t -> data = key;
    t -> height = 1;
    t -> lchild = t -> rchild = NULL;
    return t;
  }

  if (key < p -> data)
    p -> lchild = r_insert(p -> lchild, key);
  else if (key > p -> data)
    p -> rchild = r_insert(p -> rchild, key);

  p -> height = node_height(p);

  if (balance_factor(p) == 2 && balance_factor(p -> lchild) == 1)
    return ll_rotation(p);
  else if (balance_factor(p) == 2 && balance_factor(p -> lchild) == -1)
    return lr_rotation(p);
  else if (balance_factor(p) == -2 && balance_factor(p -> rchild) == -1)
    return rr_rotation(p);
  else if (balance_factor(p) == -2 && balance_factor(p -> rchild) == 1)
    return rl_rotation(p);
  
  return p;
}

int main(int argc, char **argv)
{
  root = r_insert(root, 50);
  r_insert(root, 10);
  r_insert(root, 20);

  return 0;
}
