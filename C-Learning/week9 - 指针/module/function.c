#include <stdio.h>

void minmax(int *min,int *max,int a[],int length);

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10,12,15,20,33,55};
	int min,max;
	minmax(&min,&max,a,sizeof(a)/sizeof(a[0]));
	printf("min=%d,max=%d",min,max);
	return 0;
}

void minmax(int *min,int *max,int a[],int length)
{
	if (length==0) {
		return;
	}
	
	*min=a[0];
	*max=a[0];
	for (int i=0;i<length;i++) {
		if (a[i]<*min) {
			*min=a[i];
		} else if (a[i]>*max) {
			*max=a[i];
		}
	}
}