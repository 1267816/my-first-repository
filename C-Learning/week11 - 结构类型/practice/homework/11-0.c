/*
11-0. 平面向量加法

本题要求编写程序，计算两个二维平面向量的和向量。

输入格式：

输入在一行中按照“x1 y1 x2 y2”的格式给出两个二维平面向量V1=(x1, y1)和V2=(x2, y2)的分量。

输出格式：

在一行中按照“(x, y)”的格式输出和向量，坐标输出小数点后1位（注意不能输出-0.0）。

输入样例：
3.5 -2.7 -13.9 8.7
输出样例：
(-10.4, 6.0)
*/

#include <stdio.h>
#include <math.h>

#define eps 0.05 // eps不能设置成1e-8，不然拦不住

int main(void) {
	double x1,x2,y1,y2;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	double x=x1+x2;
	double y=y1+y2;
	if (fabs(x)<0.05) {
		x=0.0;
	}
	if (fabs(y)<0.05) {
		y=0.0;
	}
	
	printf("(%.1f, %.1f)",x,y);
	
	return 0;
}