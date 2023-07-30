#include <stdio.h>
#include <string.h>

#define MAXLEN 1024

void reverse(char s[]);
int get_line(char s [ ],int lim);

int main()
{
	char line[MAXLEN];
	int i, len;

	len = get_line(line, MAXLEN);

	reverse(line);

	i = 0;
	while(line[i] != '\0') {
		putchar(line[i]);
		i++;
	}

	printf("\n");
	
	return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
	
	int c, i, j;
		
	for(i = 0, j = strlen(s)-1; i < j; i++, j--) {

		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


/* get_line: read a line from input into s, return length */
int get_line(char s [ ],int lim)
{
	int c, i;

	for(i = 0; i<lim-1 && ( c = getchar()) != 'x' && c != '\n'; i++)
		s[i] = c;

	if(c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	return i;

}


































