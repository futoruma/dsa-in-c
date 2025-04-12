#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void selection_sort(int *A, int n)
{
  int i, j, k;

  for (i = 0; i < n-1; ++i)
  {
    for (j = k = i; j < n; ++j)
    {
      if (A[j] < A[k]) {
        k=j;
      }
    }

    swap(&A[i], &A[k]);
  }
}

int main()
{
  int A[] = {151, 13, 27, 132, 6, 49, 214, 85, 10, 3};
  int n = 10;
  int i;

  selection_sort(A, n);

  for (i = 0; i < 10; ++i) {
    printf("%d ",A[i]);
  }
  printf("\n");

  return 0;
}
