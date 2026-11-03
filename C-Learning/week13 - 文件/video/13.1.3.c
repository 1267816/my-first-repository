// 13.1.3 二进制文件：fwrite / fread 与 nitem
// AI 整理（DSH）：按课件与 note-13.1 整理，不是翁恺视频里的逐字原文，变量名与注释可能与课堂不同。
#include <stdio.h>

#define STRLEN 20

/* int(4) + char[20] + int(4) = 28 字节，正好和课件里“一个学生 28 字节、
   两个学生 56 字节”对得上；换成别的字段组合就不是这个数了 */
struct student {
    int id;
    char name[STRLEN];
    int score;
};

int main(void)
{
    struct student a_stu[2] = {
        {1, "Zhao", 90},
        {2, "Qian", 85},
    };
    struct student b_stu;
    int number = 2;
    FILE *fp;
    char format[10];

    /* 动态拼格式串的小技巧：%% 输出一个百分号，%d 把 19 填进去，再补个 s，
       做出来就是 "%19s"。写死成 scanf("%19s") 也可以，这里只是演示能拼。 */
    sprintf(format, "%%%ds", STRLEN - 1);
    printf("拼出来的格式串：%s\n", format);

    printf("一个学生 %d 字节，两个学生 %d 字节\n",
           (int)sizeof(struct student), (int)sizeof(a_stu));

    /* "wb" / "rb" 是二进制模式（Windows 上不加 b，换行会被改写，读写就不对称了）。
       nitem 用来说明这次读写几个“结构体单位”：这里写 2，所以返回值的正常值是 2，不是 56。
       返回值和 number 比，不相等说明没写完，按失败处理。 */
    fp = fopen("stu.dat", "wb");
    if (fp) {
        if (fwrite(a_stu, sizeof(struct student), number, fp) != number) {
            printf("写入失败\n");
        }
        fclose(fp);
    }

    /* 读的时候 nitem 一般写 1：一次读一个结构体，读到文件尾 fread 返回 0，循环自然结束 */
    fp = fopen("stu.dat", "rb");
    if (fp) {
        while (fread(&b_stu, sizeof(struct student), 1, fp) == 1) {
            printf("%d %s %d\n", b_stu.id, b_stu.name, b_stu.score);
        }
        fclose(fp);
    }

    return 0;
}
