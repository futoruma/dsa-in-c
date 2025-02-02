#include <stdio.h>

int fact(int n)
{
	if (n == 0) {
		return 1;
	}

	return fact(n - 1) * n;
}

int ncr(int n, int r)
{
	if (n == r || r == 0) {
		return 1;
	}

	return ncr(n - 1, r - 1) + ncr(n - 1, r);
}

int main()
{
	printf("%d\n", ncr(5, 3));

	return 0;
}

