/* 读取配置信息函数：*/
ParameterInit()
{
    /* 设置文件名字 */
    QSettings settings("ICConfig.ini", QSettings::IniFormat);
    IPaddrLineEdit->setText(settings.value("IP").toString());
    portLineEdit->setText(settings.value("port").toString());
}

/* 修改配置信息函数：*/
ParameterSave(QString Type, QString p)
{
    /*  读取文件名字 */
    QSettings settings("ICConfig.ini", QSettings::IniFormat);
    settings.setValue(Type,p);
}
