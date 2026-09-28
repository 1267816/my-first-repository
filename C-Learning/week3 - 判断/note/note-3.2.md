# 第三周：判断

## 3.2 分支

**嵌套的 if**：
- 当 if 的条件满足或者不满足的时候，要执行的语句也可以是一条 if 或 if-else 语句，这就是嵌套的 if 语句
- 例：找三个数中的最大——先比较两个，把较大的和第三个再比较
```c
if ( gameover == 0 )
    if ( player2move == 2 )
        printf("Your turn\n");
    else
        printf("My turn\n");
else
    printf("GAME OVER\n");
```

**else 的匹配**：
- `else` 总是和最近的那个 if 匹配
- 缩进格式**不能**暗示 else 的匹配关系：
```c
if ( code == READY )
    if ( count < 20 )
        printf("一切正常\n");
else
    printf("继续等待\n");     // 这个 else 其实跟的是里面的 if
```
- 想让 else 跟外面的 if 匹配，就要用大括号把里面的 if 括起来：
```c
if ( code == READY ) {
    if ( count < 20 )
        printf("一切正常\n");
} else
    printf("继续等待\n");
```
- tips：在 if 或 else 后面总是用 `{}`，即使只有一条语句的时候

**级联的 if-else if**（分段函数）：
- 分段函数：x < 0 时 f = -1；x = 0 时 f = 0；x > 0 时 f = 2x
```c
if ( x < 0 ) {
    f = -1;
} else if ( x == 0 ) {
    f = 0;
} else {
    f = 2 * x;
}
```
- 一般形式：
```c
if ( exp1 )
    st1;
else if ( exp2 )
    st2;
else
    st3;
```

**单一出口**：
- 同样是分段函数，把结果算出来再统一打印（单一出口）比每个分支里直接 printf 更好：
```c
int f;
if ( x < 0 ) {
    f = -1;
} else if ( x == 0 ) {
    f = 0;
} else {
    f = 2 * x;
}
printf("%d", f);
```

**if 语句常见的错误**：
- **忘了大括号**：只有紧跟着 if 的那一条语句受 if 控制
```c
if ( age > 60 )
    salary = salary * 1.2;
    printf("%f", salary);     // 这条会被无条件执行
```
- **if 后面的分号**：`if ( age > 60 );` 这个分号表示 if 后面跟的是一条空语句，后面的语句块不受控制
- **错误使用 `==` 和 `=`**：if 只要求括号里的值是零或非零，所以 `if ( a = b )` 是赋值，结果非零就成立
- **让人困惑的 else**：匹配到了不该匹配的 if

**代码风格**：
- 在 if 和 else 之后必须加上大括号形成语句块
- 大括号内的语句缩进一个 tab 的位置
- 幻灯片说“风格是三观”，这两条没有例外

**switch-case**：
```c
switch ( type ) {
    case 1:
        printf("你好");
        break;
    case 2:
        printf("早上好");
        break;
    default:
        printf("啊，什么啊？");
}
```
- 控制表达式只能是整数型的结果
- case 后面是常量，可以是常数，也可以是常数计算的表达式
- 根据表达式的结果寻找匹配的 case，执行 case 后面的语句，一直到 break 为止
- 如果所有的 case 都不匹配，就执行 default 后面的语句；如果没有 default，那就什么都不做

**break 的作用**：
- switch 语句可以看作一种基于计算的跳转：计算控制表达式的值后，程序跳转到相匹配的 case（分支标号）处
- 分支标号只是说明 switch 内部位置的路标，执行完分支中的最后一条语句后，如果后面没有 break，就会顺序执行到下面的 case 里去，直到遇到一个 break，或者 switch 结束为止
```c
switch ( type ) {
    case 1:
    case 2:
        printf("你好\n");
        break;
    case 3:
        printf("晚上好\n");
    case 4:
        printf("再见\n");
        break;
}
```

**成绩分级**：
```c
int grade;
scanf("%d", &grade);
grade /= 10;
switch ( grade ) {
    case 10:
    case 9:
        printf("A\n");
        break;
    case 8:
        printf("B\n");
        break;
    case 7:
        printf("C\n");
        break;
    case 6:
        printf("D\n");
        break;
    default:
        printf("F\n");
        break;
}
```
- 多个 case 可以共用一段代码（10 和 9 都输出 A）
- 这段代码不满足“单一出口”的原则，因为还没学过字符或字符串数据的处理
- 类似的例子还有根据月份输出英文月份名，幻灯片说今后可以用数组来做

**思考**：
- 幻灯片最后问：分段函数能不能用 switch-case 写？——不能直接照搬，因为 case 后面必须是可以枚举的常量，而这里的条件是 x 与 0 的大小关系
