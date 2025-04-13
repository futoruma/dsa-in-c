#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node * next;
} Node;

Node * front = NULL, * rear = NULL;

void enqueue(int x)
{
  Node * t;
  t = (Node *) malloc(sizeof(Node));
  if (t == NULL)
    printf("Queue is full\n");
  else {
    t -> data = x;
    t -> next = NULL;
    if (front == NULL)
      front = rear = t;
    else {
      rear -> next = t;
      rear = t;
    }
  }
}

int dequeue()
{
  int x = -1;
  Node * t;

  if (front == NULL)
    printf("Queue is empty\n");
  else {
    x = front -> data;
    t = front;
    front = front -> next;
    free(t);
  }

  return x;
}

void display()
{
  Node * p = front;
  
  while (p) {
    printf("%d ", p -> data);
    p = p -> next;
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  enqueue(105);
  enqueue(24);
  enqueue(37);
  enqueue(405);
  enqueue(501);

  display();

  printf("%d ", dequeue());

  return 0;
}
