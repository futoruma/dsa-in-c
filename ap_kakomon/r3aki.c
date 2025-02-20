#include <stdio.h>

#define N 6
#define M 8

int main()
{
  size_t start[M + 1] = {0, 1, 2, 3, 4, 2, 5, 4, 6};
  size_t end[M + 1] = {0, 2, 3, 4, 1, 5, 4, 6, 2};

  size_t edgefirst[N + 1] = {0, 1, 2, 3, 4, 6, 8};
  size_t edgenext[M + 1] = {0, 0, 5, 0, 7, 0, 0, 0, 0};

  size_t current[N + 1] = {};
  size_t searched[M + 1] = {};
  size_t path[M + 1] = {};

  for (size_t i = 1; i <= N; ++i) {
    current[i] = edgefirst[i];
  }

  size_t top = 1;
  size_t last = M;
  size_t x = 1;
  size_t tmp = 0;

  while (last >= 1) {
    if (current[x] != 0) {
      tmp = current[x];
      searched[top] = tmp;
      current[x] = edgenext[tmp];
      x = end[tmp];
      top++;
    }
    else {
      top--;
      tmp = searched[top];
      path[last] = tmp;
      x = start[tmp];
      last--;
    }
  }

  printf("Path: ");
  for (size_t i = 1; i <= M; ++i) {
    printf("%zu ", path[i]);
  }

  return 0;
}

