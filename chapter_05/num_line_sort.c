#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000		/* max #lines to be sorted */
#define MAXBUF 5000
char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int nlines);
int get_line(char *s,  int lim);
void writelines(char *lineptr[], int nlines);

void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int str_cmp(char *s1, char *s2);

char *alloc(int n);

/* sort input lines */
int main(int argc, char *argv[])
{
	int nlines;	/* number of input lines read */
	int numeric = 0;	/* 1 if numeric sort */


	if(argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;

	if( (nlines = readlines(lineptr, MAXLINES)) >= 0) {
		q_sort( (void**) lineptr, 0, nlines-1,
			(int (*)(void*,void*))(numeric ? numcmp : str_cmp));
		writelines(lineptr, nlines);
		
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}

}


/* readlines: reads lines from the input for sorting */
int readlines(char * lineptr[], int maxlines)
{
	char line[MAXLINES];
	int nlines = 0;
	int len;
	char *p;

	while((len = get_line(line, MAXLINES)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}



/* writeline: prints the sorted lines */    
void writelines(char * lineptr[], int nlines)
{
	int i = 0;
	printf("OUTPUT: \n");
	while(nlines--)
		printf("%s\n", lineptr[i++]);
}



/* q_sort: sort v[], using quick sort algorithm */
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, pivot;
	void swap(void *v[], int i, int j);

	if(left >= right)	/* do nothing if array containes */
		return;			/* less than two elements */

	swap(v, left, (left+right)/2);
	pivot = left;

	for(i = left+1; i<= right; i++)
		if( (*comp)(v[i], v[left]) < 0)
			swap(v, ++pivot, i);
	swap(v, left, pivot);
	q_sort(v, left, pivot-1, comp);
	q_sort(v, pivot+1, right, comp);
}


/* numcmp: compare s1 and s2 numerically */ 
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else 
		return 0;
}

/* str_cmp: compare s1 and s2 lexicographically */
int str_cmp(char *s1, char *s2)
{
	return strcmp(s1, s2);
}


/* swap: swap the values of v[i] & v[j] */
void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}



char allocbuf[MAXBUF];
char *allocp = allocbuf;

/* alloc: allocates n memory space if available, returns pointer */
char *alloc(int n)
{
	if(allocbuf + MAXBUF - allocp >= n) {	/* memory available */
		allocp += n;
		return allocp-n;
	}
	else
		return 0;
}



/* get_line: reads a line in s, returns length */
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




















































