#include <stdio.h>

void fun(int* idx);

int main()
{
	int idx = 0, i;
	
	for( i=0; i<4; i++) {
		fun(&idx);
		printf("%d\n", idx);
	}
	
	return 0;
}

void fun(int* idx)
{	
	int arr[] = {10, 20, 30, 50, 60};
	printf("%d", arr[*idx]);
	*idx = *idx + 1;
}





























