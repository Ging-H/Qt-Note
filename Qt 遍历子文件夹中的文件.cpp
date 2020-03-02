
QStringList dir_name_list = QDir(dir_name).entryList(QDir::Dirs);
for each (QString dir in dir_name_list)
{
	content += ReadAllContents(dir_name + dir + "/");
}