#include <stdio.h>

int main()
{
	char *p, *q;
	p = q;

	*q++ = 'a';
	*q++ = 'b';
	*q++ = 'c';

	printf("%s\n", p);

	return 0;
}





















