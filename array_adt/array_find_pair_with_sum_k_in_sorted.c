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

void arr_find_pair_with_sum_k_in_sorted(Array *arr, int target)
{
  size_t l = 0;
  size_t r = arr->len - 1;

  while (l < r) {
    if ((arr->items[l] + arr->items[r]) > target) {
      r--;
    }
    else if ((arr->items[l] + arr->items[r]) < target) {
      l++;
    }
    else {
      printf("Pair with sum %d: %d and %d.\n", target, arr->items[l], arr->items[r]);
      return;
    }
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
  arr_append(&arr, 3);
  arr_append(&arr, 5);
  arr_append(&arr, 6);
  arr_append(&arr, 7);
  arr_append(&arr, 10);
  arr_append(&arr, 11);
  arr_append(&arr, 16);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  arr_find_pair_with_sum_k_in_sorted(&arr, 17);

  return 0;
}

