# 读写ini配置文件

```c++
#include <QSettings>
/* 读取配置信息函数：*/
ParameterInit()
{
    /*  读取文件名字 */
    QSettings settings("Style.ini", QSettings::IniFormat);
    settings.beginGroup("Skins");
    settings.setValue("Style", styleName);
    settings.endGroup();
}

/* 修改配置信息函数：*/
ParameterSave(QString Type, QString p)
{
    QSettings settings("Style.ini", QSettings::IniFormat);
    settings.beginGroup("Skins");
    QString styleName = settings.value("Style").toString();
    return styleName;
}

```
