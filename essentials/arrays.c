#include <stdio.h>

int main()
{
  int a[5];
  a[0] = 7;
  a[1] = 12;
  a[2] = 20;
    
  printf("Size of a is %zu bytes.\n", sizeof(a));
  printf("The 2nd element of a is %d.\n", a[1]);
    
  int b[5] = {4, 9, 16, 25, 81};
    
  printf("Size of b is %zu bytes.\n", sizeof(b));
  printf("The 3rd element of b is %d.\n", b[2]);
    
  int c[] = {4, 9, 16, 25, 81};
    
  printf("Size of c is %zu bytes.\n", sizeof(c));
  printf("The 3rd element of c is %d.\n", c[2]);

  return 0;
}

