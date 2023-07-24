#include<stdio.h>

int main() 
{
	int c, i, j;
	char letter;
	int char_frequency[256];

	for(i=0; i<256; i++)
		char_frequency[i] = 0;

	while( (c = getchar()) != 'x' )
	{
		++char_frequency[c];
	}


	for(i=0; i<256; i++)
	{
		if(char_frequency[i] != 0)
		{
			printf("%d ", i);
			putchar(i);
			while(char_frequency[i] > 0)
			{
				printf(" * ");
				--char_frequency[i];
			}

			printf("\n");
		}
	}	
}





























































