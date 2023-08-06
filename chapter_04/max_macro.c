#include <stdio.h>

#define max(A,B) ( (A) > (B) ? (A) : (B))

int main()
{
	int a, b;
	
	scanf("%d", &a);
	scanf("%d", &b);

	printf("MAX = %d\n", max(a, b) );

	return 0;
}

























