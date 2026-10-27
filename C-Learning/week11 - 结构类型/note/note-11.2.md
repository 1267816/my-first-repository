# 第十一周：结构类型

## 11.2 结构

### 11.2.1 结构类型

**声明结构类型**

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    struct date {
        int month;
        int day;
        int year;
    }; //HERE

    struct date today;

    today.month = 07;
    today.day = 31;
    today.year = 2014;

    printf("Today's date is %i-%i-%i.\n",
        today.year, today.month, today.day);

    return 0;
}

```

==初学者最常见的错误：漏了注释处的分号！==

**在函数内/外？**

和本地变量一样，在函数内部声明的结构类型只能在函数内部使用。所以，通常在函数外部声明结构类型，这样就可以被多个函数所使用了。

**声明结构的形式**

```c
struct point {
    int x;
    int y;
};

struct point p1,p2;
```

p1和p2都是point，里面有x和y的值。

```c
struct {
    int x;
    int y;
} p1,p2;
```

p1和p2都是一种无名结构，里面有x和y。（这种不太常见）

```c
struct point {
    int x;
    int y;
} p1,p2;
```

**结构变量**

```c
struct date today;
today.month=6;
today.day=19;
today.year=2005;
```

声明了结构类型之后，可以定义多个本地变量。

**结构的初始化**

```c
#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

int main(int argc, char const *argv[])
{
    struct date today = {07,31,2014};
    struct date thismonth = {.month=7, .year=2014};

    printf("Today's date is %i-%i-%i.\n",
        today.year,today.month,today.day);
    printf("This month is %i-%i-%i.\n",
        thismonth.year,thismonth.month,thismonth.day);

    return 0;
}
```

根据输出结果，thismonth里面未初始化的day的值为0。

**结构成员**
结构和数组有点像：

- 数组用[]运算符和下标访问其成员：
  `a[0]=10;`
- 结构用 . 运算符和名字访问其成员：
  `today.day`
  `student.firstName`
  `p1.x`
  `p1.y`

**结构运算**

要访问整个结构，直接用结构变量的名字。
对于整个结构，可以做赋值、取地址，也可以传递给函数参数。

```c
p1=(struct point){5,10};
//相当于p1.x=5;p1.y=10;

p1=p2;
//相当于p1.x=p2.x;p1.y=p2.y;
```

数组无法做这两种运算。

**结构指针**

和数组不同，结构变量的名字并不是结构变量的地址，必须使用&运算符。

### 11.2.2 结构与函数

`int numberOfDays(struct date d)`
整个结构可以作为参数的值传入函数，这时候，是在函数内新建一个结构变量，并复制调用者的结构的值。
也可以返回一个结构，这与数组完全不同。

以下是一个计算后一天的程序：

```c
#include <stdio.h>
#include <stdbool.h>

// 定义日期结构体
struct date {
    int month;
    int day;
    int year;
};

bool isLeap(struct date d);
int numberOfDays(struct date d);

int main(int argc, char const *argv[]) {
    struct date today, tomorrow;

    // 输入今天的日期（月 日 年）
    printf("Enter today's date (mm dd yyyy):");
    scanf("%i %i %i", &today.month, &today.day, &today.year);

    // 核心逻辑：判断“明天”的日期
    if (today.day != numberOfDays(today)) {
        // 情况1：今天不是本月最后一天，天数直接 +1
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    } else if (today.month == 12) {
        // 情况2：今天是12月最后一天，跨年到下一年的1月1日
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    } else {
        // 情况3：今天是某月最后一天（非12月），进入下个月1号
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }

    printf("Tomorrow's date is %i-%i-%i.\n", tomorrow.year, tomorrow.month, tomorrow.day);
    return 0;
}

// 获取某个月的天数（考虑闰年）
int numberOfDays(struct date d) {
    int days;
    const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.month == 2 && isLeap(d)) {
        days = 29; // 闰年2月有29天
    } else {
        days = daysPerMonth[d.month - 1];
    } //注意下标
    return days;
}

// 判断是否为闰年
bool isLeap(struct date d) {
    bool leap = false;
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
        leap = true;
    }
    return leap;
}
```

**输入结构**

没有直接的方式可以一次scanf一个结构。
如果我们打算写一个函数来读入结构：

```c
#include <stdio.h>

struct point {
    int x;
    int y; };

void getStruct(struct point);
void output(struct point);
void main( ) {
    struct point y = {0, 0};
    getStruct(y);
    output(y); }

void getStruct(struct point p) {
    scanf("%d", &p.x);
    scanf("%d", &p.y);
    printf("%d, %d\n", p.x, p.y); }

void output(struct point p) {
    printf("%d, %d\n", p.x, p.y); }
```

但是，读入的结构如何送回来呢？
这里执行了一个传值的操作，函数中的p和main中的y是不同的。
在函数读入了p的数值之后，没有任何东西回到main，所以y还是{0,0}。

**解决的方案**

问题在于，传入函数的是外面那个结构的克隆体，而不是指针，传入结构和传入数组是不同的。
在这个输入函数中，完全可以创建一个临时的结构变量，然后把这个结构返回给调用者。
注意用来接收的需要是相同结构类型的变量。

```c
#include <stdio.h>

struct point {
    int x;
    int y;
};

struct point getStruct(void);
void output(struct point);

int main(int argc, char const *argv[])
{
    struct point y = {0, 0};
    y = getStruct();
    output(y);
}

struct point getStruct(void)
{
    struct point p;
    scanf("%d", &p.x);
    scanf("%d", &p.y);
    printf("%d, %d", p.x, p.y);
    return p;
}

void output(struct point p)
{
    printf("%d, %d", p.x, p.y);
}
```

**结构指针作为参数**

在K&R中，说过传结构指针比传整个结构更有效率。

**指向结构的指针**

```c
struct date {
    int month;
    int day;
    int year;
} myday;

struct date *p = &myway;

(*p).month = 12; // 必须加括号
p->month = 12; // 和上面的是等价的
```

用->表示指针所指的结构变量中的成员。被注释的第二行和第一行是等价的。

- 被注释第一行必须加括号的原因：
成员访问运算符 . 的优先级高于解引用运算符 * 。
如果不加括号，就会报错。

**结构指针参数**

```c
#include <stdio.h>

// 1. 定义结构体类型
struct point {
    int x;
    int y;
};

// 2. 函数声明（注意参数是指针类型）
struct point* inputPoint(struct point *p);
void output(struct point p);

int main()
{
    // 初始化为 {0, 0}
    struct point y = {0, 0};

    // 关键：传入 y 的地址（&y）
    inputPoint(&y);
    
    // 打印修改后的 y
    output(y);

    return 0;
}

// 3. 函数实现：接收结构体指针，通过 -> 修改成员
struct point* inputPoint(struct point *p)
{
    // 通过指针 p 访问成员 x 和 y，并取地址赋值给 scanf
    scanf("%d", &(p->x));
    scanf("%d", &(p->y));
    
    // 返回这个指针（虽然 main 中未使用，但符合函数定义）
    return p;
}

// 4. 输出函数：直接接收结构体变量（值传递，仅用于打印）
void output(struct point p)
{
    printf("%d, %d\n", p.x, p.y);
}
```

### 11.2.3 结构中的结构

**结构数组**

```c
struct date dates[100];
struct date dates[]= {
    {4,5,2005},{2,4,2005}
};
```

一个计算下一秒的程序如下：

```c
#include <stdio.h>

// 1. 定义时间结构体
struct time {
    int hour;
    int minutes;
    int seconds;
};

// 2. 函数声明：接收并返回结构体
struct time timeUpdate(struct time now);

int main(void) {
    // 3. 定义并初始化结构数组：包含 5 个时间点
    struct time testTimes[5] = {
        {11, 59, 59},  // 11:59:59 下一秒跨分钟
        {12, 0, 0},
        {1, 29, 59},
        {23, 59, 59},  // 23:59:59 下一秒跨天
        {19, 12, 27}
    };
    int i;

    for (i = 0; i < 5; ++i) {
        // 4. 打印当前时间
        printf("Time is %.2i:%.2i:%.2i", 
               testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);

        // 5. 将当前时间传入函数加 1 秒，并接收返回的新时间
        testTimes[i] = timeUpdate(testTimes[i]);

        // 6. 打印增加 1 秒后的时间
        printf("...one second later it's %.2i:%.2i:%.2i\n", 
               testTimes[i].hour, testTimes[i].minutes, testTimes[i].seconds);
    }

    return 0;
}

// 7. 时间加 1 秒的核心逻辑
struct time timeUpdate(struct time now) {
    ++now.seconds;
    if (now.seconds == 60) {
        now.seconds = 0;
        ++now.minutes;
        if (now.minutes == 60) {
            now.minutes = 0;
            ++now.hour;
            if (now.hour == 24) {
                now.hour = 0;
            }
        }
    }
    return now;
}
```

**结构中的结构**

```c
struct dateAndTime {
    struct date sdate;
    struct time stime;
};
```

如上所示，结构里面的成员也可以是另一个结构。

**嵌套的结构**

```c

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point pt1;
    struct point pt2;
};

// 如果有变量
struct rectangle r;
// 就可以有：
// r.pt1.x、r.pt1.y,
// r.pt2.x 和 r.pt2.y


// 如果有变量定义：
struct rectangle r, *rp;
rp = &r;

// 那么下面的四种形式是等价的：
r.pt1.x
rp->pt1.x
(r.pt1).x
(rp->pt1).x
```

但是没有rp->pt1->x，因为pt1不是指针。

**结构中的结构数组**

```c
#include <stdio.h>

// 1. 基础结构：点
struct point {
    int x;
    int y;
};

// 2. 嵌套结构：矩形（由两个点组成）
struct rectangle {
    struct point p1;  // 左上角
    struct point p2;  // 右下角
};

// 打印函数：逐层访问成员
void printRect(struct rectangle r)
{
    printf("<%d, %d> to <%d, %d>\n", r.p1.x, r.p1.y, r.p2.x, r.p2.y);
}

int main(int argc, char const *argv[])
{
    int i;
    
    // 3. 结构中的结构的数组
    // 外层[]：包含2个矩形的数组
    // 中层{}：1个矩形（包含2个点）
    // 内层{}：1个点的 x 和 y
    struct rectangle rects[] = {
        {{1, 2}, {3, 4}}, // 第1个矩形
        {{5, 6}, {7, 8}}  // 第2个矩形
    };

    for(i = 0; i < 2; i++) {
        printRect(rects[i]);
    }
    
    return 0; 
}
```
