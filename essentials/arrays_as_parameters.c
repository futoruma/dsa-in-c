#include <stdio.h>
#include <stdlib.h>

int * arr_alloc(size_t len)
{
	int *ptr;
	ptr = (int *) malloc(len * sizeof(int));

	return ptr;
}

void arr_print(int *arr, size_t len)
{
	for (size_t i = 0; i < len; ++i) {
		printf("%d\n", arr[i]);
	}
}

int main()
{
	size_t a_len = 5;
	int *aptr = arr_alloc(a_len);

	aptr[0] = 7;
	aptr[3] = 3;

	arr_print(aptr, a_len);

	free(aptr);

	return 0;
}

