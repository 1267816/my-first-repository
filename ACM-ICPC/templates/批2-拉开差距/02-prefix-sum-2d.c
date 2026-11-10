/*
二维前缀和
第一行 m n q（1 ≤ m, n ≤ 1000，1 ≤ q ≤ 1e5），
接下来 m 行每行 n 个整数 a_ij（|a_ij| ≤ 1e3）。
接下来 q 行，每行 x1 y1 x2 y2（1 ≤ x1 ≤ x2 ≤ m，1 ≤ y1 ≤ y2 ≤ n），
输出这个子矩阵的元素和。
样例：
输入：
2 3 1
1 2 3
4 5 6
1 1 2 2
输出：
12
*/

#include <stdio.h>

int main(void) {
	int m,n,q;
	scanf("%d %d %d",&m,&n,&q);
	int i,j,k;
	int a[m][n];
	
	for (i=0;i<m;i++) {
		for (j=0;j<n;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	
	for (i=0;i<q;i++) {
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int sum=0;
		for (j=y1-1;j<=y2-1;j++) {
			for (k=x1-1;k<=x2-1;k++) {
				sum+=a[j][k];
			}
		}
		printf("%d\n",sum);
	}
	
	return 0;
}