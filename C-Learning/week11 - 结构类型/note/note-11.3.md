# 第十一周：结构类型

## 11.3 联合

### 11.3.1 类型定义

**自定义数据类型（typedef）**

C语言提供了一个叫做typedef的功能来声明一个已有的数据类型的新名字，比如：

`typedef int Length;`

使得Length成为int类型的别名。
这样，Length这个名字就可以代替int出现在变量定义和参数声明的地方了：

```c
Length a,b,len;
Length numbers[10];
```

**Typedef**

声明新的类型的名字，新的名字是某种类型的别名，改善了程序的可读性。

```c
typedef long int64_t;
// 重载已有的类型名字
// 新名字的含义更清晰，具有可移植性
typedef struct ADate {
    int month;
    int day;
    int year;
} Date; 
// 简化了复杂的名字struct ADate

int64_t i = 10000000000;
Date d = {9, 1, 2005};
```

在typedef和最后的那个单词中间的所有东西是它原来的类型。

**Typedef的一些用法**

1. 定义基本类型别名
如在以下的代码中，Length等价于int类型。

```c
typedef int Length;
```

2. 定义数组和指针的别名
如在以下的代码中，Strings是10个字符串的数组的类型。

```c
typedef char* Strings[10];
```

这个语法就是把平时声明变量的语句前面加上typedef，这样，就把原来的变量名Strings变成了“类型名”，代表包含10个字符串的数组的类型。
以后，如果需要定义一个包含10个字符串的数组，就不用写`char* myArray[10];`，而可以直接写`Strings myArray;`。

3. 定义结构体别名
有两种常见方式：

    1. 定义同时起别名（合并写法）：

    ```c
    typedef struct node {
        int data;
        struct node *next;
    } aNode;
    ```

    2. 先定义，再起别名（分布写法）：

    ```c
    struct node {
        int data;
        struct node *next;
    };
    typedef struct node aNode;
    ```

这里`struct node *next;`可以简单理解为，一个类型为它所在的那个结构体本身的指针。

### 11.3.2 联合

**联合**
存储：

- 所有的成员共享一个空间
- 同一时间，只有一个成员是有效的
- union的大小是其最大的成员
初始化：

- 对第一个成员做初始化

**代码示例**

```c
union AnElt{
    int i; //占4字节
    chat c; //占1字节 
} elt1,elt2;

elt1.i=4;         //此时内存低地址存放04 00 00 00 （小端序机器）
elt2.c='a';       //此时内存存放61（ASCII码）
elt2.i=0xDEADBEEF;//4字节数据覆盖写入
```

现在不需要深入了解。
