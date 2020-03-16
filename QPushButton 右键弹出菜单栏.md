# QPushButton 右键弹出菜单栏

样例主要用于多个按钮右击弹出菜单,然后使用同一个菜单action,所以需要区分按下菜单的按钮.

```c++
{
    QMenu *btnMenu = new QMenu();
    btnMenu->addAction(ui->actionRename); // ui->actionRename 在ui当中已经链接槽函数
    ui->btnSend->setContextMenuPolicy(Qt::CustomContextMenu);
    /* 右击触发请求菜单事件 */
    connect(ui->btnSend, SIGNAL(customContextMenuRequested(const QPoint &)), this,                 SLOT(slots_showBtnRightClickMenu(const QPoint &)));
    
    /* 多个重复的按钮 */
    connect(ui->btnSend_2, SIGNAL(customContextMenuRequested(const QPoint &)), this,               SLOT(slots_showBtnRightClickMenu(const QPoint &)));

}
/* 右击事件 */
void ModbusTool::slots_showBtnRightClickMenu(const QPoint &pos)
{
    /* 记录右击的按钮 */
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    QVariant ptrBtn;
    ptrBtn.setValue(btn);
    ui->actionRename->setData( ptrBtn );
    /* 在鼠标位置弹出菜单 */
    btnMenu->exec( QCursor::pos() );
}
/* 菜单点击事件 */
void ModbusTool::on_actionRename_triggered()
{
    /* 获取点击菜单的按钮指针 */
    QVariant ptrBtn;
    ptrBtn = ui->actionRename->data();
    QPushButton* btn = ptrBtn.value<QPushButton*>();
    btn->setText("重命名");// 修改名字,证明可以回溯点击的按钮
}
```

