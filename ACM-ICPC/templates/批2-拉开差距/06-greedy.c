/*
贪心（排序后逐个处理）
第一行 n（1 ≤ n ≤ 1e5），
接下来 n 行每行两个整数 s、e（0 ≤ s < e ≤ 1e9）
表示一个活动的时间段。
一个人同一时间只能参加一个活动，求最多能参加几个活动。
样例：
输入：
4
1 3
2 4
3 5
4 6
输出：
2
*/

#include <stdio.h>

int main(void) {
	int n;
	scanf("%d",&n);
	int i;
	int s[n];
	int e[n];
	
	for (i=0;i<n;i++) {
		scanf("%d %d",&s[i],&e[i]);
	}
	
	int factivity=0;
	for (i=1;i<n;i++) {
		if (e[i]<e[factivity]) {
			factivity=i;
		}
	}
	
	int cnt=1;
	while (1) {
		int nactivity=-1;
		for (i=0;i<n;i++) {
			if (s[i]>=e[factivity]) {
				if (nactivity==-1||e[i]<e[nactivity]) {
					nactivity=i;
				}
			}
		}
		if (nactivity==-1) {
			break;
		}
		factivity=nactivity;
		cnt++;
	}
	
	printf("%d",cnt);
	
	return 0;		
}
