/*
gcd / lcm（辗转相除）
一行两个正整数 a、b（1 ≤ a, b ≤ 1e9），输出它们的最大公约数和最小公倍数，用空格分隔。
样例：
输入：
12 18
输出：
6 36
*/

#include <stdio.h>

int gcd(int a,int b) {
	while (b!=0) {
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int lcm(int a,int b) {
	return a/gcd(a,b)*b;
}

int main(void) {
	int a,b;
	scanf("%d %d",&a,&b);
	
	printf("%d %d",gcd(a,b),lcm(a,b));
	
	return 0;
}