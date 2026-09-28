/*
03-2. 用天平找小球

三个球A、B、C，大小形状相同且其中有一个球与其他球重量不同。要求找出这个不一样的球。

输入格式：

输入在一行中给出3个正整数，顺序对应球A、B、C的重量。

输出格式：

在一行中输出唯一的那个不一样的球。

输入样例：

1 1 2

输出样例：

C
*/
#include <stdio.h>

int main()
{
	//初始化
	int a,b,c;
	
	//输入
	scanf("%d %d %d",&a,&b,&c);
	
	//判断并输出
	if ( a==b ) {
		printf("C");
	} else if ( a==c ) {
		printf("B");
	} else {
		printf("A");
	}
	
	return 0;
}

