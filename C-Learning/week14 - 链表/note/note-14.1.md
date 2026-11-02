# 第十四周：链表

## 14.1 可变数组

### 14.1.1

如何构造一个大小可变的动态数组？它应当具备：

1. 可增长性
2. 可获取当前大小
3. 可访问元素

考虑这样的“接口”函数设计：

1. `Array array_create(int init_size);`
   创建动态数组
2. `void array_free(Array *a);`
   释放动态数组
3. `int array_size(const Array *a);`
   获得数组大小
4. `int* array_at(Array *a,int index);`
   访问数组的编号为index的元素，返回指针
5. `void array_inflate(Array *a,int more_size);`
   增大数组长度

如何具体实现？先实现前两个接口函数：

```c
typedef struct {
    int *array;
    int size;
} Array;
// typedef 时不要把指针带进去，写成 Array 而不是 *Array
// 否则别人看到 Array a 会不知道 a 其实是个指针

Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int) * a.size);
    // malloc 返回 void*，这里要强制类型转换
    return a;
}
// 返回结构体本身而不是指针，外面就可以写 Array a = array_create(100);
// 如果返回指针，传进来的可能是 NULL，也可能已经指向一个旧数组（那就得先 free）

void array_free(Array *a)
{
    free(a->array);
    a->size = 0;
    a->array = 0;
    // 置 0 是为了防止别人 free 两次，free(0) 是无害的
}
```

### 14.1.2

**可变数组的数据访问**

考虑第三个接口函数：

```c
int array_size(const Array *a)
{
    return a->size;
}
```

为什么不直接输出a.size？这是一种封装的思想，能提高可维护性和安全性，可以保护内部实现。

第四个接口函数：

```c
int* array_at(Array *a, int index)
{
    return &(a->array[index]);
    // 返回 int* 而不是 int，拿回来才能当左值：
    // *array_at(&a, 0) = 10;
}
```

注意，这里需要取地址，否则无法起到修改的功能。

如果不取地址，则需要另外写get函数获取值，再写set函数修改值。

### 14.1.3

**可变数组自动增长**

这是最后一个需要实现的函数。

```c
void array_inflate(Array *a, int more_size)
{
    int *p = (int*)malloc(sizeof(int) * (a->size + more_size));
    int i;
    for (i = 0; i < a->size; i++) {
        p[i] = a->array[i];
        // 申请的新空间在别处，老数据要一个一个搬过去
    }
    free(a->array);
    a->array = p;
    a->size += more_size;
}
```

原理是重新申请一块更大的空间，再把原数组逐一复制过去。
要实现“自动”，还需要在array_at函数的return前面加一段校验：

```c
int* array_at(Array *a, int index)
{
    if (index >= a->size) {
        array_inflate(a, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size);
    }
    return &(a->array[index]);
}
```

注意more_size的优化方法：

```c
#define BLOCK_SIZE 20
more_size = (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size
```

按“index-a->size+1”来涨，每多访问一个单元就要涨一次、复制一次，太费劲。
按块涨：先算出index落在第几个块里（index/BLOCK_SIZE），再涨到下一个块的边界。
例：

```text
size=100、BLOCK_SIZE=20、index=102
102/20=5，(5+1)*20=120，more_size=120-100=20
```

复制那一步也可以换成标准库的`memcpy`，效率比手写循环高。
