# my-first-repository

计算机科学与技术专业大一学生的练习仓库，存放 C 语言课程练习、前端入门练习和 Markdown 笔记。

<!-- BEGIN AUTO-STATS:overview -->
仓库统计（自动生成于 2026-10-06）：C 语言练习 74 个 `.c` 文件 · 课程课件 16 份 · C 语言笔记 17 篇 · 前端练习 19 个 HTML · Markdown 笔记 2 份。
<!-- END AUTO-STATS:overview -->

## 目录

| 目录 | 内容 |
| --- | --- |
| `C-Learning/` | 翁恺《C 语言程序设计》入门课的课件、跟课代码、练习与笔记，按课程周次组织 |
| `front-end-practice/` | 暑假跟视频做的前端练习（HTML / CSS / JavaScript） |
| `Markdown-learning/` | Markdown 语法笔记与练习 |
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
| week8 - 数组 | 1 | — | 2 |
| week9 - 指针 | — | — | — |
| week10 - ACLLib的基本图形函数 | — | — | — |
| week10 - 字符串 | — | — | — |
| week11 - 结构类型 | — | — | — |
| week12 - 程序结构 | — | — | — |
| week13 - 文件 | — | — | — |
| week14 - 链表 | — | — | — |
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

## 学习路线

两条线并行：学校课程（见 `school-learning` 仓库）优先，自学与算法竞赛围绕它安排。
当前阶段的目标是 **12 月的 ACM 程序设计新生赛**——暨大 ACM 集训队的入口是：
新生赛 → 寒假训练营 → 次年 5 月校赛 → 组队参加 GDCPC / CCPC / ICPC。

| 优先级 | 内容 | 时间 |
| --- | --- | --- |
| P0 | C 语言语法收尾：翁恺 week8–14（数组、指针、字符串、结构、文件），与学校 C 语言课同步 | 10 月 |
| P0 | 算法基础：模拟与枚举、排序、二分、前缀和、贪心、栈与队列、递归与递推、简单 DP、质数与取模 | 10–12 月 |
| P0 | 刷题：洛谷题单 + 牛客（语法入门 + 往届新生赛真题）+ 每周 1 场 Codeforces Div.4/Div.3 | 10–12 月 |
| P1 | 数据结构入门：链表、栈、队列、堆、并查集、树、图的表示与遍历（跟寒假训练营同步） | 寒假 |
| P2 | 系统学数据结构与算法：CS61B 或 MIT 6.006；离散数学 6.042J（配合学校的线代与高数） | 大一下 |
| P3 | 计算机基础系统课：CSAPP → MIT 6.S081 等，按学期推进 | 大二起 |

每周投入按工作日 1–1.5 小时（1 道题 + 复习）、周末 4–6 小时（整场虚拟赛 + 补题）来排，
学校作业和考试周优先。

资源：

- 算法与数据结构：[CS 自学指南](https://csdiy.wiki/)（数据结构与算法：CS61B、6.006；数学进阶：6.042J）
- 刷题：[洛谷](https://www.luogu.com.cn/)、[牛客竞赛](https://ac.nowcoder.com/)、[Codeforces](https://codeforces.com/contests)
- 题单：《算法竞赛试炼场：洛谷 300 题精析》对应的[洛谷题单](https://www.luogu.com.cn/training/list?type=book.luogujingxi)

新生赛是 5 小时个人赛，近年在 12 月举行，约 12–13 题，在牛客上判题，错误提交罚时 20 分钟；
备赛重点是把前 4–6 道题做得又快又稳，而不是去攻难题。

## 环境与约定

- C 语言：Dev-C++ 6.3（TDM-GCC 9.2）；源码以 UTF-8 保存，编译时加 `-fexec-charset=GBK`，
  以便 Windows 控制台正确显示中文
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
