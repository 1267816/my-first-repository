# 题目
7-1 Joyfine 的祝福
分数 25
作者 HZNUACM Joyfine
单位 杭州师范大学
随着期末的到来，大家都在努力的准备期末考，Joyfine 学长也希望大家考出一个好成绩。

输入格式:
本题无输入。

输出格式:
输出一行，见样例。

输入样例:
No Input
输出样例:
`//I wish you all the best in the final exam!\\`
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
    printf("//I wish you all the best in the final exam!\\");
}
```
答案错误

### 提交2
```c
#include <stdio.h>
int main(void) {
    printf("//I wish you all the best in the final exam!\\\");
}
```
编译错误

### 提交3
```c
#include <stdio.h>
int main(void) {
    printf("//I wish you all the best in the final exam!\\\\");
}
```
答案正确