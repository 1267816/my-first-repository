//用while循环遍历n位正整数的模块

#include <stdio.h>
int main() {
	//初始化
	int n=0;
	
	//输入n
	scanf("%d",&n);
	
	//遍历并输出
	int count=n;
	int min=1;
	while (count>1) {
		min*=10;
		count--;
	}
	int max=min*10;
	int x=min;
	while (x<max) {
		printf("%d ",x);
		x++;
	}
	
	return 0;
}