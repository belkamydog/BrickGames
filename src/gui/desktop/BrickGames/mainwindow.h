#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QKeyEvent>

#include "../../../brick_game/snake/Snake.h"
#include "gamescene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_resetBtn_clicked();
    void mainRender();
    void on_startBtn_clicked();

    void on_leftBtn_clicked();

    void on_rightBtn_clicked();


    void on_pauseBtn_clicked();

private:
    Ui::MainWindow *ui_;
    QTimer timer_;
    GameScene scene_;
    GameInfo_t game_;
    s21::Snake *snake_;
    void startGame();

};
#endif // MAINWINDOW_H
