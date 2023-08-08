#include<stdio.h>

#define MAXVAL 100

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


