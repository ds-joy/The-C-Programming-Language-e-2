#include<stdio.h>
#define MAXLINE 1024


int get_line(char s[], int lim);

int main()
{
	char line[MAXLINE];
	int len, i;
	i = 0;
	while( (len = get_line(line, MAXLINE)) > 0 ) {
		
		while(line[i] != '\n') {
			putchar(line[i]);
			++i;
		} 
		
		printf("length %d \n\n", len);
	}

	
	return 0;
}


/* 
	get_line: modified get_line function,
	for loop without usinf && and ||
*/

int get_line(char s[], int lim)
{
	int c, i;

	for(i = 0; i<lim-1; ) 
		if((c = getchar()) != 'x') {
			if(c != '\n') {
				s[i] = c;
				i++;
			}
				
			else 
				break;
		}

		else
			break;
			

	if(c == '\n') {
		s[i] = c;
		++i;
	}

	return i;
}































