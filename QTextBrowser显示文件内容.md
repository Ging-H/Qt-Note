# Qt QTextBrowser显示文件内容

以文本流的形式读取文件内容,然后再显示.

```C++
QFile file("file.html");
if(!file.open(QFile::ReadOnly | QFile::Text))
  qDebug() << "Can not open";
QTextStream in(&file);
licenceTextBrowser->setHtml(in.readAll()); 
```




