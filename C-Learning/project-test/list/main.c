// 14.2 链表：读入若干整数（-1 结束），打印、查找、删除、最后清空
// AI 整理（DSH）：各函数取自 note-14.2（14.2.2 ~ 14.2.6），main() 的流程是把那几段串起来的
// （视频里是一段一段讲的，没有这样一份完整程序），所以不是视频里的逐字原文。
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* 把 head 和 tail 装进一个结构体，函数只要收 List* 就行。
   这是课件讲 add() 时说的“第四种解决思路：包装结构体”（前三种是全局指针、
   返回新 head、二级指针）。 */
typedef struct _list {
    Node *head;
    Node *tail;
} List;

void add(List *pList, int number);
void print(List *pList);
void search(List *pList, int number);
void deleteNode(List *pList, int number);
void clear(List *pList);

int main(int argc, char const *argv[])
{
    List list;
    int number;

    list.head = NULL;
    list.tail = NULL;

    /* 一直读到 -1 为止，每读一个数就挂到链表尾巴上 */
    do {
        scanf("%d", &number);
        if (number != -1) {
            add(&list, number);
        }
    } while (number != -1);

    print(&list);

    printf("要找哪个数：");
    scanf("%d", &number);
    search(&list, number);

    printf("要删哪个数：");
    scanf("%d", &number);
    deleteNode(&list, number);
    print(&list);

    clear(&list);

    return 0;
}

/* 尾插法：链表为空时 head 和 tail 都指向新节点；不为空就接到 tail 后面，
   再把 tail 挪到新节点上（后面这两行的顺序不能反） */
void add(List *pList, int number)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;

    if (pList->head == NULL) {
        pList->head = p;
        pList->tail = p;
    } else {
        pList->tail->next = p;
        pList->tail = p;
    }
}

/* p 是遍历用的指针，走到 NULL 就说明到尾巴了 */
void print(List *pList)
{
    Node *p;

    for (p = pList->head; p; p = p->next) {
        printf("%d\t", p->value);
    }
    printf("\n");
}

/* 边遍历边比较；找到就 break，没找到靠 isFound 标记 */
void search(List *pList, int number)
{
    Node *p;
    int isFound = 0;

    for (p = pList->head; p; p = p->next) {
        if (p->value == number) {
            printf("找到了\n");
            isFound = 1;
            break;
        }
    }
    if (!isFound) {
        printf("没找到\n");
    }
}

/* 单链表只能往前走，删 p 必须知道它的前一个节点 q，用 q 跨过 p。
   q 从 NULL 起步；如果一开始就命中（删的是头节点），q 还是 NULL，
   这时候要改的是 head，而不是 q->next（NULL->next 会段错误）。
   注意：这一版只摘节点，没有同步维护 List.tail。 */
void deleteNode(List *pList, int number)
{
    Node *q;
    Node *p;

    for (q = NULL, p = pList->head; p; q = p, p = p->next) {
        if (p->value == number) {
            if (q) {
                q->next = p->next;
            } else {
                pList->head = p->next;
            }
            free(p);
            break;
        }
    }
}

/* 先把下一个节点存到 q，再 free(p)，最后靠 for 里的 p = q 往前走。
   循环结束后 head 指向的已经是释放过的内存，要置 NULL 防止误用成野指针。 */
void clear(List *pList)
{
    Node *q;
    Node *p;

    for (p = pList->head; p; p = q) {
        q = p->next;
        free(p);
    }
    pList->head = NULL;
}
