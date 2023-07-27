#include <stdio.h>
int main() 
{    
	unsigned int a, b, c, d;
	a = 200, b = 100, c =0, d = 0;
	
	c = a + b;
	d = b - a;
	
	printf("%d %d %d %d", a+b, c, b-a, d);
	
	return 0;
}

