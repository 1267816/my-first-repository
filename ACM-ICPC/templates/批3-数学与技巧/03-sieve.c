/*
埃氏筛（1..N 素数表）
一行一个整数 N（1 ≤ N ≤ 1e6），输出 1 到 N 之间素数的个数。
样例：
输入：
10
输出：
4
*/

#include <stdio.h>

int sieve(int n) {
	int a[n+1];
	int i,j;
	for (i=1;i<n+1;i++) {
		a[i]=1;
	}
	a[1]=0;
	for (i=2;i*i<=n;i++) {
		if (a[i]==1) {
			for (j=i;i*j<n+1;j++) {
				a[i*j]=0;
			}
		}
	}
	
	int cnt=0;
	for (i=1;i<n+1;i++) {
		if (a[i]==1) {
			cnt++;
		}
	}
	
	return cnt;
}

int main(void) {
	int n;
	scanf("%d",&n);
	
	printf("%d\n",sieve(n));
	return 0;
}