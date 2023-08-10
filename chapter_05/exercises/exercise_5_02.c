#include <stdio.h>
#include <ctype.h>

#define MAXLEN 20
#define SIZE 5

int getch();
void ungetch(int c);
int getfloat(float *pn);


int main()
{	
	int n, c, i;
	float array[MAXLEN];

	for(n = 0; n < SIZE && (c = getfloat(&array[n]) ) != '$' && c; n++)
		;

	
	for(i = 0; i < n; i++)
		printf("%f ", array[i]);
	printf("\n");

	
	return 0;
}


int bufp = 0;	/* next empty place in buffer */
int buffer[MAXLEN];	/* buffer for ungetch */


/* getch: get a (possible from buffer) character */
int getch()
{
	return (bufp > 0) ? buffer[--bufp] : getchar();
}

/* ungetch: put a character back in input */
void ungetch(int c)
{
	if(bufp > MAXLEN)
		printf("ungetch: buffer full\n");
	else
		buffer[bufp++] = c;
}


/* getfloat: reads a floating point number from the input */
int getfloat(float *pn)
{
	int c, sign, power;

	while ( isspace(c = getch())  )		/* skip white space */
		;

	if( !isdigit(c) && c != '$' && c != '+' && c != '-') {
		ungetch(c);	/* it is not a number */
		return 0;
	}
	
	sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		c = getch();

	*pn = 0.0;
	while(isdigit(c)) {
		*pn = 10 * (*pn) + (c - '0');
		c = getch();
	}

	power = 1;
	if(c == '.') {
		while(isdigit(c = getch() )) {
			power *= 10;
			*pn = 10 * (*pn) + (c - '0');
		}
	}

	*pn = *pn / power;
	*pn *= sign;

	if(c != '$')
		ungetch(c);
	
	return c;
}







































