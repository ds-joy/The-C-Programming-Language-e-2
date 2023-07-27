#include<stdio.h>
#define MAXLENGTH 1024


int main()
{
	int c, 
	int len;	/* holds the length of the string */
	char str[MAXLENGTH];	/* holds the string */

	len = 0;
	scanf("%s", str);

	while(str[len] != '\0')
		++len;

	printf("%d \n", len);
		
	
}




















