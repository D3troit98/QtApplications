#include "mainwindow.h"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <QSplashScreen>
#include <QTimer>
#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //set style sheet


    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap((QPixmap("C:\\Users\\Acer\\Desktop\\App\\MimoPro\\resource\\computer-version-banner.jpg"))); //
    splash->show();
    QFile styleSheetFile("C:\\Users\\Acer\\Desktop\\App\\MimoPro\\resource\\DeepBox\\DeepBox.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.setWindowTitle("Mimo Pro");
    QTimer::singleShot(4000,splash,SLOT(close()));//timer
    QTimer::singleShot(4000,&w,SLOT(show()));
    //w.setWindowTitle("Mimo Pro");
    // w.show();
    return a.exec();
}
