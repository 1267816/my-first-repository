/*
素数判断（单个）
一行一个整数 n（0 ≤ n ≤ 1e9），是素数输出 prime，否则输出 not prime。
样例一：
输入：97      输出：prime
样例二：
输入：91      输出：not prime
*/

#include <stdio.h>

int isPrime(int n) {
	int ret=1;
	if (n==1||n==0) {
		ret=0;
	} else {
		for (int i=2;i*i<=n;i++) {
			if (n%i==0) {
				ret=0;
				break;
			}
		}
	}
	return ret;
}

int main(void) {
	int n;
	scanf("%d",&n);
	if (isPrime(n)) {
		printf("prime\n");
	} else {
		printf("not prime\n");
	}
	
	return 0;
}