/*
名字：一维前缀和
第一行n q（1 ≤ n, q ≤ 1e5），第二行 n 个整数 a_i（|a_i| ≤ 1e9）。
接下来q行，每行两个整数 l r（1 ≤ l ≤ r ≤ n），对每次询问输出 a_l + ... + a_r。
样例：
输入：
5 2
1 2 3 4 5
1 3
2 5
输出：
6
14
*/

#include <stdio.h>

int main(void) {
	int n,q;
	scanf("%d %d",&n,&q);
	
	int i,j;
	int a[n];
	for (i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	
	for (i=0;i<q;i++) {
		int l,r;
		scanf("%d %d",&l,&r);
		int sum=0;
		for (j=l-1;j<=r-1;j++) {
			sum+=a[j];
		}
		printf("%d",sum);
		if (i!=q-1) {
			printf("\n");
		}
	}
	
	return 0;
}