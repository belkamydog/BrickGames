#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);
    game_ = controller_.getGameInfo();
    main_field_scene_ = new GameScene (12, *game_.field);
    timer_.setInterval(game_.speed);
    ui_->graphicsView->setScene(main_field_scene_);
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
    case Qt::Key_Up:
        result = Up;
        break;
    case Qt::Key_Down:
        result = Down;
        break;
    case Qt::Key_Q:
        result = Terminate;
        break;
    case Qt::Key_Space:
        result = Action;
        break;
    case Qt::Key_P:
        result = Pause;
        break;
    case Qt::Key_S:
        on_startBtn_clicked();
        break;
    case Qt::Key_R:
        on_resetBtn_clicked();
        break;
    default:
        result = Start;
        break;
    }
    if (!need_update_) controller_.getUserActionFromGui(result);
    need_update_ = true;
}

void MainWindow::mainRender()
{
    game_ = controller_.getGameInfo();
    game_ = controller_.sendDataToGui();
    timer_.setInterval(game_.speed);
    main_field_scene_->updateData(*game_.field);
    main_field_scene_->updateScene();
    showNext();
    ui_->levelData->setText(QString::number(game_.level));
    ui_->scoreData->setText(QString::number(game_.score));
    ui_->recordData->setText(QString::number(game_.high_score));
    if (game_.status == 0){
        ui_->gameOverLabel_1->setText(" GAME");
        ui_->gameOverLabel_2->setText(" OVER");
        timer_.stop();
    }
    else{
        ui_->gameOverLabel_1->clear();
        ui_->gameOverLabel_2->clear();
    }
    need_update_ = false;
}

void MainWindow::on_startBtn_clicked()
{
    startGame();
    if (current_game_ == TetrisGame){
        ui_->nextView->setEnabled(true);
        current_game_ = SnakeGame;
        controller_.setCurrentGame(SnakeGame);
    }
    else if (current_game_ == SnakeGame){
        current_game_ = TetrisGame;
        controller_.setCurrentGame(TetrisGame);
        ui_->nextView->setEnabled(false);
    }
}

void MainWindow::on_resetBtn_clicked()
{
    controller_.resetGames();
    startGame();
}

void MainWindow::startGame()
{
    game_ = controller_.getGameInfo();
    main_field_scene_->updateData(*game_.field);
    main_field_scene_->initializeScene();
    if(!timer_.isActive()) timer_.start();
}

void MainWindow::showNext()
{
    if (game_.next != nullptr && current_game_ == TetrisGame){
        next_figure_ = new GameScene (8, *game_.next);
        next_figure_->updateData(*game_.next);
        next_figure_->initializeScene();
        next_figure_->updateScene();
        ui_->nextView->setScene(next_figure_);
        ui_->nextView->show();
    }
}

void MainWindow::on_leftBtn_clicked()
{
    controller_.getUserActionFromGui(Left);
}

void MainWindow::on_rightBtn_clicked()
{
    controller_.getUserActionFromGui(Right);
}

void MainWindow::on_pauseBtn_clicked()
{
    controller_.getUserActionFromGui(Pause);
}

void MainWindow::on_dropBtn_clicked()
{
        controller_.getUserActionFromGui(Down);
}

void MainWindow::on_upBtn_clicked()
{
        controller_.getUserActionFromGui(Up);
}

void MainWindow::on_actionBtn_clicked()
{
    controller_.getUserActionFromGui(Action);
}

