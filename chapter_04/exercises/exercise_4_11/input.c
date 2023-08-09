
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
	int i;
	static int c = ' ';
	int type;
	i = 0;
	
	while( (s[0] = c) == ' ' || c == '\t')
		c = getch();
	s[1] = '\0';


	/* handling library function inputs */
	if(isalpha(c)) {

		if( (!isalpha(c = getch())) ) 
			return VAR;
		
		
		while( isalpha(c) ) {
			s[++i] = c;
			c = getch();
		}

		s[i+1] = '\0';

		return FUNCTIONS;
	} 

	/* c i set to its initial value before return */
	if( !isdigit(c) && c != '.' && c != '-') {	/* not a number */
		type = c;
		c = ' ';
		return type; 	
	}

	if(c == '-') {	/* handling unary '-' */

		if( isdigit(c = getch()) || c == '.' )
			s[++i] = c;
		else {
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



