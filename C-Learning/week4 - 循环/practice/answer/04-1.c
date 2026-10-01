#include <stdio.h>

int main()
{
    int n;
    int i;
    int min = 1;
    int max;
    int x, y, z, sum;

    // 预先存放 0~9 的 n 次幂，在n较大时可以大幅优化计算量
    int p0 = 0, p1 = 1;
    int p2 = 1, p3 = 1, p4 = 1, p5 = 1;
    int p6 = 1, p7 = 1, p8 = 1, p9 = 1;

    scanf("%d", &n);

    // 计算 2~9 的 n 次幂
    i = 0;
    while (i < n) {
        p2 *= 2;
        p3 *= 3;
        p4 *= 4;
        p5 *= 5;
        p6 *= 6;
        p7 *= 7;
        p8 *= 8;
        p9 *= 9;
        i++;
    }

    // 求 n 位数的范围，例如 n=3 时 min=100, max=1000
    i = 1;
    while (i < n) {
        min *= 10;
        i++;
    }
    max = min * 10;

    // 初始化遍历的下界
    x = min;
    while (x < max) {
        // 用y存储x
        y = x;
        //初始化sum为0
        sum = 0;

        // 取出每一位数字，累加它的 n 次幂
        while (y > 0) {
            z = y % 10;
            y /= 10;
            switch (z) {
                case 0: sum += p0; break;
                case 1: sum += p1; break;
                case 2: sum += p2; break;
                case 3: sum += p3; break;
                case 4: sum += p4; break;
                case 5: sum += p5; break;
                case 6: sum += p6; break;
                case 7: sum += p7; break;
                case 8: sum += p8; break;
                case 9: sum += p9; break;
            }
        }

        //判断是否符合定义
        if (sum == x) {
            printf("%d\n", x);
        }
        //改变x的值以遍历
        x++;
    }

    return 0;
}