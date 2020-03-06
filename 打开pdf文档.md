# 打开PDF文档

```c++
#include <QDesktopServices>
/* 打开Modbus协议文档 */
void DAC::on_actionModbus_triggered()
{
    QString path = QDir::currentPath();
    path += "/Modbus.pdf"; // 当前路径下的.pdf文档
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}
```

