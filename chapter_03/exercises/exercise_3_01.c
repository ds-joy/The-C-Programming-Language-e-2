#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int comparator(const void* p, const void* q);
void print_arr(int arr[], int size);

int binary_search_v1(int arr[], int len, int x);
int binary_search_v2(int arr [], int len, int x);


int main()
{
	int i,n, pos,x, size;
	clock_t time;

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
		
	//print_arr(arr, size);




	/* the number to be searched */
	printf("Please enter the number you want to search: ");
	scanf("%d", &x);
	printf("\n");
	
	
	/* binary search version 01 */
	time = clock();
	for(i = 0; i<1000; i++)
		pos = binary_search_v1(arr,n,x);
	time = clock() - time;
	
	printf("binary_search_v1:\n");
	if(pos != -1)
		printf("Found at position %d\n", pos);
	else
		printf("Not found\n");
	printf("clock cycle taken --> %lu\n\n", (unsigned long) time);


	/* binary search version 02 */
	time = clock();
	for(i = 0; i<1000; i++)
		pos = binary_search_v1(arr,n,x);
	time = clock() - time;
	
	printf("binary_search_v2:\n");
	if(pos != -1)
		printf("Found at position %d\n", pos);
	else
		printf("Not found\n");
	printf("clock cycle taken --> %lu\n\n", (unsigned long) time);

	
	return 0;
}

int binary_search_v1(int arr [ ],int len,int x)
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





int binary_search_v2(int arr [ ],int len,int x)
{
	int low, high, mid;

	low = 0;
	high = len - 1;

	while( low <= high && x != arr[mid]) {
		mid = (low+high) / 2;

		if( x < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;	
	}

	if(x == arr[mid])
		return mid;
	else
		return -1;
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





































