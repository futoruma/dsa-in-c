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

int arr_binary_search(Array *arr, int x)
{
  int l, mid, r;
  l = 0;
  r = arr->len - 1;

  while (l <= r) {
    mid = l + (r - l) / 2;
    if (arr->items[mid] < x) {
      l = mid + 1;
    }
    else if (arr->items[mid] > x) {
      r = mid - 1;
    }
    else {
      return mid;
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
  arr_append(&arr, 7);
  arr_append(&arr, 11);
  arr_append(&arr, 15);
  arr_append(&arr, 23);
  arr_append(&arr, 45);
  arr_append(&arr, 53);
  arr_append(&arr, 78);
  arr_append(&arr, 125);
  
  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  printf("Index of 53: %d\n", arr_binary_search(&arr, 53));

  printf("Index of 50: %d\n", arr_binary_search(&arr, 50));
  
  return 0;
}

