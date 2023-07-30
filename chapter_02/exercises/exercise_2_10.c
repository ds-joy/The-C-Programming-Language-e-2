#include<stdio.h>
#define MAXLINE 1028

void modified_lower(char* c);


int main()
{
	char str[MAXLINE];
	int i;

	scanf("%s", str);

	for(i=0; str[i] != '\0'; i++)
		modified_lower(&str[i]);

	printf("%s \n", str);
		

	return 0;
}


void modified_lower(char * c)
{
	(*c >= 'A' && *c <= 'Z') ?
		*c = *c + 'a' -'A': *c ;
}






























