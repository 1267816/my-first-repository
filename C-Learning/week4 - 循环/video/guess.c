#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	
	//初始化
	srand(time(0));
	int number = rand()%100 + 1;
	int count = 1;
	int a = 0;
	printf("准备完成.请输入1到100范围内的正整数:\n");
	
	//主体部分
	scanf("%d",&a);
	while ( a!=number ) {
		if ( a > number ) {
			printf("猜大了.\n");
		} else {
			printf("猜小了.\n");
		}
		scanf("%d",&a);
		count = count + 1;
	}
	printf("猜中了!共猜了%d次.\n",count);
	
	return 0;
}