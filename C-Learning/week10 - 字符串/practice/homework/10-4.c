/*
10-4. 字符串循环左移(20)

输入一个字符串和一个非负整数N，要求将字符串循环左移N次。

输入格式：

输入在第1行中给出一个不超过100个字符长度的、以回车结束的非空字符串；
第2行给出非负整数N。

输出格式：

在一行中输出循环左移N次后的字符串。

输入样例：
Hello World!
2
输出样例：
llo World!He
*/
#include <stdio.h>
#include <string.h>

int main(void) {
	int n;
	char s[101]="";
	int i=0;
	int ch;
	while ((ch=getchar())!=EOF&&ch!='\n') {
		s[i++]=(char)ch;
	}
	s[i]='\0';
	scanf("%d",&n);
	
	int length=strlen(s);
	n=n%length;
	
	char temp[101]="";
	strcpy(temp,s+n);
	s[n]='\0';
	printf("%s",strcat(temp,s));
	
	return 0;
}