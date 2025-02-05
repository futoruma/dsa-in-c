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

Array * arr_union(Array *arr1, Array *arr2)
{
  Array *arr3 = (Array *) malloc(sizeof(Array));
  arr3->cap = arr1->cap + arr2->cap;
  arr3->len = 0;
  arr3->items = (int *) malloc(arr3->cap * sizeof(int));

  int i = 0, j = 0;
  while (i < arr1->len && j < arr2->len) {
    if (arr1->items[i] < arr2->items[j]) {
      arr3->items[arr3->len] = arr1->items[i];
      i++;
    }
    else if (arr1->items[i] > arr2->items[j]) {
      arr3->items[arr3->len] = arr2->items[j];
      j++;
    }
    else {
      arr3->items[arr3->len] = arr1->items[i];
      i++;
      j++;
    }
    arr3->len++;
  }

  while (i < arr1->len) {
    arr3->items[arr3->len] = arr1->items[i];
    i++;
    arr3->len++;
  }

  while (j < arr2->len) {
    arr3->items[arr3->len] = arr2->items[j];
    j++;
    arr3->len++;
  }

  return arr3;
}

Array * arr_intersect(Array *arr1, Array *arr2)
{
  Array *arr3 = (Array *) malloc(sizeof(Array));
  arr3->cap = arr1->cap + arr2->cap;
  arr3->len = 0;
  arr3->items = (int *) malloc(arr3->cap * sizeof(int));

  int i = 0, j = 0;
  while (i < arr1->len && j < arr2->len) {
    if (arr1->items[i] < arr2->items[j]) {
      i++;
    }
    else if (arr1->items[i] > arr2->items[j]) {
      j++;
    }
    else {
      arr3->items[arr3->len] = arr1->items[i];
      i++;
      j++;
      arr3->len++;
    }
  }

  return arr3;
}

Array * arr_diff(Array *arr1, Array *arr2)
{
  Array *arr3 = (Array *) malloc(sizeof(Array));
  arr3->cap = arr1->cap + arr2->cap;
  arr3->len = 0;
  arr3->items = (int *) malloc(arr3->cap * sizeof(int));

  int i = 0, j = 0;
  while (i < arr1->len && j < arr2->len) {
    if (arr1->items[i] < arr2->items[j]) {
      arr3->items[arr3->len] = arr1->items[i];
      i++;
      arr3->len++;
    }
    else if (arr1->items[i] > arr2->items[j]) {
      j++;
    }
    else {
      i++;
      j++;
    }
  }

  while (i < arr1->len) {
    arr3->items[arr3->len] = arr1->items[i];
    i++;
    arr3->len++;
  }

  return arr3;
}

int main()
{
  Array arr1;
  arr1.cap = 10;
  arr1.len = 0;
  arr1.items = (int *) malloc(arr1.cap * sizeof(int));

  arr_append(&arr1, 2);
  arr_append(&arr1, 5);
  arr_append(&arr1, 6);
  arr_append(&arr1, 7);
  
  printf("Array 1:\n");
  for (size_t i = 0; i < arr1.cap; ++i) {
    printf("%d ", arr1.items[i]);
  }
  printf("\n");

  Array arr2;
  arr2.cap = 10;
  arr2.len = 0;
  arr2.items = (int *) malloc(arr2.cap * sizeof(int));

  arr_append(&arr2, 3);
  arr_append(&arr2, 7);
  arr_append(&arr2, 89);
  
  printf("Array 2:\n");
  for (size_t i = 0; i < arr2.cap; ++i) {
    printf("%d ", arr2.items[i]);
  }
  printf("\n");

  Array *arr3 = arr_union(&arr1, &arr2);
 
  printf("Union of Array 1 and Array 2:\n");
  for (size_t i = 0; i < arr3->cap; ++i) {
    printf("%d ", arr3->items[i]);
  }
  printf("\n");

  Array *arr4 = arr_intersect(&arr1, &arr2);
 
  printf("Intersection of Array 1 and Array 2:\n");
  for (size_t i = 0; i < arr4->cap; ++i) {
    printf("%d ", arr4->items[i]);
  }
  printf("\n");

  Array *arr5 = arr_diff(&arr1, &arr2);
 
  printf("Difference of Array 1 and Array 2:\n");
  for (size_t i = 0; i < arr5->cap; ++i) {
    printf("%d ", arr5->items[i]);
  }
  printf("\n");

  return 0;
}

