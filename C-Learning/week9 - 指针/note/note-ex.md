# 指针的应用

### 应用一：通过函数修改外部变量

**问题**

函数参数是值传递，函数内改参数，外面的变量不会变。

```c
void f(int k) {
    k = 10;   // 外面的 i 不变
}
```

**解决**

传变量的地址，函数内用 `*` 解引用。

```c
void f(int *p) {
    *p = 10;  // 改的是外面的 i
}

int main() {
    int i = 6;
    f(&i);
    printf("%d\n", i);  // 10
}
```

**套路**

1. 函数参数写 `int *p`
2. 函数里用 `*p` 读写
3. 调用时传 `&i`

**典型例子：交换两个变量**

```c
void swap(int *pa, int *pb) {
    int t = *pa;
    *pa = *pb;
    *pb = t;
}
```

**另一个场景：函数返回多个结果**

函数只能返回一个值，但可以通过指针带回多个结果。

```c
void minmax(int a[], int len, int *max, int *min) {
    *min = *max = a[0];
    for (int i = 1; i < len; i++) {
        if (a[i] < *min) *min = a[i];
        if (a[i] > *max) *max = a[i];
    }
}
```

==调用时把要保存结果的变量地址传进去==：

```c
int min, max;
minmax(a, n, &max, &min);
```

---

### 应用二：向函数传递数组

**问题**

数组很大，传值效率低；函数内也无法直接知道数组长度。

**解决**

==传数组名（退化为指针）和长度。==

```c
void print(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
```

调用时直接写数组名：

```c
int arr[3] = {1, 2, 3};
print(arr, 3);
```

**注意**

- 数组参数等价于指针，下面四种写法完全一样：

```c
int sum(int *ar, int n);
int sum(int *, int);
int sum(int ar[], int n);
int sum(int [], int);
```

- 在函数内 `sizeof(a)` 得到的是指针大小，不是数组大小。

```c
void f(int a[]) {
    printf("%zu\n", sizeof(a));  // 8，不是 40
}
```

- 如果不想让函数修改数组内容，加 `const`：

```c
int sum(const int a[], int length);
```

---

### 应用三：动态内存分配

**问题**

数组大小在运行时才能确定。C99 之前不能用变量定义数组大小。

**解决**

用 `malloc` 申请内存，用完 `free`。

```c
#include <stdlib.h>

int n;
scanf("%d", &n);

int *a = malloc(n * sizeof(int));
if (a == NULL) {
    return 1;   // 申请失败
}

for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
}

// 用完了
free(a);
a = NULL;   // 避免悬空指针
```

**要点**

- `malloc(size)` 的参数是字节数，返回 `void*`，需要转成需要的类型。
- 申请失败返回 `NULL`，必须检查。
- 只能 `free` 申请来的空间的首地址。
- 不要重复 `free`，也不要 `free` 不是 `malloc` 得到的地址。
- 忘记 `free` 会导致内存泄漏。

**测试系统能给多少空间**

```c
void *p;
int cnt = 0;
while ((p = malloc(100 * 1024 * 1024))) {
    cnt++;
}
printf("分配了 %d00MB 的空间\n", cnt);
```

---

### 应用四：表示“没有”（空指针）

**问题**

指针可能无效，需要一个特殊值表示“不指向任何地方”。

**解决**

用 `NULL`。

```c
int *p = NULL;

if (p != NULL) {
    printf("%d\n", *p);
}
```

**用途**

- ==初始化指针==，避免野指针。
- 函数返回无效指针时返回 `NULL`。
- ==释放内存后把指针置为 `NULL`==。

```c
free(p);
p = NULL;
```

**注意**

- ==不要解引用 `NULL`==。
- 0 地址通常不能随便访问，所以用 `NULL` 表示无效。
- 有的编译器不愿意直接用 `0` 表示空指针，所以用 `NULL`。

---

### 9.3.5 总结：什么时候用指针

1. **想改函数外面的变量** → 传地址，函数内用 `*p`。
2. **传数组给函数** → 传数组名 + 长度。
3. **运行时才知道要多少内存** → `malloc` / `free`。
4. **表示“没有”** → `NULL`。

其他情况优先用普通变量和数组下标。指针不是到处都要用，只在上面这四种场合出场。