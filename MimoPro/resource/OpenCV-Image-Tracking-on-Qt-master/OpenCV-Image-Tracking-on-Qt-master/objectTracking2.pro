#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T18:42:28
# Author: Nauroze Hoath
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = objectTracking2
TEMPLATE = app
CONFIG += c++41


SOURCES += main.cpp\
        mainwindow.cpp



    HEADERS += mainwindow.h

        FORMS += \
            mainwindow.ui



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../opencv/build/x64/vc15/lib/ -lopencv_world451
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../opencv/build/x64/vc15/lib/ -lopencv_world451d
else:unix: LIBS += -L$$PWD/../../../../../../../../opencv/build/x64/vc15/lib/ -lopencv_world451

INCLUDEPATH += $$PWD/../../../../../../../../opencv/build/include
DEPENDPATH += $$PWD/../../../../../../../../opencv/build/include
