/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionQuit;
    QAction *sound;
    QWidget *centralwidget;
    QLCDNumber *lcd;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(753, 523);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Icons/icons8-files-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName("actionPlay");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/Icons/icons8-circle-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon1);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName("actionPause");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/Icons/icons8-circle-32 (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon2);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName("actionStop");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Icons/icons8-circle-32 (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        sound = new QAction(MainWindow);
        sound->setObjectName("sound");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("Icons/sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        sound->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lcd = new QLCDNumber(centralwidget);
        lcd->setObjectName("lcd");
        lcd->setGeometry(QRect(200, 470, 81, 31));
        lcd->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"}"));
        lcd->setDigitCount(8);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 753, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionPlay);
        menuEdit->addAction(actionPause);
        menuEdit->addAction(actionStop);
        toolBar->addSeparator();
        toolBar->addAction(actionPause);
        toolBar->addAction(actionPlay);
        toolBar->addAction(actionStop);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "Open a file", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPlay->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
#if QT_CONFIG(shortcut)
        actionPlay->setShortcut(QCoreApplication::translate("MainWindow", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
#if QT_CONFIG(shortcut)
        actionPause->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#if QT_CONFIG(shortcut)
        actionStop->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        sound->setText(QCoreApplication::translate("MainWindow", "Sound Icon", nullptr));
#if QT_CONFIG(tooltip)
        sound->setToolTip(QCoreApplication::translate("MainWindow", "Sound Icon", nullptr));
#endif // QT_CONFIG(tooltip)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
