#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node * next;
} Node;

Node * top = NULL;

void push(int x)
{
  Node * t;
  t = (Node *) malloc(sizeof(Node));

  if (t == NULL)
    printf("Stack is full\n");
  else {
    t -> data = x;
    t -> next = top;
    top = t;
  }
}

int pop()
{
  Node * t;
  int x = -1;

  if (top == NULL)
    printf("Stack is empty\n");
  else {
    t = top;
    top = top -> next;
    x = t -> data;
    free(t);
  }

  return x;
}

void display()
{
  Node * p;
  p = top;
  
  while (p != NULL) {
    printf("%d ", p -> data);
    p = p -> next;
  }

  printf("\n");
}

int main(int argc, char **argv)
{
  push(130);
  push(202);
  push(15);

  display();

  printf("%d ", pop());

  return 0;
}
