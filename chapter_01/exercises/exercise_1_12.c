#include<stdio.h>

int main() 
{
	int c;


	while ( (c = getchar()) != 'x')
	{
		if( c == ' ')
			printf("\n");
		else
			putchar(c);
	}

	printf("\n");
}



























