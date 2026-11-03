// 13.1.2 文件：写进去、再读回来
// AI 整理（DSH）：按课件与 note-13.1 整理，不是翁恺视频里的逐字原文，变量名与注释可能与课堂不同。
#include <stdio.h>

int main(void)
{
    /* fopen 的第二个参数是模式：
         "r" 只读、"r+" 读写、"w" 只写（不存在就新建，存在就清空）、
         "w+" 读写、"a" 追加、"wx" 只新建（已存在就失败） */
    FILE *fp = fopen("test.txt", "w");

    /* fopen 失败会返回 NULL，不判断就去写，程序会直接崩 */
    if (fp) {
        fprintf(fp, "%d %s\n", 123, "hello");
        fclose(fp);
        printf("写入完成\n");
    } else {
        printf("无法打开文件\n");
        return 1;
    }

    /* 读回来：模式和上面读写对称，%9s 限制最多读 9 个字符，
       防止文件里的内容比数组长，把缓冲区写穿 */
    fp = fopen("test.txt", "r");
    if (fp) {
        int num;
        char word[10];
        fscanf(fp, "%d %9s", &num, word);
        printf("读回：%d %s\n", num, word);
        fclose(fp);
    } else {
        printf("无法打开文件\n");
    }

    return 0;
}
