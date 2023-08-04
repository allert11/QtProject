#include "widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600,400);

    info = new QLabel("如果鼠标移动到窗外，\n按Ctrl键获取鼠标位置",this);
    info->move(20,50);
    mouseText = new QLabel("键入值",this);
    mouseText->move(20,150);
    e_mouseText = new QLineEdit(this);
    e_mouseText->move(160,150);

    mousePos = new QLabel("鼠标坐标",this);
    mousePos->move(20,200);
    e_mousePos = new QLineEdit(this);
    e_mousePos->move(160,200);

    keyDec = new QLabel("键盘键值(ASCII)",this);
    keyDec->move(20,250);
    e_keyDec = new QLineEdit(this);
    e_keyDec->move(160,250);

    keyHex = new QLabel("键盘键值(Hex)",this);
    keyHex->move(20,300);
    e_keyHex = new QLineEdit(this);
    e_keyHex->move(160,300);

    keyMean = new QLabel("键盘键值",this);
    keyMean->move(20,350);
    e_keyMean = new QLineEdit(this);
    e_keyMean->move(160,350);
}

void Widget::keyPressEvent(QKeyEvent *event){
    qDebug() << "=== press key";
    int keyVal = event->key();
    if(keyVal == Qt::Key_Control){
        // 按下ctrl 获得鼠标的位置
        QPoint pt = QCursor::pos();
        QString str;
        str = QString("%1，%2").arg(pt.x()).arg(pt.y());
        e_mousePos->setText(str);  // 填入鼠标位置信息
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event){
    qDebug()<<"  release key ===";
    QString str_key;
    str_key = getKeyValue(event);
    /*
    自动重复是指按下键盘上的键（修饰键除外）不放时，会不断重复的发送键按下事件，Qt 默认是启用自动重复的。
    若要实现类似按键 A+D 之类的快捷键，就需要关闭自动重复。可使用如下方法来关闭自动重复：
    */
    if(event->isAutoRepeat()) return;
}

// 将Qt::Key_xxx转化为键盘上所能看到的值
QString Widget::getKeyValue(QKeyEvent *event){
    int keyVal; // 数值表示意义
//    QString keyVal_Hex; // 十六进制
    QString keyMean;  // 表示意义

    keyVal = event->key();
//    keyVal_Hex = QString("0x%1").arg(keyVal,2,16,QLatin1Char('0'));
    keyMean = QString(keyVal);

    switch (keyVal)
    {
    case Qt::Key_Escape:
        keyMean = QString("Esc");
        break;
    case Qt::Key_Tab:
        keyMean = QString("Tab");
        break;
    case Qt::Key_CapsLock:
        keyMean = QString("CapsLock");
        break;
    case Qt::Key_Shift:
        keyMean = QString("Shift");
        break;
    case Qt::Key_Control:
        keyMean = QString("Ctrl");
        break;
    case Qt::Key_Alt:
        keyMean = QString("Alt");
        break;
    case Qt::Key_Backspace:
        keyMean = QString("Backspace");
        break;
    case Qt::Key_Meta:
        keyMean = QString("Win");
            break;
    case Qt::Key_Return:
        keyMean = QString("Enter(main)");
        break;
    case Qt::Key_Enter:
        keyMean = QString("Enter(num)");
        break;
    case Qt::Key_Home:
        keyMean = QString("Home");
        break;
    case Qt::Key_End:
        keyMean = QString("End");
        break;
    case Qt::Key_PageUp:
        keyMean = QString("PageUp");
        break;
    case Qt::Key_PageDown:
        keyMean = QString("PageDown");
        break;
    case Qt::Key_Insert:
        keyMean = QString("Insert");
        break;
    case Qt::Key_Up:
        keyMean = QString::fromLocal8Bit("↑");
        break;
    case Qt::Key_Right:
        keyMean = QString::fromLocal8Bit("→");
        break;
    case Qt::Key_Left:
        keyMean = QString::fromLocal8Bit("←");
        break;
    case Qt::Key_Down:
        keyMean = QString::fromLocal8Bit("↓");
        break;
    case Qt::Key_Delete:
        keyMean = QString("Del");
        break;
    case Qt::Key_Space:
        keyMean = QString("Space");
        break;
    case Qt::Key_F1:
        keyMean = QString("F1");
        break;
    case Qt::Key_F2:
        keyMean = QString("F2");
        break;
    case Qt::Key_F3:
        keyMean = QString("F3");
        break;
    case Qt::Key_F4:
        keyMean = QString("F4");
        break;
    case Qt::Key_F5:
        keyMean = QString("F5");
        break;
    case Qt::Key_F6:
        keyMean = QString("F6");
        break;
    case Qt::Key_F7:
        keyMean = QString("F7");
        break;
    case Qt::Key_F8:
        keyMean = QString("F8");
        break;
    case Qt::Key_F9:
        keyMean = QString("F9");
        break;
    case Qt::Key_F10:
        keyMean = QString("F10");
        break;
    case Qt::Key_F11:
        keyMean = QString("F11");
        break;
    case Qt::Key_F12:
        keyMean = QString("F12");
        break;
    case Qt::Key_NumLock:
        keyMean = QString("NumLock");
        break;
    case Qt::Key_ScrollLock:
        keyMean = QString("ScrollLock");
        break;
    case Qt::Key_Pause:
        keyMean = QString("Pause");
        break;
    }
//    e_keyDec->setText(QString("%1").arg(keyVal));  // 展示ascci码值
//    e_keyHex->setText(keyVal_Hex);
    e_keyMean->setText(keyMean);
    return keyMean;
}

Widget::~Widget()
{
}

