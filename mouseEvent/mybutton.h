#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include<QPushButton>
#include<QMouseEvent>

class myButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myButton(QPushButton *parent = nullptr);

signals:

protected:
    void mousePressEvent(QMouseEvent *event);
private:
    QPushButton *btn;

};

#endif // MYBUTTON_H
