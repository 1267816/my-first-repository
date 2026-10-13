# 第十周：字符串

## 10.2 字符串函数

### 10.2.1

**putchar**
`int putchar(int c);`
向标准输出写一个字符，返回写了几个字符，EOF(-1)表示失败。

**getchar**
`int getchar(void);`
从标准输入读入一个字符，返回类型为int的原因是需要返回EOF(-1)。
```c
#include <stdio.h>
int main(int argc,char const *argv[])
{
	int ch;
	
	while ((ch=getchar())!=EOF) {
		putchar(ch);
	}
	
	printf("EOF\n");
	
	return 0;
}
```
先输入回车，再输入Ctrl+C使程序强制退出，或输入Ctrl+Z使程序正常退出。

### 10.2.2
**string.h**
- strlen
- strcmp
- strcpy
- strcat
- strchr
- strstr
使用上述函数，需要`#include <string.h>`。

**strlen**
`size_t strlen(const char *s);`
返回s的字符串长度，不包括结尾的0。

这个函数怎么实现呢？
```c
int mylen(const char* s)
{
    int cnt=0;
    while (s[idx]!='\0'){
        idx++;
    }
    return idx;
}
```

### 10.2.3

**strcmp**
cmp的意思是compare。
`int strcmp(const char *s1,const char *s2);`
比较两个字符串，返回：
- 0：s1==s2
- 1：s1>s2
- -1：s1<s2

这个函数怎么实现呢？
```c
int mycmp(const charU*s1,const char* s2)
{
    while (*s1==*s2&&*s1!='\0') {
        s1++;
        s2++;
    }
    return *s1-*s2;
}
```