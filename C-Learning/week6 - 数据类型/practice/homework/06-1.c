/*
06-1. 简单计算器

模拟简单运算器的工作。假设计算器只能进行加减乘除运算，
运算数和结果都是整数，4种运算符的优先级相同，按从左到右的顺序计算。

输入格式：

输入在一行中给出一个四则运算算式，没有空格，且至少有一个操作数。
遇等号“=”说明输入结束。

输出格式：

在一行中输出算式的运算结果，或者如果除法分母为0或有非法运算符，
则输出错误信息“ERROR”。

输入样例：
1+2*10-10/2=

输出样例：
10
*/
#include <stdio.h>
int main(){
	int result=0;
	char c=0;
	int d=0;
	int a=0;
	int num_cnt=0;
	int err=0;
	int op=0;
	
	do {
		scanf("%c",&c);
		
		if (c>='0'&&c<='9') {
			switch (c) {
				case '0':d=0;break;
				case '1':d=1;break;
				case '2':d=2;break;
				case '3':d=3;break;
				case '4':d=4;break;
				case '5':d=5;break;
				case '6':d=6;break;
				case '7':d=7;break;
				case '8':d=8;break;
				case '9':d=9;break;
			}
			a=a*10+d;
		} else if (c=='+'||c=='-'||c=='*'||c=='/'||c=='=') {
			num_cnt++;
			if (num_cnt==1) {
				result=a;
			} else if (op!=0){
				switch (op) {
					case '+':result+=a;break;
					case '-':result-=a;break;
					case '*':result*=a;break;
					case '/':
					if (a!=0) {
						result/=a;
						break;
					} else {
						printf("ERROR");
						err=1;
						break;
					}
				}
				if (err==1) {
					break;
				}
			}
			a=0;
			op=c;
			if (c=='=') {
				printf("%d",result);
			}
		} else {
			printf("ERROR");
			break;
		}
	} while (c!='=');
	
	return 0;
}