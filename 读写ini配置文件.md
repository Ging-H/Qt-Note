# 读写ini配置文件

```c++
/* 保存为.ini文件 */
void DAC::saveStyle(QString styleName)
{
    /*  文件名字 Style.ini */
    QSettings settings("Style.ini", QSettings::IniFormat);
    settings.beginGroup("Skins"); // 组
    settings.setValue("Style", styleName);// 值
    settings.endGroup();
}
/* 加载.ini文件 */
QString DAC::loadStyle()
{
    QSettings settings("Style.ini", QSettings::IniFormat);
    settings.beginGroup("Skins");
    QString styleName = settings.value("Style").toString();
    return styleName;
}

```
