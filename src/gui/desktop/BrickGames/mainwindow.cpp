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
    game_speed_timer_.setInterval(game_.speed);
    ui_->graphicsView->setScene(main_field_scene_);
    ui_->graphicsView->show();
    one_second_timer_.setInterval(1000);
    game_time_ = new QTime(0, 0, 0, 0);
    connect(&game_speed_timer_, SIGNAL(timeout()), this, SLOT(mainRender()));
    connect(&one_second_timer_, SIGNAL(timeout()), this, SLOT(updateGameTime()));
    ui_->gameOverLabel_1->setVisible(false);
    ui_->gameOverLabel_2->setVisible(false);
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
        on_pauseBtn_clicked();
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
    game_speed_timer_.setInterval(game_.speed);
    main_field_scene_->updateData(*game_.field);
    main_field_scene_->updateScene();
    showNext();
    ui_->levelData->setText(QString::number(game_.level));
    ui_->scoreData->setText(QString::number(game_.score));
    ui_->recordData->setText(QString::number(game_.high_score));
    if (game_.status == 0){
        ui_->game_time->setVisible(false);
        ui_->gameOverLabel_1->setVisible(true);
        ui_->gameOverLabel_2->setVisible(true);
        game_speed_timer_.stop();
    }
    else{
        ui_->gameOverLabel_1->setVisible(false);
        ui_->gameOverLabel_2->setVisible(false);
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
    game_time_ = new QTime(0, 0, 0, 0);
    one_second_timer_.start();
    one_second_timer_.start();
    ui_->game_time->setVisible(true);
}

void MainWindow::on_resetBtn_clicked()
{
    controller_.resetGames();
    startGame();
    game_time_->setHMS(0, 0, 0, 0);
    one_second_timer_.start();
    ui_->game_time->setVisible(true);

}

void MainWindow::startGame()
{
    game_ = controller_.getGameInfo();
    main_field_scene_->updateData(*game_.field);
    main_field_scene_->initializeScene();
    if(!game_speed_timer_.isActive()) game_speed_timer_.start();
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

void MainWindow::updateGameTime()
{
   *game_time_ =  game_time_->addSecs(1);
   ui_->game_time->setText(game_time_->toString());
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
    if (game_.pause == 0) one_second_timer_.stop();
    else one_second_timer_.start();
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

