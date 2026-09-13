#include <stdio.h>
 
int main()
{
 	int i;
 	scanf("%d", &i);
 	int a = i % 100 %10;
 	int b = i / 100;
 	int c = i %100 / 10;
 	i = a*100 + b + c*10;
 	printf("%d",i);
 	return 0;
}