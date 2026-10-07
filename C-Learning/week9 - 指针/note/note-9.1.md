# 第九周：指针

## 9.1 指针

### 9.1.1

**sizeof**
是一个运算符，给出某个类型或变量在内存中所占据的字节数。
- `sizeof(int);`
- `sizeof(i);`

**运算符&**
- `scanf("%d",&i);`里的&
- 获得变量的地址，它的操作数必须是变量
  - `int i=0;printf("0x%x",&i);`可以取出i的地址，该语句可能会warning，因为它需要你用的是%p而非%x
- 地址的大小是否与int相同取决于编译器
  - `int i=0;printf("%p",&i);`

在64位架构下，sizeof(int)的结果是4，sizeof(&i)的结果是8；在32位架构下，sizeof(int)和sizeof(&i)的结果都是4。

**&不能取的地址**
&不能对没有地址的东西取地址
- &(a+b);
- &(a++);
- &(++a);

**试试这些&**
- 变量的地址
- 相邻的变量的地址
```c
int i=0;
int p;
printf("%p\n",&i);
printf("%p\n",&p);
```
输出结果为
```
000000000065FE4C
000000000065FE48
```
- &的结果的sizeof
- 数组的地址
- 数组单元的地址
- 相邻的数组单元的地址
```c
int a[10];
printf("%p\n",&a);
printf("%p\n",a);
printf("%p\n",&a[0]);
printf("%p\n",&a[1]);
```
输出结果为
```
000000000065FE20
000000000065FE20
000000000065FE20
000000000065FE24
```

### 9.1.2

**scanf**
如果能够将取得的变量的地址传递给一个函数，能否通过这个地址在那个函数内访问这个变量？
- `scanf("%d",&i)`;

`scanf()`的原型应该是怎样的？我们需要一个参数能保存别的变量的地址，如何表达能够保存地址的变量？

**计算机圣经**
学计算机一定要有一个非常强大的心理状态，什么呢？计算机的所有东西都是人做出来的，别人能想得出来的，我也一定能想得出来。在计算机里头没有任何黑魔法，所有的东西只不过是我现在不知道而已，总有一天我会把所有的细节，所有的内部的东西全都搞明白了，那个scanf里面到底怎么做事情的，只不过我们现在才刚开始学习，我们还没有来得及去看scanf的原始代码是怎么样的，scanf也不过是个函数，也不过是某个人给他写出来的，那个人和我们一样，同样只是一个脑袋而已。

**指针**
保存地址的变量。
- `int i;`
- `int* p=&i;`
- `int* p,q;`
- `int *p,q;`
  上述二者都表示p是一个指针，而q是一个普通的int变量，我们是把星号交给了p而不是int，因此，并没有int*这个类型

**指针变量**
变量的值是内存的地址
- 普通变量的值是实际的值
- 指针变量的值是具有实际值的变量的地址

**作为参数的指针**
`void f(int p);`
在f函数被调用的时候得到了某个变量的地址：
- `int i=0;f(&i);`
- 这意味着在函数里面可以通过这个指针访问外面这个i
```c
#include <stdio.h>

int main(void) {
    int i=6;
    printf("&i=%p\n",&i);
    f(&i);
    return 0;
}

void f(int *p) {
  printf(" p=%p\n", p);
}

void g(int k) {
  printf("k=%d\n",k);
}
```
在上述例子中，p得到了i的地址，而k只得到了i的值，k和外面的i没有任何关系。

**访问那个地址上的变量**
*是一个单目运算符，用来访问指针的值所=表示的地址上的变量，可以做右值也可以做左值。
- `int k=*p;`
- `*p=k+1;`

**传入地址**
为什么`int i;scanf{"%d",i};`的编译没有报错？
因为scanf不知道你传进去的6不是一个地址，而运行一定会出错的原因是scanf把它读进来的那个数字写到了不该写的地方。

### 9.1.3

**指针应用场景一**
交换两个变量的值：
```c
#include <stdio.h>
void swap(int *pa,int *pb);
int main(void) {
  int a=5;
  int b=6;
  swap(&a,&b);//注意要把a和b的地址传进去
  printf("a=%d,b=%d\n",a,b);
  return 0;
}
void swap(int *pa,int *pb) {
  int t=*pa;
  *pa=*pb;
  *pb=t;
}
```

**指针应用场景二**
函数要返回多个值，某些值就只能通过指针返回。传入的参数实际上是需要保存带回的结果的变量。
```c
#include <stdio.h>
void minmax(int a[],int len,int *max,int *min);
int main(void) {
  int a[]={1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55};
  int min,max;
  minmax(a,sizeof(a)/sizeof(a[0]),&min,&max);
  printf("min=%d,max=%d\n",min,max);
  return 0;
}
void minmax(int a[],int len,int *max,int *min)
{
  int i;
  *min=*max=a[0];
  for (i=1;i<len;i++) {
    if (a[i]<*min) {
      *min=a[1];
    } 
    if (a[i]>*max) {
      *max=a[1];
    }
  }
}
```

**指针应用场景二b**
函数返回运算的状态，结果通过指针返回。
常用的套路是让函数返回特殊的不属于有效范围内的值来表示出错：
- -1或0（在文件操作会看到大量的例子）

但是当任何数值都是有效的可能结果是，就得分开返回了。
后续的语言（C++，Java）采用了异常机制来解决这个问题。
```c
#include <stdio.h>
/**
    @return 如果除法成功，返回1；否则返回0
*/
int divide(int a.int b,int *result);
int main(void) {
  int a=5;
  int b=2;
  int c;
  if (divide(a,b,&c)) {
    printf("%d/%d=%d\n",a,b,c);
  }
  return 0;
}
int divide(int a,int b,int *result) {
  int ret=1;
  if (b==0) {
    ret=0;
  } else {
    *result=a/b;
  }
  return ret;
}
```

**指针最常见的错误**
定义了指针变量，还没有指向任何变量，就开始使用指针。因为如果指针还没被初始化，分配给指针的地址可能指向重要数据，所以有可能会崩溃。

### 9.1.4

**传入函数的数组变成了什么？**
```c
int isPrime(int x,int knownPrimes,int numberofKnownPrimes) 
{
    int ret=1;
    int i;
    for (i=0;i<numberofKnownPrimes;i++) {
      if (x%knownPrimes[i]==0) {
        ret=0;
        break;
      }
    }
    return ret;
}
```
函数参数表中的数组实际上是指针，`sizeof(a)==sizeif(int *)`，但是可以用数组的运算符[]进行运算。

**数组参数**
以下四种函数原型是等价的：
1. `int sum(int *ar,int n);`
2. `int sum(int *,int);`
3. `int sum(int ar[],int n);`
4. `int sum(int [],int);`

**数组变量是特殊的指针**
数组变量本身表达地址，所以`int a[10];int *p=a;`无需用&取地址，但是数组的单元表达的是变量，需要用&取地址。同时，有`a==&a[0]`。
[]运算符可以对数组做，也可以对指针做。
*运算符可以对指针做，也可以对数组做。
数组变量是const的指针，所以不能被赋值。

### 9.1.5（C99）

**指针是const**
表示一旦得到了某个变量的地址，不能再指向其他变量。
```c
int *const q=&i; //q是const
*q=26; //OK
q++; //ERROR
```
意思就是说：可以通过i来改变q的值，但是不能通过q改变i的值，因为如果要通过q改变i的值，就相当于让q指向了其他变量而非i。

**所指是const**
表示不能通过这个指针取修改那个变量，这并不能使得那个变量成为const。
```c
const int *p=&i;
*p=26; //ERROR，因为*p是const
i=26; //OK
p=&j; //OK
```

**这些是啥意思**
```c
int i;
const int* p1=&i;
int const* p2=&i;
int *const p3=&i;
```
判断哪个被const了的标志是const在*的前面还是后面，如果在前面，那么表示说“所指是const”，也就是通过指针不能修改，即第1和2种；如果在后面，呢么表示说“指针是const”，也就是指针不能修改，即第3种。

**转换**
总是可以把一个非const的值转换为const的。
```c
void f(const int *x);
int a=15;
f(&a); //OK
const int b=a;
f(&b); //OK
b=a+1; //ERROR
```
当要传递的参数的类型比地址大的时候，这是常用的手段：既能用比较少的字节数传递值给参数，又能避免函数对外面的变量的修改。
后面讲结构的时候，会再展开讲。

**const数组**
`const int a[]={1,2,3,4,5,6};`
数组变量已经是const的指针了，这里的const表明数组的每个单元都是const int，所以必须通过初始化进行赋值。

**保护数组值**
因为把数组传入函数时传递的是地址，所以那个函数内部可以修改数组的值。为了保护数组不被破坏，可以设置参数为const：
`int sum(const int a[],int length);`
