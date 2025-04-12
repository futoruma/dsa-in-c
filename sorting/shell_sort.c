#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void shell_sort(int *A, int n)
{
  int gap, i, j, tmp;

  for (gap = n/2; gap >= 1; gap /= 2) {
    for (i = gap; i < n; ++i)
    {
      tmp = A[i];
      j = i - gap;
      while (j >= 0 && A[j] > tmp) {
        A[j+gap] = A[j];
        j = j - gap;
      }
      A[j+gap] = tmp;
    }
  }
}

int main(int argc, char **argv)
{
  int A[] = {151, 13, 47, 12, 16, 59, 24, 25, 107, 33};
  int n = 10;
  int i;

  shell_sort(A, n);

  for (i = 0; i < 10; ++i) {
    printf("%d ", A[i]);
  }
  printf("\n");

  return 0;
}
