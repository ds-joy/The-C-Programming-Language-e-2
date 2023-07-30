#include <stdio.h>
#include <string.h>

#define MAXLEN 1024


int get_line(char s[], int lim);
int trim(char s[]);

int main()
{
	char input[MAXLEN];
	int input_len, output_len;
	
	input_len = get_line(input, MAXLEN);
	printf("Input length: %d\n", input_len);

	output_len = trim(input);
	printf("Trimmed output: %s\n", input);
	printf("Output length: %d\n", output_len);
	
	return 0;
}


/* get_line: read full input in s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for(i = 0; i < lim -1 && (c = getchar()) != 'x'; i++)
		s[i] = c;

	s[i] = '\0';
	return i;

}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
	int n;

	for(n = strlen(s) - 1; n >= 0; n--)
		if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;

	s[n+1] = '\0';
	return n+1;
}


























