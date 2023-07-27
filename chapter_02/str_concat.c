#include<stdio.h>
#define MAXLEN 1024


int get_line(char s[], int lim);
void str_concat(char s1[], char s2[]);

int main()
{
	char str1[MAXLEN], str2[MAXLEN];
	int len;

	if( (len = get_line(str1,MAXLEN/2) ) > 0 && (len = get_line(str2, MAXLEN/2) ) > 0 ) {
		str_concat(str1, str2);

		printf("%s \n", str1);
	}
	else {
		printf("Invalid input");
	}

	return 0;
}

/* str_concat: concatinates s2 with s1 */
void str_concat(char s1[], char s2[])
{
	int i, j;

	i = j = 0;

	while(s1[i] != '\0') /* find end of s */
		i++;

	s1[i++] = ' ';
	while( (s1[i++] = s2[j++]) != '\0' )
		;
}

/* get_line: reads a line into s, returns length */
int get_line(char s [ ],int lim)
{
	int c, i;

	for(i=0; i < lim-1 && (c = getchar()) != 'x' && c != '\n'; i++)
		s[i] = c;

	s[i] = '\0';

	return i;
}































