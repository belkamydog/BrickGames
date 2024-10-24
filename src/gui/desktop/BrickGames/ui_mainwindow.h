/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *startBtn;
    QPushButton *resetBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *scoreLabel;
    QLabel *scoreData;
    QLabel *levelLabel;
    QLabel *levelData;
    QLabel *recordLabel;
    QLabel *recordData;
    QPushButton *actionBtn;
    QPushButton *upBtn;
    QPushButton *rightBtn;
    QPushButton *dropBtn;
    QPushButton *leftBtn;
    QGraphicsView *nextView;
    QGraphicsView *holdView;
    QPushButton *pauseBtn;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(300, 536);
        MainWindow->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/console.jpg);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(59, 50, 125, 245));
        graphicsView->setStyleSheet(QString::fromUtf8("background: rgb(158, 172, 136);\n"
"border: 2px solid black;\n"
"border-radius: 0;"));
        startBtn = new QPushButton(centralwidget);
        startBtn->setObjectName("startBtn");
        startBtn->setGeometry(QRect(240, 350, 16, 16));
        startBtn->setAutoFillBackground(false);
        startBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  rgb(251, 214, 69);\n"
"	image: none;\n"
"	border: 3px solid rgba(94, 94, 94, 208);\n"
"	border-radius: 7;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(255, 147, 0);\n"
"	border: 3px solid rgb(0, 0, 0);\n"
"	image: none;\n"
"}"));
        startBtn->setAutoDefault(true);
        startBtn->setFlat(false);
        resetBtn = new QPushButton(centralwidget);
        resetBtn->setObjectName("resetBtn");
        resetBtn->setGeometry(QRect(190, 350, 16, 16));
        resetBtn->setAutoFillBackground(false);
        resetBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  rgb(251, 214, 69);\n"
"	image: none;\n"
"	border: 3px solid rgba(94, 94, 94, 208);\n"
"	border-radius: 7;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(255, 147, 0);\n"
"	border: 3px solid rgb(0, 0, 0);\n"
"	image: none;\n"
"}"));
        resetBtn->setAutoDefault(true);
        resetBtn->setFlat(false);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(186, 330, 31, 16));
        label->setStyleSheet(QString::fromUtf8("image: none;\n"
"color: rgba(33, 33, 33, 233);\n"
"font: 10pt \".AppleSystemUIFont\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 330, 31, 16));
        label_2->setStyleSheet(QString::fromUtf8("image: none;\n"
"color: rgba(33, 33, 33, 233);\n"
"font: 10pt \".AppleSystemUIFont\";"));
        scoreLabel = new QLabel(centralwidget);
        scoreLabel->setObjectName("scoreLabel");
        scoreLabel->setGeometry(QRect(200, 240, 33, 16));
        scoreLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 172, 136);\n"
"font: 10pt \".AppleSystemUIFont\";\n"
"image: none;\n"
"color: rgb(0, 0, 0)\n"
""));
        scoreData = new QLabel(centralwidget);
        scoreData->setObjectName("scoreData");
        scoreData->setGeometry(QRect(201, 256, 33, 13));
        scoreData->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 172, 136);\n"
"font: 10pt \".AppleSystemUIFont\";\n"
"image: none;\n"
"color: rgb(0, 0, 0)\n"
""));
        levelLabel = new QLabel(centralwidget);
        levelLabel->setObjectName("levelLabel");
        levelLabel->setGeometry(QRect(200, 210, 33, 16));
        levelLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 172, 136);\n"
"font: 10pt \".AppleSystemUIFont\";\n"
"image: none;\n"
"color: rgb(0, 0, 0)\n"
""));
        levelData = new QLabel(centralwidget);
        levelData->setObjectName("levelData");
        levelData->setGeometry(QRect(200, 226, 33, 12));
        levelData->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 172, 136);\n"
"font: 10pt \".AppleSystemUIFont\";\n"
"image: none;\n"
"color: rgb(0, 0, 0)\n"
""));
        recordLabel = new QLabel(centralwidget);
        recordLabel->setObjectName("recordLabel");
        recordLabel->setGeometry(QRect(200, 266, 38, 16));
        recordLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 172, 136);\n"
"font: 10pt \".AppleSystemUIFont\";\n"
"image: none;\n"
"color: rgb(0, 0, 0)\n"
""));
        recordData = new QLabel(centralwidget);
        recordData->setObjectName("recordData");
        recordData->setGeometry(QRect(200, 280, 38, 16));
        recordData->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 172, 136);\n"
"font: 10pt \".AppleSystemUIFont\";\n"
"image: none;\n"
"color: rgb(0, 0, 0)\n"
""));
        actionBtn = new QPushButton(centralwidget);
        actionBtn->setObjectName("actionBtn");
        actionBtn->setGeometry(QRect(201, 405, 71, 71));
        actionBtn->setAcceptDrops(false);
        actionBtn->setAutoFillBackground(false);
        actionBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  rgb(251, 214, 69);\n"
"	image: none;\n"
"	border: 3px solid rgba(94, 94, 94, 208);\n"
"	border-radius: 35;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(255, 147, 0);\n"
"	border: 3px solid rgb(0, 0, 0);\n"
"	image: none;\n"
"}"));
        actionBtn->setCheckable(false);
        actionBtn->setAutoDefault(true);
        actionBtn->setFlat(false);
        upBtn = new QPushButton(centralwidget);
        upBtn->setObjectName("upBtn");
        upBtn->setGeometry(QRect(72, 374, 50, 50));
        upBtn->setAutoFillBackground(false);
        upBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  rgb(251, 214, 69);\n"
"	image: none;\n"
"	border: 3px solid rgba(94, 94, 94, 208);\n"
"	border-radius: 25;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(255, 147, 0);\n"
"	border: 3px solid rgb(0, 0, 0);\n"
"	image: none;\n"
"}"));
        upBtn->setAutoDefault(true);
        upBtn->setFlat(false);
        rightBtn = new QPushButton(centralwidget);
        rightBtn->setObjectName("rightBtn");
        rightBtn->setGeometry(QRect(115, 410, 50, 50));
        rightBtn->setAutoFillBackground(false);
        rightBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  rgb(251, 214, 69);\n"
"	image: none;\n"
"	border: 3px solid rgba(94, 94, 94, 208);\n"
"	border-radius: 25;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(255, 147, 0);\n"
"	border: 3px solid rgb(0, 0, 0);\n"
"	image: none;\n"
"}"));
        rightBtn->setAutoDefault(true);
        rightBtn->setFlat(false);
        dropBtn = new QPushButton(centralwidget);
        dropBtn->setObjectName("dropBtn");
        dropBtn->setGeometry(QRect(72, 445, 50, 50));
        dropBtn->setAutoFillBackground(false);
        dropBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  rgb(251, 214, 69);\n"
"	image: none;\n"
"	border: 3px solid rgba(94, 94, 94, 208);\n"
"	border-radius: 25;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(255, 147, 0);\n"
"	border: 3px solid rgb(0, 0, 0);\n"
"	image: none;\n"
"}"));
        dropBtn->setAutoDefault(true);
        dropBtn->setFlat(false);
        leftBtn = new QPushButton(centralwidget);
        leftBtn->setObjectName("leftBtn");
        leftBtn->setGeometry(QRect(27, 410, 50, 50));
        leftBtn->setAutoFillBackground(false);
        leftBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  rgb(251, 214, 69);\n"
"	image: none;\n"
"	border: 3px solid rgba(94, 94, 94, 208);\n"
"	border-radius: 25;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(255, 147, 0);\n"
"	border: 3px solid rgb(0, 0, 0);\n"
"	image: none;\n"
"}\n"
""));
        leftBtn->setAutoDefault(true);
        leftBtn->setFlat(false);
        nextView = new QGraphicsView(centralwidget);
        nextView->setObjectName("nextView");
        nextView->setGeometry(QRect(198, 61, 40, 80));
        nextView->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 172, 136)"));
        holdView = new QGraphicsView(centralwidget);
        holdView->setObjectName("holdView");
        holdView->setGeometry(QRect(198, 165, 40, 31));
        holdView->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 172, 136)"));
        pauseBtn = new QPushButton(centralwidget);
        pauseBtn->setObjectName("pauseBtn");
        pauseBtn->setGeometry(QRect(140, 350, 16, 16));
        pauseBtn->setAutoFillBackground(false);
        pauseBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  rgb(251, 214, 69);\n"
"	image: none;\n"
"	border: 3px solid rgba(94, 94, 94, 208);\n"
"	border-radius: 7;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color:  rgb(255, 147, 0);\n"
"	border: 3px solid rgb(0, 0, 0);\n"
"	image: none;\n"
"}"));
        pauseBtn->setAutoDefault(true);
        pauseBtn->setFlat(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 330, 41, 16));
        label_3->setStyleSheet(QString::fromUtf8("image: none;\n"
"color: rgba(33, 33, 33, 233);\n"
"font: 10pt \".AppleSystemUIFont\";"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        startBtn->setDefault(true);
        resetBtn->setDefault(true);
        actionBtn->setDefault(false);
        upBtn->setDefault(true);
        rightBtn->setDefault(true);
        dropBtn->setDefault(true);
        leftBtn->setDefault(true);
        pauseBtn->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startBtn->setText(QString());
        resetBtn->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        scoreLabel->setText(QCoreApplication::translate("MainWindow", "score:", nullptr));
        scoreData->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        levelLabel->setText(QCoreApplication::translate("MainWindow", "level", nullptr));
        levelData->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        recordLabel->setText(QCoreApplication::translate("MainWindow", "record:", nullptr));
        recordData->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        actionBtn->setText(QString());
        upBtn->setText(QString());
        rightBtn->setText(QString());
        dropBtn->setText(QString());
        leftBtn->setText(QString());
        pauseBtn->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
