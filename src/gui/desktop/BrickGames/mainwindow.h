#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QKeyEvent>

#include "../../../controllers/BrickGameController.h"
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
    void on_dropBtn_clicked();
    void on_upBtn_clicked();
    void on_actionBtn_clicked();

private:
    Ui::MainWindow *ui_;
    QTimer timer_;
    GameScene *main_field_scene_;
    GameScene *next_figure_;
    GameInfo_t game_;

    void startGame();
    void showNext();
    s21::BrickGameController controller_;
    GamesList_t current_game_ = TetrisGame;

};
#endif // MAINWINDOW_H
