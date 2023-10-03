#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLINE 1024
#define ALLOCSIZE 5000


void read_line(char *str_queue[]);
void write_line(char *str_queue[]);
char *alloc(int n);

int get_line(char *s, int lim);
int a_to_i(char *s);

void enqueue(char *s, char *str_queue[]);
char *dequeue(char *str_queue[]);

int queuesize;
int tail = 0;

int main(int argc, char *argv[])
{
	
	int tail;
	if(argc != 2) {
		printf("USAGE: ./a.out -n;\nwhere n is number of lines to be printed from the end\n");
		return -2;
	}

	int n = a_to_i(argv[1]);

	/* without '-' */
	if(n > 0) {
		printf("USAGE: ./a.out -n;\nwhere n is number of lines to be printed from the end\n");
		return -2;
	}
	n = -n;
	queuesize = n;
	printf("%d\n", n);

	char *str_queue[n];

	read_line(str_queue);
	write_line(str_queue);


	return 0;
}




/* read_line: reads n lines from input and stores their address in lineptr */
void read_line(char *str_queue[])
{
	int len;
	char *p;

	char line[MAXLINE];

	while((len = get_line(line, MAXLINES)) > 0) {
		if( (p = alloc(len+1)) != NULL) {
			strcpy(p, line);
			enqueue(p, str_queue);
		}
		else
			printf("not enough memory");
	}
	
}



/* write_line: prints last n lines of the input */
void write_line(char *str_queue[])
{

	int i = 0;
	
	printf("\nOUTPUT:\n");
	while(i < tail)
		printf("%s", str_queue[i++]);
	printf("\n");
}


char allocbuffer[ALLOCSIZE];
char *allocp = allocbuffer;


/* alloc: return pointer to n characters */
char *alloc(int n)
{
	if(allocbuffer + ALLOCSIZE - allocp >= n) { /* enough memory available */
		allocp += n;
		return allocp - n;
	} else
		return 0;
}










void enqueue(char *p, char *str_queue[])
{
	if(tail < queuesize) {
		str_queue[tail] = p;
		tail++;
	}
	else {
		dequeue(str_queue);
		enqueue(p, str_queue);
	}
}

char *dequeue(char *str_queue[])
{	
	int i;
	char *p;
	
	if(tail <= 0)
		printf("DEQUEUE: Empty queue!\n");
	else {
		p = str_queue[0];
		for(i = 0; i < tail; i++)
			str_queue[i] = str_queue[i+1];
		tail--;
	}
	return p;
}




/* get_line: reads a line into s, returns length */
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




/* a_to_i: converts a string into integer */
int a_to_i(char *s)
{
	int num = 0;
	int sign = 1;
	char c;

	c = *s;
	if(c == '-') {
		sign = -1;
		*s++;
	}

	while( (c = *s++) ) 
		num = 10*num + c - '0';

	num *= sign;

	return num;

}
















































