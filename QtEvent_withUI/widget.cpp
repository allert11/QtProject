#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
#include<QPushButton>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动定时器
    id1 = startTimer(1000);  // 参数1：间隔 单位ms

    id2 = startTimer(2000);

    // 定时器第二种方式
    QTimer *timer = new QTimer(this);
    // 启动定时器
    timer->start(500);
    connect(timer,&QTimer::timeout,[=]{
        static int num3 = 1;
        ui->label_4->setText(QString::number(num3++));
    });
    // 点击暂停按钮，实现定时器暂停功能
    connect(ui->btn,&QPushButton::clicked,[=]{
        timer->stop();
    });

    // 安装事件过滤器
    ui->label->installEventFilter(this);
}

// 重写事件过滤器
bool Widget::eventFilter(QObject *obj,QEvent *ev){
    if(obj == ui->label){
    if(ev->type() == QEvent::MouseButtonPress){
        // 目前的e是 QEvent 类的  要转化为 QMouseEvent类型的
        QMouseEvent *me = static_cast<QMouseEvent *>(ev);
        QString str = QString("事件过滤器中，鼠标按下，x = %1 y = %2 globalX = %3 globalY = %4").arg(me->x()).arg(me->y())
                          .arg(me->globalX()).arg(me->globalY());
        qDebug() << str;
        return true;  // true代表用户自己处理这个事件 不向下分发
        }
    }
    return QWidget::eventFilter(obj,ev);
}

void Widget::timerEvent(QTimerEvent *e){
    if(e->timerId() == id1){
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    }

    if(e->timerId() == id2){
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }

}

Widget::~Widget()
{
    delete ui;
}

