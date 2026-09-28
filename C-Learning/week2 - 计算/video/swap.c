#include <stdio.h>

int main()
{
	int a=5;
	int b=6;
	int t;
	t=a;
	a=b;
	b=t;
	printf("a=%d,b=%d",a,b);
	return 0;
}