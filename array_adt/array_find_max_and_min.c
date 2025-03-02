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

void arr_find_max_and_min(Array *arr)
{
  int min = arr->items[0];
  int max = arr->items[0];

  for (size_t i = 1; i < arr->len; ++i) {
    if (arr->items[i] > max) {
      max = arr->items[i];
    }
    else if (arr->items[i] < min) {
      min = arr->items[i];
    }
  }

  printf("Max is %d and min is %d.\n", max, min);
}

int main()
{
  Array arr;
  arr.cap = 10;
  arr.len = 0;
  arr.items = (int *) malloc(arr.cap * sizeof(int));

  arr_append(&arr, 2);
  arr_append(&arr, 25);
  arr_append(&arr, 6);
  arr_append(&arr, 53);
  arr_append(&arr, 7);
  arr_append(&arr, 10);
  arr_append(&arr, 71);
  arr_append(&arr, 12);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_find_max_and_min(&arr);

  return 0;
}

