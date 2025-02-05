#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t cap;
  size_t len;
  int *items;
} Array;

void arr_append(Array *arr, int x)
{
  if (arr->len == arr->cap) {
    printf("The array is already full.\n");
    return;
  }

  arr->items[arr->len] = x;
  arr->len++;
}

void arr_reverse(Array *arr)
{
  int l = 0;
  int r = arr->len - 1;
  int tmp;

  while (l < r) {
    int tmp = arr->items[l];
    arr->items[l] = arr->items[r];
    arr->items[r] = tmp;

    l++;
    r--;
  }
}

int main()
{
  Array arr;
  arr.cap = 10;
  arr.len = 0;
  arr.items = (int *) malloc(arr.cap * sizeof(int));

  arr_append(&arr, 2);
  arr_append(&arr, 5);
  arr_append(&arr, 1);
  arr_append(&arr, 6);
  arr_append(&arr, 7);
  arr_append(&arr, 3);
  arr_append(&arr, 8);
  arr_append(&arr, 9);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_reverse(&arr);

  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  return 0;
}

