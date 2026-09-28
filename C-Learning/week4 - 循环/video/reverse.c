#include <stdio.h>

int main(){
	//初始化
	int x = 0;
	int z = 0;
	
	//输入
	scanf("%d",&x);
	
	//处理
	while ( x > 0 ) {
    z = z * 10 + x % 10;
    x = x / 10;
	}
	
	//输出
	printf("%d\n",z);
	
	return 0;
}