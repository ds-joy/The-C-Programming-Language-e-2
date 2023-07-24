#include<stdio.h>
#define MAXLINE 1000 /* maximum length of an input line */

int get_line(char line[], int maxline);


/* print the longest input line */
int main() {
	int len;	/* current line length */
	
	char line[MAXLINE];		/* current input line */	

	while( (len = get_line(line, MAXLINE) ) > 0) {
			printf("%s\n", line);
	}

	return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim) 
{
	int c, i;

	for(i=0; i < lim-1 && (c = getchar() ) != 'x' && c !='\n'; i++) {

		if(c == ' ' || c == '\t') {
			s[i++] = ' ';
			c = getchar();
			while( c == '\t' || c == ' ') {
				c = getchar();
			}
		}
		s[i] = c;
	}
	
		

	if(c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}









































