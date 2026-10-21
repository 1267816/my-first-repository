/*
第1题：数组统计（最大值、最小值、和、平均值）
对应能力：输入n个数，求最大值、最小值、和、平均。
建议限时：20分钟
题目描述：
输入一个整数n，再输入n个整数。请输出这n个数的最大值、最小值、总和以及平均值。
输入格式：
第一行输入一个整数n。
第二行输入n个整数，数与数之间用空格隔开。
输出格式：
输出四行，格式如下：
max=最大值
min=最小值
sum=总和
avg=平均值
平均值保留两位小数。
数据范围：
1<=n<=100
-1000<=ai<=1000
样例输入：
5
3 1 4 1 5
样例输出：
max=5
min=1
sum=14
avg=2.80
要求：
1.只遍历数组一次完成最大值、最小值、求和。
2.注意n=1的情况。
3.平均值用浮点数计算并保留两位小数。
4.最大值和最小值初始值不能随意设为0，要考虑负数。
*/
#include <stdio.h>

int main() {
	
	int n;
	scanf("%d",&n);
	
	int i;
	int a[n];
	for (i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	
	int max=a[0];
	int min=a[0];
	int sum=0;
	
	for (i=0;i<n;i++) {
		if (a[i]>max) {
			max=a[i];
		}
		if (a[i]<min) {
			min=a[i];
		}
		sum+=a[i];
	}
	
	double average=1.0*sum/n;
	
	printf("max=%d\n",max);
	printf("min=%d\n",min);
	printf("sum=%d\n",sum);
	printf("avg=%.2f\n",average);
	
	return 0;
}

//用时：5分30秒