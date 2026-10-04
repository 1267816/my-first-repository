# 第八周：数组

## 8.1 数组

### 8.1.1

如何写一个程序计算用户输入的数字的平均数？
由于不需要记录下所有输入的数，所以：
```c
#include <stdio.h>
int main(){
    int x;
    double sum=0;
    int cnt=0;
    scanf("%d",&x);
    while (x!=-1) {
        sum+=x;
        cnt++;
        scanf("%d",&x);
    }
    if (cnt>0) {
        printf("%f\n",sum/cnt);
    }
    return 0;
}
```

如何写一个程序计算用户输入的数字的平均数，并输出所有大于平均数的数？
- 显然，这个程序要记录下所有输入的数。

如何记录很多数？
- 定义很多很多变量`int num1,num2,num3...`？显然不合适。这就要使用数组了。

**数组**
- `int number[100];`
- `scanf("%d",&number[i]);`

因此，可以把一开始的程序改成如下形式，修改的部分用两个斜杠进行注释。
```c
#include <stdio.h>
int main(){
    int x;
    double sum=0;
    int cnt=0;
    int number[100]; //定义数组
    scanf("%d",&x);
    while (x!=-1) {
        number[cnt]=x; //对数组中的元素赋值
        sum+=x;
        cnt++;
        scanf("%d",&x);
    }
    if (cnt>0) {
        printf("%f\n",sum/cnt);
        for (int i=0;i<cnt;i++) {  //遍历数组
            if (number[i]>sum/cnt) {  //使用数组中的元素
                printf("%d\n",number[i]);  //使用数组中的元素
            }  //
        }  //
    }
    return 0;
}
```
当然，这个程序存在安全隐患，那就是没有防止cnt超过数组的下标。


