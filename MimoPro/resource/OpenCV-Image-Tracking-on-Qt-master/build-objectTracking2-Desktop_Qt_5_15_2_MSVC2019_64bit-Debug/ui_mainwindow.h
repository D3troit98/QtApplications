/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpinBox *vminBox;
    QSpinBox *smaxBox;
    QSlider *horizontalSlider_5;
    QLabel *label_2;
    QSpinBox *hminBox;
    QPushButton *addButton;
    QSlider *horizontalSlider_6;
    QLabel *label_3;
    QSlider *horizontalSlider_3;
    QLabel *label_6;
    QSlider *horizontalSlider;
    QSpinBox *sminBox;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QSpinBox *vmaxBox;
    QLabel *label_4;
    QLabel *label_7;
    QSlider *horizontalSlider_4;
    QSpinBox *hmaxBox;
    QLabel *label_5;
    QLineEdit *nameLineEdit;
    QLabel *label_8;
    QPushButton *defaultButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(573, 470);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(30);
        sizePolicy.setVerticalStretch(30);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        vminBox = new QSpinBox(centralWidget);
        vminBox->setObjectName(QString::fromUtf8("vminBox"));
        vminBox->setMaximum(255);

        gridLayout->addWidget(vminBox, 11, 2, 1, 1);

        smaxBox = new QSpinBox(centralWidget);
        smaxBox->setObjectName(QString::fromUtf8("smaxBox"));
        smaxBox->setMaximum(255);
        smaxBox->setValue(255);

        gridLayout->addWidget(smaxBox, 8, 2, 1, 1);

        horizontalSlider_5 = new QSlider(centralWidget);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setMaximum(255);
        horizontalSlider_5->setValue(255);
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_5, 8, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 7, 1, 1, 1);

        hminBox = new QSpinBox(centralWidget);
        hminBox->setObjectName(QString::fromUtf8("hminBox"));
        hminBox->setMaximum(255);

        gridLayout->addWidget(hminBox, 2, 2, 1, 1);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 20, 2, 1, 1);

        horizontalSlider_6 = new QSlider(centralWidget);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setMaximum(255);
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_6, 6, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        horizontalSlider_3 = new QSlider(centralWidget);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setValue(255);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_3, 18, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 17, 1, 1, 1);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 11, 1, 1, 1);

        sminBox = new QSpinBox(centralWidget);
        sminBox->setObjectName(QString::fromUtf8("sminBox"));
        sminBox->setMaximum(255);

        gridLayout->addWidget(sminBox, 6, 2, 1, 1);

        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_2, 2, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 5, 1, 1, 1);

        vmaxBox = new QSpinBox(centralWidget);
        vmaxBox->setObjectName(QString::fromUtf8("vmaxBox"));
        vmaxBox->setMaximum(255);
        vmaxBox->setValue(255);

        gridLayout->addWidget(vmaxBox, 18, 2, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 1, 1, 1, Qt::AlignLeft);

        horizontalSlider_4 = new QSlider(centralWidget);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setMaximum(255);
        horizontalSlider_4->setValue(255);
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_4, 4, 1, 1, 1);

        hmaxBox = new QSpinBox(centralWidget);
        hmaxBox->setObjectName(QString::fromUtf8("hmaxBox"));
        hmaxBox->setMaximum(255);
        hmaxBox->setValue(255);

        gridLayout->addWidget(hmaxBox, 4, 2, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 10, 1, 1, 1);

        nameLineEdit = new QLineEdit(centralWidget);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 20, 1, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 19, 1, 1, 1);

        defaultButton = new QPushButton(centralWidget);
        defaultButton->setObjectName(QString::fromUtf8("defaultButton"));

        gridLayout->addWidget(defaultButton, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        horizontalSlider_6->raise();
        label_6->raise();
        horizontalSlider_3->raise();
        horizontalSlider->raise();
        label->raise();
        horizontalSlider_2->raise();
        label_5->raise();
        label_3->raise();
        hminBox->raise();
        sminBox->raise();
        vmaxBox->raise();
        vminBox->raise();
        label_7->raise();
        label_4->raise();
        horizontalSlider_4->raise();
        hmaxBox->raise();
        label_2->raise();
        horizontalSlider_5->raise();
        smaxBox->raise();
        nameLineEdit->raise();
        addButton->raise();
        label_8->raise();
        defaultButton->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 573, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(hminBox, SIGNAL(valueChanged(int)), horizontalSlider_2, SLOT(setValue(int)));
        QObject::connect(hmaxBox, SIGNAL(valueChanged(int)), horizontalSlider_4, SLOT(setValue(int)));
        QObject::connect(sminBox, SIGNAL(valueChanged(int)), horizontalSlider_6, SLOT(setValue(int)));
        QObject::connect(smaxBox, SIGNAL(valueChanged(int)), horizontalSlider_5, SLOT(setValue(int)));
        QObject::connect(vminBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(vmaxBox, SIGNAL(valueChanged(int)), horizontalSlider_3, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), hminBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_4, SIGNAL(valueChanged(int)), hmaxBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_6, SIGNAL(valueChanged(int)), sminBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_5, SIGNAL(valueChanged(int)), smaxBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), vminBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), vmaxBox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "S_MAX", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "H_MIN", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "V_MAX", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "S_MIN", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "H_MAX", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Adjust the HSV range until the target object is the only part of the image isolated in white.", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "V_MIN", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Name :", nullptr));
        defaultButton->setText(QCoreApplication::translate("MainWindow", " Default Settings ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
