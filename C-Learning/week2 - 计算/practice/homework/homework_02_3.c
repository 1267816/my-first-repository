//02-3.逆序的三位数
//程序每次读入一个正3位数，然后输出按位逆序的数字。
//注意：当输入的数字含有结尾的0时，输出不应带有前导的0。比如输入700，输出应该是7。
//输入格式：每个测试是一个3位的正整数。
//输出格式：输出按位逆序的数。
//输入样例：123
//输出样例：321

#include <stdio.h>
int main()
{
	int start,end;
	scanf("%d",&start);
	int hundred_1 = start / 100;
	int ten_1 = start / 10 - hundred_1 * 10;
	int one_1 = start - hundred_1 * 100 - ten_1 * 10;
	int hundred_2,ten_2,one_2;
	one_2 = hundred_1;
	ten_2 = ten_1;
	hundred_2 = one_1;
	end = hundred_2 * 100 + ten_2 * 10 + one_2;
	printf("%d",end);
	return 0;
}
