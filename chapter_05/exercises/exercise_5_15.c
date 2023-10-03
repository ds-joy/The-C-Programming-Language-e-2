#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 1000
#define MAXLINE 1000
#define BUFSIZE 5000

char *lineptr[MAXLINES];
int caseInsensitive = 0;


int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
int get_line(char *s, int lim);

void q_sort(void *v[], int left, int right, int (*comp)(void *, void *), int order);
void swap(void *v[], int i, int j);

int numcmp(char *s1, char *s2);
int str_cmp(char *s1, char *s2);
int strcmpi(char *s1, char *s2);
char *alloc(int n);

int main(int argc, char *argv[])
{
	int numeric = 0;
	int reverse = 0;
	int nlines;
	
	while (--argc > 0) {
        if (strcmp(*++argv, "-n") == 0)
            numeric = 1;
        else if (strcmp(*argv, "-r") == 0)
            reverse = 1;
		else if(strcmp(*argv, "-f") == 0)
			caseInsensitive = 1;
		else {
			printf("usage: ./a.out [-n] [-r] [-f]");
			return 0;
		}
			
    }

	if( (nlines = readlines(lineptr, MAXLINES)) >= 0) {
	
		q_sort( (void**) lineptr, 0, nlines-1,
			(int (*)(void*,void*))(numeric ? numcmp : caseInsensitive? strcmpi : str_cmp), reverse ? -1 : 1);
		
		writelines(lineptr, nlines);
		
		return 0; 
	}
	else {
		printf("input too big for sort");
		return 1;
	}
}



/* readlines: reads n lines from the input and stores them */
int readlines(char *lineptr[], int maxlines)
{
	char line[MAXLINE];
	int len;
	int nlines=0;
	
	char *p;
	
	while( (len = get_line(line, MAXLINE)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
		return nlines;
}



/* writelines: prints the sorted lines */
void writelines(char *lineptr[], int nlines)
{
	int i = 0;
	printf("\nOUTPUT:\n");
	while(nlines--)
		printf("%s\n", lineptr[i++]);
}


/* q_sort: sort v[], using quick sort algorithm */
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *), int order)
{
	int i, pivot;

	
	void swap(void *v[], int i, int j);

	if(left >= right)	/* do nothing if array containes */
		return;			/* less than two elements */

	swap(v, left, (left+right)/2);
	pivot = left;

	for(i = left+1; i<= right; i++)
		if(order * (*comp)(v[i], v[left]) < 0)
			swap(v, ++pivot, i);
	swap(v, left, pivot);
	q_sort(v, left, pivot-1, comp, order);
	q_sort(v, pivot+1, right, comp, order);
}






/* swap: swap value of v[i], v[j] */
void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


/* numcmp: compares s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atoi(s1);
	v2 = atoi(s2);

	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else
		return 0;
}


/* str_cmp: compares s1 and s2 lexicographically */
int str_cmp(char *s1, char *s2)
{
	return strcmp(s1, s2);
}


/* strcmpi: compares s1 and s2 without considering the case*/
int strcmpi(char *s1, char *s2)
{
	int i;
	printf("hi\n");
	for(i = 0; i <= strlen(s1); i++)
		if(toupper(s1[i]) != toupper(s2[i]))
			return toupper(s1[i]) - toupper(s2[i]);
		
	return 0;
}



static char allocbuf[BUFSIZE];
static char *allocp = allocbuf;

/* alloc: allocates n free memory, returns pointer */
char *alloc(int n)
{
	if( allocbuf + BUFSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	}
	else
		return 0;
}


/* get_line: reads a line in s, returns length */
int get_line(char *s, int lim)
{
	int c, i;

	for(i = 0; i < lim-1 && (c = getchar()) != '$' && c != '\n'; i++)
		*s++ = c;

	if(c == '\n') {
		*s++ = c;
		i++;
	}

	*s = '\0';
	return i;
}















