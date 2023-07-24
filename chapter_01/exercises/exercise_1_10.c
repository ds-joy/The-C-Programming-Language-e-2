#include<stdio.h>

int main()
{
	char c;

	c = getchar();
	while(c != 'x')
	{
	
		if(c == '\t')
		{
			putchar('\\');
			putchar('t');
		}
		else if(c == '\b')
		{
			putchar('\\');
			putchar('b');
		}

		else if(c == '\\')
		{
			putchar('\\');
			putchar('\\');
		}
		else 
		{
			putchar(c);
		}

		c = getchar();
	}

	printf("\n");
	
}

