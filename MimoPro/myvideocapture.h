// mode: c++
#ifndef MYVIDEOCAPTURE_H
#define MYVIDEOCAPTURE_H

#include <QString>
#include <QThread>
#include <QMutex>
#include <QPixmap>

#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/objdetect.hpp"
// open cv core
#include "opencv2\core\core.hpp"
#include "opencv2\core.hpp"
#include "opencv2\face.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\objdetect\objdetect.hpp"

#include "opencv2/videoio.hpp"
#include "opencv2/video/background_segm.hpp"

using namespace std;

#define ID_CAMERA 0

class MyVideoCapture : public QThread
{
    Q_OBJECT
public:
    MyVideoCapture(QObject *parent = nullptr);
    void setRunning(bool run) {running = run; };
    void takePhoto() {taking_photo = true; }
    void setFaceDetectingStatus(bool status) {
        face_detecting_status = status;
        face_detected = false;
    };
    void setMotionDetectingStatus(bool status) {
        motion_detecting_status = status;
        motion_detected = false;
    };

    QPixmap pixmap() const
    {
        return mPixmap;
    }
protected:
    void run() override;
public:
    void faceDetect(cv::Mat &mframe);
signals:
    void newPixmapCaptured(cv::Mat *data);
    void connected(bool *message);


private:
    void detectFaces(cv::Mat &mFrame);
    void takePhoto(cv::Mat &mframe);
    // void faceDetect(cv::Mat &mframe);
    void motionDetect(cv::Mat &frame);
private:
    bool running;
    QPixmap mPixmap;
    cv::Mat frame;
    cv::VideoCapture mVideoCap();
    bool message;



    QImage cvMatToQImage( const cv::Mat &inMat );
    QPixmap cvMatToQPixmap( const cv::Mat &inMat );

    // face detection
    cv::CascadeClassifier *classifier;

    // take photos
    bool taking_photo;
    // face analysis
    bool face_detecting_status;
    bool face_detected;
    // motion analysis
    bool motion_detecting_status;
    bool motion_detected;
    cv::Ptr<cv::BackgroundSubtractorMOG2> segmentor;
};

#endif // MYVIDEOCAPTURE
