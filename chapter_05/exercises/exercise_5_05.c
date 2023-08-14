#include <stdio.h>
#include <string.h>

#define MAXSIZE 1024

void strn_cpy(char *s, char *t, int n);
void strn_cat(char *s, char *t, int n);
int strn_cmp(char *s, char *t, int n);

int main()
{
	char s[MAXSIZE];
	char t[MAXSIZE];
	int n;

	int s_len;
	int t_len;

	printf("Please enter s: ");
	scanf("%s", s);

	printf("Please enter t: ");
	scanf("%s", t);

	printf("Please enter n: ");
	scanf("%d", &n);
	
	/* strings must be at least n characters long */ 
	s_len = strlen(s);
	t_len = strlen(t);
	if(s_len < n || t_len < n) 
		printf("Strings must be at least %d characters long.\n", n);

	printf("STRNCMP: %d\n", strn_cmp(s, t, n));

	strn_cpy(s, t, n);
	printf("STRNCPY: %s\n", s);

	strn_cat(s, t, n);
	printf("STRNCAT: %s\n", s);

		
	return 0;
}



/* strn_cpy: copies the first n characters of t into s */
void strn_cpy(char * s, char * t, int n)
{
	while(n--)
		*s++ = *t++; 
}



/* strn_cat: concats first n char of string t after string s */
void strn_cat(char *s, char *t, int n)
{
	while(*++s) ; /* reach the end of string s */

	while(n--)
		*s++ = *t++;
}




/* strn_cmp: compares the first n characters of both the strings */
int strn_cmp(char * s, char * t, int n)
{
	int i = 0;
	int flag = 1;

	for(i = 0; i < n; i++) {
		if( *(s++) != *(t++) ) {
			flag = 0;
			break;
		}
	}

	return flag;
}

