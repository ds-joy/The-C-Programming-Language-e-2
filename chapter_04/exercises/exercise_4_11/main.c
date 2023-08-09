#include <stdio.h>


#define MAXOP 100

#define NUMBER '0'
#define FUNCTIONS 1
#define VAR 'a'




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
void handle_functions(char s[], int* flag);
void handle_var(char c);
void var_push(char c);
char var_pop();



/* reverse polish calculator */
int main()
{	
	int type;
	double op1;
	double op2;
	int flag = 0;
	
	
	char s[MAXOP];
	
	while ((type = getop(s)) != '$') {
		switch (type) {
		case NUMBER:
			push(a_to_f(s));
			break;
		case FUNCTIONS:
			handle_functions(s, &flag);
			break;
		case VAR:
			handle_var(s[0]);
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
			if(flag == 1) {
				flag = 0;
			} else {
				printf("Result: %.8g\n", pop());
			}
			break;
		default:
			printf("error: unknown command %s\n", s);
		break;
		}
	}
	return 0;
}

