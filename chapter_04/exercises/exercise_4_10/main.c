#include <stdio.h>
#include <ctype.h>


#define MAXOP 100

#define NUMBER '0'
#define FUNCTIONS 1
#define VAR 'a'





int getop(char s[]);
int get_line(char line[], int lim);


void push(double);
double pop(void);
void show();
void duplicate();
void top_swap();
void clear_stack();



double a_to_f(char s[]);

double f_mod(double a, double b);
void handle_functions(char s[], int* flag);
void handle_var(char c);
void var_push(char c);
char var_pop();

int idx = 0;
char line[MAXOP];


/* reverse polish calculator */
int main()
{	
	int type;
	double op1;
	double op2;
	int flag = 0;
	int len;
	
	
	
	char s[MAXOP];
	
	int i = 0;
	while( (len = get_line(line, MAXOP)) > 0) {
		idx = 0;
		while ((type = getop(s)) != '$' && idx <= len) {
			
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
				if(flag != 1) {
					printf("Result: %.8g\n", pop());
					clear_stack();

				}
				flag = 0;
				break;
			default:
				printf("error: unknown command %s\n", s);
			break;
			}
		}

	}
	return 0;
}


/* getop: get next character or numeric operand */
int getop(char s[ ])
{
	int i, c;

	while( (s[0] = c = line[idx++]) ==' ' || c == '\t')
		;
	s[1] = '\0';


	/* handling library function inputs */
	if( isalpha(c) ) {
		if( !isalpha(c = line[idx++])  ) {
			if(c != '$')
				idx--;
			return VAR;
		}

		while( isalpha(c) ) {
			s[++i] = c;
			c = line[idx++];
		}

		s[i+1] = '\0';

		if(c != '$')
			idx--;
		return FUNCTIONS;
	}

	/* return operator */
	if(!isdigit(c) && c != '.')
		return c;
	
	
	i = 0;
	if(c == '-') {	/* handling unary '-' */

		if( isdigit(c = line[idx++]) || c == '.' )
			s[++i] = c;
		else {
			if( c != '$' )
				idx--;
			return '-';
		}	
	}
	
	if(isdigit(c))		/* collect integer part */
		while(isdigit(s[++i] = c = line[idx++]))
			;

	if(c == '.')		/* collect integer part */
		while(isdigit(s[++i] = c = line[idx++]))
			;

	s[i] = '\0';
	idx--;

	return NUMBER;







	
}

