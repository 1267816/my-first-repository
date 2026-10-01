#include <stdio.h>
int main(){
	int n;
	double t,sum;
	int symbol=1;
	
	scanf("%d",&n);
	
	//注意1.0的使用，把int i和symbol运算结果强制变成double型
	//这里也可以不使用1.0强制转换，double symbol=1.0也可
	for (int i=1;i<=n;i++) {
		t=1.0/i*symbol;
		sum+=t;
		symbol*=-1;
	}
	
	printf("f(%d)=%f",n,sum);
	
	return 0;
}