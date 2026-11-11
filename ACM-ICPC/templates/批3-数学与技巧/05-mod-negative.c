/*
取模与负数取模
一行三个整数 a、b、m（-1e9 ≤ a, b ≤ 1e9，1 ≤ m ≤ 1e9），
输出 (a - b) mod m 的非负结果（落在 [0, m)）。
样例：
输入：
3 10 8
输出：
1
*/

#include <stdio.h>

int main(void) {
	int a,b,m;
	scanf("%d %d %d",&a,&b,&m);
	
	int c=a-b;
	int result=(c%m+m)%m;
	printf("%d",result);	
	return 0;
}