# week14 video

| 文件 | 对应小节 | 说明 |
| --- | --- | --- |
| `14.1.c` | 14.1 可变数组 | 单文件，直接编译运行 |
| （不在这里） | 14.2 链表 | 多文件工程 `node.h` + `main.c`，见下 |

**这里的代码是 AI（DSH）整理的**：`14.1.c` 的五个接口函数取自 `note-14.1`，`main()` 是补的；
`project-test/list/` 里的链表各函数取自 `note-14.2`，文件拆分与 `main()` 流程是串起来的。
两个 `.c` 的开头都标了 `AI 整理（DSH）`，不是翁恺视频里的逐字原文。

## 14.2 链表的代码在哪

Dev-C++ 编译多文件工程时要求工程路径为纯英文，放在 `week14 - 链表/video/` 下编不过，所以按仓库规矩放在：

```text
C-Learning/project-test/list/
├── node.h
├── main.c
├── list.dev          Dev-C++ 工程
└── Makefile.win
```

命令行编译（在该目录下，路径带中文也能编）：

```text
cd C-Learning/project-test/list
gcc main.c -o list.exe -fexec-charset=GBK
./list.exe
```

Dev-C++ 里双击 `list.dev` 打开，按 F11 编译运行。

代码取自 `note-14.2`（14.2.2 ~ 14.2.6：建链表、add 用包装结构体那种写法、搜索、删除、清除）。
有一个课堂还没处理到的细节：这一版 `deleteNode` 只把节点摘下来 `free`，没有同步维护 `List.tail`，
所以删除之后不要再 `add`（会写到已经释放的节点上）。
