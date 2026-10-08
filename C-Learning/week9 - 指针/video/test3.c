#include <stdio.h>

int main() {
	char ac[]={0,1,2,3,4,5,6,7,8,9,-1};
	//-1不输出，作为结尾的标志
	char *p=&ac[0];
	int i;
	while (*p!=-1) {
		printf("%d\n",*p++);
	}
}