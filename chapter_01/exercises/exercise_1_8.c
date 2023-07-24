#include<stdio.h>

int main()
{
	char c;
	int blanks, tabs, newlines;

	blanks = 0;
	tabs = 0;
	newlines= 0;

	c = getchar();
	while(c != 'x')
	{
		if(c == ' ')
			blanks++;
		else if(c == '\t')
			tabs++;
		else if(c == '\n')
			newlines++;

		c = getchar();
	}

	printf("Blanks = %d \n", blanks);
	printf("Tabs = %d \n", tabs);
	printf("New Lines = %d \n", newlines);
}
