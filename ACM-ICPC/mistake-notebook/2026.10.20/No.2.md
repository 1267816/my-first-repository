# 题目
7-3 怎么办被自己整除了
分数 10
作者 HZNUACM Joyfine
单位 杭州师范大学
给定一个长度为 n 的下标从 1 开始的数组 a，求数组中 ai可以被 i 整除的个数。

输出格式:
第一行给定一个数字 n(2≤n≤500)。
第二行给定 n 个数字代表数组 a(1≤ai≤10^9)。

输入样例:
5
2 1 3 4 1
输出样例:
3
代码长度限制
16 KB
时间限制
1000 ms
内存限制
256 MB
栈限制
8192 KB

## 题源
拼题A网站 2023-2024学年第一学期《程序设计基础》期末考试

### 提交1
```c
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);

    int a[n];
    int i;
    for (i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }

    int cnt=0;
    if (a[i]%(i+1)==0) {
        cnt++;
    }

    printf("%d",cnt);
    return 0;
}
```
答案错误

### 提交2
```c
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);

    int a[n];
    int i;
    for (i=0;i<n;i++) {
        scanf("%d",&a[i]);
        if (i==n-1) {
            scanf("\n");
        } else {
            scanf(" ");
        }
    }

    int cnt=0;
    i=0;
    if (a[i]%(i+1)==0) {
        cnt++;
    }

    printf("%d",cnt);
    return 0;
}
```
部分错误

### 提交3
```c
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);

    int a[n];
    int i;
    for (i=0;i<n;i++) {
        scanf("%d",&a[i]);
        if (i==n-1) {
            scanf("\n");
        } else {
            scanf(" ");
        }
    }

    int cnt=0;
    i=0;
    if (a[i]%(i+1)==0) {
        cnt++;
        i++;
    }

    printf("%d",cnt);
    return 0;
}
```
部分错误

### 提交4
```c
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d",&n);

    int a[n];
    int i;
    for (i=0;i<n;i++) {
        scanf("%d",&a[i]);
        if (i==n-1) {
            scanf("\n");
        } else {
            scanf(" ");
        }
    }

    int cnt=0;
    for (i=0;i<n;i++) {
        if (a[i]%(i+1)==0) {
            cnt++;
        }
    }

    printf("%d",cnt);
    return 0;
}
```
答案正确。