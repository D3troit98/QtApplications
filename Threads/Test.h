#ifndef TEST_H
#define TEST_H
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QDateTime>
#include <QTimer>


class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:

public slots:
    void timeout();
    void start();

private:
    QTimer timer;

};

#endif // TEST_H
