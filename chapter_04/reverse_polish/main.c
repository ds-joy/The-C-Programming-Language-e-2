#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);



double a_to_f(char s[]);

double f_mod(double a, double b);

/* reverse polish calculator */
int main()
{	
	int type;
	double op2;
	double op1;
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
			
		case '%':
			printf("inside %");
			op2 = pop();
			op1 = pop();
			printf("%ld %ld\n", op1, op2);
			push(f_mod(op1, op2));
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

