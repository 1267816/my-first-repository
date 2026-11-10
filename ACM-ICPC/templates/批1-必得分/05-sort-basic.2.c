// 名字：排序三件套（选择 / 冒泡 / 插入）
// 最低周次：week8
// 题面（自拟，配套这份模板）：
//   第一行 n（1 ≤ n ≤ 1000），第二行 n 个整数 a_i（|a_i| ≤ 1e9）。
//   把它们按从小到大排序后输出，数字之间用一个空格分隔。
//   样例：
//     输入：
//       5
//       5 2 9 1 5
//     输出：
//       1 2 5 5 9

#include <stdio.h>

void swap(int *pa,int *pb) {
	int t;
	t=*pa;
	*pa=*pb;
	*pb=t;
}

int main(void) {
	int n;
	scanf("%d",&n);
	int a[n];
	int i,j;
	for (i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	
	for (i=0;i<n-1;i++) {
		int min=i;
		for (j=i+1;j<n;j++) {
			if (a[j]<a[min]) {
				min=j;
			}
		}
		swap(&a[i],&a[min]);
	}
	
	for (i=0;i<n;i++) {
		printf("%d",a[i]);
		if (i==n-1) {
			printf("\n");
		} else {
			printf(" ");
		}
	}
	
	return 0;
}