# Qt Widget触发鼠标悬停事件

重写事件过滤器

``` c++
/* 安装事件过滤器 */
ui->btnOtherSend->setAttribute(Qt::WA_Hover,true); // 安装事件过滤器
ui->btnOtherSend->installEventFilter(this);

/* 事件触发 */
bool ModbusMaster::eventFilter(QObject *obj, QEvent *event)
{
  if(event->type() == QEvent::HoverEnter){ // 鼠标悬停进入
    if( obj == ui->btnOtherSend ){
      qDebug()<<event;
      return true;
    }
  }
  return QWidget::eventFilter(obj,event);
}

```