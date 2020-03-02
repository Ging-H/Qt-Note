QFile file(filename);
if (!file.open(QFile::ReadOnly))
{
    return;
}

QTextStream in(&file);

in.setCodec("UTF-8");
QString qss = in.readAll();

qApp->setStyleSheet(qss);