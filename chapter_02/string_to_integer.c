#include<stdio.h>
#define MAXLINE 1024

int string_to_int(char s[]);

int main()
{
	char s[MAXLINE];

	printf("Enter number: ");
	scanf("%s", s);

	printf("%d\n",string_to_int(s));
	
	return 0;
}


/* string_to_int: convert s to integer */

int string_to_int(char s[]) 
{
	int n, i;
	n = 0;

	for(i = 0; s[i] >= '0' && s[i] <= '9'; i++)
		n = 10 * n + (s[i] - '0');
	

	return n;
}



















