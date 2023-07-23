#include <stdio.h>

int main()
{
	char c;
	long num_of_characters;

	num_of_characters = 0;
	c = getchar();

	while(c != '\n')
	{
		++num_of_characters;
		c = getchar();
	}

	printf("Character Count is %ld \n", num_of_characters);
}
