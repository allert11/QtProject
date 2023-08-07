#include "mylabel.h"
#include<QDebug>

myLabel::myLabel(QWidget *parent)
    : QLabel{parent}
{
    setMouseTracking(true);
}

//// 鼠标进入事件
//void myLabel::enterEvent(QEvent *event){
//    qDebug() << "鼠标进入了";
//}

//// 鼠标离开事件
//void myLabel::leaveEvent(QEvent *event){
//    qDebug() << "鼠标离开了";
//}

// 鼠标按下事件
void myLabel::mousePressEvent(QMouseEvent *ev){
    QString str = QString("鼠标按下，x = %1 y = %2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y())
                      .arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str;
}

// 鼠标释放事件
void myLabel::mouseReleaseEvent(QMouseEvent *ev){
    QString str = QString("鼠标释放，x = %1 y = %2 ").arg(ev->x()).arg(ev->y());
    qDebug() << str;
}

// 鼠标移动事件
void myLabel::mouseMoveEvent(QMouseEvent *ev){
    QString str = QString("鼠标移动");
    qDebug() << str;
}

bool myLabel::event(QEvent *e){
    // 如果是鼠标按下，在event事件分发中做拦截操作
    if(e->type() == QEvent::MouseButtonPress){
        // 目前的e是 QEvent 类的  要转化为 QMouseEvent类型的
        QMouseEvent *me = static_cast<QMouseEvent *>(e);
        QString str = QString("Event函数中，鼠标按下，x = %1 y = %2 globalX = %3 globalY = %4").arg(me->x()).arg(me->y())
                          .arg(me->globalX()).arg(me->globalY());
        qDebug() << str;
        return true;  // true代表用户自己处理这个事件 不向下分发
    }

    // 其他事件交给父类处理 默认处理
    return QLabel::event(e);
}
