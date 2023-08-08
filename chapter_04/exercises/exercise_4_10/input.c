#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define VAR 'a'
#define FUNCTIONS 1
#define NUMBER '0'

#define BUFSIZE 100
#define MAXVAL 100






/* get_line: reads a line of input into line returns length */
int get_line(char line[], int lim)
{
	int i, c;

	for(i = 0; i< lim-1 && (c = getchar()) != '$' && c != '\n'; i++) 
		line[i] = c;

	if(c == '\n') {
		line[i] = c;
		i++;
	}

	line[i] = '\0';
	return i;

}


































