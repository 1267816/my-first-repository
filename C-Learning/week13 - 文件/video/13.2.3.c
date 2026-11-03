// 13.2.3 输出一个数的二进制
// AI 整理（DSH）：按课件与 note-13.2 整理，不是翁恺视频里的逐字原文，变量名与注释可能与课堂不同。
#include <stdio.h>

int main(void)
{
    int number;

    /* 1u 是无符号的 1：有符号的 1 << 31 会溢到符号位，是未定义行为，
       写成 1u << 31 才是“第 31 位为 1、其余为 0”的掩码 */
    unsigned mask = 1u << 31;

    printf("输入一个数：");
    scanf("%d", &number);

    /* 从最高位开始，一位一位地和掩码做与，非 0 就是 1；
       每轮把掩码右移一位，移 32 次之后 mask 变成 0，循环结束 */
    for (; mask; mask >>= 1) {
        printf("%d", number & mask ? 1 : 0);
    }
    printf("\n");

    return 0;
}
