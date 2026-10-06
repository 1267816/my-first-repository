# 第八周：数组

## 8.2 数组运算

### 8.2.1

在一组给定的数据中，如何找出数据是否存在？
一个写好的程序如下：
```c
#include <stdio.h>

/**
找出key在数组a中的位置
@param key 要寻找的数字
@param a 要寻找的数组
@param length 数组a的长度
@return 如果找到，返回其在a中的位置；如果找不到返回-1
*/

int search(int key,int a[],int length);

int main(void)
{
	int a[]={2,4,6,7,1,3,5,9,11,13,23,14,32};
	int x;
	int loc;
	printf("请输入一个数字：");
	scanf("%d",&x);
	loc=search(x,a,sizeof(a)/sizeof(a[0]));
	if (loc!=-1) {
		printf("%d在第%d个位置上\n",x,loc);
	} else {
		printf("%d不存在\n",x);
	}
	return 0;
}

int search(int key,int a[],int length)
{
	int ret=-1;
	int i;
	for (i=0;i<length;i++) {
		if (a[i]==key) {
			ret=i;
			break;
		}
	}
	return ret;
}
```

**数组的集成初始化**
```c
int a[]={2,4,6,7,1,3,5,9,11,13,23,14,32};
```
这种方法直接用大括号给出数组的所有元素的初始值，不需要给出数组的大小，编译器替你数数。
但是，如果这样写：`int a[13]={2};`，就只有`a[0]`会被赋值2，`a[1]`到`a[12]`都是0。
当然，可以这样把一个数组里的所有元素全部初始化为0：`int count[number]={0};`。

**集成初始化的定位**
在C99中，可以直接用[n]在初始化数据中给出定位，没有定位的数据接在前面的位置后面，其他位置的值补零。同样，也可以不给出数组大小，让编译器算（如果这样写，数组大小取决于定位的最大下标）。
这种方式特别适合初始数据稀疏的数组。
```c
int a[10]={
    [0]=2,[2]=3,6,
}
```
则`a[0]`等于2，`a[2]`等于3，`a[3]`等于6。

**数组的大小**
怎么让程序知道数组的大小呢？
- sizeof()给出整个数组所占据的内容的大小，单位是字节

因此有`sizeof(a)/sizeof(a[0])`
- sizeof(a[0])给出数组中单个元素的大小，于是相除就得到了数组的单元个数
- 这样的代码，一旦修改数组中初始的数据，不需要修改遍历的代码

**数组的赋值**
现有：
```c
int a[]={2,4,6,7,1,3,5,9,11,13,23,14,32};
```
那能不能写：`int b[]=a;`呢？答案是否定的。
因此：
- 数组变量本身不能被赋值
- 要把一个数组的所有元素交给另一个数组，必须采用遍历
```c
for (i=0;i<length;i++) {
  b[i]=a[i];
}
```

**遍历数组**
通常使用for循环，让循环变量i从0到<数组的长度，这样循环体内最大的i正好是数组最大的有效下标。
==常见错误==是：
- 循环结束条件是<=数组长度
- 离开循环后，继续用i的值来做数组元素的下标，因为此时i正好等于数组的长度，是无效的下标

所以，当数组作为函数参数时，==往往必须再用另一个参数来传入数组的大小==。
因为数组作为函数的参数时：
1. 不能再[]中给出数组的大小
2. 不能再利用sizeof来计算数组的元素个数

### 8.2.2

**判断素数**
之前写过一个程序：
```c
#include <stdio.h>
int isPrime(int x);
int main(void){
    int x;
    scanf("%d",&x);
    if (isPrime(x)){
        printf("%d是素数\n",x);
    } else {
        printf("%d不是素数\n",x);
    }
    return 0;
}
```

怎么来写这个isPrime函数更好呢？

1. 从2到x-1测试是否可以整除
```c
int isPrime(int x){
    int ret=1;
    int i;
    if(x==1) {
        ret=0;
    }
    for (i=2;i<x;i++) {
        if (x%i==0) {
            ret=0;
            break;
        }
    }
    return ret;
}
```
这个代码对n要循环n-1遍，当n很大时认为要循环n遍，效率很低。

2. 去掉偶数后，从3到x-1，每次加2
```c
int isPrime(int x) {
    int ret=1;
    int i;
    if (x==1||(x%2==0&&x!=2)) {
        ret=0;
    }
    for (i=3;i<x;i+=2) {
        if (x%i==0) {
            ret=0;
            break;
        }
    }
    return ret;
}
```
如果x是偶数，立刻能判断；否则要循环(n-3)/2+1遍，当n很大时就是n/2遍。

3. 无需到x-1，到sqrt(x)就够了
```c
#include <math.h>

...

int isPrime(int x) {
    int ret=1;
    int i;
    if (x==1||(x%2==0&&x!=2)) {
        ret=0;
    }
    for (i=3;i<=sqrt(x);i+=2) {
        if (x%i==0) {
            ret=0;
            break;
        }
    }
    return ret;
}
```
或把`i<=sqrt(x)`改成`i*i<=x`，就不用写`#include <math.h>`了。
只需要循环的次数
$$
K = \left[ \frac{\sqrt{x} - 1}{2} \right]
$$
当x很大时，只需要循环$ {\sqrt{x}} $遍。

还有没有更好的？

4. 判断是否能被已知的且小于x的素数整除
```c
#include <stdio.h>

// 判断x是否为素数（用已知素数试除）
int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes);

int main(void) {
    const int number = 100;          // 目标：找前100个素数
    int prime[number] = {2};         // 素数表，默认第一个素数为2
    int count = 1;                   // 已找到的素数个数
    int i = 3;                       // 待测数从3开始（跳过偶数）

    while (count < number) {
        if (isPrime(i, prime, count)) {
            prime[count++] = i;      // 是素数，存入表并更新计数
        }
        i++;
    }

    // 格式化输出，每行5个
    for (i = 0; i < number; i++) {
        printf("%d", prime[i]);
        if ((i + 1) % 5) printf("\t");
        else printf("\n");
    }
    return 0;
}

int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes) {
    int ret = 1;
    for (int i = 0; i < numberOfKnownPrimes; i++) {
        // 能被已知素数整除，则不是素数
        if (x % knownPrimes[i] == 0) {
            ret = 0;
            break;
        }
    }
    return ret;
}
```
5. 构造素数表
欲构造n以内的素数表：
- 令x为2；
- 将2x,3x,4x直至ax<n的数标记为非素数
- 令x为下一个没有被标记为非素数的数，重复上一步，直到所有的数都已经尝试完毕

这种算法叫做埃拉托斯特尼筛法。
因此可以写出以下的伪代码：
- 开辟prime[n]，初始化其所有元素为1，prime[x]为1表示x是素数
- 令x=2
- 如果x是素数，则遍历`for(i=2;x*i<n;i++)`,令`prime[i*x]=0`
- 令x++，如果x<n，重复上一步，否则结束

```c
#include <stdio.h>

int main(void) {
    const int maxNumber = 25;
    int isPrime[maxNumber];          
    // 标记数组：1为素数，0为非素数

    // 初始化：假设所有数都是素数
    for (int i = 0; i < maxNumber; i++) {
        isPrime[i] = 1;
    }

    // 筛法：从2开始，将素数的倍数全部标记为0
    for (int x = 2; x < maxNumber; x++) {
        if (isPrime[x]) {
            for (int i = 2; i * x < maxNumber; i++) {
                isPrime[i * x] = 0;
            }
        }
    }

    // 输出标记为素数的数
    for (int i = 2; i < maxNumber; i++) {
        if (isPrime[i]) {
            printf("%d\t", i);
        }
    }
    printf("\n");
    return 0;
}
```





