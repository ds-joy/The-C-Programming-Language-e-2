#include <stdio.h>
#include <string.h>

#define MAXLINES 5000	/* the maximum number of lines to be sorted */
#define MAXLEN 1000		/* max length of the lines */

int readlines(char *lineptr[], char store_lines[MAXLINES][MAXLEN], int maxlines);
void writelines(char *lines[], int nlines);
int get_line(char *s, int lim);
void qsort(char *v[], int left, int right);


char* lineptr[MAXLINES];	/* stores pointer to the lines */
char store_lines[MAXLINES][MAXLEN];

/* sort input lines */
int main()
{
	int nlines;	/* number of input lines read */

	if( (nlines = readlines(lineptr, store_lines, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return -1;
	}
}




void swap(char *v[], int i, int j);

/* qsort: sort v[left].....v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, pivot;

	if(left >= right)	/* less than two elements */
		return;
	swap(v, left, (left+right)/2);

	pivot = left;
	for(i = left+1; i <= right; i++)
		if( strcmp(v[i], v[left]) < 0)
			swap(v, ++pivot, i);

	swap(v, left, pivot);
	qsort(v, left, pivot-1);
	qsort(v, pivot+1, right);
	
}







/* readlines: read input lines */
int readlines(char* lineptr[], char store_lines[MAXLINES][MAXLEN], int maxlines)
{
	int i, len, nlines;
	char line[MAXLEN];

	nlines = 0;
	i = 0;
	while( (len = get_line(line, MAXLEN)) > 0)
		if(nlines >= maxlines)
			return -1;
		else {
			line[len-1] = '\0';		/* removing the new line */
			strcpy(store_lines[i], line);
			lineptr[nlines++] = store_lines[i++];
		}
	return nlines;
}




/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	putchar('\n');
	for(i = 0; i<nlines; i++)
		printf("%s\n", lineptr[i]);
}


/*get_line: reads a line into s, returns length */
int get_line(char *s, int lim)
{
	int i, c;

	for(i=0; i<lim-1 && (c = getchar()) != '$' && c != '\n'; i++)
		*s++ = c;

	if(c == '\n') {
		*s++ = c;
		i++;
	}
	*s = '\n';
	
	return i;
}


/*swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	
}



































