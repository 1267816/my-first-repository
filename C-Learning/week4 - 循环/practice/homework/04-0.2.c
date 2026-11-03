// 04-0.2 求符合给定条件的整数集（另一种写法）
// AI 整理（DSH）：和 04-0.c 同一题、同一套枚举思路，只把四层嵌套 if 换成 &&。
// 用到的都在第 4 周之前：while、if、&&（第 3 周）；没有用第 5 周的 for / break / continue。
#include <stdio.h>

int main()
{
    int n;          // 输入的 A
    int a, b, c;    // 百位、十位、个位
    int sum;        // 组成的三位数
    int count = 1;  // 计数器，每 6 个换一行

    scanf("%d", &n);

    a = n;
    b = n + 1;
    c = n + 2;
    sum = a * 100 + b * 10 + c;

    while (a < n + 4) {
        if (a != b && a != c && b != c) {
            if (count % 6 == 0) {
                printf("%d\n", sum);
            } else {
                printf("%d ", sum);
            }
            count++;
        }

        if (c < n + 3) {
            c++;
        } else if (b < n + 3) {
            b++;
            c = n;
        } else {
            a++;
            b = n;
            c = n;
        }
        sum = a * 100 + b * 10 + c;
    }

    return 0;
}
