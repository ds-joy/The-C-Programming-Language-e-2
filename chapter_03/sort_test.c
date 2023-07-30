#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 1000

/* 
	This function is used in qsort to decide the relative order 
	of elements at addresses p and q. 
*/

int comparator(const void* p, const void* q);
void print_arr(int arr[], int size);

int main()
{
	int i, size;
	int arr[MAXLEN];

	/* filling the array with 1000000 random values */
	for(i = 0; i < MAXLEN; i++)
		arr[i] = (int)( rand() % 1000 );
	

	/* sorting the array */
	size = sizeof(arr) / sizeof(arr[0]);
	qsort( (void*)arr, size, sizeof(arr[0]), comparator);


	/* printing the array */
	print_arr(arr, MAXLEN);
	

	return 0;
}


int comparator(const void* p, const void* q)
{
	return ( *(int*)p - *(int*)q );
}

void print_arr(int arr [ ],int size)
{
	int i;
	for(i = 0; i < size; i++) {
		if(i % 40 == 0)
			printf("\n");

		printf("%d ", arr[i]);
	}

	printf("\n");
}




























