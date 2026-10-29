# my-first-repository

计算机科学与技术专业大一学生的练习仓库，存放 C 语言课程练习、前端入门练习和 Markdown 笔记。

<!-- BEGIN AUTO-STATS:overview -->
仓库统计（自动生成于 2026-10-29）：C 语言练习 107 个 `.c` 文件 · 课程课件 25 份 · C 语言笔记 28 篇 · 前端练习 19 个 HTML · Markdown 笔记 2 份。
<!-- END AUTO-STATS:overview -->

## 目录

| 目录 | 内容 |
| --- | --- |
| `C-Learning/` | 翁恺《C 语言程序设计》入门课的课件、跟课代码、练习与笔记，按课程周次组织 |
| `front-end-practice/` | 暑假跟视频做的前端练习（HTML / CSS / JavaScript） |
| `Markdown-learning/` | Markdown 语法笔记与练习 |
| `Lyra-learning/` | UE5 Lyra 源码阅读与实操笔记：环境搭建、第1～3章的实验记录 |
| `ACM-ICPC/` | ACM / ICPC 竞赛的选拔信息与备赛计划 |
| `ai-workspace/` | AI 协作用的工作目录，以及维护本仓库文档的脚本 |

下面按目录列出概况，各目录的详细说明见该目录下的 `README.md`。

## C-Learning

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
| week10 - ACLLib的基本图形函数 | — | — | — |
| week10 - 字符串 | 7 | 2 | 2 |
| week11 - 结构类型 | 2 | 3 | 3 |
| week12 - 程序结构 | 3 | — | 3 |
| week13 - 文件 | — | — | — |
| week14 - 链表 | — | — | — |
| project-test | 2 | — | — |
<!-- END AUTO-STATS:c-learning -->

每周的目录结构一致，含义固定：

- `weekN/docs/`：课程课件
- `weekN/video/`：跟着视频敲的程序
- `weekN/practice/answer/`：例题解答
- `weekN/practice/homework/`：课后练习
- `weekN/module/`：自己整理的可复用代码模块
- `weekN/note/`：笔记

练习文件名对应题目编号，例如 `04-2.c` 是第 4 周第 2 题。
编译方式与命名约定见 [`C-Learning/README.md`](C-Learning/README.md)。

## front-end-practice

<!-- BEGIN AUTO-STATS:front-end -->
当前共 19 个 HTML 练习文件。编号 1–18 按学习顺序排列（`1.常见文本标签.html` … `18.flex弹性布局.html`）。另有 `html文件结构.html`。
配套文件：`css/` 下 1 个样式表，`js/` 下 2 个脚本。
<!-- END AUTO-STATS:front-end -->

用浏览器直接打开任意 `.html` 文件即可，不需要构建步骤；文件名开头的数字是学习顺序，
点号后面的部分是这一节的主题。详细说明见
[`front-end-practice/README.md`](front-end-practice/README.md)。

## Markdown-learning

<!-- BEGIN AUTO-STATS:markdown -->
笔记文件：`Markdown入门.md`、`photo_format.md`。配图：`photo_format.png`。
<!-- END AUTO-STATS:markdown -->

`Markdown入门.md` 是语法笔记兼练习，`photo_format.md` 记录图片语法。详细说明见
[`Markdown-learning/README.md`](Markdown-learning/README.md)。

## Lyra-learning

一边读 UE5 Lyra 的教程（教程放在本地 `D:\gamedev-club`，不在本仓库），一边动手做实验，
把结论和验证过程记在这里。目前五篇：

| 文件 | 内容 |
| --- | --- |
| `00.md` | 开发环境搭建：MinGW-w64、Visual Studio 2026、UE 缓存与虚拟内存、生成并编译 LyraStarterGame（429 个编译任务）、第 0 章两个实验的验证结果 |
| `01.md` | 第 1 章 对象世界与反射：宏、蓝图与资产的对应关系 |
| `02.md` | 第 2 章 GameMode 的存在端验证（纯蓝图） |
| `03.md` | 第 3 章 网络入门：服务器权威、属性复制、NetMode |
| `04.md` | 第 4 章 数据与资产：第一个实操是看引用链（Reference Viewer） |

笔记只写结论与验证过程，不复制教程正文。引擎与工程都不在仓库里：引擎在 `D:\UE_5.8`，
Lyra 工程在 `D:\LyraStarterGame`，派生数据缓存重定向到 `D:\UnrealEngineCache`。

## 竞赛与学习路线

竞赛相关的内容集中在 [`ACM-ICPC/`](ACM-ICPC/README.md)：选拔流程与难度估算、九周备赛计划、
每日训练模板、易错清单、平台清单都在那里（`ACM-ICPC/10.5.md` 是原始建议记录）。
分阶段打勾清单见 [`ACM-ICPC/pre-competition-checklist.md`](ACM-ICPC/pre-competition-checklist.md)。

一句话版：为 **12 月的 ACM 程序设计新生赛**（个人赛、5 小时、约 12–13 题、牛客判题、罚时 20 分钟）
备赛。赛前只做三件事——C 语言语法收尾（翁恺 week8–14）、基础算法（模拟、枚举、排序、前缀和、
二分、双指针、贪心、基础数学）、刷题（洛谷题单 + 牛客往届真题 + 每周 1 场 Codeforces）。
寒假之后进入数据结构与系统课，学校课程与考试周优先。

## 环境与约定

- C 语言：Dev-C++ 6.3（TDM-GCC 9.2）；源码以 UTF-8 保存，编译时加 `-fexec-charset=GBK`，
  以便 Windows 控制台正确显示中文
- C++ 与 UE：MinGW-w64（GCC 16.2，`C:\mingw64`）写日常 C/C++；Visual Studio 2026 用来编译 UE；
  引擎装在 `D:\UE_5.8`，Lyra 工程在 `D:\LyraStarterGame`
- 编辑器：VS Code（仓库自带 `my-first-repository.code-workspace`）；版本管理：Git + GitHub Desktop
- `.gitignore` 排除 `.exe`、`.o`、`.obj`、`.out` 等编译产物；课程课件与笔记的 PDF 保留在仓库里
- 空目录中的 `.gitkeep` 是占位文件，用来让 git 保留该目录

## 说明

- 仓库中不含编译产物，克隆后需要自行编译 `.c` 文件
- 上面的统计区块由 [`ai-workspace/update_repo_stats.py`](ai-workspace/update_repo_stats.py)
  自动生成，不需要手动维护；提交前勾子会自动更新它们

## 联系

- GitHub：[@1267816](https://github.com/1267816)
- Email: 2587872607@qq.com
