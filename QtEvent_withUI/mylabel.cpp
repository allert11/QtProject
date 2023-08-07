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
