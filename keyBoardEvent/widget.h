#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QKeyEvent>
#include<QEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString getKeyValue(QKeyEvent *event);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QLabel *info;
    QLabel *mouseText;
    QLineEdit *e_mouseText;
    QLabel *mousePos;
    QLineEdit *e_mousePos;
    QLabel *keyDec;
    QLineEdit *e_keyDec;
    QLabel *keyHex;
    QLineEdit *e_keyHex;
    QLabel *keyMean;
    QLineEdit *e_keyMean;
};
#endif // WIDGET_H
