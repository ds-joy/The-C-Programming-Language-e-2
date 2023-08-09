#include <stdio.h>

#define swap(t, x, y)  {\
	t temp;\
	temp = x;\
	x = y;\
	y = temp;\
}

int main()
{
	int x, y;

	x = 22;
	y = 33;
	
	printf("Before swap:\n");
	printf("x = %d y = %d\n\n", x, y);

	swap(int, x, y);

	printf("After swap:\n");
	printf("x = %d y = %d\n\n", x, y);

	
	return 0;
}

































