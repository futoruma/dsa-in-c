#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a[2][3] = {{1,2,3},{4,5,6}};

  for (size_t i = 0; i < 2; ++i) {
    for (size_t j = 0; j < 3; ++j) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  int *b[2];
  b[0] = (int *) malloc(3 * sizeof(int));
  b[1] = (int *) malloc(3 * sizeof(int));

  for (size_t i = 0; i < 2; ++i) {
    for (size_t j = 0; j < 3; ++j) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }

  int **c = (int **) malloc(2 * sizeof(int *));
  c[0] = (int *) malloc(3 * sizeof(int));
  c[1] = (int *) malloc(3 * sizeof(int));

  for (size_t i = 0; i < 2; ++i) {
    for (size_t j = 0; j < 3; ++j) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}

