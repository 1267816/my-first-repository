/*
08-1. 求一批整数中出现最多的个位数字

给定一批整数，分析每个整数的每一位数字，
求出现次数最多的个位数字。
例如给定3个整数1234、2345、3456，
其中出现最多次数的数字是3和4，均出现了3次。

输入格式：

输入在第1行中给出正整数N（<=1000），
在第2行中给出N个不超过整型范围的正整数，数字间以空格分隔。

输出格式：

在一行中按格式“M: n1 n2 ...”输出，其中M是最大次数，
n1、n2、……为出现次数最多的个位数字，按从小到大的顺序排列。
数字间以空格分隔，但末尾不得有多余空格。

输入样例：
3
1234 2345 3456
输出样例：
3: 3 4
*/
#include <stdio.h>

int main(void) {
	int n;
	int d;
	int i,j;
	
	scanf("%d",&n);
	int num[n];
	int cnt[10];
	int out[10];
	
	for (i=0;i<10;i++) {
		cnt[i]=0;
		out[i]=0;
	}
	
	for (i=0;i<n;i++) {
		scanf("%d",&num[i]);
		while (num[i]>0) {
			d=num[i]%10;
			for (j=0;j<10;j++) {
				if (j==d) {
					cnt[j]++;
				}
			}
			num[i]/=10;	
		}
	}
	
	int ismax=1;
	int max;
	int m=0;
	for (i=0;i<10;i++) {
		ismax=1;
		for (j=0;j<10;j++) {
			if (cnt[i]<cnt[j]) {
				ismax=0;
				break;
			}
		}
		out[i]=ismax;
		if (out[i]==1) {
			max=cnt[i];
			m++;
		}
	}
	
	printf("%d: ",max);
	for (i=0;i<10;i++) {
		if (out[i]==1) {
			printf("%d",i);
			m--;
			if (m>0) {
				printf(" ");
			} else {
				printf("\n");
			}
		}
	}
	
	return 0;
}