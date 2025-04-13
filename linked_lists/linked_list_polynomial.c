#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
  int coeff;
  int exp;
  struct Node * next;
} Node;

Node * poly = NULL;

void create()
{
  Node * t, * last = NULL;
  int num, i;

  printf("Enter number of terms");
  scanf("%d", & num);
  printf("Enter each term with coeff and exp\n");

  for (i = 0; i < num; ++i) {
    t = (Node *) malloc(sizeof(Node));
    scanf("%d%d", & t -> coeff, & t -> exp);
    t -> next = NULL;

    if (poly == NULL) {
      poly = last = t;
    } else {
      last -> next = t;
      last = t;
    }
  }
}

void display(Node * p)
{
  while (p) {
    printf("%dx%d +", p -> coeff, p -> exp);
    p = p -> next;
  }
  
  printf("\n");
}

long eval(Node * p, int x)
{
  long val = 0;

  while (p) {
    val += p -> coeff * pow(x, p -> exp);
    p = p -> next;
  }

  return val;
}

int main(int argc, char **argv)
{
  create();

  display(poly);

  printf("%ld\n", eval(poly, 1));
  
  return 0;
}
