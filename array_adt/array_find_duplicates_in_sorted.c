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

void arr_find_duplicates_in_sorted(Array *arr)
{
  printf("Duplicate numbers: ");

  int last_duplicate = -1;

  for (size_t i = 0; i < arr->len - 1; ++i) {
    if ((arr->items[i] == arr->items[i+1]) && (arr->items[i] != last_duplicate)) {
      printf("%d ", arr->items[i]);
      last_duplicate = arr->items[i];
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
  arr_append(&arr, 5);
  arr_append(&arr, 5);
  arr_append(&arr, 5);
  arr_append(&arr, 7);
  arr_append(&arr, 10);
  arr_append(&arr, 11);
  arr_append(&arr, 11);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_find_duplicates_in_sorted(&arr);

  return 0;
}

