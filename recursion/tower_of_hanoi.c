#include <stdio.h>

void tower_of_hanoi(int disks, int a, int b, int c)
{
	if (disks < 1) {
		return;
	}

	tower_of_hanoi(disks - 1, a, c, b);

	printf("(%d,%d)\n", a, c);

	tower_of_hanoi(disks - 1, b, a, c);
}


int main()
{
	tower_of_hanoi(4, 1, 2, 3);

	return 0;
}

