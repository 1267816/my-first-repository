# 第五周：循环控制

## 5.2 循环控制

### 5.2.1

**break 和 continue**
- break：跳出循环
- continue：跳过循环这一轮剩下的语句进入下一轮

**讨论**
在写判断素数的代码时，老师提到了一种“聪明”的做法：可以不设`isPrime`，直接利用循环出口处循环变量和终点值的关系来判断循环是否break了。这种做法是不合适的，为什么？
```c
#include <stdio.h>
int main(){
	int x;
	scanf("%d",&x);
	int i;
	int isPrime=1;  // x是素数
	for (i=2;i<x;i++) {
		if (x%i==0) {
			isPrime = 0;
			break;
		}
	}
	if (isPrime==1) { 
//这里也能判断i是否等于x，但不好
		printf("是素数\n");
	} else {
		printf("不是素数\n");		
	}
	return 0;
}
```
我查看了评论区，询问了ai，综合自己想法得到答案：
- 可读性差
- 过度依赖循环的具体写法，如果把循环写成只试除到x的平方根，就会出问题
- 不符合“循环变量只在循环内使用”的习惯

### 5.2.2
对prime.c进行修改，得到能输出2-100内所有素数的代码：
```c
#include <stdio.h>
int main(){
	int x;
	int i; // x是素数
	for (x=2;x<100;x++) {
		int isPrime=1;
		for (i=2;i<x;i++) {
			if (x%i==0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime==1) {
			printf("%d ",x);
		}
	}
	printf("\n");
	return 0;
}
```
**易错点**
`isPrime`必须放在第一个for循环里面，才能让每次判断x是否为素数时，`isPrime`始终被正确地初始化为1。