# QTextEdit设置某一行字体颜色

``` c++
	/*-------- 设置文本颜色 ----------*/
QTextCursor cursor = ui->txtMessage->textCursor();   // 获取当前文本的游标
cursor.select(QTextCursor::LineUnderCursor);       // 选中游标所在行
QTextCharFormat charFormat;                  // 文本格式
charFormat.setForeground(QColor(rgb(255, 128, 128))); // 前景色，即字体颜色为红色
cursor.mergeCharFormat(charFormat);             // 设置文本格式
cursor.clearSelection();															// 取消选择
cursor.movePosition(QTextCursor::EndOfLine);       // 移动游标到末尾
```



## 改变文本颜色

```c++
ui->txtMessage->setTextColor(QColor(255, 128, 128)); // 改变后续文本的颜色
```

