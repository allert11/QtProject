#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"mybutton.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    myButton mbtn;
};
#endif // WIDGET_H
