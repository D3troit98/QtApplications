#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStatusBar>
#include <QLabel>
#include <QListView>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include <QMutex>
#include <QStandardItemModel>
#include <QGraphicsPixmapItem>
#include <QMap>


#ifdef MIMOPRO_USE_QT_CAMERA
#include <QCameraViewfinder>
#include <QCamera>
#endif

//////// open cv core WebCam//////////////////////////
#include "opencv2\core\core.hpp"
#include "opencv2\core.hpp"
#include "opencv2\face.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\opencv.hpp"
///////////////Video handling/////////////////

#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/core/ocl.hpp>

#include "myvideocapture.h"
#include "hsvColor.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MyVideoCapture;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool windowProperty(int value);

    ~MainWindow();

    void updateProgressBar(); 
private slots:
    void on_openCamera_clicked();
    void on_showCameraInfo_clicked();
    void on_trainModel_clicked();
    void on_updateMonitorStatus_stateChanged(int status);
    void on_faceDetect_stateChanged(int status);
    void on_objectTracking_clicked();

    void on_peopleTracking_clicked();

private:
    void detectFaces(cv::Mat &frame,cv::Mat*);
    void takePhoto(cv::Mat &mframe);
    void  eigenFaceTrainer();

private:
    Ui::MainWindow *ui;
    MyVideoCapture *mOpenCamera;
    hsvColor *hsv;

#ifdef MIMOPRO_USE_QT_CAMERA
    QCamera *camera;
    QCameraViewfinder *viewfinder;
#endif

    cv::CascadeClassifier *classifier;
    QString currentImagePath;
    QGraphicsPixmapItem *currentImage;
    QStatusBar *mainStatusBar;
    QLabel *mainStatusLabel;
    cv::Mat currentFrame;


};
#endif // MAINWINDOW_H
