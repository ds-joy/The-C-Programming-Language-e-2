#include<stdio.h>
#include<limits.h>


int main()
{
	printf("\nRange of char : %d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("Range of unsigned char :0 to %d\n\n", UCHAR_MAX);
	
	printf("Range of short : %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("Range of ungigned short : 0 to %d\n\n",USHRT_MAX);
	
	printf("Range of int : %d to %d\n", INT_MIN, INT_MAX);
	printf("Range of ungigned int : 0 to %u\n\n",UINT_MAX);
	
	
	printf("Range of long : %ld to %ld\n", LONG_MIN, LONG_MAX);
	printf("Range of ungigned long : 0 to %lu\n\n",ULONG_MAX);

	printf("\n");
	
}
































