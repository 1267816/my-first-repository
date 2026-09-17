#include <stdio.h>

int main()
{
	
	//初始化
	const int MINOR = 35;
	int age = 0;
	
	//输入年龄
	printf("你的年龄是：（岁）");
	scanf("%d",&age);
	
	//判断age与MINOR的大小关系
	if (age < MINOR) {
		printf("年轻是美好的，");
	}
	
	printf("年龄决定了你的精神世界，好好珍惜吧。");
	
	return 0;
}