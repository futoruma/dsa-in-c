#include <stdio.h>

void recurseA(int n);
void recurseB(int n);

void recurseA(int n)
{
	if (n <= 0) {
		return;
	}

	printf("%d\n", n);
	recurseB(n - 1);
}

void recurseB(int n)
{
	if (n <= 1) {
		return;
	}

	printf("%d\n", n);
	recurseA(n / 2);
}

int main()
{
	recurseA(20);

	return 0;
}

