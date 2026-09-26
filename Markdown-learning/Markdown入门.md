# Markdown入门
### 一、基本语法
1. **标题**
   #一级标题
   ##二级标题
   ...
   与html一样，最多六级标题
2. **引用**
   > 编辑这类教程文档很好用！
   >> 引用能够进行嵌套，只需要打多一个右尖括号
3. **列表**
   1. 无序列表
   - 列表1
   - 列表2
   - 列表3
   - 减号也可以换成星号或者加号
   2. 有序列表
   数字 + 半角点号. + 空格 + 内容
   注意事项：
   - 数字可以都写1. ，会自动按顺序编号
   - 可以与无序列表混用
   3. 嵌套
   - 可以嵌套，子列表缩进2或4个空格
   4. TodoList
      - [x] 已完成的任务
      - [ ] 未完成的任务 
    - 减号也可以换成星号或者加号
4. **表格**
   | 左对齐 | 居中对齐 | 右对齐 |
   | :- | :-: | -: |
   | a | b | c |
   
   用竖线分隔单元格，在第二行用减号分隔表头和内容
   在分隔行加冒号控制对齐，只有减号默认左对齐
5. **段落**
   - 换行 —— 直接回车
   - 分段 —— 空一行再回车
   - 分割线 —— 三个或以上星号
   ***
   - 字体
     | 字体 | 代码 |
     | :-: | :-: |
     | *斜体* | * * |
     | ==高亮== | == == |
     | **粗体** | ** ** |
     | ***斜粗体*** | *** *** |
     | ~~删除~~ | ~~ ~~ |
     | <u>下划线</u> | ```<u> </u>``` |
   - 脚注
     需要解释的内容[^1]
     在最后面输入`[^1]:`，再输入解释，脚注才有效
6. **代码**
   `print("Hello world!);`
   ```c
   #include <stdio.h>
   int main(){
    printf("Hello world!");
    return 0;
   }
   ```
7. **超链接**
   常见使用方法：
   ```markdown
   1. 最基础形式
   [百度](https://www.baidu.com)
   2. 带提示
   [百度](https://www.baidu.com "百度一下，你就知道")
   3. 参考式(与脚注类似)
   [百度][baidu]

   [baidu]:https://www.baidu.com
   4. 页内跳转
   [跳到标题](#标题)
   ## 标题
   5. 邮箱
   <someone@example.com>
   [发邮件](mailto:someone@example.com)
   ```
   样例：
   1. 最基础形式
   [百度](https://www.baidu.com)
   2. 带提示
   [百度](https://www.baidu.com "百度一下，你就知道")
   3. 参考式(与脚注类似)
   [百度][baidu]

   [baidu]:https://www.baidu.com
   4. 页内跳转
   [跳到标题](#一-基本语法)
   5. 邮箱
   <someone@example.com>
   [发邮件](mailto:someone@example.com)
   6. 自动链接
   - 直接粘贴网址可能并不能被成功识别，可在网址两端加上尖括号
   - 更多使用教程可参考网站：<https:///www.runoob.com/markdown/md-link-html>
8. **图片**
   - 使用图床保存图片并实现插入
   路过图床：<https://imgchr.com>
   把需要的图片上传到图床上，便可直接调用
   - 使用markdown语法插入
   [![pn3Jaiq.png](https://s41.ax1x.com/2026/09/26/pn3Jaiq.png)](https://imgchr.com/i/pn3Jaiq)
   - 使用html语言实现调整图片大小和位置功能
   <a href="https://imgchr.com/i/pn3Jaiq"><div align=center><img src="https://s41.ax1x.com/2026/09/26/pn3Jaiq.png" alt="pn3Jaiq.png" border="0" width="80%" height="60%"/></div></a>
### 二、其它操作
  - **插入latex公式**
    - 行内显示公式：$f(x)=ax+b$
    - 块内显示数学表达式：
    $$
    \begin{Bmatrix}
    a & b \\
    c & d
    \end{Bmatrix}
    $$
  - **html/css语法**
    - 通过Ctrl+Shift+P搜索"Markdown Preview Enhanced:Customize CSS"，在style中使用css语法修改格式 ，这会在工作区根目录创建一个.crossnote文件夹。
    - 修改CSS后，必须保存文件，预览窗口才会更新。
    - 如果CSS没生效，先检查语法是否正确，在通过Ctrl+Shift+P搜索"Markdown Preview Enhanced:Clear Cache"进行清理缓存，然后重新打开预览。
  - **个性化设置**
    - 左上角的"文件"(files)-"首选项"(preferences)-"设置"(settings)
### 三、导出为pdf文档
  - 使用Markdown PDF(不推荐，效果很差)
  - 右键预览窗口，点击在浏览器中打开-右键，打印PDF文档(如果需要高亮，则需要勾选更多选项内的背景图形)，注意关闭更多选项内的"页眉与页脚"选项

[^1]:解释