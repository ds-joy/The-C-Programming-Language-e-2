#include<stdio.h>

void print_histogram(char s[][], int row, int column);


int main()
{
	int i, j;
	
	int row, column;
	row = 2;
	column = 2;
	char s[1024][1024] ={{'a', ' '}, {'a', 'a'}}; 
	//int c[2][3] = {{1, 3, 0}, {-1, 5, 9}};

	

	
	/*
	
	for(i=0; i<row; ++i)
		for(j=0; j<column; ++j) 
			scanf("%c", &s[i][j]);
	*/

	
	for(i=0; i<row; i++) {
		for(j=0; j<column; j++) 
			printf("%c ", s[i][j]);
		printf("\n");
	}
	return 0;
	
}











































