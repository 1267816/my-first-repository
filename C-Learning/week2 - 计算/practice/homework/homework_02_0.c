//02-0.整数四则运算
//本题要求编写程序，计算2个正整数的和、差、积、商并输出。题目保证输入和输出全部在整型范围内。
//输入格式：输入在一行中给出2个正整数A和B。
//输出格式：在4行中按照格式“A 运算符 B = 结果”顺序输出和、差、积、商。

#include <stdio.h>

int main()
{
	int a;
	int b;
	
	scanf("%d %d",&a,&b);
	
	int sum = a+b;
	int difference = a-b;
	int product = a*b;
	int quotient = a/b;
	
	printf("%d + %d = %d\n",a,b,sum);
	printf("%d - %d = %d\n",a,b,difference);
	printf("%d * %d = %d\n",a,b,product);
	printf("%d / %d = %d\n",a,b,quotient);
	
	return 0;
	
}