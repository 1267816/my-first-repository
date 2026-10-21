## 题目
7-9 11111111
分数 5
作者 HZNUACM lyb
单位 杭州师范大学
给定一个整数 n，判断能否通过 11,111,1111,11111,111111,… 中的数字，
通过多次相加得到n（数字可重复使用）。​例如

33=11+11+11
144=111+11+11+11 
输入格式:
一行包含一个正整数 n (1≤x≤10^9)。

输出格式:
如果能生成 n ，输出 "YES"（不带引号），否则输出 "NO"。

输入样例1:
33
输出样例1:
YES
输入样例2:
69
输出样例2:
NO
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
栈限制
8192 KB

### 提交1
```c
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);

    int a[8];
    a[0]=11;
    int i;
    for (i=0;i<7;i++) {
        a[i+1]=10*a[i]+1;
    }

    int isyes=0;
    i=7;
    while (n>=11) {
        if (n>=a[i]) {
            n-=a[i];
        } else {
            i--;
        }
    }

    if (n==0) {
        isyes=1;
    }

    if (isyes==1) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
```
部分正确：2个测试点正确，3个错误

### 提交2
```c
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);

    int a[8];
    a[0]=11;
    int i;
    for (i=0;i<7;i++) {
        a[i+1]=10*a[i]+1;
    }

    int isyes=0;
    int x,y;
    for (x=0;x<(n/11+1);x++) {
        for (y=0;y<(n/111+1);y++) {
            if (n==11*x+111*y) {
                isyes=1;
                break;
            }
        }
    }

    if (isyes==1) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
```
部分正确：3正确，2超时

### 提交3通过询问ai进行了作答。
```c
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);

    int r=n%11;
    if (n>=r*111) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
```
但是我仍然未能搞懂原理。