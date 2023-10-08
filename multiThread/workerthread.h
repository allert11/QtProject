#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QObject>
#include<QDebug>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = nullptr);
    void run() override
    {
        // 在这里执行后台工作，例如模拟耗时计算
        for (int i = 0; i < 5; ++i)
        {
            qDebug() << "Worker Thread: Working..." << i;
            sleep(1); // 模拟耗时操作
        }

        emit finished(); // 工作完成后发送信号
    }

signals:
    void finished();

};

#endif // WORKERTHREAD_H
