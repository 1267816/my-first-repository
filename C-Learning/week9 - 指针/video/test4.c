#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int number;
	int *a;
	int i;
	printf("输入数量：");
	scanf("%d",&number);
	a=malloc(number*sizeof(int));
	for (i=0;i<number;i++) {
		scanf("%d",&a[i]);
	}
	for (i=number-1;i>=0;i--) {
		printf("%d ",a[i]);
	}
	return 0;
}