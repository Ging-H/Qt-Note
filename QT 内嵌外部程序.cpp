/* nain.cpp*/

QProcess m;
void MainWindow::on_pushButton_clicked()
{
    //创建进程
    QString cmd = "SerialAssistant.exe";
    m.start(cmd);
    m.waitForFinished(2000);
    QSharedMemory sharedMemory;
    // 将共享内存与该进程绑定
    sharedMemory.setKey("winID");
    if (!sharedMemory.attach())
    {
        qDebug()<< sharedMemory.error() << "Unable to attach to shared memory segment.";
        return;
    }
    WId wid = *(WId*)sharedMemory.data();
    QWindow * window = QWindow::fromWinId(wid);
    if (window)
    {
        window->setFlags(window->flags() | Qt::CustomizeWindowHint | Qt::WindowTitleHint); //这边可以设置一下属性
        QWidget * widget = QWidget::createWindowContainer(window, this, Qt::Widget);
        ui->gridLayout->addWidget(widget);

    }
    sharedMemory.detach();
}
/* 子程序使用共享内存，输出本窗口的控制句柄，main程序读取控制句柄，骑劫窗口到main窗口 */
/* process.processId()输出的是pid，不是控制窗口句柄ID。 */
/* sub.cpp*/
void SerialAssistant::outWinId()
{
    // 创建共享内存段
    sharedMemory.setKey("winID");
    if (!sharedMemory.create(sizeof(int)))
    {
        qDebug() << sharedMemory.errorString() << "\n Unable to create shared memory segment.";
        return;
    }
    sharedMemory.lock();
    WId *to = (WId*)sharedMemory.data();
    *to = this->winId();
    qDebug()<<this->winId();

    sharedMemory.unlock();
}