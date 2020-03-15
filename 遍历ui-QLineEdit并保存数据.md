# 遍历ui QLineEdit并保存数据



**在关闭时保存数据，并在启动时读取**

```c++
/* 窗口关闭事件，保存数据 */ 
void ModbusTool::closeEvent(QCloseEvent *e)
{
  e = e;
  QSettings settings("ModbusMaster.ini", QSettings::IniFormat);// 设定文件名字
  settings.beginGroup("QLineEdit"); 
  QObjectList objList = ui->groupBox_8->children(); // 获取对象列表
  QLineEdit *txtEdit;
  /* 遍历Widget */
  foreach (QObject *obj, objList) {
    txtEdit = qobject_cast<QLineEdit*>(obj); 
    if(txtEdit){
      if(!txtEdit->text().isEmpty())
        settings.setValue(txtEdit->objectName(), txtEdit->text());// 保存数据
    }
  }
}
/* 启动时读取数据 */ 
void ModbusTool::getInitTxt()
{
  QSettings settings("ModbusMaster.ini", QSettings::IniFormat);
  settings.beginGroup("QLineEdit");
  QLineEdit *txtEdit;
  /* 获取*.ini文件当中的Keys */
  QStringList keyList = settings.childKeys();
  foreach (QString objName, keyList) {
    /* 根据Keys搜索Widget */
    txtEdit = ui->groupBox_8->findChild< QLineEdit * >(objName);
    if(txtEdit){
      txtEdit->setText(settings.value(objName).toString());
    }
  }
}


```



