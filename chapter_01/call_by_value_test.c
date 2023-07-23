#include<stdio.h>

void test(int a);

int main()
{

/*
	a program to check call by value feature
*/

	int a;

	a = 1;
	printf("\na before function call = %d\n", a);

	test(a);
	printf("a after function call = %d\n\n", a);
}

void test(int a)
{
	int b;
	printf("inside function a1 = %d\n", a);

	b = 2;
	a = b + 1;

	printf("inside function a2 = %d\n", a);
}









































