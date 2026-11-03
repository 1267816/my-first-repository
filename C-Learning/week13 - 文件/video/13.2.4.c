// 13.2.4 位段
// AI 整理（DSH）：按课件与 note-13.2 整理，不是翁恺视频里的逐字原文，变量名与注释可能与课堂不同。
#include <stdio.h>

/* 位段：指定每个成员占几位（单位是 bit，不是 byte）。
   3 + 1 + 1 + 27 = 32，正好一个 unsigned int，所以整个结构体只占 4 字节。
   如果加起来超过 32，编译器会再开一个 int 来放。 */
struct {
    unsigned int leading : 3;
    unsigned int FLAG1 : 1;
    unsigned int FLAG2 : 1;
    unsigned int trailing : 27;
} u;

void printBin(unsigned int number);

int main(void)
{
    /* 每个成员落在哪几位是由编译器/ABI 决定的：本机 GCC（MSVCRT 目标）从低位开始分配，
       所以 leading 落在最低 3 位、FLAG1 落在第 3 位，打印出来是 ...00001010 = 10。 */
    u.leading = 2;     /* 010 */
    u.FLAG1 = 1;
    u.FLAG2 = 0;
    u.trailing = 0;

    /* 位段没法整体打印，课件里的做法是把整个结构体当无符号整数读出来：
       取地址 → 转成 unsigned int* → 解引用。 */
    printBin(*(unsigned int *)&u);
    printf("sizeof = %d\n", (int)sizeof(u));

    return 0;
}

void printBin(unsigned int number)
{
    unsigned mask = 1u << 31;
    for (; mask; mask >>= 1) {
        printf("%d", number & mask ? 1 : 0);
    }
    printf("\n");
}
