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

void arr_insert(Array *arr, int idx, int x)
{
  if (arr->len == arr->cap) {
    printf("The array is already full.\n");
    return;
  }

  if (idx < 0 || idx > arr->len) {
    printf("Invalid index.\n");
    return;
  }

  for (size_t i = arr->len; i > idx; --i) {
    arr->items[i] = arr->items[i-1];
  }

  arr->items[idx] = x;
  arr->len++;
}

int arr_linear_search(Array *arr, int x)
{
  for (size_t i = 0; i < arr->len; ++i) {
    if (arr->items[i] == x) {
      int tmp = arr->items[0];
      arr->items[0] = arr->items[i];
      arr->items[i] = tmp;

      return i;
    }
  }

  return -1;
}

int main()
{
  Array arr;
  arr.cap = 10;
  arr.len = 0;
  arr.items = (int *) malloc(arr.cap * sizeof(int));

  arr_append(&arr, 2);
  arr_append(&arr, 5);
  arr_insert(&arr, 0, 10);
  arr_insert(&arr, 2, 15);
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

  printf("Index of 3: %d\n", arr_linear_search(&arr, 3));
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  printf("Index of 0: %d\n", arr_linear_search(&arr, 0));
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  return 0;
}

