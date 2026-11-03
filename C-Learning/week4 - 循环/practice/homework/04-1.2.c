// 04-1.2 N 位水仙花数（另一种写法）
// AI 整理（DSH）：和 04-1.c 同一题。原写法用一个游标 y 反复除、再用 cnt 数乘方次数，
// 变量多、容易绕；这里改成“每次取出一位（%10）、这一位乘 n-1 次（while 累乘）、再把 y 除以 10”，
// 判定条件没变。只用第 4 周之前的 while、if、%、/。
#include <stdio.h>

int main()
{
    int n;
    int min = 1;    // n 位数的下界：10^(n-1)
    int q;
    int x, y;
    int digit, power, k;
    int sum;

    scanf("%d", &n);

    q = n;
    while (q > 1) {
        min *= 10;
        q--;
    }

    x = min;
    while (x < min * 10) {
        sum = 0;
        y = x;
        while (y > 0) {
            digit = y % 10;      // 取出最低一位
            power = 1;
            k = 0;
            while (k < n) {      // digit 的 n 次方：乘 n 次
                power *= digit;
                k++;
            }
            sum += power;
            y /= 10;             // 去掉最低位
        }
        if (sum == x) {
            printf("%d\n", x);
        }
        x++;
    }

    return 0;
}
