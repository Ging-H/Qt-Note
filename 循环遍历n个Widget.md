# 循环遍历n个Widget

```c++
/* 创建一个Vector，然后推入Widget */
QVector < QPushButton *> multiPushButton;
multiPushButton.push_back(ui->btnMultiPush01);
multiPushButton.push_back(ui->btnMultiPush02);
multiPushButton.push_back(ui->btnMultiPush03);
multiPushButton.push_back(ui->btnMultiPush04);

/* 遍历Widget */
foreach (QPushButton *btnPush, multiPushButton) { // 链接点击信号到一个函数
  connect(btnPush,SIGNAL(clicked(bool)),this,SLOT(slots_multiSend()));
}
```

