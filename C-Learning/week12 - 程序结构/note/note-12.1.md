# 第十二周：程序结构

## 12.1 全局变量

### 12.1.1

**全局变量**
定义在函数外面的变量是全局变量。
全局变量具有全局的生存期和作用域，它们与任何函数都无关，在任何函数内部都可以使用它们。

```c
#include <stdio.h>

int f(void);

int gall = 12;

int main(int argc, char const *argv[])
{
    printf("in %s gall=%d\n", __func__, gall);
    f();
    printf("again in %s gall=%d\n", __func__, gall);
    return 0;
}

int f(void)
{
    printf("in %s gall=%d\n", __func__, gall);
    gall += 2;
    printf("again in %s gall=%d\n", __func__, gall);
    return gall;
}
```

代码中的`__func__`是C99标准引入的预定义宏，会自动替换成当前函数的名称（“main”或“f”），方便调试。
注意它每一边都有两个下划线。

**全局变量初始化**

没有做初始化的全局变量会得到0值，指针会得到NULL值。
只能用编译时刻已知的值来初始化全局变量，它们的初始化发生在main函数之前。

**被隐藏的全局变量**

如果函数内部存在与全局变量同名的变量，则全局变量会被隐藏。

### 12.1.2

**静态本地变量**

在本地变量定义时，加上static修饰符，就成为静态本地变量。
当函数离开的时候，静态本地变量会继续存在并保持其值。
静态本地变量的初始化只会在第一次进入这个函数时做，以后进入函数时会保持上次离开时的值。

```c
#include <stdio.h>

int f(void);

int gall = 12;

int main(int argc, char const *argv[])
{
    printf("in %s gall=%d\n", __func__, gall);
    f();
    printf("again in %s gall=%d\n", __func__, gall);
    return 0;
}

int f(void)
{
    printf("in %s gall=%d\n", __func__, gall);
    gall += 2;
    printf("again in %s gall=%d\n", __func__, gall);
    return gall;
}
```

**静态本地变量**

静态本地变量实际上是特殊的全局变量，它们位于相同的内存区域。
静态本地变量具有全局的生存期，函数内的局部作用域。
static在这里的意思是局部作用域（本地可访问）。

### 12.1.3

***返回指针的函数**

返回本地变量的地址是危险的，会产生悬空指针；
返回全局变量或静态本地变量的地址是安全的；
返回在函数内malloc的内存是安全的，但是容易造成问题；
最好的做法是返回传入的指针。

**tips**

不要使用全局变量来在函数间传递参数和结果。
尽量避免使用全局变量。
使用全局变量和静态本地变量的函数是线程不安全的。
