#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QDateTime>
#include <QTimer>
#include <QSharedPointer>
#include "Test.h"
#include "Test2.h"
#include "Manager.h"
#include "Counter.h"

static QSharedPointer<QThread> sptr;
void timeout()
{
    if(!sptr.isNull())
    {
        qInfo() <<" Time out - stopping other thread from" << QThread::currentThread();
        sptr.data()->quit();
    }
}
static QSharedPointer<Test2>shptr;
void timeout2()
{
    if(!shptr.isNull())
    {
        qInfo() <<" Time out stopping thread" << QThread::currentThread();
        shptr.data()->quit();
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Test2 thread2;
    shptr.reset(&thread2);
    thread2.start();

    QTimer timer2;
    timer2.singleShot(5000,&timeout2);

///////////////////////////////////////////////
    qInfo() << "App Thread: " << a.thread();
    qInfo() << "Current Thread: " <<QThread::currentThread();

    Q_ASSERT(a.thread() == QThread::currentThread());

    qInfo() << "Running" << QThread::currentThread()->isRunning();
    qInfo() << "loop level" << QThread::currentThread()->loopLevel();
    qInfo() << "Stack size" << QThread::currentThread()->stackSize();
    qInfo() << "Finished" << QThread::currentThread()->isFinished();
    //    qInfo() << "Before" << QDateTime::currentDateTime().toString();
    //    QThread::sleep(5);
    //    qInfo() << "After" << QDateTime::currentDateTime().toString();

    qInfo() << "Current Thread: " <<QThread::currentThread();

    Test t;
    qInfo() << "Timer Thread: " << t.thread();

    QThread thread;
    sptr.reset(&thread);
    t.moveToThread(&thread);
    qInfo() << "Timer Thread: " << t.thread();

    t.start();

    qInfo() << "Thread state: "<< thread.isRunning();
    thread.start();

    QTimer timer;
    timer.singleShot(5000,&timeout);
    //////////////////////////
    QThread::currentThread()->setObjectName("Main");
    Manager m;
    m.start();

    return a.exec();
}
