#include <stdio.h>

int add(int a, int b)
{
	int res;
	res = a + b;

	return res;
}

int main()
{
	int num1 = 5;
	int num2 = 7;
	int sum;

	sum = add(num1, num2);
	printf("The sum of %d and %d is %d.\n", num1, num2, sum);

	return 0;
}

