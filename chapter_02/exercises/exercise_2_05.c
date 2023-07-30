/* 
	returns the first location in a string s1
	where any character from the string s2 occurs, 
	or -1 if s1 contains no characters from s2 
*/

#include<stdio.h>
#define MAXLINE 1024

int any(char s1[], char s2[]);
int main()
{
	char str1[MAXLINE], str2[MAXLINE];
	int position;
		
	printf("Enter str1: ");
	scanf("%s", str1);

	printf("Enter str2: ");
	scanf("%s", str2);

	position = any(str1, str2);
	printf("position: %d\n", position);
	
	return 0;
}


/* 
   any: returns the position of the first character of s1
   which matches with any character of s2
*/
int any(char s1 [ ],char s2 [ ])
{
	int i,j;
	
	for(i = 0; s2[i] != '\0'; i++)
		for(j = 0; s1[j] != '\0'; j++)
			if(s2[i] == s1[j])
				return j;
			
	return -1;         
}


























