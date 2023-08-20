#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXOP 100
#define NUMBER '1'
#define INVALID '0'


void push(int n);
int pop();

int a_to_i(char *s);
int get_op(char *value);

int stack[MAXOP];
int top = 0;

 
int main(int argc, char *argv[])
{
	char s[MAXOP];
	int type;
	int i = 1;
	int op1, op2;
	int flag = 0;
	
	while(--argc) {
		if(flag)
			break;
		type = get_op(argv[i++]);
		

		
		//printf("stack: %d\n", stack[top - 1]);
		switch(type) {
			case NUMBER:
				push(a_to_i(argv[i - 1]));
				break;
				
			case '+':
				op2 = pop();
				op1 = pop();
				push(op1 + op2);
				break;

				
			case '-':
				op2 = pop();
				op1 = pop();
				push(op1 - op2);
				break;
				
			case '*':
				op2 = pop();
				op1 = pop();
				push(op1 * op2);
				break;
				
			case '/':
				op2 = pop();
				op1 = pop();
				push(op1 / op2);
				break;
			case INVALID:
			default:
				printf("Invalid input\n");
				flag = 1;
				break;	
		}
	}

	printf("Result: %d\n", pop());
	return 0;
}



int get_op(char *value)
{
	char c = *value++;
	int len;

	if( !isdigit(c) && c != '-')
		return c;

	if(c == '-') {
		len = strlen(value);
		if(len == 0) 
			return c;
			
		else if( isdigit(*value)) 
			return NUMBER;
		else
			return INVALID;
	}

	return NUMBER;
	
}









void push(int n)
{
	if(top > MAXOP)
		printf("PUSH: Stack Full!\n");
	else
		stack[top++] = n;
}

int pop()
{
	if(top < 1)
		printf("POP: Empty Stack!\n");
	else
		return stack[--top];
}


int a_to_i(char *s)
{
	int num;
	int sign;

	sign = (*s == '-') ? -1 : 1;

	if(*s == '-' || *s == '+')
		s++;

	num = 0;
	while(*s) {
		num = num*10 + *s - '0';
		s++;
	}

	num *= sign;

	return num;

}
