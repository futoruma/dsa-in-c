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

void arr_delete(Array *arr, int idx)
{
  if (idx < 0 || idx >= arr->len) {
    printf("Invalid index.\n");
    return;
  }

  for (size_t i = idx; i < arr->len - 1; ++i) {
    arr->items[i] = arr->items[i+1];
  }

  arr->len--;
}

int main()
{
  Array arr;
  arr.cap = 10;
  arr.len = 0;
  arr.items = (int *) malloc(arr.cap * sizeof(int));

  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_append(&arr, 2);

  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_append(&arr, 5);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_insert(&arr, 0, 10);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_insert(&arr, 2, 15);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_delete(&arr, 1);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  return 0;
}

