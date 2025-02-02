#include <stdio.h>

int power(int m, int n)
{
	if (n == 0) {
		return 1;
	}

	return power(m, n - 1) * m;
}

int main()
{
	printf("%d\n", power(2, 10));

	return 0;
}

