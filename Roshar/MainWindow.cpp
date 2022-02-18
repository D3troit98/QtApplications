#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ui_Dialog.h"
#include "GraphicsMovieItem.h"
#include <QIODevice>
#include <QDir>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QTextStream>
#include <QRandomGenerator>
#include <QTimer>
#include <QScreen>
#include <QIcon>
#include <QMovie>
#include <QGraphicsScene>
#include <QGraphicsView>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     setStyleSheet("background:transparent;");
      setAttribute(Qt::WA_TranslucentBackground);
      setWindowFlags(Qt::FramelessWindowHint);

    ui->setupUi(this);
    move(screen()->geometry().center() -frameGeometry().center());
   // move(450,250);
    ui->textEdit->setWindowOpacity(1.0);
    ui->textEdit->setFrameShape(QFrame ::NoFrame);
   // ui->textEdit->setStyleSheet("font:30pt" "Courier");
    ui->textEdit->setFontWeight(50);
    ui->textEdit->setFontPointSize(32);
    ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // ui->textEdit->setFontWeight(30);
    ui->textEdit->setFontFamily("Corbel");
     //ui->textEdit->setFontFamily("Calluna");
    ui->textEdit->setTextColor("White");
   // ui->textEdit->setGeometry(240,340,434,456);
 //  QPixmap pix("C:\\Users\\Acer\\Desktop\\App\\build-Roshar-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\\debug\\image\\1.jpg");
   // ui->label->setStyleSheet("border-image:url(C:\\Users\\Acer\\Desktop\\App\\build-Roshar-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\\debug\\image\\image\\icons8-setting-60 (1).png");

    //ui->label->setPixmap(pix);
 //   QPixmap btn("C:\\Users\\Acer\\Desktop\\App\\build-Roshar-Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\\debug\\image\\image\\icons8-setting-60 (1).png");
 ////   QIcon buttonIcon(btn);
 //   ui->settingBtn->setIcon(buttonIcon);
 //   ui->settingBtn->setIconSize(btn.rect().size());
   // ui->settingBtn->setStyleSheet("QPushButton{background: visible};");
  //  ui->settingBtn->setWindowOpacity(1.0);
     cosmere();
     /////////////////////////////////////////////////////////////////////////////////
qmovie();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::qmovie()
{
   // scene = new QGraphicsScene(this);
   // ui->graphicsView->setScene(scene);
//    QMovie *mv = new QMovie("C:\\Users\\Acer\\Desktop\\App\\Roshar\\2305-settings-icon.gif");
//    mv->start();
//    ui->label_2->setAttribute(Qt::WA_NoSystemBackground);
//    ui->label_2->setMovie(mv);
   // scene->addWidget(ui->label_2);
    ////////////////////////////////////////
     QMovie *mv = new QMovie("C:\\Users\\Acer\\Desktop\\App\\Roshar\\GIF-210827_134433.gif");
     //label gif
      ui->label_2->setMovie(mv);
      mv->setScaledSize(QSize(1000,1000));
      mv->start();

}

void MainWindow::secondMovie()
{
 QMovie *mv = new QMovie("");
 GraphicsMovieItem* item = new GraphicsMovieItem();
 item->setMovie(mv);
  //scene.addItem(item);
}

QByteArray getHeader(){
    QByteArray header;
    header.append("@!~!@");
    return header;
}
void MainWindow::cosmere()
{
    ui->textEdit->clear();
    QString path = QDir::currentPath()+QDir::separator()+"text.txt";
    QFile file(path);
    QByteArray header = getHeader();
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    qint64 value =  QRandomGenerator::global()->bounded(3500);
    qInfo() << value;
    in.seek(value);
    QByteArray buffer = file.peek(5);
    while (!in.atEnd() && !buffer.startsWith(header)) {
        file.seek(value++);
        buffer = file.peek(value);
        qInfo()<< "header not found at beggining " << " value: "<< value;
        //  return;
    }
    qInfo()<< "looking for header at file pos: " << file.pos() << " value: "<< value;
    //  buffer = file.peek(5);

        file.seek(value+4);
    for (int i=0;i<3 ;i++ ) {
        QString line = in.readLine();
        ui->textEdit->append(line);
        qInfo() << value;

        qInfo() << line;
    }
    QTimer::singleShot(60000,this,&MainWindow::cosmere);
}

bool put(QString path, QByteArray data,QIODevice::OpenMode mode) {
    QFile file(path);

    if(!file.open(mode)) {
        qWarning() <<file.errorString();
        return false;
    }
    qint64 bytes = file.write(data);
    if(!bytes) {
        qWarning() << file.errorString();
    }else{
        qInfo() << "Wrote" <<bytes << "to the file";
    }
    file.flush();
    file.close();

    return true;

}

void write(QString path,QByteArray data)
{
    qInfo() << "Write to file";
    if(put(path,data,QIODevice::WriteOnly)){
        qInfo() << "Data Written to file";
    }else {
        qWarning() << "Failed to write to file!";
    }
}

void append(QString path,QByteArray data)
{
    qInfo() << "Write to file";
    if(put(path,data,QIODevice::Append)){
        qInfo() << "Data Written to file";
    }else {
        qWarning() << "Failed to append file!";
    }
}


void readLines(QString path)
{
    QFile file(path);
    if(!file.exists()){
        qWarning() <<"File not found";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qWarning() <<file.errorString();
        return;
    }
    qInfo() <<"*********Reading files";
    while (!file.atEnd()){
        QString line(file.readLine());
        qInfo() << "Read:" << line.trimmed();
        qInfo() <<"****done";
    }
    file.close();
}


void MainWindow::on_settingBtn_clicked()
{
//    QPropertyAnimation *animation = new QPropertyAnimation(ui->settingBtn, "size");
//    animation->setDuration(1000);
//    QSize test = this->size();
//    animation->setStartValue(test);
//    animation->setEndValue(QSize(test.width()+100,test.height()+100));
//    animation->start();
    QString style = "border:4px solid; \n";
    style += " border-top-left-radius: 20px; \n";
    style += "border-top-right-radius: 20px;";
    ui->label_2->setStyleSheet(style);
    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->settingBtn, "iconSize");
    animation2->setDuration(500);
    // QSize test = this->size();
    animation2->setStartValue(QSize(100,50));
    animation2->setEndValue(QSize(50,25));
    animation2->start();
   //Dialog
    QCoreApplication::setOrganizationDomain("Cosmere");
    QCoreApplication::setOrganizationName("Stormlight Archive");
    QCoreApplication::setApplicationName("Roshar");
    QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());

    settings.setValue("text",123);
    qInfo()<<settings.value("test").toString();
    qInfo() <<settings.value("test").toInt();

}
