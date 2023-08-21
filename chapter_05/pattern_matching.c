#include <stdio.h>
#include <string.h>
#define MAXLINE 1024

int get_line(char *s, int lim);

/* print lines that match pattern form first languages */
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if(argc != 2)
		printf("Usage: find pattern\n");
	else
		while( get_line(line, MAXLINE) > 0)
			if( strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
	return found;
}



/* get_line: reads input line into s, returns length */
int get_line(char *s, int lim)
{
	int i, c;

	for(i = 0; i < lim-1 && (c = getchar()) != '$' && c != '\n'; i++)
		*s++ = c;

	if(c == '\n') {
		*s++ = c;
		i++;
	}

	*s = '\0';
	return i;
}







































