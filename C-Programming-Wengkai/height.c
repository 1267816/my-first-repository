#include <stdio.h>

int main()
{
	printf("请分别输入身高的英尺和英寸，"
	    "如输入\"5 7\"表示5英尺7英寸：");
	    
	double foot = 0;
	double inch = 0;
	
	// 注意：格式要用空格分隔（%lf %lf），和提示里的 "5 7" 一致
	// 原来写的 "%lf, %lf" 要求输入 "5, 7" 才能读对
	if (scanf("%lf %lf", &foot, &inch) != 2) {
		printf("输入格式有误，请按\"英尺 英寸\"格式重新输入。\n");
		return 1;
	}
	
	
	printf("身高是%f米。\n",((foot + inch / 12) * 0.3048));
	return 0;
}
