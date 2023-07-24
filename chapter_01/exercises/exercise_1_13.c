#include<stdio.h>

int main()
{
	int c, word_length, i;
	
	word_length = 0;
	i = 1;

	while( (c = getchar()) != 'x')
	{
		if( c == ' ')
		{
			printf("%d ", i++);

			while(word_length > 0)
			{
				printf(" * ");
				--word_length;
			}
			printf("\n");
		}
		else
			++word_length;
	}
}






























