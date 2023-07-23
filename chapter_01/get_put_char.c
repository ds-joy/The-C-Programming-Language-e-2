#include <stdio.h>

int main()
{
	int c;

	c = getchar();
	while (1) 
	{
		putchar(c);
		c = getchar();
		
		if( c == '\n')
		{
			printf("\n");
			break;
		}	
	}


	return 0;
}


