#include <stdio.h>
#define MAXLINE 1024

int get_line(char *s, int lim);
int main()
{
	char line[MAXLINE];


	printf("Length : %d\n", get_line(line, MAXLINE));
	printf("%s\n", line);
	
	

	return 0;
}

/* getline: reads one line of input into s, returns length */
int get_line(char *s, int lim)
{
	int c, i;

	for(i = 0; i<lim-1 && (c = getchar()) != '$' && c != '\n'; i++)
		*s++ = c;

	if(c == '\n')
		*s++ = c;
	
	*s = '\0';p

	return i;
}






























