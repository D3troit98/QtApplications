#ifndef TEST2_H
#define TEST2_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Test2 : public QThread
{
    Q_OBJECT
public:
    explicit Test2(QObject *parent = nullptr);

signals:

public slots:
    void quit();

protected:
    void run();

private:
    bool ok;

};

#endif // TEST2_H
