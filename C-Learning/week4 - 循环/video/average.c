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
	if ( n != 0 ) {
		printf("%f,%d\n",1.0*sum/n,n);
	} else {
		printf("没有输入有效数字，无法计算平均值.\n");
	}
	
	return 0;
}