// 04-3.2 统计素数并求和（另一种写法）
// AI 整理（DSH）：和 04-3.c 同一题，换掉枚举乘积对的算法。
// 原写法把 1..n 的两两乘积全部走一遍再数“能凑出这个数的对数”，
// 每个 x 都要跑一遍二重循环；这里直接试除到平方根，一旦发现因数就把标志位清零。
// 注意：这里故意不用 break——break 是第 5 周才讲的，第 4 周只有 while / if / 标志变量。
#include <stdio.h>

int main()
{
    int m, n;
    int x, d;
    int isPrime;
    int num = 0;    // 素数个数
    int sum = 0;    // 素数和

    scanf("%d %d", &m, &n);

    x = m;
    while (x <= n) {
        isPrime = 1;
        if (x < 2) {
            isPrime = 0;    // 1 和 0 都不是素数
        } else {
            d = 2;
            while (d * d <= x) {
                if (x % d == 0) {
                    isPrime = 0;
                }
                d++;
            }
        }
        if (isPrime) {
            num++;
            sum += x;
        }
        x++;
    }

    printf("%d %d", num, sum);

    return 0;
}
