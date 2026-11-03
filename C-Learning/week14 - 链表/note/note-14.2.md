# 第十四周：链表

## 14.2 链表

### 14.2.1

**可变数组的缺陷**

- 需要时间复制
- 可能被内存受限的场景限制

### 14.2.2

**链表**

结点的头文件node.h定义如下：

```c
#ifndef _NODE_H_
#define _NODE_H_

typedef struct _node {
    int value;
    struct _node *next;
} Node;

#endif;
```

之前的读入若干个数据，直到读入-1才停下的程序，可以用变长数组，也可以用链表。
下面演示怎么用链表做这个事情：

```c
#include "node.h"
#include <stdio.h>

int main(int argc,char const *argv[]) {
    Node *head=NULL;
    int number;
    do {
        scanf("%d",&number);
        if (number!=-1) {
            // 加入链表
            Node *p=(Node*)malloc(sizeof(Node));
            p->value=number;
            p->next=NULL;
            // 找到最后那一个
            Node *last=head;
            if (last) {
                while (last->next) {
                    last=last->next;
                }
                // 接上去
                last->next=p;
            } else {
                head=p;
            }
        }
    } while (number!=-1);
    return 0;
}
```

### 14.2.3

**链表的函数**

我们想要把`if (number!=-1) {...}`里面的结构做成一个函数：

```c
void add(Node* head,int number) {
    Node *p=(Node*)malloc(sizeof(Node));
    p->value=number;
    p->next=NULL;
    Node *last=head;
    if (last) {
        while (last->next) {
            last=last->next;
        }
        last->next=p;
    } else {
        head=p;
    }
}
```

但是，一个严重的问题出现了：
传进去的head指针只是一个副本，与原始head指针虽然同名，指向同一区域，但是，它们被存放在不同的内存地址里。
要注意区分的是，这里与swap函数里的指针应用不同。
因为，swap函数改变的是指针指向的内容，而我们期望的add函数需要改变指针自己的指向。
所以说，要修改数据，必须传数据的指针；要修改指针，必须传指针的指针。

一种解决思路是全局指针。
为什么不推荐使用全局指针？
原因是：它是一次性的，就无法同时存在多个链表；而且，它是强耦合的，任何函数都可以修改；最后，它是线程安全的。

第二种解决思路是把add函数的返回值类型改成`Node*`，在调用函数时，写`head=add(head,number);`.
不过，这种思路也有小缺点，就是如果在调用时忘记写`head=`，就会出错。

然后，就来到了第三种解决思路：二级指针。
我们要把函数原型改成这样：

```c
void add(Node** pHead,int number);
```

然后在相应的地方做修改：

- 主函数必须给head加取地址符
- 函数内部必须给pHead解引用

最后，还有第四种解决思路：包装结构体。
我们可以把head，甚至tail（尾指针）和size（链表长度）装进一个结构体“List”里，只需要传给函数List的地址：

```c
typedef struct _list {
    Node *head;
    Node *tail; // 存入尾指针，可以用尾插法
    // int size; //可存链表长度
} List;
```

main函数中的调用：

```c
int main(int argc,char const *argv[]) {
    List list;
    list.head=NULL;
    list.tail=NULL;

    int number;
    do {
        scanf("%d",&number);
        if (number!=-1) {
            add(&list,number);
        }
    } while (number!=-1);

    return 0;
}
```

add函数的实现：

```c
void add(List *pList,int number) {
    // 创建新节点
    Node *p=(Node*)malloc(sizeof(Node));
    p->value=number;
    p->next=NULL;

    // 挂载节点
    if (pList->head==NULL) {
        // 链表为空
        pList->head=p;
        pList->tail=p;
    } else {
        // 链表不为空
        pList->tail->next=p; // 1
        pList->tail=p;       // 2
    }
}
```

解释带有注释1和2的两行代码：

`pList->tail`拿出来的是当前的尾指针，指向的是目前的链表尾，`->next`就拿出了链表尾的next成员，把p赋给它，这样，链表尾next指针就指向了新节点p；

之后，p已经接到链表尾了，因此我们需要更新tail，让下一个节点能够接到新的链表尾p上，而非旧的。所以需要`pList->tail=p;`，改变tail的指向。

### 14.2.4

**链表的搜索**

我们需要遍历整个list，并进行搜索。
实现如下：

```c
Node *p;
int isFound=0;
for (p=list.head;p;p=p->next) {
    if (p->value==number) {
        printf("找到了\n");
        isFound=1;
        break;
    }
}
if (!isFound) {
    printf("没找到\n");
}
```

### 14.2.5

**链表的删除**

我们想要在链表中找到值为i的节点，并把它删掉。
我们知道单链表是单向的，如果节点p需要删掉，那么，必须知道它的前一个节点q，才能把链表重新连起来。

考虑如下的代码：

```c
Node *q;
for (q=NULL,p=list.head;p;q=p,p=p->next) {
    if (p->value==number) {
        q->next=p->next;
        // 让q跨过p，指向p的下一个节点
        free(p);
        // 记得释放内存
        break;
    }
}
```

q跟在p后面，记住前一个节点。每次循环末尾，q先走到p的位置，然后p在向前走一步。

但是，这段代码有严重的bug：
如果我们要删的节点恰好是头节点，怎么办？
程序会崩溃，因为q是NULL，NULL->next会段错误！

一种机械的检查这种边界情况的方法是：
==`->`左边的指针必须要检查是不是NULL，它必须不能是NULL。==

改进的方法：

```c
Node *q;
for (q=NULL,p=list.head;p;q=p,p=p->next) {
    if (p->value==number) {
        if (q) {
            q->next=p->next;
            // 如果q不是NULL
            // 让q跨过p，指向p的下一个节点 
        } else {
            list.head=p->next;
            // 如果q是NULL
            // 让下一个节点直接成为头节点
        }
        free(p);
        // 记得释放内存
        break;
    }
}
```

### 14.2.6

**链表的清除**

在做完所有事情后，我们需要把整个链表占用的内存全部都释放掉。

```c
for (p=list.head;p;p=q) {
    q=p->next;
    free(p);
}
```

`q=p->next;`的意思是，先把p指向的结构体list中指向下一个节点的指针next存到q里，然后就可以`free(p);`了。在这之后，由于for内的`p=q`，p又会指向下一个节点。以此类推，就可以把整个链表占用的内存就全部被释放掉了。

在释放完之后，list.head依然保存着原来第一个节点的地址，由于指向的内存全部被free了，所以，list.head会变成一个野指针。

因此，在实际写完整的clear函数时，循环结束后通常还需要加上：

```c
list.head=NULL;
```

防止误用list.head。
