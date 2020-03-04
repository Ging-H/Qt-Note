# 将QLingEdit设定为只能输入十六进制的字符

使用正则表达式限制输入:

```C++
QRegExp regExp("[a-fA-F0-9 ]*");  // 匹配十六进制字符和空格
QRegExpValidator *reg = new QRegExpValidator (regExp,this); 
txtLine->setValidator(reg);      // 设定正则表达式
```

