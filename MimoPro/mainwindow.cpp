#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include <QCameraInfo>
#include <QGridLayout>
#include <QIcon>
#include <QStandardItem>
#include <QSize>
#include <QInputDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QTimer>
////file handling
#include <fstream>
#include <sstream>

using namespace std;


QString name;
string filename;
string elisa;
QString sd;


int filenumber = 0;
int counter = 0;

//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities.h"
#include "myvideocapture.h"


bool windowProperty(int value)
{
    return value;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      currentImage(nullptr)
{

    ui->setupUi(this);
    ui->peopleTracking->setToolTipDuration(1200);
    ui->peopleTracking->setToolTip("Detect objects by their HSV color");

    mOpenCamera = new MyVideoCapture(this);
    /////////////////////////////////////////////////////////////////////////////////
    // timer = new QTimer(this);
    // connect(timer,SIGNAL(timeout()),this,SLOT(updateProgressBar()));
    ////////////////////////////////////////////////////////////////////////////////
    //    connect(&source,&MyVideoCapture::connected,this,[&]()
    //    {
    //        ui->label->setText("Main window caused this");
    //    });
    //////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////
    mainStatusBar = statusBar();
    mainStatusLabel = new QLabel(mainStatusBar);
    mainStatusBar->addPermanentWidget(mainStatusLabel);
    mainStatusLabel->setText("MimoPro is ready");
    ui->label->setText("Welcome to MimoPro");

}

void MainWindow::on_openCamera_clicked()
{
    if(mOpenCamera != nullptr) {
        // if a thread is already running, stop it
        mOpenCamera->setRunning(false);
        connect(mOpenCamera, &MyVideoCapture::finished, mOpenCamera, &MyVideoCapture::deleteLater);
    }
    //mOpenCamera->start(QThread::HighestPriority);
    int camID = 0;
    mOpenCamera = new MyVideoCapture;
    connect(mOpenCamera, &MyVideoCapture::newPixmapCaptured,this,[&]()
    {
        ui->opencvFrame->setPixmap(mOpenCamera->pixmap().scaled(900,600));
    });
    mOpenCamera->start();
    mainStatusLabel->setText(QString("Capturing Camera %1").arg(camID));
}

void MainWindow::on_showCameraInfo_clicked()
{
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    QString info = QString("Available Cameras: \n");

    foreach (const QCameraInfo &cameraInfo, cameras)
        info += "  - " + cameraInfo.deviceName() + "\n";

    QMessageBox::information(this, "Cameras", info);
}

static void dbread(vector<cv::Mat>& images, vector<int>& labels)
{
    vector<cv::String>fn;
    // QString path = QDir::currentPath() + QDir::separator() + "faces" + QDir::separator();
    string path = "C:\\Users\\Acer\\Desktop\\Faces\\";
    cv::glob(path, fn, false);

    size_t count = fn.size();

    for (size_t i = 0; i < count; i++)
    {
        string itsname = "";
        char sep = '\\';
        size_t j = fn[i].rfind(sep, fn[i].length());
        if (j != string::npos)
        {
            itsname = (fn[i].substr(j + 1, fn[i].length() - j - 6));
        }
        images.push_back(cv::imread(fn[i], 0));
        labels.push_back(atoi(itsname.c_str()));
    }

}
void MainWindow:: eigenFaceTrainer() {

    vector<cv::Mat> images;
    vector<int>labels;
    dbread(images, labels);
    cout << "size of the image is" << images.size() << endl;
    cout << "size of the label is " << labels.size() << endl;
    cout << "Training begins...." << endl;
    ui->label->setText("Training begins");
    //create algorith eigenface recognizer

    cv::Ptr<cv::face::EigenFaceRecognizer> model = cv::face::EigenFaceRecognizer::create();

    //train data
    cout<< "about to train"<< endl;
    model->train(images, labels);
    // recognizer->train
    cout << "about to save" << endl;
    model->save("C:\\Users\\Acer\\Desktop\\elisa.yml");
    //model->save("elisa.yml");

    cout << "Training finished....." << endl;
    ui->label->setText("Training finished");
}


void MainWindow::on_trainModel_clicked()
{
    bool ok;
    sd = QInputDialog::getText(this,
                               tr("Add ID of Face"),
                               tr("Owners ID"),
                               QLineEdit::Normal,
                               tr("0"),    &ok);
    if(ok && !sd.isEmpty())
    {
        cv::VideoCapture capture(0);
        if (!capture.isOpened())
            return;
        cv::Mat frame;
        QString note = QString("Capturing your face 50 times, Press 'OK' Move your face dring progress");
        QMessageBox::information(this, "Cameras", note);
        int i = 0;
        for (;;)
        {
            capture >> frame;
            if(i<100)
            {
                takePhoto(frame);
                // cout << "Face Added"

                i++;

            }
            else{

                QString added = QString("Face Added");
                QMessageBox::information(this, "Cameras", added);
                break;
            }
        }   eigenFaceTrainer();
        mainStatusLabel->setText("Adding Serial NO");
    }

}

void MainWindow::takePhoto(cv::Mat &mframe)
{
    stringstream ssfn;
    elisa = sd.toStdString();

    cv::Mat res;
    cv::resize(mframe,res,cv::Size(128,128),0,0,cv::INTER_LINEAR);

    filename = "C:\\Users\\Acer\\Desktop\\Faces\\";
    qDebug() << sd;
    qDebug() << name;
    cout << elisa ;

    ssfn << filename << elisa << filenumber << ".jpg";
    filename = ssfn.str();
    cv::imwrite(filename, res);

    filenumber ++;
    ui->label->setText("Capturing Images");
}


void MainWindow::on_updateMonitorStatus_stateChanged(int status)
{

    if(status) {
        mOpenCamera->setMotionDetectingStatus(true);
        ui->trainModel->setEnabled(false);
    } else {
        mOpenCamera->setMotionDetectingStatus(false);
        ui->trainModel->setEnabled(true);
    }
}
void MainWindow::updateProgressBar()
{

    ui->progressBar->setValue(ui->progressBar->value()+1);
    //    timer->start(1000);
    //    if(counter <=100)
    //    {
    //        counter ++;
    //        ui->progressBar->setValue(counter);
    //        qInfo() << "counting";
    //        qInfo() << counter;
    //    }
    //    else
    //    {
    //        timer->stop();
    //        delete timer;
    //    }
}

void MainWindow::on_faceDetect_stateChanged(int status)
{
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::updateProgressBar);
    if(status) {
        mOpenCamera->setFaceDetectingStatus(true);
        ui->trainModel->setEnabled(false);
        ui->label->setText("Recognizing");
        timer->start(150);
    } else {
        mOpenCamera->setFaceDetectingStatus(false);
        ui->trainModel->setEnabled(true);
        ui->label->setText("Closing");
        ui->opencvFrame->update();
        timer->stop();
        delete timer;
        ui->progressBar->setValue(0);
    }
}

void MainWindow::on_objectTracking_clicked()
{


    QString info = QString("MimoPro \n");

    QMessageBox::information(this, "About", info);
}

void MainWindow::on_peopleTracking_clicked()
{
    hsv = new hsvColor(this);
    hsv->show();
    // windowProperty(false);
}
MainWindow::~MainWindow()
{
    delete ui;
    mOpenCamera->terminate();
    this->destroy();
}
