#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a[5] = {2,4,6,8,10};

  for (size_t i = 0; i < 5; ++i) {
    printf("%d\n", a[i]);
  }

  int *bp = (int *) malloc(5 * sizeof(int));
  bp[0] = 3;
  bp[1] = 6;
  bp[2] = 9;
  bp[3] = 12;
  bp[4] = 15;

  for (size_t i = 0; i < 5; ++i) {
    printf("%d\n", bp[i]);
  }

  free(bp);

  for (size_t i = 0; i < 5; ++i) {
    printf("%d\n", bp[i]);
  }

  return 0;
}

