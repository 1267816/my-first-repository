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
其中，`size_t`是C语言中专门用来表示“大小”或“长度”的一种无符号整数类型。`sizeof()`的返回值也是这个类型。
注意：
1. printf它需要用`%zu`
2. 无符号数需要注意相减的结果不能为负数

这个函数怎么实现呢？
```c
int mylen(const char* s)
{
    int idx=0;
    while (s[idx]!='\0'){
        idx++;
    }
    return idx;
}
```
注：
1. idx表示index。
2. mylen的返回值类型和变量idx的类型写成`size_t`更好。
   不过，使用这个类型还需要`#include <stddef.h>`。

### 10.2.3

**strcmp**
cmp的意思是compare。
`int strcmp(const char *s1,const char *s2);`
比较两个字符串，返回：
- 0：s1==s2
- 1：s1>s2
- -1：s1<s2

在某些编译器中，这个函数返回的结果是`s1-s2`。

这个函数怎么实现呢？
```c
int mycmp(const char*s1,const char* s2)
{
    int ret=0;
    while (*s1==*s2&&*s1!='\0') {
        s1++;
        s2++;
    }
    if (*s1>*s2) {
        ret=1;
    } else if (*s1<*s2) {
        ret=-1;
    }
    return ret;
}
```
注：
1. 如果函数返回的结果是`s1-s2`，也可以直接`return *s1-*s2;`。
2. while循环的条件`*s1!='\0'`也可以直接写成`*s1`。

### 10.2.4

**strcpy**
原型声明：
```c
char *strcpy(char *restrict dst,const char *restrict src);
```
cpy的意思是copy，这个函数会把src的字符串拷贝到dst。
restrict表明src和dst的地址不重叠。（C99）
注意：第一个参数（dst）是copy的目标，第二个参数（src）是copy的来源。
- 因为src表示source，dst表示destination

它的返回值是字符串dst，因为这样，strcpy的结果就能够再参与其他运算。

**复制一个字符串**

套路：
```c
char *dst=(char*)malloc(strlen(src)+1);
strcpy(dst,src);
```
加1的原因：strlen()不包括'\0'。

这个函数怎么实现呢？
1. 数组版本：
```c
char *mycpy(char *dst,const char *src)
{
    int idx=0;
    while (src[idx]!='\0') {
        dst[idx]=src[idx];
        idx++;
    }
    dst[idx]='\0';
    return dst;
}
```
注：
在while结束后，dst还差最后的一个`'\0'`，所以还需要把它写入。

2. 指针版本：
```c
char *mycpy(char *dst,const char *src)
{
    char *ret=dst;
    while (*src!='\0') {
        *dst++=*src++;
    }
    *dst='\0';
    return ret;
}
```
注：
- 写入0的原因同上
- 为了正确输出dst的初始位置，需要先保存
3. 指针还有更抽象的版本：
```c
char *mycpy(char *dst,const char *src)
{
    char *ret=dst;
    while (*dst++=*src++) {
        /*empty*/
    }
    return ret;
}
```
注：
- 同样需要保存dst的初始位置
- 原理是赋值表达式的值是被赋值的结果。当`*src`遇到末尾的`'\0'`时，它会把`'\0'`赋给`*dst`。此时，赋值表达式的值为0，循环终止
- 因此，这次就不能在最后写入0了，否则会越界

### 10.2.5

**strcat**
```c
char *strcat(char *restrict s1,const char * restrict s2);
```
作用是把s2拷贝到s1后面，接成一个长的字符串，返回s1。
s1必须要有足够的空间。

**安全问题**
strcpy和strcat都可能出现安全问题。
如果目的地没有足够的空间呢？就会越界。
建议使用安全版本：
```c
char * strncpy(char *restrict dst, const char *restrict src, size_t n);
char * strncat(char *restrict s1, const char *restrict s2, size_t n);
int strncmp(const char *s1, const char *s2, size_t n);
```
strncmp可以只比较两个字符串的前n个字符。


### 10.2.6

**字符串中找字符**
```c
char *strchr(const char *s,int c);
char *strrchr(const char *s,int c);
```
功能是在字符串s里面寻找c第一次出现的位置，并返回指针。
`strchr()`表示从左边开始读，`strrchr()`表示从右边开始读。
返回NULL表示没有找到。

经典套路：如何寻找第2个？
```c
#include <stdio.h>
#include <string.h>

int main(int argc,char const *argv[])
{
    char s[]="hello";
    char *p=strchr(s,'l');
    p=strchr(p+1,'l');
    printf("%s\n",p);
    //输出第二个l开始的字符串
    return 0;
}
```

经典套路2：如何找到这个l，然后把这个l后面的东西去复制到另外一个字符串里头？
```c
#include <stdio.h>
#include <string.h>

int main(int argc,char const *argv[])
{
    char s[]="hello";
    char *p=strchr(s,'l');
    char *t=(char*)malloc(strlen(p)+1);
    strcpy(t,p);
    printf("%s\n",t);
    //输出字符串t
    free(t);
    
    return 0;
}
```