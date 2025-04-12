#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *A;
  int n;
} Matrix;

void matrix_set(Matrix *m, int i, int j, int x)
{
  if (i >= j) {
    m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
  }
}

int matrix_get(Matrix m, int i, int j)
{
  if (i >= j) {
    return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
  }

  return 0;
}

void matrix_display(Matrix m)
{
  int i, j;

  for (i = 1; i <= m.n; ++i)
  {
    for (j = 1; j <= m.n; ++j)
    {
      if (i >= j) {
        printf("%d ",m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]);
      }
      else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

int main(int argc, char** argv)
{
  Matrix m;
  int i, j, x;

  printf("Enter the number of dimensions: ");
  scanf("%d",&m.n);

  m.A= (int *) malloc(m.n*(m.n+1)/2*sizeof(int));

  printf("Enter the elements: ");

  for (i = 1; i <= m.n; ++i)
  {
    for (j = 1; j <= m.n; ++j)
    {
      scanf("%d",&x);
      matrix_set(&m, i, j, x);
    }
  }

  printf("\n\n");

  matrix_display(m);

  return 0;
}
