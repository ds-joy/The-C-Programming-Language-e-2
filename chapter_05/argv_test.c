#include<stdio.h>

int main(int argc, char *argv[])
{	
    int i = 1;
	while(--argc > 0) {
		printf("%d: %s\n", i, argv[i]);
		i++;
	}
	return 0;
}









































