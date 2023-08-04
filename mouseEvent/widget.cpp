#include "widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    mbtn.setParent(this);
    mbtn.setText("点击触发鼠标点击事件");

    resize(600,400);
}

void Widget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        qDebug()<<"鼠标左键点击主窗口";
    }
    else if(event->button() == Qt::RightButton){
        qDebug()<<"鼠标右键点击主窗口";
    }
    else{
        qDebug()<<"鼠标中键点击主窗口";
    }
}

Widget::~Widget()
{
}

