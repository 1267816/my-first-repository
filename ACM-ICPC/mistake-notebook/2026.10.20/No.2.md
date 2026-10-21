# No.2｜7-3 怎么办被自己整除了

| 项 | 内容 |
| --- | --- |
| 题源 | 拼题A网站 2023-2024学年第一学期《程序设计基础》期末考试 |
| 分数 / 作者 | 10 / HZNUACM Joyfine（杭州师范大学） |
| 限制 | 16 KB / 1000 ms / 256 MB / 栈 8192 KB |
| 做题日期 | 2026-10-20 |
| 结果 | 提交4次，答案正确 |

## 题目

给定一个长度为 n 的下标从 1 开始的数组 a，求数组中 a[i] 可以被 i 整除的个数。

输入格式：

第一行给定一个数字 n（2≤n≤500）。
第二行给定 n 个数字代表数组 a（1≤a[i]≤10^9）。

输入样例：

```text
5
2 1 3 4 1
```

输出样例：

```text
3
```

（原题面把这一段标成了「输出格式」，实际是输入格式。）

## 提交记录

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

判题结果：答案错误

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

判题结果：部分错误

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

判题结果：部分错误

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

判题结果：答案正确

## 复盘

- **错在哪**：只判了一次，没有扫完整个数组。提交1把 `if` 写在输入循环外面，循环结束时 i==n，`a[i]` 已经越界，等于只判了下标 n 这一个位置；提交2把 `i` 手动置 0，只判下标 1；提交3在 `if` 里面加 `i++`，`if` 不成立时 `i` 根本不前进，还是只统计了一个；提交4改成 `for (i=0;i<n;i++)` 扫全程才对。
- **顺带**：提交2起加的 `scanf(" ")` / `scanf("\n")` 是多余的，`%d` 本身就会跳过前导空白，这两行既没修掉越界，也拖慢输入。
- **怎么避免**：计数类题目先写循环骨架（每个下标都走一遍），再往骨架里填判断；循环结束后不要拿循环变量的值当下标用。
