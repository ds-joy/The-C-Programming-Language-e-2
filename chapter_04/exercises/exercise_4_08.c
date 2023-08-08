#include <stdio.h>
#include <string.h>

#define BUFSIZE 1

int getch();
void ungetch(int c);


int main()
{
	int c;

	while( (c = getch()) != '$') {
		if(c == '*') 
			ungetch('#');
		else
			putchar(c);
	}
	
	putchar('\n');	
	return 0;
}


int bufp = 0;
char buffer[BUFSIZE];

int getch()
{
	return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("Ungetchar: too many characters\n");
	else
		buffer[bufp++] = c;

}










































