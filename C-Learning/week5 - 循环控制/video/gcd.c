#include <stdio.h>
int main(){
	int a,b,r;
	scanf("%d %d",&a,&b);
	//不需要比较a和b的大小，因为若a<b，
	//则下一轮新的被除数变成b，除数变成b
	while (a%b!=0) {
		r=a%b;
		a=b;
		b=r;
	}
	
	//当最后一轮的余数为0时，除数即为最大公约数
	printf("%d",b);

	return 0;
}