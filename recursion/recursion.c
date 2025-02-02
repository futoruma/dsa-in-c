#include <stdio.h>

void head_recurse(int x)
{
	if (x <= 0) {
		return;
	}

	head_recurse(x - 1);
	printf("%d\n", x);
}

void tail_recurse(int x)
{
	if (x <= 0) {
		return;
	}

	printf("%d\n", x);
	tail_recurse(x - 1);
}

int main()
{
  printf("Head recursion.\n");
	head_recurse(5);
	
	printf("Tail recursion.\n");
	tail_recurse(5);

	return 0;
}

