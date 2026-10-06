#include <stdio.h>

/**
找出key在数组a中的位置
@param key 要寻找的数字
@param a 要寻找的数组
@param length 数组a的长度
@return 如果找到，返回其在a中的位置；如果找不到返回-1
*/

int search(int key,int a[],int length);

int main(void)
{
	int a[]={2,4,6,7,1,3,5,9,11,13,23,14,32};
	int x;
	int loc;
	printf("请输入一个数字：");
	scanf("%d",&x);
	loc=search(x,a,sizeof(a)/sizeof(a[0]));
	if (loc!=-1) {
		printf("%d在第%d个位置上\n",x,loc);
	} else {
		printf("%d不存在\n",x);
	}
	return 0;
}

int search(int key,int a[],int length)
{
	int ret=-1;
	int i;
	for (i=0;i<length;i++) {
		if (a[i]==key) {
			ret=i;
			break;
		}
	}
	return ret;
}