# C-Learning

翁恺《C 语言程序设计》入门课的课件、跟课代码、练习与笔记，按课程周次组织。

<!-- BEGIN AUTO-STATS:c-learning -->
| 周目录 | `.c` 文件 | 课件 | 笔记 |
| --- | --- | --- | --- |
| week1 - 程序设计与C语言 | 2 | 3 | 3 |
| week2 - 计算 | 12 | 2 | 2 |
| week3 - 判断 | 16 | 2 | 2 |
| week4 - 循环 | 13 | 2 | 2 |
| week5 - 循环控制 | 9 | 1 | 2 |
| week6 - 数据类型 | — | — | — |
| week7 - 函数 | — | — | — |
| week8 - 数组 | — | — | — |
| week9 - 指针 | — | — | — |
| week10 - ACLLib的基本图形函数 | — | — | — |
| week10 - 字符串 | — | — | — |
| week11 - 结构类型 | — | — | — |
| week12 - 程序结构 | — | — | — |
| week13 - 文件 | — | — | — |
| week14 - 链表 | — | — | — |
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
