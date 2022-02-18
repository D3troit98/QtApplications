#include "Test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

void Test::timeout()
{
    qInfo() <<QDateTime::currentDateTime().toString() << "on" << QThread::currentThread();
}

void Test::start()
{
    connect(&timer,&QTimer::timeout,this,&Test::timeout);
    timer.setInterval(1000);
    timer.start();
}
