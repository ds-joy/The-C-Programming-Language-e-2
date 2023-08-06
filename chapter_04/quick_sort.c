#include <stdio.h>
#include <stdlib.h>


void swap(int *px, int *py);
int partition(int arr[], int left, int right);
void quick_sort(int arr[], int left, int right);

void print_array(int arr[], int len);

int main()
{
	int i, n;

	printf("Enter the length of the array: ");
	scanf("%d", &n);

	int arr[n];

	for(i = 0; i < n; i++)
		arr[i] = rand() % 1000;

	quick_sort(arr, 0, n-1);

	print_array(arr, n);

	return 0;
}


/* quick_sort: */

void quick_sort(int arr [ ],int left,int right)
{
	if(left > right)
		return;

	int pivot = partition(arr, left, right);

	quick_sort(arr, left, pivot-1);
	quick_sort(arr, pivot+1, right);

}



/* partition: */
int partition(int arr [ ], int left, int right)
{
	int pivot, pos, i;

	pivot = arr[right];
	pos = left - 1;

	for(i = left; i < right; i++) {
		if(arr[i] < pivot)
			swap(&arr[++pos], &arr[i]);
	}

	swap(&arr[++pos], &arr[right]);
	
	return pos;
	
}







/* swap: swaps the value of &px and &py */
void swap(int *px, int *py)
{
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
}



/* print_array: prints array 'arr' */
void print_array(int arr[], int len)
{
	int i;
	for(i = 0; i < len; i++) {
		if(i % 20 == 0)
			printf("\n");
		printf("%d ", arr[i]);
	}

	printf("\n");
}


































