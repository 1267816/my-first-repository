/*
10-2. 删除字符串中的子串(20)

输入2个字符串S1和S2，要求删除字符串S1中出现的所有子串S2，即结果字符串中不能包含S2。

输入格式：

输入在2行中分别给出不超过80个字符长度的、以回车结束的2个非空字符串，对应S1和S2。

输出格式：

在一行中输出删除字符串S1中出现的所有子串S2后的结果字符串。

输入样例：
Tomcat is a male ccatat
cat
输出样例：
Tom is a male
*/
#include <stdio.h>
#include <string.h>

int main(void) {
	char s1[81];
	char s2[81];
	
	int i=0;
	int ch;
	
	while ((ch=getchar())!='\n'&&ch!=EOF) {
		s1[i++]=(char)ch;
	}
	s1[i]='\0';
	i=0;
	while ((ch=getchar())!='\n'&&ch!=EOF) {
		s2[i++]=(char)ch;
	}
	s2[i]='\0';
	
	char *dst=NULL;
	while ((dst=strstr(s1,s2))!=NULL) {
		char *src=dst+strlen(s2);
		while (*src!='\0') {
			*dst++=*src++;
		}
		*dst='\0';
	}
	
	printf("%s",s1);
	return 0;
}