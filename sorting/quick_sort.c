#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

int partition(int *A, int l, int h)
{
  int pivot = A[l];
  int i = l, j = h;

  do
  {
    do {
      ++i;
    } while (A[i] <= pivot);

    do {
      --j;
    } while (A[j] > pivot);

    if (i < j) {
      swap(&A[i], &A[j]);
    }
  } while (i < j);

  swap(&A[l], &A[j]);

  return j;
}

void quick_sort(int *A, int l, int h)
{
  int j;

  if (l < h)
  {
    j = partition(A, l, h);

    quick_sort(A, l, j);
    quick_sort(A, j + 1, h);
  }
}

int main(int argc, char **argv)
{
  int A[]= {11, 123, 7, 412, 16, 95, 24, 35, 10, 3};
  int n = 10;
  int i;

  quick_sort(A, 0, n);

  for (i = 0; i < 10; ++i) {
    printf("%d ", A[i]);
  }
  printf("\n");

  return 0;
}
