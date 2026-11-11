/*
输入输出骨架
版本 A（T 组）：第一行一个整数 T（1 ≤ T ≤ 100），接下来 T 行每行两个整数 a、b（|a|,|b| ≤ 1e9），
每组输出一行 a + b。
版本 B（读到 EOF）：不知道有多少行，每行两个整数 a、b，读到文件结束为止，每行输出 a + b。
样例（版本 A）：
输入：
3
1 2
3 4
5 6
输出：
3
7
11
*/

//#include <stdio.h>
//
//int main(void) {
//	int T;
//	scanf("%d",&T);
//
//	for (int i=0;i<T;i++) {
//		int a,b;
//		scanf("%d %d",&a,&b);
//		printf("%d\n",a+b);
//	}
//
//	return 0;
//}

#include <stdio.h>

int main(void) {
	int a,b;
	while (scanf("%d %d",&a,&b)==2) {
		printf("%d\n",a+b);
	}
	
	return 0;
}