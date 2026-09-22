#include <stdio.h>

int main(){
	//初始化
	int x = 0;
	int n = 0;
	int q = 1;
	int z = 0;
	
	//输入
	scanf("%d",&x);
	
	//处理
	int y = x;
	
	//获取位数
	while ( y > 0 ) {
		y = y / 10;
		n = n + 1;
	}
	
	//获取10的最大位数次方
	while ( n > 1 ) {
		q = q * 10;
		n = n - 1;
	}
	
	//分解并求和
	while ( q > 0 ) {
		z = z + q * ( x % 10 );
		x = x / 10;
		q = q / 10;
	}
	
	//输出
	printf("%d\n",z);
	
	return 0;
}