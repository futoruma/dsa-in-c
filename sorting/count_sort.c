#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

int find_max(int *A, int n)
{
  int max = INT32_MIN;
  int i;

  for (i = 0; i < n; ++i) {
    if (A[i] > max) {
      max=A[i];
    }
  }

  return max;
}

void count_sort(int *A, int n)
{
  int i, j, max, *C;

  max = find_max(A, n);

  C = (int *) malloc(sizeof(int) * (max + 1));

  for (i = 0; i < max + 1; ++i) {
    C[i] = 0;
  }

  for (i = 0; i < n; ++i) {
    C[A[i]]++;
  }

  i = 0;
  j = 0;

  while (j < max + 1) {
    if (C[j] > 0) {
      A[i++] = j;
      C[j]--;
    }
    else {
      ++j;
    }
  }
}

int main(int argc, char **argv)
{
  int A[] = {311, 143, 7, 121, 16, 95, 24, 25, 150, 3};
  int n = 10;
  int i;

  count_sort(A, n);

  for (i = 0; i < 10; ++i) {
    printf("%d ", A[i]);
  }
  printf("\n");

  return 0;
}
