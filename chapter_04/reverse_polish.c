#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100   /* max size of operand or operator */
#define MAXVAL 100  /* maximum depth of val stack */
#define BUFSIZE 100	/* buffer for ungetch */
#define NUMBER '0'



int getop(char []);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

double a_to_f(char s[]);


/* reverse polish calculator */
int main()
{	
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != '$') {
		switch (type) {
		case NUMBER:
			push(a_to_f(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("Result: %.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
		break;
		}
	}
	return 0;
}





int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */


/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}


/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next character or numeric operand */
int getop(char s[ ])
{
	int i, c;

	while( (s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';
	if( !isdigit(c) && c != '.' )
		return c; 		/* not a number */

	i = 0;
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


/* a_to_f: convert string s to double */
double a_to_f(char s[])
{

	double val, power;
	int i, sign, exp = 0;

	for(i=0; isspace(s[i]); i++) /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;

	for(val = 0.0; isdigit(s[i]); i++) 
		val = 10.0 * val + (s[i] - '0');

	if(s[i] == '.')
		i++;

	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}


	
	if(s[i] == 'e' || s[i] == 'E') { 	/* scientific notation check */
		i++;
		
		if(s[i] == '-' || s[i] == '+') { /* scientific notation's sign */
			
			if(s[i] == '-') {	/* 123.45e-6 type case */
				i++;
				exp = s[i] - '0';

				while(exp > 0) {
					power *= 10;
					exp--;
				}
		    }

			else {	/* 123.45e+6 type case */
				i++;
				
				exp = s[i] - '0';
				while(exp > 0) {
					power /= 10;
					exp--;
				}
		    }
		}

		else {		/* 123.45e6 type case */
			
			exp = s[i] - '0';

			while(exp > 0) {
				power /= 10;
				exp--;
			}
		}
 	}

	return sign * val / power;
}































