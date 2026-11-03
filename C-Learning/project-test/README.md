==注意：路径一定要是纯英文！！！==
在week12 - 程序结构的video文件夹下，max项目编译失败了；但是换到C-Learning/project-test/max下，就成功了。

现在有两个工程：

- `max/`：第 12 周讲的多文件大程序（`main.c` + `max.c`）
- `list/`：第 14 周 14.2 的链表（`main.c` + `node.h`）。它在课堂上本来属于 `week14 - 链表/video/`，
  因为同样的路径问题搬到这里，`week14/video/README.md` 里留了指引

命令行编译（本机任何路径下都能编，中文路径也没问题）：

```text
gcc main.c -o <工程名>.exe -fexec-charset=GBK
```

Dev-C++ 里双击对应的 `*.dev` 打开，按 F11 编译运行。

`*.o`、`*.exe` 是编译产物，被 `.gitignore` 排除，不进仓库。
