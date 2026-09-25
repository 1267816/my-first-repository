/*
04-3.统计素数并求和

本题要求统计给定整数M和N区间内素数的个数并对它们求和。

输入格式：

输入在一行中给出2个正整数M和N（1<=M<=N<=500）。

输出格式：

在一行中顺序输出M和N区间内素数的个数以及它们的和，数字间以空格分隔。

输入样例：
10 31
输出样例：
7 143
*/
#include <stdio.h>
int main() {
	//初始化
	int m=0;
	int n=0;
	
	//输入
	scanf("%d %d",&m,&n);
	
	//遍历M到N的所有正整数,然后与1到500内所有正整数的两两乘积进行比较，
	//若二者相等则计数器加1，若最终计数器=2则为素数。
	//对求出的素数，执行素数计数器加1并加和。
	int x=m;
	int y=1;
	int z=1;
	int product=0;
	int count=0;
	int num=0;
	int sum=0;
	
	while (x<=n) {
		while (z<=n) {
			if (y<z) {
				product=y*z;
				y++;
			} else {
				product=y*z;
				z++;
				y=1;
			}
			if (product==x) {
				count++;
			}
		}
		if (count==1) {
			num++;
			sum+=x;
		}
		count=0;
		z=1;
		x++;
	}
	
	//输出
	printf("%d %d",num,sum);
	
	
	return 0;
}