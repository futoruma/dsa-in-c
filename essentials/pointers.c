#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p;

	int a = 10;
	p = &a;

	printf("a is %d.\n", a);
	printf("a is %d.\n", *p);

	int b[5] = {3,4,5,6,7};
	p = b;

	for (size_t i = 0; i < 5; ++i) {
		printf("%d\n", p[i]);
	}

	p = (int *) malloc(3 * sizeof(int));
	p[0] = 11;
	p[1] = 15;
	p[2] = 23;

	for (size_t i = 0; i < 3; ++i) {
		printf("%d\n", p[i]);
	}

	free(p);

	return 0;
}

