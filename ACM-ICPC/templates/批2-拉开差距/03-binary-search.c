/*
二分查找
第一行 n q（1 ≤ n, q ≤ 1e5），第二行 n 个严格递增的整数 a_i（|a_i| ≤ 1e9）。
接下来 q 行，每行一个整数 x，
输出第一个大于等于 x 的元素的下标（从 1 开始），
若不存在，则输出 -1。
样例：
输入：
5 2
1 3 5 7 9
5
6
输出：
3
4
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
		int x,result;
		scanf("%d",&x);
		if (x>a[n-1]) {
			printf("-1\n");
			continue;
		} else {
			int l=0;
			int r=n-1;
			int isfound=0;
			while (l<r) {
				int mid=(l+r)/2;
				if (x==a[mid]) {
					result=mid+1;
					isfound=1;
					break;
				} else if (x<a[mid]) {
					r=mid;
				} else {
					l=mid+1;
				}
			}
			if (isfound==0) {
				result=r+1;
			}
		}
		printf("%d\n",result);
	}
	
	return 0;
}