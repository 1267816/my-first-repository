#include <stdio.h>
int main(){
	int x=2;
	int i; // x是素数
	int cnt=0; // cnt记录已求出的素数个数
	//while (cnt<50) {
	for (x=2;cnt<50;x++) {
		int isPrime=1;
		for (i=2;i<x;i++) {
			if (x%i==0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime==1) {
			printf("%d ",x);
			cnt++;
		}
		//x++;
	}
	printf("\n");
	return 0;
}