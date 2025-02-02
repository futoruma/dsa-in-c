#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp;
    
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main()
{
  int num1 = 5;
  int num2 = 7;
  printf("num1 is %d and num2 is %d.\n", num1, num2);
    
  swap(&num1, &num2);
  printf("num1 is %d and num2 is %d.\n", num1, num2);

	return 0;
}

