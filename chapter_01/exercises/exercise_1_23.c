#include<stdio.h>
#define MAXLENGTH 2048

int get_program(char s[], int lim);
void delete_comments(char s[], int len);


int main()
{
	char program[MAXLENGTH];
	int i, len;

	len = get_program(program, MAXLENGTH);

	delete_comments(program, len);
}




/* gtet_line: reads a line into s, returns length */
int get_program(char s [ ],int lim)
{
	int c, i;

	for(i=0; i<lim-1 && (c = getchar()) != 'x'; ++i) 
		s[i] = c;
	
	return i;
}



/* deletes c style comments of s char array */ 
void delete_comments(char s [ ], int len)
{
	int i;

	for( i=0; i<len; ++i) {

		
		if(s[i] == '\'' || s[i] == '\"') {	  /* ignores comment like structures in quotation marks */
			
			putchar(s[i]);
			++i;
			
			if(s[i-1] == '\'') {		/* single quotation mark */
				while(s[i] != '\'') {
					putchar(s[i]);
					++i;
				}

				putchar(s[i]);	
			}

			else if(s[i-1] == '\"') {		/* single quotation mark */
				
				while(s[i] != '\"') {
					putchar(s[i]);
					++i;
				}

				putchar(s[i]);	
			}
				
		}
		
		
		
		else if( s[i] == '/' && s[i+1] == '*') {	/* delete multiline comment */
			i += 2;

			while(1) {
				if(s[i] == '*' && s[i+1] == '/') {
					++i;
					break;
				}
				++i;
					
			}
		}

		
		else if( s[i] == '/' && s[i+1] == '/' ) {	/* delete single line comments */
			i += 2;
			while(1) {
				if(s[i] == '\n') 
					break;
				
				++i;
			}
		}

		else
			putchar(s[i]);
	}
	
}


























