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

void arr_find_missing_in_sorted(Array *arr)
{
  printf("Missing numbers: ");

  int diff = arr->items[0] - 0;

  for (size_t i = 1; i < arr->len; ++i) {
    while (diff < (arr->items[i] - i)) {
      printf("%zu ", i + diff);
      diff++;
    }
  }
}

int main()
{
  Array arr;
  arr.cap = 10;
  arr.len = 0;
  arr.items = (int *) malloc(arr.cap * sizeof(int));

  arr_append(&arr, 2);
  arr_append(&arr, 4);
  arr_append(&arr, 5);
  arr_append(&arr, 6);
  arr_append(&arr, 7);
  arr_append(&arr, 10);
  arr_append(&arr, 11);
  arr_append(&arr, 13);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_find_missing_in_sorted(&arr);

  return 0;
}

