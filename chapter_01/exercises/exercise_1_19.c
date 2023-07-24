#include<stdio.h>
#define MAXLINE 1000

void swap(char s[], int pos1, int pos2);
void reverse(char s[], int len);
int get_line(char line[], int lim);

/* this program reverses an input line */
int main()
{
	int len;
	char line[MAXLINE];

	while( (len = get_line(line, MAXLINE) ) > 0) {
		reverse(line, len - 1);
		printf("%s", line);
	}
}



/* 
	reads a line from the terminal
	and calls the reverse function
*/
int get_line(char s [],int lim)
{
	int c, i;
	for(i=0; i < lim-1 && (c = getchar()) != 'x' && c != '\n'; ++i)
		s[i] = c;

	if( c== '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}




/* a function to reverse a character array */
void reverse(char s [ ],int len)
{
	if(len > 1) {
		int i;
		i = 0;

		while(i < len) {
			swap(s, i++, len--);
		}
	}

}


/* swaps the position of two characters */
void swap(char s [ ],int pos1,int pos2)
{
	char temp;
	
	temp = s[pos1];
	s[pos1] = s[pos2];
	s[pos2] = temp;
}


