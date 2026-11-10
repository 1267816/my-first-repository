/*
双指针（两数之和 / 去重 / 区间统计）
第一行 n（1 ≤ n ≤ 1e5），第二行 n 个非递减排列的整数 a_i（|a_i| ≤ 1e9）。
原地去重（保留第一次出现的元素），
第一行输出去重后的元素个数，第二行输出去重后的数组。
样例：
输入：
6
1 1 2 3 3 3
输出：
3
1 2 3
*/

#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	
	int a[n];
	int i,j;
	
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int *write=a+1;
	
	for (int *read=a+1;read<a+n;read++) {
		if (*read!=*(write-1)) {
			*write=*read;
			write++;
		}
	}
	
	int length=write-a;
	printf("%d\n",length);
	for (i=0;i<length;i++) {
		printf("%d",a[i]);
		if (i==length-1) {
			printf("\n");
		} else {
			printf(" ");
		}
	}
	
	return 0;
}