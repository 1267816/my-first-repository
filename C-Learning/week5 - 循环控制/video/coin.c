#include <stdio.h>
int main(){
	int x;
	int one,two,five,sum;
	int exit;
	
	scanf("%d",&x);
	
	//不同于百马百担问题，这里只有一个约束条件，
	//所以必须写三个循环遍历
	for (one=1;one<x*10;one++) {
		for (two=1;two<x*5;two++) {
			for (five=1;five<x*2;five++) {
				sum=one+two*2+five*5;
				if (sum==x*10) {
					printf("可以用%d个1角加%d个2角加%d个5角得到%d元\n",
					one,two,five,x);
					exit = 1;
					break;
				}
			}
			if (exit==1) {
				break;
			}
		}
		if (exit==1) {
			break;
		}
	}
	//用exit变量判断实现接力break

	return 0;
}