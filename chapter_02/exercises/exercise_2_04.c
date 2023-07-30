#include<stdio.h>
#define MAXLINE 1024

void squeeze(char str1[], char str2[]);
void delete_char(char str1[], char c);

/* 
	This program deletes each character in
	s1 that matches any character in the string s2.
*/
int main()
{
	char str1[MAXLINE], str2[MAXLINE];
	
	printf("Enter str1: ");
	scanf("%s", str1);

	printf("Enter str2: ");
	scanf("%s", str2);

	squeeze(str1, str2);
	printf("Modified str1: %s\n", str1);
	
	return 0;
}


/* deletes all the char from str1 that matches with str2 */
void squeeze(char str1[ ], char str2[])
{
	int i; 
	
	for(i=0; str2[i] != '\0'; ++i) 
		delete_char(str1, str2[i]);
}




/* deletes all instances of char c from str1 */
void delete_char(char str1 [ ],char c)
{
	int i, j = 0;
	
	for(i = 0; str1[i] != '\0'; i++) 
		if(str1[i] != c)
			str1[j++] = str1[i];
		
	str1[j] = '\0';
}





























