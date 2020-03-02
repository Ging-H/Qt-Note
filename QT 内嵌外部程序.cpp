/* nain.cpp*/

QProcess m;
void MainWindow::on_pushButton_clicked()
{
    //��������
    QString cmd = "SerialAssistant.exe";
    m.start(cmd);
    m.waitForFinished(2000);
    QSharedMemory sharedMemory;
    // �������ڴ���ý��̰�
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
        window->setFlags(window->flags() | Qt::CustomizeWindowHint | Qt::WindowTitleHint); //��߿�������һ������
        QWidget * widget = QWidget::createWindowContainer(window, this, Qt::Widget);
        ui->gridLayout->addWidget(widget);

    }
    sharedMemory.detach();
}
/* �ӳ���ʹ�ù����ڴ棬��������ڵĿ��ƾ����main�����ȡ���ƾ������ٴ��ڵ�main���� */
/* process.processId()�������pid�����ǿ��ƴ��ھ��ID�� */
/* sub.cpp*/
void SerialAssistant::outWinId()
{
    // ���������ڴ��
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