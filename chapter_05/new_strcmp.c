#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINES 5000

int mystrcmp(char *s1, char *s2);
int 
int main(int argc, char *argv[])
{
	int caseInsensitive = 1;
	int directory = 1;

	return 0;
}


int mystrcmp(char * s1,char * s2)
{
	if(directory) {
		while(!isalnum(*s1) && !isblank(*s1) && *s1)
			++s1;
		while(!isalnum(*s1) && !isblank(*s1) && *s1)
			++s2;
	}
	while(fold ? (tolower(*s1) == tolower(*s2)) : (*s1 == *s2)) {
		if(*s1 == '\0')
			return 0;
		++s1;
		++s2;
		if(directory) {
			while(!isdigit(*s1) && !isalpha(*s1) && !isspace(*s1) && *s1)
				++s1;       /* ignore bad characters */
			while(!isdigit(*s2) && !isalpha(*s2) && !isspace(*s2) && *s2)
				++s2;       /* ignore bad characters */
		}
	}
	return fold ? (tolower(*s1) - tolower(*s2)) : (*s1 - *s2);
}















































