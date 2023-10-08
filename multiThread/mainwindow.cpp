#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 创建UI元素
    QPushButton *startButton = new QPushButton("Start Work", this);
    textEdit = new QTextEdit(this);

    // 连接按钮点击事件到槽函数
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startWork);

    // 设置布局
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(startButton);
    layout->addWidget(textEdit);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);

    setCentralWidget(centralWidget);
}


void MainWindow::startWork(){
    textEdit->append("Main Thread: Starting work...");

    // 创建工作线程
    WorkerThread *workerThread = new WorkerThread();
    connect(workerThread, &WorkerThread::finished, this, &MainWindow::workFinished);

    // 启动工作线程
    workerThread->start();
}

void MainWindow::workFinished()
{
    textEdit->append("Main Thread: Work finished!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

