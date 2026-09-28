//求平均值
//写一个程序，输入两个整数，输出它们的平均值

#include <stdio.h>

int main()
{
	int a, b;
	printf("请输入两个整数：");
	scanf("%d %d", &a, &b);
//平均数可能是小数，所以要用double，下面的printf要用%f
	double c = (a + b)/2.0;
	printf("%d和%d的平均值是%f", a, b, c);
	return 0;
}