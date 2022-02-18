#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void qmovie();
    void secondMovie();

protected:
    void mousePressEvent(QMouseEvent *evt)
    {
        oldPos = evt->globalPos();
    }

    void mouseMoveEvent(QMouseEvent *evt)
    {
        const QPoint delta = evt->globalPos() -oldPos;
        move(x()+delta.x(),y()+delta.y());
        oldPos = evt->globalPos();
    }

private:
    QPoint oldPos;
public slots:
    void cosmere();
private slots:

    void on_settingBtn_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
};
#endif // MAINWINDOW_H
