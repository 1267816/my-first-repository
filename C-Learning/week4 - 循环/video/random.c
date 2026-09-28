#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int a = rand();
	
	printf("%d\n",a);
	
	return 0;
}