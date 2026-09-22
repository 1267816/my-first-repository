#include <stdio.h>

int main()
{
	//初始化
	int n = 0;
	int sum = 0;
	int a;
	
	//输入
	scanf("%d",&a);
	
	//主体部分
	while ( a != -1 ) {
		sum = sum + a;
		n = n + 1;
		scanf("%d",&a);
	}
	
	
	//输出
	printf("%f,%d\n",1.0*sum/n,n);
	
	return 0;
}