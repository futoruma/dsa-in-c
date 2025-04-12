#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void insertion_sort(int *A, int n)
{
 int i, j, x;

 for (i = 1; i < n; ++i)
  {
    j = i - 1;
    x=A[i];

    while (j > -1 && A[j] > x)
    {
      A[j+1] = A[j];
      --j;
    }

    A[j+1] = x;
  }
}

int main(int argc, char **argv)
{
  int A[] = {81, 13, 73, 122, 6, 49, 2, 5, 101, 3};
  int n = 10;
  int i;

  insertion_sort(A, n);

  for (i = 0; i < 10; ++i) {
    printf("%d ",A[i]);
  }
  printf("\n");

  return 0;
}
