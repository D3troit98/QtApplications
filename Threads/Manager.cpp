#include "Manager.h"

Manager::Manager(QObject *parent) : QObject(parent)
{
    for(int i = 0;i <5;i++)
    {
        QThread* thread = new QThread(this);
        thread->setObjectName("Thread" + QString::number(i));
        qInfo() <<"Created " << thread->objectName();

        connect(thread,&QThread::started,this,&Manager::started);
        connect(thread,&QThread::finished,this,&Manager::finished);

        threads.append(thread);
        qInfo() << threads;
    }
}

void Manager::start()
{
    qInfo() << "Starting....";
    qInfo() << "Starting....";
    foreach(QThread* thread, threads)
    {
        qInfo() << "Starting....";
        qInfo() << "Starting: " << thread->objectName();
        Counter* c = new Counter(); //No parents;
        c->moveToThread(thread);

        connect(thread,&QThread::started,c,&Counter::start);
        thread->start();
    }
}

void Manager::started()
{
    QThread* thread = qobject_cast<QThread*>(sender());
    if(!thread)return;
    qInfo() <<"Started: "  << thread->objectName();
}

void Manager::finished()
{
    QThread* thread = qobject_cast<QThread*>(sender());
    if(!thread)return;
    qInfo() <<"Finished: "  << thread->objectName();

}
