#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);
    timer_.setInterval(game_.speed);
    ui_->graphicsView->setScene(&scene_);
    ui_->graphicsView->show();
    connect(&timer_, SIGNAL(timeout()), this, SLOT(mainRender()));
}

MainWindow::~MainWindow()
{
    delete ui_;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    UserAction_t result;
    switch (event->key()) {
    case Qt::Key_Left:
        result = Left;
        break;
    case Qt::Key_Right:
        result = Right;
        break;
    case Qt::Key_Q:
        result = Terminate;
        break;
    case Qt::Key_Space:
        result = Action;
        break;
    default:
        result = Start;
        break;
    }
    snake_->userInput(result, false);
}

void MainWindow::mainRender()
{
    game_ = snake_->getGameInfo();
    snake_->updateCurrentState();
    timer_.setInterval(game_.speed);
    scene_.setGame(game_);
    scene_.updateScene();
    ui_->levelData->setText(QString::number(game_.level));
    ui_->scoreData->setText(QString::number(game_.score));
    ui_->recordData->setText(QString::number(game_.high_score));
}

void MainWindow::on_startBtn_clicked()
{
    startGame();
}


void MainWindow::on_resetBtn_clicked()
{
    if (snake_ != nullptr){
        timer_.stop();
        delete snake_;
        startGame();
    }

}

void MainWindow::startGame()
{
    snake_ = new s21::Snake;
    game_ = snake_->getGameInfo();
    scene_.setGame(game_);
    scene_.initializeScene();
    timer_.start();
}


void MainWindow::on_leftBtn_clicked()
{
    snake_->userInput(Left, false);
}


void MainWindow::on_rightBtn_clicked()
{
    snake_->userInput(Right, false);
}





void MainWindow::on_pauseBtn_clicked()
{
    snake_->userInput(Pause, false);
}

