#include <stdio.h>

void recurse(int n)
{
	if (n <= 0) {
		return;
	}

	printf("%d\n", n);
	recurse(n - 1);
	recurse(n - 1);
}

int main()
{
	recurse(3);
	return 0;
}

