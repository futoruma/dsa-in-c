#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Node *root = NULL;

void tree_create()
{
  Node *p, *t;
  int x;
  Queue q;
  create(&q, 100);

  printf("Enter the root value ");
  scanf("%d", &x);
  root = (Node *) malloc(sizeof(Node));
  root -> data = x;
  root -> lchild = root -> rchild = NULL;
  enqueue(&q, root);

  while (!is_empty(q)) {
    p = dequeue(&q);
    printf("Enter the left child of %d ", p -> data);
    scanf("%d", &x);

    if (x != -1) {
      t = (Node *) malloc(sizeof(Node));
      t -> data = x;
      t -> lchild = t -> rchild = NULL;
      p -> lchild = t;
      enqueue(&q, t);
    }

    printf("Enter the right child of %d ", p -> data);
    scanf("%d", &x);

    if (x != -1) {
      t = (Node *) malloc(sizeof(Node));
      t -> data = x;
      t -> lchild = t -> rchild = NULL;
      p -> rchild = t;
      enqueue(&q, t);
    }
  }
}

void preorder(Node *p)
{
  if (p) {
    printf("%d ", p -> data);
    preorder(p -> lchild);
    preorder(p -> rchild);
  }
}

void inorder(Node *p)
{
  if (p) {
    inorder(p -> lchild);
    printf("%d ", p -> data);
    inorder(p -> rchild);
  }
}

void postorder(Node *p)
{
  if (p) {
    postorder(p -> lchild);
    postorder(p -> rchild);
    printf("%d ", p -> data);
  }
}

int main(int argc, char **argv)
{
  tree_create();
  preorder(root);
  printf("\nPost Order ");
  postorder(root);

  return 0;
}
