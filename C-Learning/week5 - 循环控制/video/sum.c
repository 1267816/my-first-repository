#include <stdio.h>
int main(){
	int n;
	double t,sum;
	int symbol=1;
	
	scanf("%d",&n);
	
	for (int i=1;i<=n;i++) {
		t=1.0/i*symbol;
		sum+=t;
		symbol*=-1;
	}
	
	printf("f(%d)=%f",n,sum);
	
	return 0;
}