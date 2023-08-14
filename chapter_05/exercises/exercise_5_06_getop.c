#include <stdio.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'


int get_op(char *s);

int main()
{
	int type;
	char s[MAXOP];

	while( (type = get_op(s)) != '$') {
		
		switch(type)  {
			case NUMBER:
				printf("TYPE: NUMBER\n");
				printf("NUM = %s\n", s);
				break;

			case '+':
				printf("TYPE: +\n");
				break;

			case '-':
				printf("TYPE: -\n");
				break;
				
			case '*':
				printf("TYPE: *\n");
				break;

			case '/':
				printf("TYPE: /\n");
				break;
				
			case '%':
				printf("TYPE: +\n");
				break;
				
			case '\n':
				printf("TYPE: NEW LINE\n");
				break;

			default:
				printf("Unknown operator\n");
				break;

		}
	
	}


	return 0;
}


int get_op(char *s)
{
	char temp;
	static int c = ' ';

	while( (*s = c) == ' ' || c == '\t')
		c = getchar();
	*s = '\0';

	if( !isdigit(c) ) {
		temp = c;
		c = ' ';
		return temp;
	}
	
	while(isdigit(c)) {
		*s++ = c;
		c = getchar();
	}

	*s = '\0';
	return NUMBER;

}






































