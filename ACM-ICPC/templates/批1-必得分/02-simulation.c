/*
模拟（把题面逐句翻成代码）
给一个 24 小时制的时刻 h m s（0 ≤ h < 24，0 ≤ m,s < 60）和一个整数 n（0 ≤ n ≤ 1e9）表示经过的秒数，
输出经过 n 秒之后的时刻，格式为 h m s，各段用空格分隔。
样例：
输入：
23 59 30 45
输出：
0 0 15
*/

#include <stdio.h>

int main(void) {
	int h1,m1,s1,n;
	scanf("%d %d %d %d",&h1,&m1,&s1,&n);
	
	int start=h1*60*60+m1*60+s1;
	int end=(start+n)%(24*60*60);
	
	int h2,m2,s2;
	h2=end/(60*60);
	end%=(60*60);
	m2=end/60;
	end%=60;
	s2=end;
	
	printf("%d %d %d",h2,m2,s2);
	
	return 0;
}