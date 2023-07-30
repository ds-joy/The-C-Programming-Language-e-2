#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 1000

int main()
{
	int i;
	int arr[MAXLEN];

	/* filling the array with 1000000 random values */
	for(i = 0; i < MAXLEN; i++)
		arr[i] = (int)( rand() % 1000 );

	/* printing the array */
	for(i = 0; i < MAXLEN; i++) {
		if(i % 40 == 0)
			printf("\n");

		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}




































