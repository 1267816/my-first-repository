# C-Learning

翁恺《C 语言程序设计》入门课的跟课代码与课后练习，按课程周次组织。

最后更新：2026-09-27

## 目录结构

```text
C-Learning/
└── weekn/
    ├── video/              跟着视频敲的程序
    └── practice/
        ├── answer/         PAT习题解答
        └── homework/       PAT习题
    └── module/             整理的可复用代码模块
    └── note/               整理的笔记
```

## 命名约定

- 练习文件名对应题目编号：`04-2.c` 是第 4 周第 2 题，`03-1.c` 是第 3 周第 1 题
- 跟课代码沿用视频/MOOC里的文件名（`hello.c`、`calculate.c`），
  从第 2 周起练习文件开始带上周次编号（`answer_02_3.c`、`homework_02_0.c` 等）

## 进度

| 周次 | 主题 | 跟课代码 | 例题 | 作业 | 状态 |
| --- | --- | --- | --- | --- | --- |
| 第 1 周 | 程序设计与 C 语言 | 2 | — | — | 已完成 |
| 第 2 周 | 计算 | 6 | 2 | 4 | 已完成 |
| 第 3 周 | 判断 | 8 | 4 | 4 | 已完成 |
| 第 4 周 | 循环 | 8 | 0 | 4 | 作业已完成，习题解析未做 |
| 第 5 周 | 循环控制 | 1 | 0 | 0 | 进行中，练习未开始 |

第 4 周的四道作业（`04-0` ~ `04-3`）已在本地用 TDM-GCC 9.2 编译运行，
输出与课程样例一致；`week4/module/用while循环遍历n位正整数.c` 是从第 4 周练习里抽出来的可复用模块。

## 编译与运行

- Dev-C++ 6.3：打开 `.c` 文件后按 F11 编译运行
- 命令行（gcc 已加入 PATH）：

  ```powershell
  gcc 04-0.c -o 04-0.exe -fexec-charset=GBK
  .\04-0.exe
  ```

源码统一用 UTF-8 保存，`-fexec-charset=GBK` 用于让 Windows 控制台正确显示中文；
在不含中文输出的环境下编译可以省略该参数。

## 待补

- 第 4 周的习题解析（`week4/practice/answer/`）
- 第 5 周的例题与作业（`week5/practice/`）、笔记（`week5/note/`）

## 鸣谢
- B站浙大翁恺老师的C语言课程
- CSDN平台codestory整理的[翁恺-C语言程序设计习题集-解答汇总](https://blog.csdn.net/fjinhao/article/details/46853171?ops_request_misc=elastic_search_misc&request_id=1130b3535f65a5c4a61ab578c7396ccd&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-46853171-null-null.142^v102^pc_search_result_base2&utm_term=%E7%BF%81%E6%81%BAc%E8%AF%AD%E8%A8%80%E7%BB%83%E4%B9%A0%E9%A2%98&spm=1018.2226.3001.4187)
