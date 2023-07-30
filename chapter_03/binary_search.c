#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXLEN 1000000



int comparator(const void* p, const void* q);
void print_arr(int arr[], int size);

int binary_search(int arr[], int len, int x);

int main()
{
	int i, n, pos, x, size;
	struct timeval tvalBefore, tvalAfter; 

	/* finding out the array length */
	printf("Enter the number of elements: ");
	scanf("%d", &n);	

	

	/* array input */
	int arr[n];
	for(i = 0; i<n; i++)
		arr[i] = (rand() % 1000) + 1;


	/* sorting the array */
	size = sizeof(arr) / sizeof(arr[0]);
	qsort( (void*)arr, size, sizeof(arr[0]), comparator);
		
		
	/* the number to be searched */
	printf("Please enter the number you want to search: ");
	scanf("%d", &x);

	


	print_arr(arr, size);
	
	/* binary search and run-time mesurement*/
	gettimeofday (&tvalBefore, NULL);
	pos = binary_search(arr,n,x);
	gettimeofday (&tvalAfter, NULL);

	
	if(pos != -1)
		printf("Found at position %d\n", pos);
	else
		printf("Not found\n");

	printf("Time in microseconds: %3f microseconds\n",
            (double) 1000000.0 * ((tvalAfter.tv_sec - tvalBefore.tv_sec) + 
                      (1.0/1000000) * (tvalAfter.tv_usec - tvalBefore.tv_usec)));
	return 0;
}

int binary_search(int arr [ ],int len,int x)
{
	int low, high, mid;

	low = 0;
	high = len - 1;

	while( low <= high) {
		mid = (low+high) / 2;

		if( x < arr[mid])
			high = mid - 1;
		
		else if(x > arr[mid])
			low = mid + 1;
		
		else	/* found match */
			return mid;
	}

	return -1; /* no match */
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

































