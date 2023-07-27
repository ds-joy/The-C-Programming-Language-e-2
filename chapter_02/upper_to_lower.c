#include<stdio.h>
#define MAXLEN 1024

void lower(char* c);

int main()
{
	int i = 0;
	char str[MAXLEN];

	scanf("%s", str);

	while(str[i] != '\0')
		lower(&str[i++]);

	printf("%s\n", str);

	return 0;
}

/* lower: converts c to lower case; ASCII only */

void lower(char* c)
{
	if(*c >= 'A' && *c <= 'Z')
		*c = *c + 'a' - 'A';
}




























