#include <stdio.h>


void shell_sort(int arr[], int len);
int main()
{
	int len, i;
	printf("Please enter the number of elements: ");
	scanf("%d", &len);
	
	int arr[len+1];
	printf("Please enter the elements: \n");
	for(i =0; i<len; i++)
		scanf("%d", &arr[i]);

	shell_sort(arr, len);
	
	printf("\nSorted array:\n");
	for(i =0; i<len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	

	return 0;
}


/* shell_sort: sort arr in incresing order using shell sort algorithm */
void shell_sort(int arr [ ],int len)
{
	int gap, i, j, temp;

	for(gap = len/2; gap > 0; gap /= 2)		/* initialize the gap size */
		for(i = gap; i < len; i++)
			for(j = i - gap; j >= 0 && arr[j] > arr[j+gap]; j-=gap) { /* compare the gap elements */
				temp = arr[j];
				arr[j] = arr[j+gap];
				arr[j+gap] = temp;
			}
}





































