#include <ctype.h>
#define NUMBER '0'

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

