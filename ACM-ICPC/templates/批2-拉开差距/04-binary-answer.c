/*
二分答案（最小的最大值）
第一行 n k（1 ≤ n ≤ 1e5，1 ≤ k ≤ 1e5），
第二行 n 个正整数表示木棍长度（1 ≤ 长度 ≤ 1e9）。
把这些木棍切成 k 段等长的小段（长度必须是整数），
求每小段的最大长度；
做不到输出 0。
样例：
输入：
4 11
802 743 457 539
输出：
200
*/

#include <stdio.h>

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);
	
	int i;
	int a[n];
	int l=1,r=0;
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>r) 
		{
			r=a[i];
		}
	}
	
	int max=0;
	while (l<=r) 
	{
		long long sum=0;
		int mid=(l+r)/2;
		for (i=0;i<n;i++) {
			sum+=a[i]/mid;
		}
		if (sum>=k) {
			max=mid;
			l=mid+1;
		} else {
			r=mid-1;
		}
	}
	
	printf("%d",max);
	
	return 0;
}