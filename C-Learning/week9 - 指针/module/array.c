#include <stdio.h>

void print(int *a,int length)
{
	if (length==0) {
		return;
	}
	for (int i=0;i<length;i++) {
		printf("%d\n",a[i]);
	}
}

int main(void)
{
	int a[]={1,2,3};
	print(a,sizeof(a)/sizeof(a[0]));
	
	return 0;
}