#include <stdio.h>

#define MAXLEN 512

void expand(char s1[], char s2[]);
void print_string(char s[]);
int main()
{
	char s1[20];	/* holds the shorthand notation */
	char s2[MAXLEN];	/* holds the expanded notation */

	scanf("%s", s1);


	expand(s1, s2);
	print_string(s2);

	return 0;
}


/* expand: expands the shorthand notation from s1 into s2 */
void expand(char s1[], char s2[])
{
	int i, j;
	char start, end;

	i = j = 0;
	if(s1[i] == '-')
		i++;
	
	start = end = s1[i];
	i++;
	while(s1[i] != '\0') {
		
		if(s1[i] == '-') { /* a-b-f type case */
			start = end;
			i++;
			end = s1[i];
		}
		else {		/* a-z0-9 type case */
			start = s1[i];
			i += 2;
			end = s1[i];
		}

		while(start <= end) { 	/* expanding from start to end */
			
			if(j > 0 && s2[j-1] == start) /* in a-b-c type cases, avoids printing b twice */
				start += 1;
			
			s2[j] = start;
			j++;
			start += 1;
		}
		
		i++;
	}

	s2[j] = '\0';
}


/* print_string: print string s */
void print_string(char s[])
{
	int i = 0;
	while(s[i] != '\0') {
		putchar(s[i]);
		i++;
	}
	printf("\n");

}
























