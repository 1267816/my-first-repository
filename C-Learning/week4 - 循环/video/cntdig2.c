#include <stdio.h>

int main()
{
	//初始化
	int x;
	int n = 0;
	
	//输入
	scanf("%d",&x);
	
	//判断
	do {
		n = n + 1;
		x = x / 10;
	} while ( x > 0 );
		
	//输出
	printf("%d\n",n);
	
	return 0;
}