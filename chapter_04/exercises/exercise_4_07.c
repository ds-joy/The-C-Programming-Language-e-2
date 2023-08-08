#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

int getch();
void ungetch(int c);
void ungets(char str[]);

int main()
{
	char str[] = "BDCOM Bangladesh$";
	ungets(str);

	int c;

	while( (c = getch()) != '$')
		putchar(c);
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

void ungets(char str[])
{
	int size = strlen(str);

	while(size > 0)
		ungetch(str[--size]);
}




























