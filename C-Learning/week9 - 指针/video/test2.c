#include <stdio.h>

int main(void)
{
	char ac[]= {0,1,2,3,4,5,6,7,8,9};
	char *p=ac;
    char *p1=&ac[5];
	printf("p=%p\n",p);
	printf("p+1=%p\n",p+1);
    printf("p1-p=%d\n",p1-p);
	
	return 0;
}