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

void arr_find_pair_with_sum_k(Array *arr, int target)
{
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
    if (count[target - arr->items[i] - min] > 0) {
      printf("Pair with sum %d: %d and %d.\n", target, arr->items[i], target - arr->items[i]);
      return;
    }

    count[arr->items[i] - min]++;
  }

  printf("Pair with sum %d not found.\n", target);
}

int main()
{
  Array arr;
  arr.cap = 10;
  arr.len = 0;
  arr.items = (int *) malloc(arr.cap * sizeof(int));

  arr_append(&arr, 2);
  arr_append(&arr, 5);
  arr_append(&arr, 6);
  arr_append(&arr, 5);
  arr_append(&arr, 7);
  arr_append(&arr, 10);
  arr_append(&arr, 11);
  arr_append(&arr, 16);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_find_pair_with_sum_k(&arr, 18);

  return 0;
}

