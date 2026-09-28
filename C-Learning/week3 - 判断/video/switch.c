#include <stdio.h>

int main()
{
	//初始化
	int type;
	
	//输入
	printf("请输入类型：");
	scanf("%d",&type);
	
	//switch-case语句控制输出
	switch ( type ) {
	case 1:
		printf("你好");
		break;
	case 2:
		printf("早上好");
		break;
	case 3:
		printf("晚上好");
		break;
	case 4:
		printf("再见");
		break;
	default:
		printf("啊，什么啊？");
	}
	
	return 0;
}