#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char data;
  struct Node * next;
} Node;

Node * top = NULL;

void push(char x)
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

char pop()
{
  Node * t;
  char x = -1;

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

int is_balanced(char * exp)
{
  int i;

  for (i = 0; exp[i] != '\0'; ++i) {
    if (exp[i] == '(')
      push(exp[i]);
    else if (exp[i] == ')') {
      if (top == NULL)
        return 0;
      pop();
    }
  }

  if (top == NULL)
    return 1;
  else
    return 0;
}

int main(int argc, char **argv)
{
  char * exp = "((a+b)*(c-d)))";

  printf("%d ", is_balanced(exp));

  return 0;
}
