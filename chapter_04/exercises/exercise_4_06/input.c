#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define VAR 'a'
#define FUNCTIONS 1
#define NUMBER '0'

#define BUFSIZE 100
#define MAXVAL 100

int getch(void);
void ungetch(int);


/* getop: get next character or numeric operand */
int getop(char s[ ])
{
	int i, c, next;
	i = 0;
	
	while( (s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';


	/* handling library function inputs */
	if(isalpha(c)) {

		if( (!isalpha(c = getch())) ) {
			if(c != '$')
				ungetch(c);
			return VAR;
		}
		
		while( isalpha(c) ) {
			s[++i] = c;
			c = getch();
		}

		s[i+1] = '\0';

		if(c != '$')
			ungetch(c);
		return FUNCTIONS;
	} 

	
	if( !isdigit(c) && c != '.' && c != '-')	/* not a number */
		return c; 		

	if(c == '-') {	/* handling unary '-' */

		if( isdigit(c = getch()) || c == '.' )
			s[++i] = c;
		else {
			if( c != '$' )
				ungetch(c);
			return '-';
		}	
	}

	
	if(isdigit(c))		/* collect integer part */
		while(isdigit(s[++i] = c = getch()))
			;
		
	if(c == '.')		/* collect fraction part */
		while(isdigit(s[++i] = c = getch()))
			;
		
	s[i] = '\0';
	if(c != '$')
		ungetch(c);

	return NUMBER;
}



char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/* push character back on input */
{
	if(bufp >= BUFSIZE)
		printf("Ungetchar: too many characters\n");
	else
		buf[bufp++] = c;
}



