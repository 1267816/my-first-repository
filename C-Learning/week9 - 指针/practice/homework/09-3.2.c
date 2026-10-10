#include <stdio.h>

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	
	int i;
	int a[n];
	int b[n];
	
	for (i=0;i<n;i++) {
		scanf("%d",&a[i]);
		b[(i+k)%n]=a[i];
	}
	
	for (i=0;i<n;i++) {
		printf("%d",b[i]);
		if (i==n-1) {
			printf("\n");
		} else {
			printf(" ");
		}
	}
	
	return 0;
}