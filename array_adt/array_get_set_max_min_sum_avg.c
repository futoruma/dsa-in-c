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

int arr_get(Array *arr, int idx)
{
  if (idx < 0 || idx >= arr->len) {
    printf("Invalid index.\n");
    return -1;
  }

  return arr->items[idx];
}

void arr_set(Array *arr, int idx, int x)
{
  if (idx < 0 || idx >= arr->len) {
    printf("Invalid index.\n");
    return;
  }

  arr->items[idx] = x;
}

int arr_max(Array *arr)
{
  if (arr->len == 0) {
    printf("Array is empty.\n");
    return -1;
  }

  int max = arr->items[0];

  for (size_t i = 1; i < arr->len; ++i) {
    if (max < arr->items[i]) {
      max = arr->items[i];
    }
  }

  return max;
}

int arr_min(Array *arr)
{
  if (arr->len == 0) {
    printf("Array is empty.\n");
    return -1;
  }

  int min = arr->items[0];

  for (size_t i = 1; i < arr->len; ++i) {
    if (min > arr->items[i]) {
      min = arr->items[i];
    }
  }

  return min;
}

int arr_sum(Array *arr)
{
  int sum = 0;

  for (size_t i = 0; i < arr->len; ++i) {
    sum += arr->items[i];
  }

  return sum;
}

float arr_avg(Array *arr)
{
  if (arr->len == 0) {
    printf("Array is empty.\n");
    return -1;
  }

  int sum = arr_sum(arr);

  return (float) sum / (float) arr->len;
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

  printf("Value at index 3: %d\n", arr_get(&arr, 3));

  printf("Set value at index 3 to 25.\n");
  arr_set(&arr, 3, 25);

  for (size_t i = 0; i < arr.cap; ++i) {
    printf("%d ", arr.items[i]);
  }
  printf("\n");

  printf("Array max: %d\n", arr_max(&arr));

  printf("Array min: %d\n", arr_min(&arr));

  printf("Array sum: %d\n", arr_sum(&arr));

  printf("Array average: %f\n", arr_avg(&arr));

  return 0;
}

