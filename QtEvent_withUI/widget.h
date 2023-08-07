#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"mylabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 重写定时器事件
    void timerEvent(QTimerEvent *e);

    // 重写事件过滤器
    bool eventFilter(QObject *obj,QEvent *ev);

private:
    Ui::Widget *ui;
    int id1;
    int id2;
    myLabel *mLabel;
};
#endif // WIDGET_H
