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

int arr_is_sorted(Array *arr)
{
  for (size_t i = 0; i < arr->len - 1; ++i) {
    if (arr->items[i] > arr->items[i+1]) {
      return 0;
    }
  }

  return 1;
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

  if (arr_is_sorted(&arr)) {
    printf("Array is sorted.\n");
  }
  else {
    printf("Array is not sorted.\n");
  }

  arr.items[2] = 5;
  arr.items[5] = 8;

  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  if (arr_is_sorted(&arr)) {
    printf("Array is sorted.\n");
  }
  else {
    printf("Array is not sorted.\n");
  }

  return 0;
}

