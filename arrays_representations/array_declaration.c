#include <stdio.h>

int main()
{
  int a[5];
  int b[5] = {2,3,4,5,6};
  int c[10] = {2,3,4};
  int d[5] = {0};
  int e[] = {1,2,3,4,5,6};

  for (size_t i = 0; i < 6; ++i) {
    printf("%p\n", (void *) &e[i]);
  }

  return 0;
}

