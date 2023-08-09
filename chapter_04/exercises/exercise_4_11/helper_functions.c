#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void push(double);
double pop(void);
void show();
void duplicate();
void top_swap();
void clear_stack();

void var_push(char c);
char var_pop();

double arr[100];

/* handles working with variables */
void handle_var(char c)
{
	if(c>= 'a' && c<= 'z') {
		var_push(c);
		push(arr[c - 'a']);
		
	}
	
	else {
		var_push(c - 'A' + 'a');
		push(arr[c - 'A' + 'a']);
	}
}





void handle_functions(char s [ ], int* flag)
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
	else if( strcmp(s, "store") == 0) {
		int pos = var_pop() - 'a';
		arr[pos] = pop();

		//printf("pos-->%d value--> %lf \n", pos, arr[pos]);
		
		*flag = 1;
	}
	else
		printf("Unknown identifier\n");
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


