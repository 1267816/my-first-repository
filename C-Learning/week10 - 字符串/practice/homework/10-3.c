/*
10-3. 字符串逆序(15)

输入一个字符串，对该字符串进行逆序，输出逆序后的字符串。

输入格式：

输入在一行中给出一个不超过80个字符长度的、以回车结束的非空字符串。

输出格式：

在一行中输出逆序后的字符串。

输入样例：
Hello World!
输出样例：
!dlroW olleH
*/
#include <stdio.h>
#include <string.h>

int main(void) {
	char s1[81]="";
	char s2[81]="";
	
	int i=0;
	int ch;
	while ((ch=getchar())!=EOF&&ch!='\n') {
		s1[i]=(char)ch;
		i++;
	}
	s1[i]='\0';
	
	int len=strlen(s1);
	for (i=0;i<len;i++) {
		s2[len-i-1]=s1[i];
	}
	s2[i]='\0';
	printf("%s",s2);
	
	return 0;
}