#include <stdio.h>

int memo[10];

int fib(int n)
{
	if (n < 2) {
		return n;
	}

	if (memo[n] > 0) {
		return memo[n];
	}

	memo[n] = fib(n - 1) + fib (n - 2);
	return memo[n];
}

int main()
{
	memo[0] = 0;
	memo[1] = 1;

	printf("%d\n", fib(10));

	return 0;
}

