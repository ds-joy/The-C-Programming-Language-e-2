#include <stdio.h>
#define MAXLEN 1024

int copy(char from[], char to[], int len);
int get_line(char s[], int lim);

int main()
{
	char line[MAXLEN];		/* stores input */
	char output[MAXLEN];	/* stores modified output string */

	int input_len, output_len, i;

	input_len = get_line(line, MAXLEN);
	
	output_len =copy(line, output, input_len);


	for(i=0; i<output_len; i++)
		putchar(output[i]);
	printf("\n");

	return 0;
}


/* 
	copy: copying from 'from'char array to 'to' array
		 replacing new lines with \n and tabs with \t.
		 returns the modified array's length
*/
int copy(char from[], char to[], int len)
{
	int i, j;
	char c;
	
	for(i = 0, j = 0; i<len; i++) {
		c = from[i];
		
		switch(c) {
			case '\n':
				to[j++] = '\\';
				to[j++] = 'n';
				break;
				
			case '\t':
				to[j++] = '\\';
				to[j++] = 't';
				break;
				
			default:
				to[j++] = from[i];
		}
	}

	return j;

}


/* 
	get_line: loads the full input into s untill x
			  returns length
*/
int get_line(char s[], int lim)
{
	int c, i;

	for(i = 0; i<lim-1 && (c = getchar()) != 'x'; i++)
		s[i] = c;

	return i;
}





















































