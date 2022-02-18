QT       += core gui multimedia multimediawidgets network concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
TARGET = MimoPro
TEMPLATE = app


SOURCES += \
    hsvColor.cpp \
    myvideocapture.cpp \
    main.cpp \
    mainwindow.cpp \
    utilities.cpp


HEADERS += \
    hsvColor.h \
   myvideocapture.h \
    mainwindow.h \
    utilities.h



FORMS += \
    hsvColor.ui \
    mainwindow.ui

# Using OpenCV or QCamera
# DEFINES += MIMOPRO_USE_QT_CAMERA=1
# QT += multimediawidgets

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


# QT += multimediawidgets

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world451
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world451d
else:unix: LIBS += -L$$PWD/../../../../../opencv/build/x64/vc15/lib/ -lopencv_world451

INCLUDEPATH += $$PWD/../../../../../opencv/build/include
DEPENDPATH += $$PWD/../../../../../opencv/build/include


# DEFINES += OPENCV_DATA_DIR= "C:\\opencv\\build\\etc\\haarcascades\\"
DEFINES += OPENCV_DATA_DIR= "C:\\opencv\\build\\etc\\haarcascades\\"



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc16/lib/ -lopencv_face451
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc16/lib/ -lopencv_face451d
else:unix: LIBS += -L$$PWD/../../../../../opencv/build/x64/vc16/lib/ -lopencv_face451

INCLUDEPATH += $$PWD/../../../../../opencv/build/include/opencv2
DEPENDPATH += $$PWD/../../../../../opencv/build/include/opencv2

RC_ICONS = ico.ico

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc14/lib/ -lopencv_tracking331
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../opencv/build/x64/vc14/lib/ -lopencv_tracking331d
else:unix: LIBS += -L$$PWD/../../../../../opencv/build/x64/vc14/lib/ -lopencv_tracking331

INCLUDEPATH += $$PWD/../../../../../opencv/build/x64/vc14
DEPENDPATH += $$PWD/../../../../../opencv/build/x64/vc14
