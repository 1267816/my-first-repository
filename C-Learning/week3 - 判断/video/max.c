#include <stdio.h>

int main()
{
	//初始化
	int a,b,max;
	
	//输入
	printf("请输入两个整数：");
	scanf("%d %d",&a,&b);
	
	//比较
	if (a>=b) {
		max = a;
	} else {
		max = b;
	}	
	
	//输出
	printf("大的那个是：%d",max);
		
	return 0;
}