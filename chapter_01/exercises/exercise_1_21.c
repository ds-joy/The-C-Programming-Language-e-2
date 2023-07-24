#include<stdio.h>

#define MAXLINE 1024
#define SPACE ' '
#define TAB '\t'
#define HASH '#'

int get_line(char s [ ],int lim);
void replace_tab(char s[], int pos);


int main()
{
	int i, len;
	char line[MAXLINE];
	
	int nSpaces;
	nSpaces = 0;

	while( (len = get_line(line, MAXLINE)) > 0) {
		
		for (i=0; i<len; i++) {
			if(line[i] == SPACE)
				++nSpaces;
			else
				nSpaces = 0;

			if(line[i] == TAB)
				line[i] = HASH;

			if(nSpaces == 4) {
				i -= 3;
				replace_tab(line, i);
			}	
		}

		printf("%s \n", line);
	}
	
}




/* getline: read a line into s, return length */
int get_line(char s [ ],int lim)
{
	int c, i;

	for(i = 0; i < lim-1 && ( c = getchar() ) != 'x' && c != '\n'; ++i) 
		s[i] = c;

	if(c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

/* replace_tab: replaces 4 spaces with a tab */
void replace_tab(char s [ ],int pos)
{
	s[pos++] = '#';

	int i;
	for(i=pos; s[i+3] != '\0'; ++i) {
		s[i] = s[i+3];
	}

	s[i] = '\0';
	
}




