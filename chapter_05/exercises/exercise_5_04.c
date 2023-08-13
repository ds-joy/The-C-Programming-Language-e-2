#include <stdio.h>

#define MAXSIZE 1024

int strend(char *s, char *t);
int main()
{
	char s[MAXSIZE];
	char t[MAXSIZE];

	printf("Please enter s: ");
	scanf("%s", s);

	printf("Please enter t: ");
	scanf("%s", t);

	printf("%d\n", strend(s,t));
	
	
	return 0;
}

/* strend: returns 1 if string t is present at the end of s 0 otherwise */
int strend(char *s, char *t)
{	
	int t_len;	/* stores the length of string t */
	int flag;	/* 1 if matches, 0 otherwise */
	
	
	while(*(++s)) ;	/* go to the end of string s */

	s--;	/* point to the last char of string s */

	t_len = 0;
	while(*(++t))
		t_len++;

	t--;
	
	flag = 1;
	while(t_len--) {	/* start matching from the last position */
		
		if( *(s--) != *(t--)) {
			flag = 0;
			break;
		}	
	}

	return flag;
}


















































