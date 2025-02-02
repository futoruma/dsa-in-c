#include <stdio.h>

struct Rectangle
{
  int length;
  int breadth;
};

int main()
{
  struct Rectangle r1 = {10, 5};

  printf("Size of r1 is %zu bytes.\n", sizeof(r1));
  printf("Its length is %d and its breadth is %d.\n", r1.length, r1.breadth);

  r1.length = 15;
  r1.breadth = 18;

  printf("Size of r1 is %zu bytes.\n", sizeof(r1));
  printf("Its length is %d and its breadth is %d.\n", r1.length, r1.breadth);

  return 0;
}

