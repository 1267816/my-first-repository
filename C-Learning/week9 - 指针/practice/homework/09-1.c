/*
09-1 成绩统计

题目描述
输入 n 名学生的成绩（整数），统计最高分、最低分、及格人数（成绩大于等于 60）和平均分。

输入格式
第一行给出正整数 n（1 <= n <= 100000）。
第二行给出 n 个整数，表示每名学生的成绩（0 <= 成绩 <= 100），中间以空格分隔。

输出格式
在一行中输出四个结果：最高分、最低分、及格人数、平均分，中间以一个空格分隔，
平均分保留两位小数。

输入样例 1
6
59 60 72 100 85 44

输出样例 1
100 44 4 70.00

输入样例 2
1
60

输出样例 2
60 60 1 60.00

输入样例 3
3
0 0 0

输出样例 3
0 0 0 0.00

说明
四个结果看着像"一次算一件事"，但数据只有一份，建议试试让程序只扫一遍数组就把它们都拿到；
也建议把这四个结果交给一个函数算、通过参数带回主函数，而不是用全局变量，
这样更贴近本题想练的东西。以上都只是建议，不影响判题。
*/

#include <stdio.h>

void f(int *max,int *min,int *people,int a[],double *average,int n);

int main(void)
{
	int n;
	scanf("%d",&n);
	
	int a[n];
	int i;
	for (i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	
	int max,min,people;
	double average;
	f(&max,&min,&people,a,&average,n);
	
	printf("%d %d %d %.2f",max,min,people,average);
	
	return 0;
}

void f(int *max,int *min,int *people,int a[],double *average,int n)
{
	int i;
	int sum=0;
	*max=a[0];
	*min=a[0];
	*people=0;
	for (i=0;i<n;i++) {
		sum+=a[i];
		if (a[i]>*max) {
			*max=a[i];
		}
		if (a[i]<*min) {
			*min=a[i];
		}
		if (a[i]>=60) {
			(*people)++; //要先解引用再++
		}
	}
	*average=1.0*sum/n;
}
