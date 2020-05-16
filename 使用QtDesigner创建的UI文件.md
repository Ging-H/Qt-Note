# 使用QtDesigner创建的UI文件

方法一：

使用Qt Designer创建新的ui文件并添加到工程里面：

```c++
void PIDCurve::on_btnProtocol_clicked()
{
    QDialog *dialog = new QDialog();
    Ui::Dialog ui; // 创建的ui是QDialog类，默认名字就是Dialog，这里应该是Ui::xxx
    ui.setupUi(dialog);

    dialog->setAttribute(Qt::WA_DeleteOnClose); // 关闭的时候delete
    dialog->setWindowTitle("通信协议");
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch );// 自适应列宽
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents );// 适应单元格内容
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents );// 适应单元格内容
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(4,QHeaderView::ResizeToContents );// 适应单元格内容
    dialog->show();
}

```

使用这种方法可以直接调用新创建的ui

方法二：

在Qt Creator当中新建xx.ui文件，附带有xx.cpp，xx.h文件，可以在.cpp文件处理一些动作。

```c++
void DAC::on_actionRegList_triggered()
{
    pDialog = new protocolDialog(); // 新建的xx.ui/xx.cpp/xx.h
    pDialog->setAttribute(Qt::WA_DeleteOnClose); // 关闭的时候delete
    pDialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint);// 自定义标题的按钮
    pDialog->setWindowTitle("DAC模块寄存器列表");
    pDialog->show();
}
```