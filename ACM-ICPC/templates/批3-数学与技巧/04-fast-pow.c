/*
快速幂
一行三个整数 a、e、m（1 ≤ a ≤ 1e9，0 ≤ e ≤ 1e9，1 ≤ m ≤ 1e9），输出 a^e mod m。
样例：
输入：
2 10 1000
输出：
24
*/

#include <stdio.h>

long long quick_pow(int a,int e,int m) {
	long long res=1;
	long long base=a%m;
	while (e>0) {
		if (e%2==1) {
			res=(res*base)%m;
		}
		base=(base*base)%m;
		e/=2;
	}
	return res;
}

int main(void) {
	int a,e,m;
	scanf("%d %d %d",&a,&e,&m);
	
	printf("%lld\n",quick_pow(a,e,m));
	
	return 0;
}