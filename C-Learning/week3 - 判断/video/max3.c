#include <stdio.h>

int main()
{
	//初始化
	int a,b,c,max;
	
	//输入
	printf("请输入三个整数：");
	scanf("%d %d %d",&a,&b,&c);
	
	//比较
	if ( a>=b ) {
		if ( a >= c) {
			max = a;
		} else {
			max = c;
		}
	} else {
		if ( b>=c ){
			max = b;
		} else {
			max = c;
		}
	}
	
	//输出
	printf("%d",max);
	
	return 0;
}