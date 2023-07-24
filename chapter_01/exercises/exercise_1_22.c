#include<stdio.h>

#define MAXLINE 1024
#define OUTPUT_LINE_SIZE 20

int get_line(char s[], int lim);

int main()
{
	char line[MAXLINE];
	int i;

	int len; /* length of the input line */
	int out_len; /* length of the output line */

	while( (len = get_line(line, MAXLINE)) > 0) {

		printf("\nOUTPUT: \n");
		out_len = 0;
		for( i=0; i<len; i++) {

			if( out_len > OUTPUT_LINE_SIZE) {
				putchar('\n');
				out_len = 0;
			} else {
				putchar(line[i]);
				++out_len;
			}
			
		} // end for 

		printf("\n");
		
	} //end while
	
	
	return 0;
}


/* get_line: reads a line into s, returns length */
int get_line(char s[], int lim)
{
	int c, i;

	for(i = 0; i < lim - 1 && ( c = getchar() ) != 'x' && c !=  '\n'; ++i) 
		s[i] = c;

	if(c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}







































