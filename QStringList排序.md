# QStringList自定义排序

```c++
int main()
{
    QStringList fileList;
	qSort(fileList.begin(), fileList.end(), [](const QString &str1, const 			QString &str2){return str1.compare(str2, Qt::CaseInsensitive) < 0; });
	qDebug()<<fileList;
}
```

