#include <stdio.h>

#define MAXVAL 100

int var_sp = 0;
char var_stack[MAXVAL];

void var_push(char c)
{
	if(var_sp < MAXVAL)
		var_stack[var_sp++] = c;

	else
		printf("error: stack full, can't push %c\n", c);
}


/* pop: pop and return top value from stack */
char var_pop(void)
{
	if (var_sp > 0)
		return var_stack[--var_sp];
	else {
		printf("error: stack var empty\n");
		return 'a';
	}
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
