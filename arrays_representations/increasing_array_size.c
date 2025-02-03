#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *ap = (int *) malloc(3 * sizeof(int));
  ap[0] = 2;
  ap[1] = 3;
  ap[2] = 4;

  for (size_t i = 0; i < 3; ++i) {
    printf("%d\n", ap[i]);
  }

  int *bp = (int *) malloc(6 * sizeof(int));

  for (size_t i = 0; i < 3; ++i) {
    bp[i] = ap[i];
  }

  free(ap);
  ap = bp;
  bp = NULL;

  for (size_t i = 0; i < 3; ++i) {
    printf("%d\n", ap[i]);
  }
  
  return 0;
}

