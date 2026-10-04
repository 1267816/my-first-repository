/*
07-0. 写出这个数
读入一个自然数n，计算其各位数字之和，
用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。
这里保证n小于10^100。

输出格式：在一行内输出n的各位数字之和的每一位，
拼音数字间有1空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/

#include <stdio.h>

int trans(char c)
{
	int ret1=0;
	switch (c){
		case '0':ret1=0;break;
		case '1':ret1=1;break;
		case '2':ret1=2;break;
		case '3':ret1=3;break;
		case '4':ret1=4;break;
		case '5':ret1=5;break;
		case '6':ret1=6;break;
		case '7':ret1=7;break;
		case '8':ret1=8;break;
		case '9':ret1=9;break;
		default:break;
	}
	return ret1;
}

int max(int sum)
{
	int ret2=1;
	while (sum>9) {
		ret2*=10;
		sum/=10;
	}
	return ret2;
}

int digit(int sum)
{
	int ret3=0;
	while (sum>0) {
		ret3++;
		sum/=10;
	}
	return ret3;
}

int main() 
{
	char c;
	int d=0;
	int sum=0;
	
	do {
		scanf("%c",&c);
		if (c!='\n') {
			d=trans(c);
			sum+=d;
		}
	} while (c!='\n');
	
	int m=max(sum);
	int digit_cnt=digit(sum);
	int digit1=0;
	if (sum==0) {
		printf("ling");
	}
	while (digit_cnt>0) {
		digit1=sum/m;
		sum%=m;
		m/=10;
		switch (digit1) {
			case 0:printf("ling");break;
			case 1:printf("yi");break;
			case 2:printf("er");break;
			case 3:printf("san");break;
			case 4:printf("si");break;
			case 5:printf("wu");break;
			case 6:printf("liu");break;
			case 7:printf("qi");break;
			case 8:printf("ba");break;
			case 9:printf("jiu");break;
		}
 		if (digit_cnt!=1) {
			printf(" ");
		}
		digit_cnt--;
	}
	
	return 0;
}
