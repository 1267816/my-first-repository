#include <stdio.h>
int main(){
	int x,y;
	int max=1;
	scanf("%d",&x);
	
	y=x;
	//可以直接把max放进第一个循环中，这样就不需要定义digit了
	//不过要让循环少跑一段，把y>0改成y>9
	while (y>9) {
		y/=10;
 		max*=10;
	}
	while (max>0) {
		if (max>=10) {
			printf("%d ",x/max);
		} else {
			printf("%d\n",x/max);
		}
		x%=max;
		max/=10;
	}
	
	
	return 0;
}