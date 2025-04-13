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

void level_order(Node *root)
{
  Queue q;
  create(&q, 100);

  printf("%d ", root -> data);
  enqueue(&q, root);

  while (!is_empty(q)) {
    root = dequeue(&q);
    
    if (root -> lchild) {
      printf("%d ", root -> lchild -> data);
      enqueue(&q, root -> lchild);
    }

    if (root -> rchild) {
      printf("%d ", root -> rchild -> data);
      enqueue(&q, root -> rchild);
    }
  }
}

int main(int argc, char **argv) {
  tree_create();

  level_order(root);

  return 0;
}
