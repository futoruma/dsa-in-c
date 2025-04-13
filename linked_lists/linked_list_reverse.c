#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node * next;
} Node;

Node * first = NULL, * second = NULL, * third = NULL;

void display(Node * p)
{
  while (p != NULL) {
    printf("%d ", p -> data);
    p = p -> next;
  }
}

void create(int *A, int n)
{
  int i;
  Node * t, * last;
  
  first = (Node *) malloc(sizeof(Node));
  first -> data = A[0];
  first -> next = NULL;
  last = first;

  for (i = 1; i < n; ++i) {
    t = (Node *) malloc(sizeof(Node));
    t -> data = A[i];
    t -> next = NULL;
    last -> next = t;
    last = t;
  }
}

int count(Node * p)
{
  int l = 0;
  
  while (p) {
    ++l;
    p = p -> next;
  }

  return l;
}

void reverse_one(Node * p)
{
  int * A, i = 0;
  Node * q = p;

  A = (int *) malloc(sizeof(int) * count(p));

  while (q != NULL) {
    A[i] = q -> data;
    q = q -> next;
    ++i;
  }

  q = p;
  --i;
  
  while (q != NULL) {
    q -> data = A[i];
    q = q -> next;
    --i;
  }
}

void reverse_two(Node * p)
{
  Node * q = NULL, * r = NULL;

  while (p != NULL) {
    r = q;
    q = p;
    p = p -> next;
    q -> next = r;
  }

  first = q;
}

void reverse_three(Node * q, Node * p)
{
  if (p) {
    reverse_three(p, p -> next);
    p -> next = q;
  } else
    first = q;
}

int main(int argc, char **argv)
{
  int A[] = {
    510,
    20,
    430,
    505,
    160
  };

  create(A, 5);

  reverse_one(first);
  display(first);

  return 0;
}
