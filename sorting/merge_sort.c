#include <stdio.h>

void merge(int *A, int l, int mid, int h)
{
  int i = l, j = mid + 1, k = l;
  int B[100];

  while (i <= mid && j <= h)
  {
    if (A[i] < A[j]) {
      B[k++]= A[i++];
    }
    else {
      B[k++]= A[j++];
    }
  }

  for (; i <= mid; ++i) {
    B[k++] = A[i];
  }

  for (; j <= h; ++j) {
    B[k++] = A[j];
  }

  for (i = l; i <= h; ++i) {
    A[i] = B[i];
  }
}

void merge_sort(int *A, int l, int h)
{
  int mid;

  if (l < h) {
    mid = (l + h) / 2;

    merge_sort(A, l, mid);
    merge_sort(A, mid + 1, h);
    merge(A, l, mid, h);
  }
}

int main(int argc, char **argv)
{
  int A[] = {1, 13, 74, 12, 163, 92, 245, 51, 10, 39};
  int n = 10;
  int i;

  merge_sort(A, 0, 9);

  for (i = 0; i < 10; ++i) {
    printf("%d ", A[i]);
  }
  printf("\n");

  return 0;
}
