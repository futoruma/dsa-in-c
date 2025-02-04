#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t cap;
  size_t len;
  int *items;
} Array;

int main()
{
  Array arr;
  arr.cap = 10;
  arr.len = 0;
  arr.items = (int *) malloc(arr.cap * sizeof(int));

  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d\n", arr.items[i]);
  }

  arr.items[0] = 2;
  arr.len++;

  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d\n", arr.items[i]);
  }

  arr.items[1] = 5;
  arr.len++;
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d\n", arr.items[i]);
  }

  return 0;
}

