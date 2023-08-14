#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1024

int get_line(char *s, int lim);
int a_to_i(char *s);

int main()
{
	char line[MAXLINE];
	int number;


	printf("Length of input : %d\n", get_line(line, MAXLINE));

	number = a_to_i(line);

	if(number != -1)
		printf("Equivalent number: %d\n", number);
	

	return 0;
}

/* a_to_i: converts string s into integer, returns that integere */
int a_to_i(char *s)
{

	int c, sign;
	int num;

	while( (c = *s++) == ' ' || c == '\t')	/* removes initial white spaces */
		;

	/* sign check */
	sign = 1;
	if(c == '+' || c == '-') {
		sign = (c == '-') ? -1 : 1;
		c = *s++;
	}

	/* not a digit */
	if( !isdigit(c)) {	
		printf("Error not a valid integer!\n");
		return -1;
	}

	/*	number */
	num = 0;
	while( isdigit(c)) {
		num = 10*num + (c - '0');
		c = *s++;
	}

	num *= sign;

	return num;


}

/* getline: reads one line of input into s, returns length */
int get_line(char *s, int lim)
{
	int c, i;

	for(i = 0; i<lim-1 && (c = getchar()) != '$' && c != '\n'; i++)
		*s++ = c;

	if(c == '\n')
		*s++ = c;
	
	*s = '\0';

	return i;
}

































