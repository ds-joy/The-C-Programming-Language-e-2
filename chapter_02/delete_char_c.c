#include<stdio.h>
#define MAXLEN 1024

void squeeze(char s[], int c);
int main()
{
	char str[MAXLEN];

	printf("Please enter a string: ");
	scanf("%s", str);

	printf("%s \n", str);
		
	

	return 0;
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
	int i, j;

	for(i=j=0; s[i] != '\0'; i++) {
		if(s[i] != c)
			s[j++] = s[i];
	}
	
	s[j] = '\0';
	
}
































