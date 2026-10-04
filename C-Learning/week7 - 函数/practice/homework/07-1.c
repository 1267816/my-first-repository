/*
07-1. 换个格式输出整数
让我们用字母B来表示“百”、字母S表示“十”，
用“12...n”来表示个位数字n（<10），
换个格式来输出任一个不超过3位的正整数。
例如234应该被输出为BBSSS1234，
因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：
234
输出样例1：
BBSSS1234
输入样例2：
23
输出样例2：
SS123
*/
#include <stdio.h>

int min(int n){
	int ret=1;
	while (n>9) {
		ret*=10;
		n/=10;
	}
	return ret;
}

void printf_1(int ones) {
	for (int i=1;i<=ones;i++) {
		printf("%d",i);
	}
}

void printf_10(int tens) {
	for (int i=1;i<=tens;i++) {
		printf("S");
	}
}

void printf_100(int hundreds) {
	for (int i=1;i<=hundreds;i++) {
		printf("B");
	}
}

int main(){
	int n=0;
	
	scanf("%d",&n);
	
	int m=min(n);
	int ones=0;
	int tens=0;
	int hundreds=0;
	
	if (n<=9) {
		ones=n;
		printf_1(ones);
	} else if (n<=99) {
		tens=n/m;
		ones=n%m;
		printf_10(tens);
		printf_1(ones);
	} else {
		hundreds=n/m;
		n%=m;
		m/=10;
		tens=n/m;
		ones=n%m;
		printf_100(hundreds);
		printf_10(tens);
		printf_1(ones);
	}
	
	return 0;
}