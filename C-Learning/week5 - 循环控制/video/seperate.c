#include <stdio.h>
int main(){
	int x,y;
	int digit=0;
	int max=1;
	scanf("%d",&x);
	
	y=x;
	while (y>0) {
		y/=10;
 		digit++;
	}
	while (digit>1) {
		max*=10;
		digit--;
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