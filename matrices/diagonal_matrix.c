#include <stdio.h>

typedef struct {
  int A[10];
  int n;
} Matrix;

void matrix_set(Matrix *m, int i, int j, int x)
{
  if (i == j) {
    m->A[i-1] = x;
  }
}

int matrix_get(Matrix m, int i, int j)
{
  if (i == j) {
    return m.A[i-1];
  }
 
 return 0;
}

void matrix_display(Matrix m)
{
 int i, j;

 for (i = 0; i < m.n; ++i)
  {
    for (j = 0; j < m.n; ++j)
    {
      if (i == j) {
        printf("%d ",m.A[i]);
      }
      else {
        printf("0 ");
      }
    }

 printf("\n");
  }
}

int main(int argc, char *argv[])
{
  Matrix m;

  m.n=4;

  matrix_set(&m, 1, 1, 5);
  matrix_set(&m, 2, 2, 8);
  matrix_set(&m, 3, 3, 9);
  matrix_set(&m, 4, 4, 12);

  printf("%d \n", matrix_get(m, 2, 2));

  matrix_display(m);
  
  return 0;
}
