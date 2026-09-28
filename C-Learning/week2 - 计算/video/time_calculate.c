//计算时间差
//输入两个时间，每个时间分别输入小时和分钟的值，然后输出两个时间之间的差，也以几小时几分来表示

#include <stdio.h>

int main()
{
	int hour1, minute1;
	int hour2, minute2;
	
	printf("请以\"小时 分钟\"为格式输入第一个时间：");
	scanf("%d %d", &hour1, &minute1);
	printf("请以\"小时 分钟\"为格式输入第二个时间：");
	scanf("%d %d", &hour2, &minute2);
	
	int t1 = hour1 * 60 + minute1;
	int t2 = hour2 * 60 + minute2;
	int t = t2 - t1;
	
	printf("两个时间之间的差为：");
	printf("%d小时 %d分", t/60 , t%60);
	
	return 0;
	
}