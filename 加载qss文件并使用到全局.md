# 加载QSS文件，并应用到全局

```c++
QFile file(filename);              // QSS文件
if (!file.open(QFile::ReadOnly)){  // 打开文件
    return;
}
QTextStream in(&file);
in.setCodec("UTF-8");
QString qss = in.readAll();        // 读取数据
qApp->setStyleSheet(qss);          // 应用
```