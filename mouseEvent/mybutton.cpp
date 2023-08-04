#include "mybutton.h"
#include<QDebug>

myButton::myButton(QPushButton *parent)
    : QPushButton{parent}
{

}

void myButton::mousePressEvent(QMouseEvent *event){
    // 如果是鼠标左键点击该控件 则拦截这个事件
    if(event->button() == Qt::LeftButton){
        qDebug()<<"鼠标左键点击mybutton";
    }
    else if(event->button() == Qt::RightButton){
        qDebug()<<"鼠标右键点击mybutton";
    }
    else if(event->button() == Qt::MiddleButton){
        qDebug()<<"鼠标中键点击mybutton";
    }
    // 如果不是点击该控件，则将该事件分发给基类
    else return QWidget::mousePressEvent(event);
}
