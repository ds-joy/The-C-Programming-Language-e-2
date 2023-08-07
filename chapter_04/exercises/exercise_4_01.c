#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int get_line(char s [ ],int lim);
int strindex(char source[], char searchfor[]);

char pattern[] = "ab";	/* pattern to search for */

/* find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	int idx;

	/* pattern matching and printing the line if matched */
	while(get_line(line, MAXLINE) > 0)
		if( (idx = strindex(line, pattern)) >= 0) {
			printf("rightmost matched index: %d\n", idx);			
		}
		else {
			printf("no match found!\n");
		}

	
	return 0;
}


/*get_line: get line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	i = 0;
	while(--lim > 0 && (c = getchar()) != '$' && c != '\n')
		s[i++] = c;

	if(c == '\n')
		s[i++] = c;

	s[i] = '\0';
	return i;
}



/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;
	int last_match_index = - 1; /* stores the matching index */

	for(i = 0; s[i] != '\0'; i++) {
		for(j = i, k =0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;

		if(k > 0 && t[k] == '\0')
			last_match_index = i;
	}
	return last_match_index;
}













































