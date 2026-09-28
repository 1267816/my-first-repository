# C-Learning

翁恺《C 语言程序设计》入门课的课件、跟课代码、练习与笔记，按课程周次组织。

<!-- BEGIN AUTO-STATS:c-learning -->
| 周次 | 主题 | `.c` 文件 | 课件 | 笔记 |
| --- | --- | --- | --- | --- |
| 第 1 周 | 程序设计与 C 语言 | — | — | — |
| 第 2 周 | 计算 | — | — | — |
| 第 3 周 | 判断 | — | — | — |
| 第 4 周 | 循环 | — | — | — |
| 第 5 周 | 循环控制 | — | — | — |
| 第 6 周 | 数据类型 | — | — | — |
| 第 7 周 | 函数 | — | — | — |
| 第 8 周 | 数组 | — | — | — |
| 第 9 周 | 指针 | — | — | — |
| 第 10 周 | 字符串 | — | — | — |
| 第 11 周 | 结构类型 | — | — | — |
| 第 12 周 | 程序结构 | — | — | — |
| 第 13 周 | 文件 | — | — | — |
| 第 14 周 | 链表 | — | — | — |
<!-- END AUTO-STATS:c-learning -->

## 目录结构

```text
C-Learning/
└── weekN/                 第 N 周
    ├── docs/              课程课件（PDF）
    ├── video/             跟着视频敲的程序
    ├── practice/
    │   ├── answer/        例题解答
    │   └── homework/      课后练习
    ├── module/            自己整理的可复用代码模块
    └── note/              笔记
```

每周的六个子目录都已建好；暂时没有内容的目录里放了 `.gitkeep` 作为占位文件，
这样 git 才会保留空目录（git 本身不跟踪空目录）。

## 命名约定

- 练习文件名对应题目编号：`04-2.c` 是第 4 周第 2 题，`03-1.c` 是第 3 周第 1 题
- 跟课代码沿用视频/MOOC 里的文件名（`hello.c`、`calculate.c`），
  从第 2 周起练习文件开始带周次编号（`answer_02_3.c`、`homework_02_0.c` 等）

## 编译与运行

- Dev-C++ 6.3：打开 `.c` 文件后按 F11 编译运行
- 命令行（gcc 已加入 PATH）：

  ```powershell
  gcc 04-0.c -o 04-0.exe -fexec-charset=GBK
  .\04-0.exe
  ```

源码统一用 UTF-8 保存，`-fexec-charset=GBK` 用于让 Windows 控制台正确显示中文；
在不含中文输出的环境下编译可以省略该参数。

## 鸣谢
- B站浙大翁恺老师的C语言课程
- CSDN平台codestory整理的[翁恺-C语言程序设计习题集-解答汇总](https://blog.csdn.net/fjinhao/article/details/46853171?ops_request_misc=elastic_search_misc&request_id=1130b3535f65a5c4a61ab578c7396ccd&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-46853171-null-null.142^v102^pc_search_result_base2&utm_term=%E7%BF%81%E6%81%BAc%E8%AF%AD%E8%A8%80%E7%BB%83%E4%B9%A0%E9%A2%98&spm=1018.2226.3001.4187)
