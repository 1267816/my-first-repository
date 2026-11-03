// 14.1 可变数组
// AI 整理（DSH）：五个接口函数取自 note-14.1，main() 是补的（视频里是边讲边试，没有一段完整的演示程序）。
// 所以这里不是翁恺视频里的逐字原文，核对以视频与课件为准。
#include <stdio.h>
#include <stdlib.h>

/* 按块增长：每次至少涨一个 BLOCK_SIZE，而不是“多访问一个就涨一个”，
   否则每加一个元素都要重新申请 + 复制一次，太费劲 */
#define BLOCK_SIZE 20

typedef struct {
    int *array;
    int size;
} Array;

Array array_create(int init_size);
void array_free(Array *a);
int array_size(const Array *a);
int *array_at(Array *a, int index);
void array_inflate(Array *a, int more_size);

int main(void)
{
    Array a = array_create(100);
    int i;

    printf("size = %d\n", array_size(&a));

    /* array_at 返回的是指针，所以拿回来可以直接当左值赋值 */
    *array_at(&a, 0) = 10;
    printf("a[0] = %d\n", *array_at(&a, 0));

    /* 一直写到下标 102，超过 100 的部分会自动按块增长 */
    for (i = 0; i <= 102; i++) {
        *array_at(&a, i) = i * 2;
    }
    printf("写入 0..102 之后 size = %d\n", array_size(&a));
    printf("a[102] = %d\n", *array_at(&a, 102));

    array_free(&a);

    return 0;
}

/* 返回结构体本身而不是指针：外面可以写成 Array a = array_create(100);
   如果返回指针，外面拿到的可能是 NULL，也可能已经指向一个旧数组（那就得先 free） */
Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int *)malloc(sizeof(int) * a.size);
    return a;
}

/* 置 0 是为了防止别人 free 两次；free(0) 是无害的 */
void array_free(Array *a)
{
    free(a->array);
    a->size = 0;
    a->array = 0;
}

/* 不直接让外面访问 a->size，而是给一个函数：封装起来，内部实现以后能改 */
int array_size(const Array *a)
{
    return a->size;
}

/* 返回 int* 而不是 int，拿回来才能当左值改内容 */
int *array_at(Array *a, int index)
{
    if (index >= a->size) {
        /* 涨到 index 所在块的边界：
           例：size=100、index=102 → 102/20=5 → (5+1)*20=120 → 涨 20 */
        array_inflate(a, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size);
    }
    return &(a->array[index]);
}

/* 新申请一块更大的空间，把老数据逐个搬过去，再释放老的（复制也可以换 memcpy） */
void array_inflate(Array *a, int more_size)
{
    int *p = (int *)malloc(sizeof(int) * (a->size + more_size));
    int i;

    for (i = 0; i < a->size; i++) {
        p[i] = a->array[i];
    }
    free(a->array);
    a->array = p;
    a->size += more_size;
}
