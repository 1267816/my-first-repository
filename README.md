# my-first-repository

计算机科学与技术专业大一学生的练习仓库，存放 C 语言课程练习、前端入门练习和 Markdown 笔记。

最后更新：2026-09-26

## 目录

| 目录 | 内容 | 当前规模 |
| --- | --- | --- |
| `C-Learning/` | 翁恺《C 语言程序设计》入门课的跟课代码与练习，按课程周次组织 | 44 个 `.c` 文件 |
| `front-end-practice/` | 暑假跟视频做的前端练习（HTML / CSS / JavaScript） | 19 个 HTML、2 个 JS、1 个 CSS |
| `Markdown-learning/` | Markdown 语法笔记与练习 | 2 份笔记、1 张配图 |
| `ai-workspace/` | 与 AI 助手交接学习进度用的说明文档 | 1 个 `.md` |

## 学习进度

### C 语言（翁恺《C 语言程序设计》入门课）

| 周次 | 主题 | 跟课代码 | 例题 | 作业 | 状态 |
| --- | --- | --- | --- | --- | --- |
| 第 1 周 | 程序设计与 C 语言 | 2 | — | — | 已完成 |
| 第 2 周 | 计算 | 6 | 2 | 4 | 已完成 |
| 第 3 周 | 判断 | 8 | 4 | 4 | 已完成 |
| 第 4 周 | 循环 | 8 | 0 | 4 | 作业已完成，习题解析未做 |
| 第 5 周 | 循环控制 | 1 | 0 | 0 | 进行中 |

### 前端

`front-end-practice/` 是 19 个 HTML 练习文件，按学习顺序编号，内容覆盖 HTML 标签与表单、
CSS 选择器与盒模型、浮动与定位、flex 布局、移动端 rem 适配，以及 JavaScript 基础语法、
函数、事件和 DOM 操作。

### Markdown

`Markdown-learning/` 存放语法笔记与练习：`Markdown入门.md` 涵盖标题、引用、列表、表格、
段落与字体、代码、超链接、图片八个部分，`photo_format.md` 是图片语法的单独练习。

## 目录约定

`C-Learning/` 按课程周次划分，每周的目录含义固定：

- `weekN/video/`：跟着视频敲的程序
- `weekN/practice/answer/`：视频里的例题
- `weekN/practice/homework/`：课后作业
- `weekN/module/`、`weekN/note/`：自己整理的代码模块和笔记

练习文件名对应题目编号，例如 `04-2.c` 是第 4 周第 2 题。各子目录的内容说明见该目录下的
`README.md`。

## 环境与约定

- C 语言：Dev-C++ 6.3（TDM-GCC 9.2）；源码以 UTF-8 保存，编译时加 `-fexec-charset=GBK`
  以便 Windows 控制台正确显示中文
- 编辑器：VS Code；版本管理：Git + GitHub Desktop
- `.gitignore` 已排除 `.exe`、`.o` 等编译产物和导出的 PDF

## 说明

仓库中不包含编译产物，克隆后需要自行编译 `.c` 文件。

## 联系

- GitHub：[@1267816](https://github.com/1267816)
