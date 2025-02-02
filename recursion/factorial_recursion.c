#include <stdio.h>

int fact(int n)
{
	if (n == 0) {
		return 1;
	}

	return fact(n - 1) * n;
}

int main()
{
	printf("%d\n", fact(5));

	return 0;
}

