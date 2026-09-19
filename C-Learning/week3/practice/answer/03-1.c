#include <stdio.h>
 
int main()
{
	int i;
	scanf("%d", &i);	
	if(i%5 <= 3 && i%5 != 0)
	     printf("Fishing in day %d", i);
	else 
	     printf("Drying in day %d", i);
	return 0;
} 