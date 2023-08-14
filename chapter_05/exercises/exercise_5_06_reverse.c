#include <stdio.h>
#define MAXLINE 1024

void swap(char *px, char *py);
int get_line(char *s, int lim);
void reverse(char *s);

int main()
{
	char line[MAXLINE];

	get_line(line, MAXLINE);

	reverse(line);
	printf("\nREVERSE: %s\n", line);

	return 0;
}


/* reverse: reverses the string s */
void reverse(char *s)
{
	int s_len;
	char *temp;
	temp = s;

	s_len = 0;
	while(*++temp)
		s_len++;

	s_len /= 2;
	temp--;
	
	while(s_len--)
		swap(s++, temp--);

}

/* getline: reads one line of input into s, returns length */
int get_line(char *s, int lim)
{
	int c, i;

	for(i = 0; i<lim-1 && (c = getchar()) != '$' && c != '\n'; i++)
		*s++ = c;

	if(c == '\n')
		*s++ = c;
	
	*s = '\0';

	return i;
}


void swap(char *px, char *py)
{
	char temp;

	temp = *px;
	*px = *py;
	*py = temp;
}




































