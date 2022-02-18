#include "Test2.h"

Test2::Test2(QObject *parent) : QThread(parent)
{

}


void Test2::quit()
{
    ok = false;
    QThread::quit();
}

void Test2::run()
{
    ok =true;
    for(int i = 0; i < 1000; i++)
    {
        qInfo() << i;
        this->sleep(1);
        //this is bad cause the code is unpredictable
        //control can come from anywhere

        if(!ok) break;
    }
    qInfo()<< "Finished";
}
