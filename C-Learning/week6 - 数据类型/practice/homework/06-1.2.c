// 06-1.2 简单计算器（另一种写法）
// AI 整理（DSH）：和 06-1.c 同一题、同一套状态机，只改一处——
// 原来用 10 个 case 的 switch 把字符 '0'..'9' 转成数字，这里直接 c - '0'。
// 第 6 周讲了 char 与 ASCII，字符相减是这一周的内容，不算超纲，也和 06-2.c 里 c+'A'-'a' 同源。
#include <stdio.h>

int main()
{
    int result = 0;
    char c = 0;
    int d = 0;
    int a = 0;
    int num_cnt = 0;
    int err = 0;
    int op = 0;

    do {
        scanf("%c", &c);

        if (c >= '0' && c <= '9') {
            d = c - '0';        // '0'..'9' 的 ASCII 连续，减掉 '0' 就是数值
            a = a * 10 + d;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {
            num_cnt++;
            if (num_cnt == 1) {
                result = a;
            } else if (op != 0) {
                switch (op) {
                    case '+':
                        result += a;
                        break;
                    case '-':
                        result -= a;
                        break;
                    case '*':
                        result *= a;
                        break;
                    case '/':
                        if (a != 0) {
                            result /= a;
                            break;
                        } else {
                            printf("ERROR");
                            err = 1;
                            break;
                        }
                }
                if (err == 1) {
                    break;
                }
            }
            a = 0;
            op = c;
            if (c == '=') {
                printf("%d", result);
            }
        } else {
            printf("ERROR");
            break;
        }
    } while (c != '=');

    return 0;
}
