#include<stdio.h>

int main()
{
	char c;

	c = getchar();
	while(c != 'x')
	{
		if(c == ' ')
		{
			putchar(c);
			
			c = getchar();
			while(c == ' ' || c == '\t')
			{
				c = getchar();
			}
		}


		putchar(c);
		c = getchar();
	}	


	/*
		while( (c = getchar() != 'x') 
	*/

	printf("\n");
}

