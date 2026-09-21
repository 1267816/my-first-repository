#include <stdio.h>

int main()
{
	//初始化
	int x;
	int ret = 0;
	
	//输入
	scanf("%d",&x);
	
	//处理
	int a = x;
	while ( x > 1 ) {
		x = x / 2;
		ret = ret + 1;
	}
	
	//输出
	printf("log2 of %d is %d.",a,ret);
	
	return 0;
	
}