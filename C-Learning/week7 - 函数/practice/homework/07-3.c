/*
07-3. 数素数
令Pi表示第i个素数。现任给两个正整数M <= N <= 10^4，
请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，
其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/
#include <stdio.h>

int isPrime(int x){
	int ret=1;
	for (int j=2;j*j<=x;j++) {
		if (x%j==0) {
			ret=0;
			break;
		}
	}
	if (x<2) {
		ret=0;
	}
	return ret;
}

int main(){
	
	int m=0;
	int n=0;
	int a=0;
	int b=0;
	int ex=0;
	int i=2;
	int cnt1=0;
	int cnt2=0;
	
	scanf("%d %d",&m,&n);
	
	while (ex==0) {
		if (isPrime(i)==1) {
			cnt1++;
			if (cnt1==m) {
				a=i;
			}
			if (cnt1==n) {
				b=i;
				ex=1;
			}
		}
		i++;
	}
	
	for (int k=a;k<=b;k++) {
		if (isPrime(k)==1) {
			printf("%d",k);
				cnt2++;
			if (cnt2<n-m+1&&cnt2%10==0) {
				printf("\n");
			} else if (cnt2<n-m+1){
				printf(" ");
			}
		}
	}
	
	return 0;
}