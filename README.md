#QtStudy

## 一、.pro文件详解



## 二、Qt常用窗口

### 2.1 QWidget



### 2.2 QDialog



### 2.3 QMainWindow



## 三、事件模型

事件分为**用户操作**时发出的事件（如：使用鼠标、键盘等）和**Qt系统自身**发出的事件（如：计时器事件）

事件进行的过程：

主程序的exec()执行之后 --> 程序持续监听是否有事件 --> 发生事件，则程序创建事件对象，传递给QObject的event函数 --> event函数 --按对象类型-->分派到指定事件处理函数 

事件处理函数在基类中均为虚函数，需要我们自己再**重写**函数，实现具体的功能

### 3.1 鼠标事件

包含头文件QMouseEvent

具体案例：在主窗口中添加一个按钮，当鼠标点击按钮时，打印出具体使用的键（如：左键正在点击按钮），当出了按钮区域，点击主窗口的任意位置，输出x键正在点击主窗口

（1）点击按钮时需要进行事件处理，因此需要创建一个myButton类，在类的头文件中重写mousePressEvent函数，在类的源文件中实现mousePressEvent函数的具体操作

（2）当事件不是分发到按钮上时，需要将事件转发给基类处理，因此mousePressEvent函数的返回值为基类的鼠标点击事件函数，即：QWidget::mousePressEvent(event);

（3）我们需要将按钮控件安装在主窗口中，因此我们在主窗口的类中的头文件里设置一个myButton类型的成员变量，而为了防止外部对其访问，将该变量设置在私有属性下

（4）同时由于要主窗口也要处理鼠标事件，因此也需重写mousePressEvent函数，放在protected权限下；然后再到住窗口类的源文件中去实现它

（5）主窗口源文件的构造函数中需要设置按钮的父对象以及显示的内容

### 3.2 键盘事件



### 3.3 事件过滤器



## 四、信号与槽

连接信号和槽的函数：

```c++
connect(const QObject *sender, const char *signal, const QObject *receiver, 
        const char *member, Qt::ConnectionType = Qt::AutoConnection);
/*
	sender:信号发送者
	signal：发送的信号
	receiver：信号接收者
	member：接收的槽
*/
```

第五个参数的解析：

Qt::ConnectionType

此枚举描述了可以在信号和插槽之间使用的连接类型。特别地，它确定特定信号是立即传送到槽还是排队等待稍后传送。

（1）Qt::AutoConnection

**自动连接**：（默认值）如果信号在接收者所依附的线程内发射，则等同于直接连接。如果发射信号的线程和接受者所依附的线程不同，则等同于队列连接

（2）Qt::DirectConnection

**直接连接**：当信号发射时，槽函数将直接被调用。无论槽函数所属对象在哪个线程，槽函数都在发射信号的线程内执行。[**这种方式不能跨线程传递消息**]

（3）Qt::QueuedConnection

**队列连接**：当控制权回到接受者所依附线程的事件循环时，槽函数被调用。槽函数在接收者所依附线程执行。[**这种方式既可以在线程内传递消息，也可以跨线程传递消息**]

（4）Qt::BlockingQueuedConnection

与`Qt::QueuedConnection`类似，但是发送消息后会阻塞，直到等到关联的`slot`都被执行。[**说明它是专门用来多线程间传递消息的，而且是阻塞的**]

（5）Qt::UniqueConnection

这是一个可以与上述任何一种连接类型组合的标志，使用按位OR。设置Qt:：UniqueConnection时，如果连接已存在（即，如果同一信号已连接到同一对对象的同一插槽），则QObject:：connect（）将失败。此标志在问题4.6中引入。

## 五、常用布局



## 六、项目框架