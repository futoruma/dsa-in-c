#include <stdio.h>

int recurse(int n)
{
	if (n > 100) {
		return n - 10;
	}

	return recurse(recurse(n + 11));
}

int main()
{
	printf("%d\n", recurse(95));

	return 0;
}

