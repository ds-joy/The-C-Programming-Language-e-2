#include <stdio.h>
#include "flags.h"

void fun();
int main()
{
	printf("start count: %d\n", count);

	count++;
	printf("before fun count: %d\n", count);

	fun();
	printf("after fun  count: %d\n", count);

	
	return 0;
}





