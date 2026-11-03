# week13 video

跟课代码，都是单文件，直接编译运行：

| 文件 | 对应小节 |
| --- | --- |
| `13.1.1.c` | 13.1.1 格式化的输入输出：flags / width / precision、星号、`%n`、`%hhd`、`scanf` 的 `*` |
| `13.1.2.c` | 13.1.2 文件：`fopen` / `fclose` / `fprintf` / `fscanf`，写进去再读回来 |
| `13.1.3.c` | 13.1.3 二进制文件：`fwrite` / `fread` 与 nitem、`sprintf` 拼格式串 |
| `13.2.1.c` | 13.2.1 / 13.2.2 按位运算与左移右移 |
| `13.2.3.c` | 13.2.3 输出一个数的二进制 |
| `13.2.4.c` | 13.2.4 位段 |

**这些文件是 AI（DSH）按课件与 `note-13.1` / `note-13.2` 整理的**，不是翁恺视频里的逐字原文
（变量名、注释与演示顺序可能与课堂有出入）。每个 `.c` 开头的第二行也标了这句 `AI 整理（DSH）`，一眼能看出来。
两个课件 PDF 抽不出文字（`Active PDF object offset is outside the object section`），所以没能对着幻灯片逐行核。

编译（中文输出要 `-fexec-charset=GBK`）：

```text
gcc 13.1.2.c -o 13.1.2.exe -fexec-charset=GBK
```

`13.1.2.c` 会在当前目录写出 `test.txt`，`13.1.3.c` 会写出 `stu.dat`；这两个数据文件也算这一节的跟课内容，跟着一起提交。

编 `13.1.1.c` 时会有一条 `warning: unknown conversion type character 'h' in format`，
指的就是 `%hhd` 那一行（MSVCRT 不支持 `hh`）：紧跟着的 `(char)300` 那行才是能看出截断效果的写法。
