#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int length;
	int breadth;
} Rectangle;

Rectangle * rectangle_alloc(int length, int breadth)
{
	Rectangle * ptr;
	ptr = (Rectangle *) malloc(sizeof(Rectangle));

	ptr->length = length;
	ptr->breadth = breadth;

	return ptr;
}

void rectangle_rotate(Rectangle *ptr)
{
	int tmp = ptr->length;
	ptr->length = ptr->breadth;
	ptr->breadth = tmp;
}

int main()
{
	Rectangle *ptr = rectangle_alloc(7, 15);
	printf("The rectangle's length is %d and breadth is %d.\n", ptr->length, ptr->breadth);

	rectangle_rotate(ptr);
	printf("The rectangle's length is %d and breadth is %d.\n", ptr->length, ptr->breadth);

	free(ptr);

	return 0;
}

