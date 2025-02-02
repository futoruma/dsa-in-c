#include <stdio.h>

int recurse_static(int n)
{
	static int x = 0;

	if (n <= 0) {
		return 0;
	}

	x++;
	return recurse_static(n - 1) + x;
}

int y = 0;
int recurse_global(int n)
{
	if (n <= 0) {
		return 0;
	}

	y++;
	return recurse_global(n - 1) + y;
}

int main()
{
	printf("%d\n", recurse_static(5));
	printf("%d\n", recurse_static(5));

	printf("%d\n", recurse_global(5));
	printf("%d\n", recurse_global(5));

	return 0;
}

