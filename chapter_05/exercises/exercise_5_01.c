#include <stdio.h>
#include <ctype.h>
#define MAXLEN 20
#define SIZE 5

int getch();
void ungetch(char c);

int getint(int *pn);
int main()
{
	int n, i, c, array[SIZE]; 

	for(n = 0; n < SIZE && (c = getint(&array[n])) != '$' && c; n++)
		;


	for(i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}

int bufp = 0;		/* next free position in buffer */
int buffer[MAXLEN];	/* buffer for ungetch */





/* getch: get a (possibly pushed-back) character */
int getch()
{
	return (bufp > 0) ? buffer[--bufp] : getchar();
}


/* ungetch: push character back on input */
void ungetch(char c)


{
	if(bufp > MAXLEN)
		printf("Ungetch: Buffer Full");
	else
		buffer[bufp++] = c;
}


/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while(isspace(c = getch())) /* skip white space */
		;

	if( !isdigit(c) && c!='$' && c != '+' && c != '-') {	/*it is not a number */
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if(c == '+' || c == '-')
		while(isspace(c = getch())) /* skip white space */
			;
	
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * (*pn) + (c - '0');

	*pn *= sign;

	if(c != '$')
		ungetch(c);

	return c;
}















































