/*
计数桶 cnt[x]++
第一行 n（1 ≤ n ≤ 1e5），第二行 n 个整数 a_i（1 ≤ a_i ≤ 100）。
输出出现次数最多的那个数和它的出现次数，用空格分隔；次数相同时取数值较小的那个。
样例：
输入：
6
3 1 3 2 3 1
输出：
3 3
*/

#include <stdio.h>

int main(void) {
	int n;
	scanf("%d",&n);
	int cnt[100]={0};
	int i;
	int max=0;
	
	for (i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		cnt[a-1]++;
	}
	
	for (i=0;i<100;i++) {
		if (cnt[i]>cnt[max]) {
			max=i;
		}
	}
	
	printf("%d %d",max+1,cnt[max]);
	
	return 0;
}
