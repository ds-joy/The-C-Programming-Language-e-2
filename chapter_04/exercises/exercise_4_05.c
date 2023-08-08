#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNCTIONS 1
#define BUFSIZE 100
#define MAXVAL 100



int getop(char []);

void push(double);
double pop(void);
void show();
void duplicate();
void top_swap();
void clear_stack();

int getch(void);
void ungetch(int);

double a_to_f(char s[]);

double f_mod(double a, double b);
void handle_functions(char s[]);



/* reverse polish calculator */
int main()
{	
	int type;
	double op1;
	double op2;
	
	char s[MAXOP];
	
	while ((type = getop(s)) != '$') {
		switch (type) {
		case NUMBER:
			push(a_to_f(s));
			break;
		case FUNCTIONS:
			// printf("Functions\n");
			handle_functions(s);
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
		case '%':
			op2 = pop();
			op1 = pop();
			push( f_mod(op1, op2) );
			break;
		case '?':
			show();
			break;
			
		case '#':
			duplicate();
			break;
			
		case '@':
			top_swap();
			break;

		case '!':
			clear_stack();
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

double f_mod(double a,double b) 
{	
	double mod;

	if(a < 0)
		mod = -a;
	else
		mod = a;

	if(b < 0)
		b = -b;
	
	while(mod >= b)
		mod = mod - b;

	if(a < 0)
		return -mod;

	return mod;

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
		
		while( isalpha(c = getch()) ) {
			s[++i] = c;
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


/* duplivate: duplicates the top element of the stack */
void duplicate()
{
	double temp;

	temp = pop();
	push(temp);
	push(temp);
}


/* show: prints the top element of the stack */
void show()
{	
	if(sp > 0)
		printf("Top of stack = %lf", val[sp-1]);
	else
		printf("Empty Stack!!");
}



/* top_swap: swaps the top 2 positions of the stack */
void top_swap()
{
	double item1 = pop();
	double item2 = pop();

	push(item1);
	push(item2);
}

/* clear_stack: clears the entire stack */
void clear_stack()
{	
	sp = 0;
}


void handle_functions(char s [ ])
{
	/* 
		printf("handle Functions\n");
	    printf("%s \n", s);
	*/
	double rad;
	double value = pop();
	//printf("value = %lf\n", value);
	
	rad = (M_PI / 180.0) * value;
	
	if( strcmp(s, "sin") == 0) {	
		push( sin(rad) );
	}
	else if( strcmp(s, "cos") == 0) {	
		push( cos(rad) );
	}
	else if( strcmp(s, "tan") == 0) {	
		push( tan(rad) );
	}
	else if( strcmp(s, "exp") == 0) {	
		push( exp(value) );
	}
	else if( strcmp(s, "log") == 0) {	
		push( log(value) );
	}
	else if( strcmp(s, "pow") == 0) {	
		push( pow(pop(), value) );
	}
	else
		printf("Unknown identifier\n");
}


