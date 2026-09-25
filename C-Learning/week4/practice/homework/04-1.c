/*
04-1. 水仙花数

水仙花数是指一个N位正整数（N>=3），它的每个位上的数字的N次幂之和等于它本身。
例如：153 = 1^3 + 5^3+ 3^3。本题要求编写程序,计算所有N位水仙花数。

输入格式：

输入在一行中给出一个正整数N（3<=N<=7）。

输出格式：

按递增顺序输出所有N位水仙花数，每个数字占一行。

输入样例：

3

输出样例：

153
370
371
407
*/
#include <stdio.h>
int main()
{
	//初始化
	int n=0;
	
	//输入
	scanf("%d",&n);
	
	//处理并输出
	int q=n;
	int min=1;
	while (q>1) {
		min*=10;
		q--;
	}
	int max=min*10;
	int x=min;
	int y=x;
	int z=0;
	int t=0;
	int cnt=n;
	int sum=0;
	while (x<max) {
		while (y>0) {
			z=y%10;
			t=z;
			while (cnt>1) {
			z*=t;
			cnt--;
			}
			sum+=z;
			y/=10;
			cnt=n;
		}
		if (sum==x) {
			printf("%d\n",x);
		}
		x++;
		y=x;
		sum=0;
	}

	return 0;
}
