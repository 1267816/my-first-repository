#include <stdio.h>
int main(){
	int a,b,max,min,r;
	scanf("%d %d",&a,&b);
	if (a>=b) {
		max=a;
		min=b;
	} else {
		max=b;
		min=a;
	}
	while (max%min!=0) {
		r=max%min;
		max=min;
		min=r;
	}
	printf("%d",min);

	return 0;
}