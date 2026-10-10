#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	
	int *a=malloc(n*sizeof(int));
	if (a==NULL) {
		return 1;
	}
	
	int i;
	for (i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for (i=0;i<n;i++) {
		printf("%d",a[i]);
		if (i==n-1) {
			printf("\n");
		} else {
			printf(" ");
		}	
	}
	
	free(a);
	a=NULL;
	
	return 0;
}