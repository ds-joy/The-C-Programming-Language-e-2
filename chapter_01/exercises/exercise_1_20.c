#include<stdio.h>

#define MAXLINE 1024
#define TAB_SIZE 5
#define STAR '*'
#define TAB '\t'

int get_line(char s [ ],int lim);
int number_of_spaces(int offset, int tab_size);

int main()
{
	char line[MAXLINE];

	int len;
	int i, j , k, l;
	

	while( (len = get_line(line, MAXLINE)) > 0) {
		
		for(i =0, l=0; i < len; ++i) {
			
			if( line[i] == TAB ) {  
				j = number_of_spaces(l, TAB_SIZE);
				for(k = 0; k < j; k++) {
					putchar(STAR);
					l++;
				}
			}

			else {
				putchar(line[i]);
				l++; 
			}
		}
	}

	return 0;	
}



/*
	reads a line from  the terminal 
	returns the length
*/
int get_line(char s [ ],int lim) 
{
	int c , i;

	for(i = 0; i < lim -1 && ( c = getchar()) != 'x' && c != '\n'; i++)
		s[i] = c;

	if( c == '\n' ) {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}

/* 
	returns the number of spaces to be entered 
 	to replace a tab (\t)
 */
int number_of_spaces(int offset,int tab_size) 
{
	return tab_size - (offset % tab_size);
}


































