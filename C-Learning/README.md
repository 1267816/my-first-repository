# C-Learning

翁恺《C 语言程序设计》**入门（`week1`–`week8`）与进阶（`week9`–`week14`）**两门课的课件、跟课代码、
练习与笔记，按课程周次组织。两门课合起来 14 周，2026-09-28 开课、2026-11-03 全部跟完。

<!-- BEGIN AUTO-STATS:c-learning -->
| 周目录 | `.c` 文件 | 课件 | 笔记 |
| --- | --- | --- | --- |
| week1 - 程序设计与C语言 | 2 | 3 | 3 |
| week2 - 计算 | 12 | 2 | 2 |
| week3 - 判断 | 16 | 2 | 2 |
| week4 - 循环 | 15 | 2 | 2 |
| week5 - 循环控制 | 15 | 3 | 2 |
| week6 - 数据类型 | 6 | 2 | 2 |
| week7 - 函数 | 7 | 2 | 2 |
| week8 - 数组 | 6 | 2 | 2 |
| week9 - 指针 | 14 | 2 | 3 |
| week10 - 字符串 | 7 | 2 | 2 |
| week11 - 结构类型 | 4 | 3 | 3 |
| week12 - 程序结构 | 3 | 3 | 3 |
| week13 - 文件 | 6 | 2 | 2 |
| week14 - 链表 | 1 | — | 2 |
| project-test | 3 | — | — |
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

week1–week11 的六个子目录都已建好；暂时没有内容的目录里放了 `.gitkeep` 作为占位文件，
这样 git 才会保留空目录（git 本身不跟踪空目录）。

**week12–week14 没有 `practice/`**：课后作业题只到第 11 周——`practice/homework/11-0.c`（平面向量加法，
要拦住 `-0.0`）与 `11-1.c`（通讯录的录入与显示），两道都跑过题面样例；第 12–14 周没有配套作业题，
也不再补。`week11` 的 `practice/answer/` 仍然是空的，那周的例题没有做。

**`week14 - 链表` 连 `docs/` 也没有**：进阶课链表那一节没找到课件，只留了 `video/`、`module/`、`note/`。

第 13、14 周的跟课代码 2026-11-03 补齐了：`week13/video/` 是 6 个单文件程序（13.1.1、13.1.2、13.1.3、
13.2.1、13.2.3、13.2.4），`week14/video/` 是 `14.1.c`（可变数组）；14.2 链表是多文件工程
（`node.h` + `main.c`），按仓库规矩放在 `project-test/list/`，`week14/video/README.md` 里写了去哪找。
第 13 周的 6 个程序、第 14 周的 `14.1.c` 与 `project-test/list/` 都是 **AI（DSH）按课件与笔记整理的**
（不是视频里的逐字原文），每个 `.c` 开头的第二行和各自的 `README.md` 都标了这点。

`week10 - ACLLib的基本图形函数` 这个占位目录已于 2026-11-03 删除（它一直只有 `.gitkeep`），
理由见仓库根目录 README 的「关于删掉的 `week10 - ACLLib的基本图形函数`」一节。

## project-test

多文件工程放这里，例如 `max/`（Dev-C++ 工程，`main.c` + `max.c`）。

放在这里的唯一原因是路径：Dev-C++ 编译多文件工程时要求工程路径为纯英文，
同样的工程放在 `week12 - 程序结构/video/` 下会编译失败，搬到 `C-Learning/project-test/max/` 就正常。
以后新建多文件工程一律放这个目录，跟课的单文件程序仍放各周 `video/`。

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
