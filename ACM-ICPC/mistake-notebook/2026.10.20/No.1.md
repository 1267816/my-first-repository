# No.1｜7-1 Joyfine 的祝福

| 项 | 内容 |
| --- | --- |
| 题源 | 拼题A网站 2023-2024学年第一学期《程序设计基础》期末考试 |
| 分数 / 作者 | 25 / HZNUACM Joyfine（杭州师范大学） |
| 限制 | 16 KB / 1000 ms / 256 MB / 栈 8192 KB |
| 做题日期 | 2026-10-20 |
| 结果 | 提交3次，答案正确 |

## 题目

随着期末的到来，大家都在努力的准备期末考，Joyfine 学长也希望大家考出一个好成绩。

输入格式：本题无输入。

输出格式：输出一行，见样例。

输入样例：

```text
No Input
```

输出样例：

```text
//I wish you all the best in the final exam!\\
```

注意样例末尾是两个反斜杠。

## 提交记录

### 提交1

```c
#include <stdio.h>
int main(void) {
    printf("//I wish you all the best in the final exam!\\");
}
```

判题结果：答案错误

### 提交2

```c
#include <stdio.h>
int main(void) {
    printf("//I wish you all the best in the final exam!\\\");
}
```

判题结果：编译错误

### 提交3

```c
#include <stdio.h>
int main(void) {
    printf("//I wish you all the best in the final exam!\\\\");
}
```

判题结果：答案正确

## 复盘

- **错在哪**：提交1的源码里写的是 `\\`，C 转义后只输出一个反斜杠，而题目要两个；提交2写成 `\\\"`，其中 `\"` 把引号当成普通字符收进字符串，字符串没有正常结束，所以编译错误；提交3源码写四个反斜杠，才输出两个。
- **怎么避免**：输出里要几个反斜杠，源码里就写几个的两倍；引号、反斜杠这类转义改完之后，先本地编译跑一次、对一眼实际输出，再提交。
