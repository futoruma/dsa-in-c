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

void arr_find_missing_in_unsorted(Array *arr)
{
  printf("Missing numbers: ");

  int min = arr->items[0];
  int max = arr->items[0];

  for (size_t i = 1; i < arr->len; ++i) {
    if (arr->items[i] > max) {
      max = arr->items[i];
    }

    if (arr->items[i] < min) {
      min = arr->items[i];
    }
  }

  int count[max - min + 1];
  for (size_t i = 0; i < (max - min + 1); ++i) {
    count[i] = 0;
  }

  for (size_t i = 0; i < arr->len; ++i) {
    count[arr->items[i] - min]++;
  }

  for (size_t i = 0; i < (max - min + 1); ++i) {
    if (count[i] == 0) {
      printf("%zu ", i + min);
    }
  }
}

int main()
{
  Array arr;
  arr.cap = 10;
  arr.len = 0;
  arr.items = (int *) malloc(arr.cap * sizeof(int));

  arr_append(&arr, 21);
  arr_append(&arr, 14);
  arr_append(&arr, 15);
  arr_append(&arr, 6);
  arr_append(&arr, 7);
  arr_append(&arr, 10);
  arr_append(&arr, 19);
  arr_append(&arr, 13);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_find_missing_in_unsorted(&arr);

  return 0;
}

