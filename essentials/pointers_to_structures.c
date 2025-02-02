#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int length;
	int breadth;
} Rectangle;

int main()
{
	Rectangle r1 = {5,10};
	printf("r1 length is %d and r1 breadth is %d.\n", r1.length, r1.breadth);

	Rectangle *p;

	p = &r1;
	printf("r1 length is %d and r1 breadth is %d.\n", p->length, p->breadth);

	p = (Rectangle *) malloc(sizeof(Rectangle));
	p->length = 22;
	p->breadth = 7;

	printf("The new rectangle's length is %d and breadth is %d.\n", p->length, p->breadth);

	return 0;
}

