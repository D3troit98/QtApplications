#include "myvideocapture.h"
#include "mainwindow.h"
#include <QDebug>
#include <QtConcurrent>
#include "ui_mainwindow.h"
#include "utilities.h"


MyVideoCapture::MyVideoCapture(QObject *parent)
    :QThread{parent}


{
    face_detecting_status =  false;
    motion_detecting_status = false;
}



void MyVideoCapture::run()
{
    running = true;
    cv::VideoCapture mVideoCap(0);
    cv::Mat tmp_frame;
    emit connected(&message);
    segmentor = cv::createBackgroundSubtractorMOG2(500, 16, true);
    cv::Mat grayScale;
    while(running) {
        mVideoCap >>tmp_frame;
        if(tmp_frame.empty()){
            break;
        }
        if(motion_detecting_status) {
            motionDetect(tmp_frame);
        }
        if(face_detecting_status){
            faceDetect(tmp_frame);
        }else{
            mPixmap = cvMatToQPixmap(tmp_frame);
            frame = tmp_frame;
            emit newPixmapCaptured(&frame);}
    }
    mVideoCap.release();
    running = false;

}





void MyVideoCapture::faceDetect(cv::Mat &frame)
{
    emit connected(&message);
    // double scale = 2.0;
    cv::CascadeClassifier faceCascade;
    faceCascade.load("C:\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt.xml");
    cout << "start recognizing..." << endl;
    //load pre-trained data sets
    cout << "signal about to the sent" << endl;

    emit connected(&message);
    cv::Ptr<cv::face::FaceRecognizer> model = cv::face::FisherFaceRecognizer::create();
    cout << "reading model...." << endl;

    model->read("C:\\Users\\Acer\\Desktop\\elisa.yml");
    cout << "done reading...." << endl;
    cv::Mat testSample = cv::imread("C:\\Users\\Acer\\Pictures\\Camera Roll\\WIN_20210401_15_14_29_Pro.jpg", 0);
    cout << " done reading Test ....."<<endl;



    //VideoCapture cap("C:/Users/lsf-admin/Pictures/Camera Roll/video000.mp4")
    cout <<" passed video cap"<<endl;

    // cv::namedWindow(window, 1);
    long count = 0;
    cout <<" long cont"<<endl;
    string Pname = "";
    cv::VideoCapture mVideoCap(0);
    while (face_detecting_status)
    {

        vector<cv::Rect>faces;

        cv::Mat grayScaleFrame;
        cv::Mat original;
        cv::Mat greenframe;

        mVideoCap >>frame;
        //cap.read(frame);
        count = count + 1;//cont frames;

        if (!frame.empty()) {

            //clone from the original frame
            original = frame.clone();

            //convert image to grayscale and equalize
            cvtColor(original, grayScaleFrame, cv::COLOR_BGR2GRAY);
            equalizeHist(grayScaleFrame, grayScaleFrame);

            //detect face in gray image

            faceCascade.detectMultiScale(grayScaleFrame, faces, 1.1, 3, 0, cv::Size(90, 90));

            //number of faces detected

            cout << faces.size() << " faces detected" << endl;
            std::string frameset = std::to_string(count);
            std::string faceset = std::to_string(faces.size());

            // int width = 0, height = 0;

            //region of interest
            //cv::Rect roi:

            for (int i = 0; i < faces.size(); i++)
            {
                //region of interest
                cv::Rect face_i = faces[i];

                //crop the roi from grya image
                cv::Mat face = grayScaleFrame(face_i);

                //resizing the cropped image to suit to database image sizes
                cv::Mat face_resized;
                cv::resize(face, face_resized, cv::Size(128, 128), 1.0, 1.0, cv::INTER_CUBIC);


                //recognizing what faces detected
                int label = -1; double confidence = 0;
                model->predict(face_resized, label, confidence);

                cout << " confidence " << confidence << " Label: " << label << endl;

                Pname = to_string(label);

                //drawing green rectagle in recognize face
                rectangle(original, face_i, CV_RGB(0, 255, 0), 1);
                string text = Pname;


                int pos_x = std::max(face_i.tl().x - 10, 0);
                int pos_y = std::max(face_i.tl().y - 10, 0);

                //name the person who is in the image
                putText(original, text, cv::Point(pos_x, pos_y), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
                //cv::imwrite("E:/FDB/"+frameset+".jpg", cropImg);


            }


            putText(original, "Frames: " + frameset, cv::Point(30, 60), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
            putText(original, "No. of Persons detected: " + to_string(faces.size()), cv::Point(30, 90), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.0, CV_RGB(0, 255, 0), 1.0);
            //display to the winodw
            // cv::imshow(window, original);
            mPixmap = cvMatToQPixmap(original);
            greenframe = original;
            emit newPixmapCaptured(&greenframe);
            //cout << "model infor " << model->getDouble("threshold") << endl;
        }

    }
    // mVideoCap.release();
    // face_detecting_status =  false;
}


void MyVideoCapture::motionDetect(cv::Mat &frame )
{
    cv::Mat fgmask;
    segmentor->apply(frame, fgmask);
    if (fgmask.empty()) {
        return;
    }

    cv::threshold(fgmask, fgmask, 25, 255, cv::THRESH_BINARY);

    int noise_size = 9;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(noise_size, noise_size));
    cv::erode(fgmask, fgmask, kernel);
    kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(noise_size, noise_size));
    cv::dilate(fgmask, fgmask, kernel, cv::Point(-1,-1), 3);

    vector<vector<cv::Point> > contours;
    cv::findContours(fgmask, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    bool has_motion = contours.size() > 0;
    if(!motion_detected && has_motion) {
        motion_detected = true;

        qDebug() << "new motion detected, should send a notification.";
        QtConcurrent::run(Utilities::notifyMobile);
    } else if (motion_detected && !has_motion) {
        motion_detected = false;
        //   setVideoSavingStatus(STOPPING);
        qDebug() << "detected motion disappeared.";
    }

    cv::Scalar color = cv::Scalar(0, 0, 255); // red
    for(size_t i = 0; i < contours.size(); i++) {
        cv::Rect rect = cv::boundingRect(contours[i]);
        cv::rectangle(frame, rect, color, 1);
        //cv::drawContours(frame, contours, (int)i, color, 1);
    }
}


QImage MyVideoCapture:: cvMatToQImage( const cv::Mat &inMat )
{
    switch ( inMat.type() )
    {
    // 8-bit, 4 channel
    case CV_8UC4:
    {
        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_ARGB32 );

        return image;
    }

        // 8-bit, 3 channel
    case CV_8UC3:
    {
        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_RGB888 );

        return image.rgbSwapped();
    }

        // 8-bit, 1 channel
    case CV_8UC1:
    {
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_Grayscale8 );
#else
        static QVector<QRgb>  sColorTable;

        // only create our color table the first time
        if ( sColorTable.isEmpty() )
        {
            sColorTable.resize( 256 );

            for ( int i = 0; i < 256; ++i )
            {
                sColorTable[i] = qRgb( i, i, i );
            }
        }

        QImage image( inMat.data,
                      inMat.cols, inMat.rows,
                      static_cast<int>(inMat.step),
                      QImage::Format_Indexed8 );

        image.setColorTable( sColorTable );
#endif

        return image;
    }

    default:
        qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
        break;
    }

    return QImage();
}

QPixmap MyVideoCapture::cvMatToQPixmap( const cv::Mat &inMat )
{
    return QPixmap::fromImage( cvMatToQImage( inMat ) );
}

