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

当鼠标在指定的控件中进行操作时，做出相应的反映

#### 1 不包含ui设计界面

包含头文件QMouseEvent

具体案例：在主窗口中添加一个按钮，当鼠标点击按钮时，打印出具体使用的键（如：左键正在点击按钮），当出了按钮区域，点击主窗口的任意位置，输出x键正在点击主窗口

（1）点击按钮时需要进行事件处理，因此需要创建一个myButton类，在类的头文件中重写mousePressEvent函数，在类的源文件中实现mousePressEvent函数的具体操作

（2）当事件不是分发到按钮上时，需要将事件转发给基类处理，因此mousePressEvent函数的返回值为基类的鼠标点击事件函数，即：QWidget::mousePressEvent(event);

（3）我们需要将按钮控件安装在主窗口中，因此我们在主窗口的类中的头文件里设置一个myButton类型的成员变量，而为了防止外部对其访问，将该变量设置在私有属性下

（4）同时由于要主窗口也要处理鼠标事件，因此也需重写mousePressEvent函数，放在protected权限下；然后再到住窗口类的源文件中去实现它

（5）主窗口源文件的构造函数中需要设置按钮的父对象以及显示的内容

#### 2 包含ui设计界面

（1）写一个自定义的类myLabel，继承于QLabel

（2）在ui界面中新添加一个TextLable控件，点击右键“提升为”，基类选择QLabel，具体类输入myLabel

（3）若想要让控件TextLable拥有边界，则在QFrame中设置为Box

（4）在myLabel类中重写相应的事件即可

### 3.2 键盘事件

包含头文件QKeyEvent

实现案例：获取键盘上的值，并显示在主窗口中的控件QLineEdit中

（1）需要添加QLabel在主窗口中，设置文本为“键盘输入值”，同时添加一个QLineEdit型的文字显示框，用于将键盘上获取的值显示到窗口内，利用move函数将这两个控件的y轴坐标调成一致

（2）重写keyPressEvent(QKeyEvent *event)和keyReleaseEvent(QKeyEvent *event)，

一个是按下的时候即响应，一个是松开按键时响应

（3）添加 “按下ctrl键获取鼠标坐标” 的事件，将其放入到keyPressEvent中实现

（4）对于 键入键盘上其他按键 的事件，都放入到keyReleaseEvent中实现，无特殊含义的值一般保存为ascci码，使用event->key()来获取，该函数返回一个int类型的值，再利用QString函数转化为字符显示到控件中

（5）由于某些含有特殊意义的按键，无法用ascii码表示，因此使用switch语句，将他们转化为和我们键盘上看到的值一样的值

由于利用的key函数获取的键盘值不区分大小写，因此该界面也未实现区分大小的功能，所有键入值都会被当作为大写

实现效果：

<img src="C:\Users\jiafeng\AppData\Roaming\Typora\typora-user-images\image-20230804163044672.png" alt="image-20230804163044672" style="zoom: 50%;" />![image-20230804163455290](C:\Users\jiafeng\AppData\Roaming\Typora\typora-user-images\image-20230804163455290.png)<img src="C:\Users\jiafeng\AppData\Roaming\Typora\typora-user-images\image-20230804163044672.png" alt="image-20230804163044672" style="zoom: 50%;" />![image-20230804163455290](C:\Users\jiafeng\AppData\Roaming\Typora\typora-user-images\image-20230804163455290.png)

### 3.3 定时器

#### 1 利用重写时间函数设置定时器

（1）在类的构造函数中调用startTimer()，启动一个定时器，该定时器的参数1为事件间隔，单位为ms

（2）重写timerEvent函数，在该函数中实现将时间显示到控件的功能

（3）startTimer()的返回值为int值，是一个定时器的唯一标志，可以利用该标识来区分不同的定时器

（4）每一个定时器都需要在timerEvent函数中进行操作，新增定时器，又需要修改该函数

#### 2 利用信号槽设置定时器

（1）加入QTimer头文件，在堆区开辟一个指向QTimer类的指针变量，利用指针调用timer函数，启动定时器，利用指针调用stop函数，暂停计时

（2）使用connect连接定时器和槽函数，可利用lambda表达式，直接在connect中实现槽函数

（3）多个定时器直接使用QTimer创建新对象即可，无需获取timerId

### 3.4 事件分发器

通过重写  bool event(QEvent *e);  函数来实现

如果在该函数中对某一事件进行了拦截，则该函数返回值为true，且该事件不再向下分发；未被拦截的事件交由给父类处理（但不建议使用该函数进行拦截操作）

例如：目前event函数中对**鼠标点击事件**进行拦截，则mousePressEvent函数则不再会起作用（相当于该事件对它进行屏蔽了）

### 3.5事件过滤器

包含头文件QEvent

```c++
bool eventFilter（QObject * watched，QEvent  * event）;
/*
	创建过滤器
	watched：触发事件的目标控件
	event：触发的事件
*/
```

如果想让当前控件处理该事件，则让事件返回true，不再分发到其他控件；如果不想处理该事件，则返回false，分发到基类处理

对象只有安装了过滤器 installEventFilter() ，才能够使用过滤功能

```c++
void installEventFilter(QObject * filterObj);
/*
	filterObj:实现过滤器的部件
	在部件上安装事件过滤器，一般在父控件上实现事件过滤器
	且事件过滤器和安装过滤器的部件必须在同一线程中，否则过滤器将不起作用
*/
```

在程序将事件传送到事件分发器之前操作，如果该控件安装了过滤器，且拦截了**鼠标点击事件**，则不会再将事件分发到事件分发器中；对于其他事件，则交由给父对象处理

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